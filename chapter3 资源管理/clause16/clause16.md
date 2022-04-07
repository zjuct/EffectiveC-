# 成对使用new和delete是要形式一致
尽量少使用typedef对数组起别名
```C++
typedef string strarr[4];
string* arr = new strarr;
delete arr;  //错误
```
这种错误很容易发生，因此不要对数组做typedef动作
