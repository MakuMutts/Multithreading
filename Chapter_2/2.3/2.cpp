#include <iostream>
#include <thread>

using namespace std;

void DoWork(int i){
    cout << "Worker thread " << i << " is doing work" << endl;
}

thread CreateThread(int i){
    thread t(DoWork, i);
    cout << "Create thread: " << i << endl;
    return t;
}

int main(){
    thread w1 = CreateThread(1);
    thread w2;
    w2 = move(w1);
    w1 = CreateThread(2);
    w2.join();
    w1.join();
}