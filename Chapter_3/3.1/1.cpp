#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m;

void Counter(int id, int& counter){
   
    lock_guard<mutex> l(m);
    ++counter;
    cout << "Thread id: " << id << " Count: " << counter << endl;
}


int main(){
    int counter = 0;
    thread t1(Counter, 1, ref(counter));
    thread t2(Counter, 2, ref(counter));

    t1.join();
    t2.join();

    cout << "Counter: " << counter << endl;
}