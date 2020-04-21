#include "stdafx.h"

using namespace std;

void DisplayThreadId(){
	cout << " {threadid = "
		<< this_thread::get_id()
		<< "}" << endl;
}

void func(string msg ) {
	cout << "enter func()";
	DisplayThreadId();
	cout << "\t" << msg << endl;
	cout << "exit func()";
	DisplayThreadId();
}

int main(){
	cout << "enter main()";
	DisplayThreadId();
	cout << "\tStarting new thread..." << endl;
	thread t1(func, "Threading is cool!");
	// Wait here for thread 1 to exit
	t1.join();
	cout << "exit main()";
	DisplayThreadId();
    return 0;
}
