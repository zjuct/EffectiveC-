# �����쳣������������
����������Ӧ���׳��쳣   
���緢��ջ���ˣ���������оֲ����������������������ʱ�����������׳��쳣�����ʱͬʱ�������쳣���ڣ������쳣��ֹ   
```C++
�Ϻõ�����
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
```
�ṩ���û��Ķ���ӿ���DBConn��close(),��ʹ���û�����ͨ��try�鴦��close()�����׳����쳣��������û�������Ҳ������������˫����    
>�����������Բ�Ҫ�׳��κ��쳣��������������п����׳��쳣��һ��Ҫʹ��try-catch�鴦��    
����û���Ҫ�Լ������쳣�������ṩһ����ͨ����(������������)
