#include<iostream>
class A;
extern A obj;

class A{
public:
    A():num(100){
        std::cout<<"A的构造函数调用"<<std::endl;
    }
    int Getnum(){
        return num;
    }
private:
    int num;
};
class B{
public:
    B(){
        std::cout<<"B的构造函数调用"<<std::endl;
        std::cout<<"num的值为"<<obj.Getnum()<<std::endl;
    }
};