#include<iostream>
#include<exception>
using namespace std;
class DBConnection{
public:
    void close(){

    }
};
class DBConn{
public:
    void close(){
        db.close();
        //如果db.close()抛出异常，则closed=true不会执行
        closed=true;
    }
    ~DBConn(){
        try{
            if(!closed){
                //在析构函数中提供二重保障机制
                db.close();
            }
        }catch(exception& e){
            cout<<e.what()<<endl;
        }
    }
private:
    DBConnection db;
    bool closed;
};