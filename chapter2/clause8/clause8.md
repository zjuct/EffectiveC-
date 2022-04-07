# 别让异常逃离析构函数
析构函数不应该抛出异常   
假如发生栈减退，其调用所有局部对象的析构函数，倘若此时析构函数又抛出异常，则此时同时有两个异常存在，程序异常终止   
```C++
较好的做法
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
```
提供给用户的对外接口是DBConn的close(),这使得用户可以通过try块处理close()可能抛出的异常，但如果用户不处理，也有析构函数的双保险    
>析构函数绝对不要抛出任何异常，如果析构函数中可能抛出异常，一定要使用try-catch块处理    
如果用户需要自己处理异常，可以提供一个普通函数(而非析构函数)
