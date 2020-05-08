//
// Created by 侯正罡 on 2020/4/21.
//
#include <iostream>

using namespace std;
//
//int main() {
//    int a, b;
//    while (cin >> a >> b)
//        cout << a + b << endl;
//    return 0;
//}
//————————————————
//版权声明：本文为CSDN博主「Carey_Lu」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/carey_lu/article/details/80199631

/**
 * ++输入 
①只有一组测试数据 
以计算a+b为例：
#include < iostream >
using namespace std;
int main()
{
     int a,b;
     cin >> a >> b;
     cout << a+b << endl;
     return 0;
}

②有多组测试数据，直到读至输入文件结尾为止

#include < iostream >
using namespace std;
int main()
{
       int a,b;
       while(cin >> a >> b)
            cout << a+b << endl;
       return 0;
}

③在开始的时候输入一个N，接下来是N组数据

#include <iostream>
using namespace std;
int main() {
    int a, b, n;
    cin >> n;
    while (n--) {
        cout << a + b << endl;
    }
    return 0;
}

④输入不说明有多少组数据,但以某个特殊输入为结束标志

#include<iostream>
using namespace std;
int main()
{
    int a ,b;
    while(cin>>a>>b&&(a||b))
    {cout<<a+b<<endl;}
    return 0;
}

⑤重定向输入，保存历史

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);  //输入将被重定向到文件
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    return 0;
}

⑥输入字符串

#include<iostream>
using namespace std;
int main()
{
    char buf[ 255 ];
    while(cin.getline( buf, 255 ));

}

在C++中读入字符串通常使用cin.getline函数，可以接受用户的输入的字符，直到已达指定个数，或者用户输入了特定的字符。它的函数声明形式（函数原型）如下：

istream& getline(char line[], int size, char endchar = '\n');
char line[]： 就是一个字符数组，用户输入的内容将存入在该数组内。
int size : 最多接受几个字符，用户超过size的输入都将不被接受。
char endchar :当用户输入endchar指定的字符时，自动结束，默认是回车符。


2.C++输出

①一组接着一组，每一组后面有一空行

 cout << ans << endl << endl;
1
3.C语言输入输出 
有时候C++的输入输出可能太慢，不妨使用C语言的输入输出 
主要方法有：

printf ();//把键盘中的各类数据,加以格式控制输出到显示器屏幕上;
scanf ();//从键盘上输入各类数据,并存放到程序变量中;
puts ()://把数组变量中的一个字符串常量输出到显示器屏幕上;
gets ()://从键盘上输入一个字符串常量并放到程序的数组中;
putchar ()://把变量中的一个字符常量输出到显示器屏幕上;
getchar ()://从键盘上输入一个字符常量,此常量就是该函数的值;
sscanf()://从一个字符串中提取各类数据。


①输入

while(scanf("%d", &n) != EOF)//读取数字

while ((c = getchar()) != EOF)//读取字符

char line[1024];
while(gets(line)) //读取一行

②输出

printf("a=%d,b=%f,c=%c\n",a,b,c);
1
这里的格式化输出如下：

格式字符
d  以十进制形式输出带符号整数(正数不输出符号)
o  以八进制形式输出无符号整数(不输出前缀O)
x  以十六进制形式输出无符号整数(不输出前缀OX)
u  以十进制形式输出无符号整数
f  以小数形式输出单精度实数
lf 以小数形式输出双精度实数
e  以指数形式输出单、双精度实数
g  以%f%e中较短的输出宽度输出单、双精度实数
c  输出单个字符
s  输出字符串

精度控制

精度格式符以“.”开头，后跟十进制整数。意义是：如果输出数字，则表示小数的位数；如果输出的是字符， 则表示输出字符的个数；若实际位数大于所定义的精度数，则截去超过的部分。 
- 结果左对齐，右边填空格 
+ 输出符号(正号或负号)空格输出值为正时冠以空格，为负时冠以负号 
如：

double c=24212345.24232;
printf(“%020.4”);  表示输出精确到小数点后4位，输出占20位，若有空余的位补0
————————————————
版权声明：本文为CSDN博主「Carey_Lu」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/carey_lu/article/details/80199631
 */
