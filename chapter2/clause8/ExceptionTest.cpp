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
        //���db.close()�׳��쳣����closed=true����ִ��
        closed=true;
    }
    ~DBConn(){
        try{
            if(!closed){
                //�������������ṩ���ر��ϻ���
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