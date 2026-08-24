#include <iostream>
#include <thread>

using namespace std;


void StartWorker(thread t, int i){
    cout << "Worker: " << i << endl;
}


int main(){
    thread t1, t2;
    StartWorker(move(t1),1);

    t2 = move(t1);
    StartWorker(move(t1),2);

    t1.join();
    t2.join();
}