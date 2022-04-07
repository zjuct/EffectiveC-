/*
1.将能够声明为const的东西声明为const
2.编译器实施bitwise constness,但编程时应采用conceptual constness
3.用const版本实现non-const版本可避免代码重复
*/


#include<iostream>
class CTextBlock{
    friend std::ostream& operator<<(std::ostream& os,const CTextBlock& cb);
public:
    CTextBlock(char* ptr):pText(ptr),length(4){
    }
    const char& operator[](std::size_t position)const{
        return pText[position];
    }
    char& operator[](std::size_t position){
        //此处将*this转换为const对象是必要的，否则会发生递归调用
        return const_cast<char&>(static_cast<const CTextBlock&>(*this)[position]);
    }
    void mutabletest()const{
        length=3;
        length_is_valid=true;
    }
    std::size_t getLength()const{
        return length;
    }
private:
    mutable std::size_t length;
    mutable bool length_is_valid;
    char* pText;
};
std::ostream& operator<<(std::ostream& os,const CTextBlock& cb){
    os<<cb.pText;
    return os;
} 

int main(){
    char str[]="hello";
    const CTextBlock cb(str);
    std::cout << cb<<std::endl;
    cb.mutabletest();
    std::cout << cb.getLength();
    return 0;
}