# 以独立形式将newed对象置入智能指针
```C++
#include<iostream>
#include<memory>
using namespace std;
class Widget{

};
int priority();
void processWidget(shared_ptr<Widget>pw,int priority);
int main(){
    //不好，下面语句执行三个步骤
    //1.调用new Widget创建Widget对象
    //2.调用priority()
    //3.调用shared_ptr的构造函数
    //其中，new Widget和priority()的调用顺序是未知的
    //如果先调用new Widget，而此时如果priority()抛出异常，则由于Widget尚未被放入shared_ptr对象中
    //则此时发生内存泄漏
    processWidget(shared_ptr<Widget>(new Widget),priority());

    //较好的做法
    //即使priority()抛出异常，资源也能正常释放
    shared_ptr<Widget>pw = shared_ptr<Widget>(new Widget);
    processWidget(pw,priority());
}rtg
```