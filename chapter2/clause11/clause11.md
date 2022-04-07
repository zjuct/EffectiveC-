# ��operator=�д������Ҹ�ֵ
```C++
�汾1����û�����Ҹ�ֵ��ȫ�ԣ�Ҳ���߱��쳣��ȫ��
class Widget{
    Widget& operator=(const Widget& rhs){
        delete this->pb;
        pb=new Bitmap(*rhs.pb);
        return *this;
    }
private:
    Bitmap* pb;
};
�汾2���߱����Ҹ�ֵ��ȫ��
Widget& operator=(const Widget& rhs){
    if(this==&rhs){
        return *this;
    }
    delete this->pb;
    pb=new Bitmap(*rhs.pb);
    return *this;
}
�汾3��ͬʱ�߱����Ҹ�ֵ��ȫ�Ժ��쳣��ȫ��
Widget& operator=(const Widget& rhs){
    Bitmap* pOrig=pb;
    pb = new Bitmap(*pOrig);
    delete pOrig;
    return *this;
}
�汾4������copy and swap����
void swap(Widget& rhs){

}
Widget& operator=(const Widget& rhs){
    Widget tmp(rhs);
    swap(tmp);
    return *this;
}
�ռ���ͷ�����ʱ����tmp�����������Զ�����
�汾5��ʹ��by value���ݲ���
Widget& operator=(Widget rhs){
    swap(rhs);
    return *this;
}
```