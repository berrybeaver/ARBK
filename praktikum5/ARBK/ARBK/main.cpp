#include <iostream>
#include <thread>
#include <mutex>	
#include "semaphore.h"

using namespace std;

mutex Mutex;
Semaphore s(1);

void low_alp() {
	//Mutex.lock();
	s.wait();
	for (char i = 'a'; i <= 'z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	//Mutex.unlock();
	s.post();
}

void num() {

	//Mutex.lock();
	s.wait();
	for (int i = 0; i <= 32; i++) {
		cout << i << ", ";
	}
	cout << endl;
	//Mutex.unlock();
	s.post();
}

void high_alp() {

	//Mutex.lock();
	s.wait();
	for (char i = 'A'; i <= 'Z'; i++) {
		cout << i << ", ";
	}
	cout << endl;
	//Mutex.unlock();
	s.post();
}

int main() {

	thread T1(low_alp);
	thread T2(num);
	thread T3(high_alp);
	T1.join();
	T2.join();
	T3.join();

}
	