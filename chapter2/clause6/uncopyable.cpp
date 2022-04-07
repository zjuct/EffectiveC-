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