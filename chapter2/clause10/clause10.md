# ��operator=����һ��reference to *this
����*thisʵ��������ֵ
```C++
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
private:
    int num;
};
```
���������Widget&,����ֱ�ӷ���Widget����Ҳ��ʵ��������ֵ��Ŀ�ģ�������Ҫ����һ����ʱ����Ч�ʽϵ�

