#include "stdafx.h"

using namespace std;

mutex g_console_mutex;

void DisplayThreadId() {
	cout << " {threadid = "
		<< this_thread::get_id()
		<< "}" << endl;
}

void func(string msg, string symbol, int count) {
	g_console_mutex.lock();
	cout << msg << " enter func()";
	DisplayThreadId();
	for (int i{}; i < count; ++i){
		cout << symbol;
		this_thread::sleep_for(1ns);
	}
	cout << endl << msg << " exit func()";
	DisplayThreadId();
	g_console_mutex.unlock();
}

int main() {
	cout << "enter main()";
	DisplayThreadId();

	thread t1(func, "Thread 1", "[]", 10);
	thread t2(func, "Thread 2", "@@", 20);

	t1.join();
	t2.join();

	cout << "exit main()";
	DisplayThreadId();

	return 0;
}
