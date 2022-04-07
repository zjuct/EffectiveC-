#include<iostream>
using namespace std;

class TimeKeeper{
public:
    virtual ~TimeKeeper(){
        cout<<"TimeKeeper��������"<<endl;
    }  
};
class AtomicClock:public TimeKeeper{
public:
    ~AtomicClock(){
        cout<<"AtomicClock��������"<<endl;
    }
};
TimeKeeper* getTimeKeeper(){
    return new AtomicClock();
}
int main(){
    TimeKeeper* tk = getTimeKeeper();
    delete tk;
}