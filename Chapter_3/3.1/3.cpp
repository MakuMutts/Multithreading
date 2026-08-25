#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


class Counter
{
public:
    void Increment();
    int GetValue() const;

private:
    int value = 0;
    std::mutex m;
};

void IncrementMany(Counter& counter){
    for(int i = 0; i < 10000; i++){
        counter.Increment();
    }
    
}


int main(){
    Counter counter;


    thread t1(IncrementMany, ref(counter));
    thread t2(IncrementMany, ref(counter));
    thread t3(IncrementMany, ref(counter));
    thread t4(IncrementMany, ref(counter));


    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    cout << counter.GetValue() << endl;
}



void Counter::Increment(){
    lock_guard<mutex> l(m);
    ++value;
}

int Counter::GetValue() const{
    return value;
}
