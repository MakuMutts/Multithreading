#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include <format>
#include <vector>

using namespace std;

void ReadFile(int fileNumber){
    string filename = "file" + to_string(fileNumber) + ".txt";
    cout << "File: " + filename + " readed" << endl;
    fstream file(filename); 
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
    file.close();
}

void StartWork(vector<thread>& vec, int count){
    for(int i = 0; i < count; i++){
        thread t(ReadFile, i);
        vec.push_back(move(t));
    }
}

void FinishWork(vector<thread>& vec){
    for(auto& v : vec){
        v.join();
        cout << "Thread finished" << endl;
    }
}


int main(){
    vector<thread> threads;
    StartWork(threads, 3);
    FinishWork(threads);
}