# �Զ�����ʽ��newed������������ָ��
```C++
#include<iostream>
#include<memory>
using namespace std;
class Widget{

};
int priority();
void processWidget(shared_ptr<Widget>pw,int priority);
int main(){
    //���ã��������ִ����������
    //1.����new Widget����Widget����
    //2.����priority()
    //3.����shared_ptr�Ĺ��캯��
    //���У�new Widget��priority()�ĵ���˳����δ֪��
    //����ȵ���new Widget������ʱ���priority()�׳��쳣��������Widget��δ������shared_ptr������
    //���ʱ�����ڴ�й©
    processWidget(shared_ptr<Widget>(new Widget),priority());

    //�Ϻõ�����
    //��ʹpriority()�׳��쳣����ԴҲ�������ͷ�
    shared_ptr<Widget>pw = shared_ptr<Widget>(new Widget);
    processWidget(pw,priority());
}rtg
```