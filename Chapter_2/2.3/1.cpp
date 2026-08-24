#include <iostream>
#include <thread>

using namespace std;

void DoWork(int i){
    cout << "Worker thread " << i << " is doing work" << endl;
}


int main() {
    thread w1(DoWork, 1);
    thread w2;
    w2 = move(w1);
    w1 = thread(DoWork, 2);
    w2.join();
    w1.join();
}