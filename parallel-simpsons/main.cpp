#include "stdafx.h"

using namespace std;

// We want to integrate the unit circle
// in the first quadrant from 0 to 1
double g_a{0.0};
double g_b{1.0};

inline double f(double x)
{
    return sqrt(1 - pow(x, 2));
}

struct TCB {
    std::thread* t = nullptr;
    double a{};
    double b{};
    long intervals{};
    double integral{};
};

void simpsons(TCB* tcb)
{
    double sum = f(tcb->b) + f(tcb->a);
    double deltaX = (tcb->b - tcb->a) / tcb->intervals;
    tcb->a += deltaX;
    for (int i=1; i < tcb->intervals; i++) {
        int coeff = 2 * (i % 2 + 1);
        double y=f(tcb->a);
        if (!isnan(y)) sum += coeff*y;
        tcb->a += deltaX;
    }
    tcb->integral = (deltaX / 3) * sum;
}

int main()
{
    int max_threads = thread::hardware_concurrency();

    cout.imbue(std::locale("en_US.UTF-8"));

    cout << "This session can support " << max_threads
         << " simultaneous threads" << endl << endl;

    cout << setw(15) << "Integral"
         << setw(10) << "Threads"
         << setw(10) << "Time" << endl;

    for (int threads{1}; threads <= max_threads * 4; threads *= 2) {

        auto startTime = chrono::steady_clock::now();

        double interval_width = (g_b - g_a) / threads;

        // Each thread gets its own
        // thread control block (TCB)
        vector<TCB*> threadPool;

        for (int i{}; i < threads; i++) {
            TCB* tcb = new TCB();
            tcb->a = i * interval_width;
            tcb->b = tcb->a + interval_width;
            tcb->intervals = 134217728 / threads;  //2^27
            tcb->t = new std::thread(simpsons, tcb);
            // New thread is now running, so add its TCB
            threadPool.push_back(tcb);
        }

        double integral{};
        for (auto& tcb : threadPool)
        {
            // Wait here for this thread to finish
            tcb->t->join();
            // Now we read this thread's result
            integral += tcb->integral;
            delete tcb->t;
         }
         threadPool.clear();

        auto endTime = chrono::steady_clock::now();

        auto totalTime = chrono::duration_cast<chrono::milliseconds>
            (endTime - startTime).count();

        cout << setw(15) << fixed << setprecision(11)
             << integral * 4.0
             << setw(10) << threads
             << setw(10) << fixed << setprecision(3)
             << totalTime << "(ms)" << endl;
    }

    return 0;
}
