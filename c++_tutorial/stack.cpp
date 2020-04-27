//
// Created by fpf on 2020-04-27.
//

#include <iostream>
#include <stack>
using namespace std;

stack<int> s_data;
stack<char> s_opera;

int priority(char c){   //得到每个符号的优先级
    int pr = 0;
    switch (c) {
        case '+':
        case '-':  pr = 1; break;
        case '*':
        case '/':  pr = 2; break;
        case '(':  pr = 3; break;
        case ')':  pr = 0; break;
    }
    return pr;
}

bool is_digital(char c){   //判断是否为数字
    if(c>='0' && c<='9')
        return true;
    else
        return false;
}

void execution(){     //将数字栈的前两个数字进行运算，并将结果压栈
    int temp1,temp2;
    char operation;
    temp2 = s_data.top();
    s_data.pop();
    temp1 = s_data.top();
    s_data.pop();
    operation = s_opera.top();
    s_opera.pop();

    switch(operation){
        case '+':
            s_data.push(temp1+temp2);
            break;
        case '-':
            s_data.push(temp1-temp2);
            break;
        case '*':
            s_data.push(temp1*temp2);
            break;
        case '/':
            s_data.push(temp1/temp2);
            break;
    }
}

int main(){
    string str;
    cin>>str;
    int temp = 0;
    for(int i=0;i<str.length();i++){
        if(is_digital(str[i])){    //把数字提取出来
            if(temp == 0)         //多位数字的最高位的数字
                temp = str[i] - '0';
            else
                temp = temp*10 + (str[i] - '0');
            if(i == str.length()-1)   //将末尾的最后一个数字压进数字栈
                s_data.push(temp);
        }
        else{
            //如果碰到字符了，首先把前一个数字压入数字栈
            if(temp!=0){
                s_data.push(temp);
                temp = 0;
            }

            if(s_opera.empty())
                s_opera.push(str[i]);
            else{
                int pr_top = priority(s_opera.top());  //栈顶运算符的优先级
                if((priority(str[i])>pr_top) || (pr_top==3 && priority(str[i])!=0))
                    s_opera.push(str[i]);
                else if(pr_top==3 && priority(str[i])==0){  //当右括号遇到左括号
                    s_opera.pop();
                    continue;   //考虑下一个字符
                }
                else{
                    execution();
                    i = i - 1;
                }
            }
        }
    }

    while(!s_opera.empty()){
        execution();
    }

    cout<<s_data.top()<<endl;
    return 0;
}

//题目大意：这是一道表达式求值的题。题干要求是表达式中可以出现括号，表达式的合法性不需要判断。输出表达式的值。
//
//题目分析：这是一道使用栈的常规题，也是栈这种数据结构的经典的应用--表达式求值。
// 首先，我们建立两个栈，一个数字栈，存放数字；
// 另一个存放操作符栈。给每一个运算符一个优先级，规定+，-的优先级为1；*，/ 的优先级为2； ( 的优先级为3； ) 的优先级为0；

// 当面对一个表达式时，我们从左往右依次分析：
//
//1）如果遇到是一个数字，则将其压入数字栈;
//
//2) 如果遇到的是运算符或者括号：
//
//    ①扫描到的运算符优先级 > 操作符栈顶元素的优先级 或者 操作符栈为空时 或者 操作符栈顶元素为（，扫描到的运算符不是）时，则将扫描到的运算符入栈
//
//    ②当扫描到的运算符为（，而操作符栈顶元素为）时，弹出操作符栈顶元素
//
//    ③其余情况，从数字栈弹出两个元素，从操作符栈弹出一个运算符，进行运算，将结果压入数字栈；之后再判断扫描到的运算符优先级与目前操作符栈顶元素的优先级的大小
//
//        值得注意的是当数字不止一位时的情况，也就是直到后面是非数字才可以确定前面的多位数字。如356+34，遇到3，得到临时的数字3，遇到5，得到临时的数字3*10+5；遇到6，得到临时的数字35*10+6；遇到+，确定之前的数字是356，然后压栈。
//
//最后，扫描完表达式之后，对两个栈进行运算。不断从数字栈弹出两个数字，从操作符栈弹出一个运算符，运算，得结果，入数字栈，直到操作符栈中没有运算符为止
//————————————————
//版权声明：本文为CSDN博主「Jaster_wisdom」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/Jaster_wisdom/article/details/79435310