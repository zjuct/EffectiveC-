#include<iostream>
using namespace std;
class Transaction{
public:
    Transaction(){
        logTransaction();
    }
    virtual void logTransaction()const =0;
};
void Transaction::logTransaction()const{
    cout<<"基类logTransaction调用"<<endl;
}
class BuyTransaction:public Transaction{
public:
    virtual void logTransaction()const override {
        cout<<"子类logTransaction调用"<<endl;
    }   
};
int main(){
    BuyTransaction b;
}