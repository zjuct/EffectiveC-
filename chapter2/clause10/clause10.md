# 令operator=返回一个reference to *this
返回*this实现连续赋值
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
如果不返回Widget&,而是直接返回Widget，虽也能实现连续赋值的目的，但由于要创建一个临时对象，效率较低

