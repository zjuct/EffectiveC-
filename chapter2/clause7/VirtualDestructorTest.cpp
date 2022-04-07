#include<iostream>
using namespace std;

class TimeKeeper{
public:
    virtual ~TimeKeeper(){
        cout<<"TimeKeeper析构调用"<<endl;
    }  
};
class AtomicClock:public TimeKeeper{
public:
    ~AtomicClock(){
        cout<<"AtomicClock析构调用"<<endl;
    }
};
TimeKeeper* getTimeKeeper(){
    return new AtomicClock();
}
int main(){
    TimeKeeper* tk = getTimeKeeper();
    delete tk;
}