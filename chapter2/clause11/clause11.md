# 在operator=中处理自我赋值
```C++
版本1：既没有自我赋值安全性，也不具备异常安全性
class Widget{
    Widget& operator=(const Widget& rhs){
        delete this->pb;
        pb=new Bitmap(*rhs.pb);
        return *this;
    }
private:
    Bitmap* pb;
};
版本2：具备自我赋值安全性
Widget& operator=(const Widget& rhs){
    if(this==&rhs){
        return *this;
    }
    delete this->pb;
    pb=new Bitmap(*rhs.pb);
    return *this;
}
版本3：同时具备自我赋值安全性和异常安全性
Widget& operator=(const Widget& rhs){
    Bitmap* pOrig=pb;
    pb = new Bitmap(*pOrig);
    delete pOrig;
    return *this;
}
版本4：利用copy and swap技术
void swap(Widget& rhs){

}
Widget& operator=(const Widget& rhs){
    Widget tmp(rhs);
    swap(tmp);
    return *this;
}
空间的释放由临时对象tmp的析构函数自动进行
版本5：使用by value传递参数
Widget& operator=(Widget rhs){
    swap(rhs);
    return *this;
}
```