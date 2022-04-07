#include<iostream>
using namespace std;
class Bitmap{};
class Widget{
    void swap(Widget& rhs){

    }
    Widget& operator=(Widget rhs){
        swap(rhs);
        return *this;
    }
private:
    Bitmap* pb;
};