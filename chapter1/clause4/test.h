#include<iostream>
class A;
extern A obj;

class A{
public:
    A():num(100){
        std::cout<<"A�Ĺ��캯������"<<std::endl;
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
        std::cout<<"B�Ĺ��캯������"<<std::endl;
        std::cout<<"num��ֵΪ"<<obj.Getnum()<<std::endl;
    }
};