#include <iostream>

using namespace std;

//形参带有默认值的函数
//一般将带有默认值的形参放在参数列表最后
//实参传值给形参，从左往右以此赋值
void fun(const char *p = "hello")
{
    cout << p << endl;
}

int main(void)
{
    fun();
    fun("world");
    return 0;
}