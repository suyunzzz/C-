/*
 * @Author: your name
 * @Date: 2020-08-20 21:09:29
 * @LastEditTime: 2020-08-20 21:13:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CPP笔记\const.cpp
 */
#include<iostream>
using namespace std;
int main(){

    const int *ptr;
    int val = 3;
    ptr = &val; //ok
    // val=5;
    int* pt1=&val;
    *pt1=66;
    cout<<*pt1<<endl;
    
    cout<<*ptr<<endl;
}
