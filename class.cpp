/*
 * @Author: your name
 * @Date: 2020-08-22 11:39:10
 * @LastEditTime: 2020-08-22 11:50:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CPP笔记\class.cpp
 */
// 抽象类

#include<iostream>
using namespace std;
class Base  {
public:
    Base(){ cout << "Constructor: Base" << endl; }
    ~Base(){ cout << "Destructor : Base" << endl; }
    
    virtual void func() = 0;
};

class Derived: public Base {
public:
    Derived(){ cout << "Constructor: Derived" << endl; }
    ~Derived(){ cout << "Destructor : Derived" << endl;}
    
    void func(){cout << "In Derived.func()." << endl;}
};

int main(int argc, char const *argv[])
{
    Derived a;
    return 0;
}
