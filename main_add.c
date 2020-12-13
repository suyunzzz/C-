/*
 * @Author: your name
 * @Date: 2020-08-28 22:13:14
 * @LastEditTime: 2020-08-28 22:31:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CPP笔记\main_add.c
 */
#include"extern.h"
// #include <iostream>
// extern "C"{include"extern.h"}
extern int add(int a,int b);
int main(int argc, char *argv[])
{   
    int c;
    c=add(4,3);
    // printf(c);
    return 0;
}