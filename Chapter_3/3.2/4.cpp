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

    void RecieveMoney(int money){
        lock_guard<mutex> l(m);
        balance += money;
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
    void TransferMoney(BankAccount& account, int money){
        lock_guard<mutex> lock1(m);
        lock_guard<mutex> lock2(account.m);
        //scoped_lock<mutex, mutex> lock(m, account.m); C++17
        if(balance >= money){
            balance -= money;
            account.balance += money;
        }
    }

    private:
    int balance;
    mutex m;
};

int main(){
    BankAccount A;
    BankAccount B;
    A.SetBalance(1000);
    B.SetBalance(1000);
    thread t1(&BankAccount::TransferMoney, &A, ref(B), 100);

    thread t2(&BankAccount::TransferMoney, &B, ref(A), 200);

    t1.join();
    t2.join();

    cout << A.GetBalance() << endl;
    cout << B.GetBalance() << endl;
}