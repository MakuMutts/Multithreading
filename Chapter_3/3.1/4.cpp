#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


class BankAccount
{
public:
    void Deposit(int amount);
    bool Withdraw(int amount);
    int GetBalance() const;

private:
    int balance = 0;
    std::mutex m;
};


int main(){
    BankAccount account;
    thread t1(&BankAccount::Deposit, &account, 100);
    thread t2(&BankAccount::Withdraw, &account, 50);
    thread t3(&BankAccount::Deposit, &account, 200);
    thread t4(&BankAccount::Withdraw, &account, 30);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cout << "Balance: " << account.GetBalance() << endl;
}

void BankAccount::Deposit(int amount){
    lock_guard<mutex> l(m);
    balance += amount;
}

bool BankAccount::Withdraw(int amount){
    lock_guard<mutex> l(m);
    if(balance >= amount){
        balance -= amount;
        return true;
    }
    return false;    
}

int BankAccount::GetBalance() const{
    return balance;
}