#include<iostream>
using namespace std;
class Widget{
public:
    Widget(int n):num(n){}
    Widget& operator=(const Widget& rhs){
        this->num=rhs.num;
        return *this;
    }
    Widget& operator+=(const Widget& rhs){
        //...
        return *this;
    }
    int GetNum(){
        return num;
    }
private:
    int num;
};
int main(){
    Widget w1(1);
    Widget w2(4);
    Widget w3(8);
    w1=w2=w3;
    cout<<w1.GetNum()<<endl;
    cout<<w2.GetNum()<<endl;
    cout<<w3.GetNum()<<endl;
}