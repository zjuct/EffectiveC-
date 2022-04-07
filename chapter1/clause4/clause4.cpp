//确定对象被使用前已被初始化

#include<iostream>
#include<list>
using namespace std;

class PhoneNumber{
public:
    PhoneNumber()=default;
};
class ABEntry{
public:
    ABEntry(const string& name,const string& address,const list<PhoneNumber>& phones){
        theName=name;     //赋值，而非初始化
        theAddress=address;
        thePhones=phones;
        num=0;
    }
    
    //成员变量的初始化顺序为声明顺序，而非成员参数列表中的顺序
    ABEntry(const string& name,const string& address,const list<PhoneNumber>& phones)
    :theName(name),theAddress(address),thePhones(phones),num(0)    //初始化
    {
        
    }
private:
    string theName;
    string theAddress;
    list<PhoneNumber> thePhones;
    int num;
};

int main(){

}