#include "stdafx.h"

using namespace std;

int g_counter{};
//double g_counter{};

//atomic<int> g_counter{};

//mutex g_console_mutex;

void func()
{
    //g_console_mutex.lock();
    for (int i{}; i < 50000; i++) {
        g_counter++;
    }
    //g_console_mutex.unlock();
}

int main()
{
    cout.imbue(std::locale(""));

    for (int i{}; i < 10; ++i) {
        g_counter = 0;
        vector<thread> threadPool;
        for (size_t t{}; t < 20; ++t)
            threadPool.push_back(
                thread(func));
        for (auto& t : threadPool)
            t.join();
        cout << "Run " << i << ": "
            << "Counter = " << (int)g_counter
            << endl;
    }
    return 0;
}
