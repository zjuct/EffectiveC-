# 绝不在构造和析构过程中调用virtual函数
假设有以下代码
```C++
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
```
在调用构造函数时，试图通过调用虚函数对不同对象的创建采取不同反应    
但上述代码的结果时调用基类logTransaction()   

>在构造函数中virtual函数不会下降到derived classes阶层，这是因为当创建子类对象时，先调用基类的构造函数，此时子类对象独有的成员尚未被创建，而使用未创建的成员是危险的，因此C++拒绝这么做，而是调用基类版本
>>在Base Class构造期间，virtual函数不是virtual函数     

>同样的，在基类构造函数中使用RTTI，也会将当前对象视为基类类型    
对象在derived class构造函数执行前不会成为一个derived class对象
   
相同的道理也适用于析构函数，一旦派生类的析构函数开始执行，派生类独有的成员就会被销毁，此时多态失去意义，因此进入基类构造函数后对象就成为一个基类对象
