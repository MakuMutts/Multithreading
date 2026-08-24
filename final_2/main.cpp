#include <iostream>
#include <fstream>
#include <string>
#include <format>

using namespace std;

int main(){
    int n = 1;
    string filename = "file" + to_string(n) + ".txt";
    fstream file(filename); 
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
    file.close();
}