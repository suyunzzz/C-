/*
 * @Author: your name
 * @Date: 2020-08-28 22:10:28
 * @LastEditTime: 2020-08-28 22:28:08
 * @LastEditors: Please set LastEditors
 * @Description: add.h
 * @FilePath: \CPP笔记\extern.h
 */
// #ifndef ADD_H
// #define ADD_H
// #ifdef __cplusplus
// extern "C" {
// #endif

// int add( int a, int b)
// {
//     return a+b;
// }

// #ifdef __cplusplus
// }
// #endif


// #endif


// add.h
#ifndef ADD_H
#define ADD_H
extern "C" {
    int add(int x,int y);
}
#endif

