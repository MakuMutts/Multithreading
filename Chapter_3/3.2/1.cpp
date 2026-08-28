#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Counter{
    public:

    void Increment();
    void Decrement();
    int GetCounter(){return counter;}

    private:
    int counter = 0;
    mutex m;
};

void Counter::Increment(){
    counter++;
}

void Counter::Decrement(){
    counter--;
}

void IncrementMany(Counter& counter, int count){
    for(int i = 0; i < count; i++){
        counter.Increment();
    }
}


void DecrementMany(Counter& counter, int count){
    for(int i = 0; i < count; i++){
        counter.Decrement();
    }
}

int main(){
    Counter counter;
    thread t1(IncrementMany, ref(counter), 100);
    thread t2(IncrementMany, ref(counter), 100);
    thread t3(DecrementMany, ref(counter), 50);
    thread t4(IncrementMany, ref(counter), 50);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << counter.GetCounter() << endl;
}