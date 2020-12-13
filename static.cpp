/*
 * @Author: your name
 * @Date: 2020-08-21 10:24:15
 * @LastEditTime: 2020-08-21 10:44:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CPP笔记\static.cpp
 */
// #include<iostream> 
// using namespace std; 

// class Apple 
// { 
// public: 
// 	static int i; 
	
// 	Apple() 
// 	{ 
// 		// Do nothing 
// 	}; 
// }; 
// int Apple::i=5;
// int main() 
// { 
// Apple obj1; 
// Apple obj2; 
// obj1.i =2; 
// obj2.i = 3; 
	
// // prints value of i 
// cout << obj1.i<<" "<<obj2.i; 
// } 


// #include<iostream> 
// using namespace std; 

// class Apple 
// { 
// 	int i; 
// 	public: 
// 		Apple() 
// 		{ 
// 			i = 0; 
// 			cout << "Inside Constructor\n"; 
// 		} 
// 		~Apple() 
// 		{ 
// 			cout << "Inside Destructor\n"; 
// 		} 
// }; 

// int main() 
// { 
// 	int x = 0; 
// 	if (x==0) 
// 	{ 
// 		static Apple obj; 
// 	} 
// 	cout << "End of main\n"; 
// } 



#include<iostream> 
using namespace std; 

class Apple 
{   
    public: 
        static int num=1;
        // static member function 
        static void printMsg() 
        {   
            cout << "num: "<<num<<endl;
            num+=1;
            cout<<"Welcome to Apple!"; 
        }
//         void printMsg() 
//         {   
//             cout << "num: "<<num<<endl;
//             num+=1;
//             cout<<"Welcome to Apple!"; 
//         }
// }; 

// int Apple::num=1;
// main function 
int main() 
{ 
    // invoking a static member function 
    // Apple::printMsg(); 
    Apple a;
    a.printMsg();
} 