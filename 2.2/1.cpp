#include <iostream>
#include <string>
#include <thread>
#include <cassert>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void CalculateSum(vector<int> const& vec, int start, int end, int& result) {
    result = 0;
    for (int i = start; i < end; i++) {
        result += vec[i];
        cout << vec[i] << " ";
    }
}



int main()
{
    vector<int> v = { 1, 2, 3, 4,5, 6, 7, 8, 9, 10 };
    {
        int result;
        auto start = high_resolution_clock::now();
        CalculateSum(v, 0, 10, result);
        cout << "result: " << result << endl;
        auto end = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(end - start);
        cout << "Time without threads: " << time.count() << endl;
    }

    {

        auto start = high_resolution_clock::now();
        int sum_1, sum_2;

        thread t(CalculateSum, cref(v), 0, 5, ref(sum_1));
        thread t2(CalculateSum, cref(v), 5, 10, ref(sum_2));
        t.join();
        t2.join();
        cout << sum_1 << " " << sum_2 << " " << sum_1 + sum_2 << endl;
        auto end = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(end - start);
        cout << "Time with threads: " << time.count() << endl;

    }
}


