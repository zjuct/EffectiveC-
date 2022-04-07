#include<iostream>
using namespace std;

class Base{
public:
    Base()=default;
    Base(const int num):_num(num){
    }
private:
    Base& operator=(const Base& rhs){
        _num=rhs._num;
        return *this;
    }
    int _num;
};
class Derive:public Base{
public:
    Derive()=default;
    Derive(const int num,const string& str):_str(str),Base(num){

    }
private:
    string _str;
};

class A{
public:
    A()=default;
    A(int n):num(n){

    }
private:
    const int num;
};

class B{
public:
    B(int n):num(n){

    }
private:
    int& num;
};

int main(){
    Derive obj1(2,"str");
    Derive obj2;
    //obj2=obj1;      这是不合法的，Derive的copy assignment被定义为delete

    A a1(5);
    A a2(8);
    //a2=a1;     同样不合法,因为A中声明了const成员变量

    B b1(5);
    B b2(8);
    //b2=b1;     不合法，B中声明了引用成员
}