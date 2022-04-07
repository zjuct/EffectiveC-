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
    cout<<"����logTransaction����"<<endl;
}
class BuyTransaction:public Transaction{
public:
    virtual void logTransaction()const override {
        cout<<"����logTransaction����"<<endl;
    }   
};
int main(){
    BuyTransaction b;
}