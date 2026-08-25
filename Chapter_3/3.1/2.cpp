#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex m;

void Counter(int id, int& counter){
   
    lock_guard<mutex> l(m);
    for(int i = 0; i < 100000; i++){
        ++counter;
    }
    //cout << "Thread id: " << id << " Count: " << counter << endl;
}


int main(){
    int counter = 0;
    thread t1(Counter, 1, ref(counter));
    thread t2(Counter, 2, ref(counter));
    thread t3(Counter, 3, ref(counter));
    thread t4(Counter, 4, ref(counter));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "Counter: " << counter << endl;
}