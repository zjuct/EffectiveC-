# ������ʹ�ñ������Զ����ɵĺ������͸���ȷ�ܾ�
��C++11ǰ��������ֹһ����Ŀ�����Ϊ��һ��ͨ�õ������ǽ���copy constructor ��copy assignment����Ϊprivate   
���õ������ǣ��������uncopyable��������˽�п������캯���͸�ֵ���������Ϊ�ӿڣ��κξܾ��������ֻ࣬��Ҫ�̳�uncopyable�༴��   
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
    //a2=a1;    A�ǲ��ɿ�����
}
```