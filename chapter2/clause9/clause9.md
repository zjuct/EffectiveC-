# �����ڹ�������������е���virtual����
���������´���
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
    cout<<"����logTransaction����"<<endl;
}
class BuyTransaction:public Transaction{
public:
    virtual void logTransaction()const override {
        cout<<"����logTransaction����"<<endl;
    }   
};
int main(){
    BuyTransaction b;
}
```
�ڵ��ù��캯��ʱ����ͼͨ�������麯���Բ�ͬ����Ĵ�����ȡ��ͬ��Ӧ    
����������Ľ��ʱ���û���logTransaction()   

>�ڹ��캯����virtual���������½���derived classes�ײ㣬������Ϊ�������������ʱ���ȵ��û���Ĺ��캯������ʱ���������еĳ�Ա��δ����������ʹ��δ�����ĳ�Ա��Σ�յģ����C++�ܾ���ô�������ǵ��û���汾
>>��Base Class�����ڼ䣬virtual��������virtual����     

>ͬ���ģ��ڻ��๹�캯����ʹ��RTTI��Ҳ�Ὣ��ǰ������Ϊ��������    
������derived class���캯��ִ��ǰ�����Ϊһ��derived class����
   
��ͬ�ĵ���Ҳ����������������һ�������������������ʼִ�У���������еĳ�Ա�ͻᱻ���٣���ʱ��̬ʧȥ���壬��˽�����๹�캯�������ͳ�Ϊһ���������
