#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void DoWork(int i){
    cout << "Worker: " << i << endl;
}

void StartWork(vector<thread>& vec, int count){
    for(int i = 0; i < count; i++){
        thread t(DoWork, i+1);
        vec.push_back(move(t));
    }
}

void EndWork(vector<thread>& vec){
    int n = 1;
    for(auto& v : vec){
        v.join();
        cout << "Work " << n << " stopped" << endl;
        ++n;
    }
}

int main(){
    vector<thread> threads;
    StartWork(threads, 5);
    EndWork(threads);
}
