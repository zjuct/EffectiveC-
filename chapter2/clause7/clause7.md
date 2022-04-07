# 为多态基类声明virtual析构函数    
```C++
错误做法
#include<iostream>
using namespace std;

class TimeKeeper{
public:
    ~TimeKeeper(){
      cout<<"TimeKeeper析构调用"<<endl;
    }  
};
class AtomicClock:public TimeKeeper{
public:
    ~AtomicClock(){
        cout<<"AtomicClock析构调用"<<endl;
    }
};
TimeKeeper* getTimeKeeper(){
    return new AtomicClock();
}
int main(){
    TimeKeeper* tk = getTimeKeeper();
    delete tk;  //调用的是~TimeKeeper()
}
```
>当一个类不作为基类时，将其析构函数声明为virtual也是不妥的   
因为声明为virtual会为该类自动加上vptr和vtbl，大大增加空间占用   
较好的做法是：只有当类内至少有一个virtual函数时，才为它声明virtual析构函数   

