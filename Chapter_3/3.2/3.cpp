#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class BankAccount{
    public:
    void SetBalance(int value){
        lock_guard<mutex> l(m);
        balance = value;
    }
    int GetBalance(){
        lock_guard<mutex> l(m);
        return balance;
    }
    void Withdraw(int value){
        
        lock_guard<mutex> l(m);

        if (balance >= value)
        {
            balance -= value;
            cout << "Successful withdrawals" << endl;
        }
        else
        {
            cout << "Failed withdrawals" << endl;
        }  
    }
    private:
    int balance;
    mutex m;
};

int main(){
    BankAccount account1;
    account1.SetBalance(100);
    thread t1(&BankAccount::Withdraw, &account1, 80);

    thread t2(&BankAccount::Withdraw, &account1, 80);

    t1.join();
    t2.join();

    cout << account1.GetBalance() << endl;
}