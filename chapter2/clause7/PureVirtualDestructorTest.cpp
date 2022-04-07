#include<iostream>
using namespace std;
class Base{
public:
  virtual ~Base()=0;    //声明纯虚析构函数
};
Base::~Base(){
    //需要提供定义
}