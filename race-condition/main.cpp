#include "stdafx.h"

using namespace std;

std::atomic<int> g_counter{};
std::atomic<bool> g_won{false};

void func(string name)
{
    while(g_counter > 0)
    {
        g_counter--;
        std::this_thread::sleep_for(1us);
    }
    if (!g_won)
    {
        g_won = true;
        cout << name << " wins!" << endl;
    }
}

int main()
{
    for (int run{}; run < 10; run++)
    {
        cout << "Race " << run << ": ";
        g_counter = 20000;
        g_won = false;

        thread t1(func, "Thread 1");
        thread t2(func, "Thread 2");

        t1.join();
        t2.join();
    }
    return 0;
}
