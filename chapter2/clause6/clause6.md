# 若不想使用编译器自动生成的函数，就该明确拒绝
在C++11前，若想阻止一个类的拷贝行为，一种通用的做法是将其copy constructor 和copy assignment定义为private   
更好的做法是，定义基类uncopyable，其声明私有拷贝构造函数和赋值运算符，作为接口，任何拒绝拷贝的类，只需要继承uncopyable类即可   
```C++
#include<iostream>
using namespace std;
class uncopyable{
protected:
    uncopyable(){}
    ~uncopyable(){}
private:
    uncopyable(const uncopyable&);
    uncopyable& operator=(const uncopyable&);
};
class A:private uncopyable{
public:
    A()=default;
    A(int n):num(n){

    }
private:
    int num;
};
int main(){
    A a1(3);
    A a2(8);
    //a2=a1;    A是不可拷贝的
}
```