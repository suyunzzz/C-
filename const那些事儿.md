# const那些事儿

## 1、const含义

常类型是指使用类型修饰符const说明的类型，是**只读的（不能更新）**，这意味着需要在<font color='red'>定义的时候就要赋初值</font>。

## 2、const作用

- 定义常量

  ```cpp
  const int a=100;
  ```

  注意：要记得在定义的时候赋值（初始化）

- 类型检查

  const是定义的变量，是有数据类型的，而define定义的对象没有数据类型，所以编译器对前者进行安全检查，对后者只是进行简单的符号替换，没有安全检查，很容易出问题。

  就**起作用的方式**而言： #define只是简单的字符串替换，没有类型检查。而const有对应的数据类型，是要进行判断的，可以避免一些低级的错误。

  从**代码调试的方便程度**而言： const常量可以进行调试的，define是不能进行调试的，因为在预编译阶段就已经替换掉了。

- 防止修改，起保护作用，增加程序健壮性

  ```cpp
  void f(const int i){
      i++; //error!
  }
  ```

  ​		注意：这样其实是没有意义的，因为形参i本身就是对实参复制，采用这样的值传递，本身就不会影响实参的值。

- 可以节省空间，避免不必要的内存分配

  就**存储方式**而言：#define只是进行展开，有多少地方使用，就替换多少次，它定义的宏常量在内存中有若干个备份；const定义的只读变量在程序运行过程中只有一份备份。

## 3、const对象默认为文件局部变量

- 未被const修饰的变量是可以在不同文件中进行访问的（默认为extern）

  ```cpp
  // file1.cpp
  int ext
  // file2.cpp
  #include<iostream>
  
  extern int ext;
  int main(){
      std::cout<<(ext+10)<<std::endl;
  }
  ```

  

- 被const修饰的变量默认是只能在文件内部访问（非extern），要想在其他文件中访问，需要添加`extern`修饰

  ```cpp
  //extern_file1.cpp
  extern const int ext=12;
  //extern_file2.cpp
  #include<iostream>
  extern const int ext;
  int main(){
      std::cout<<ext<<std::endl;
  }
  ```

  

  注意：因为常量在定义后就不能被修改，所以定义时必须初始化。

## 4、定义常量

```cpp
const int b = 10;
b = 0; // error: assignment of read-only variable ‘b’
const string s = "helloworld";
const int i,j=0 // error: uninitialized const ‘i’
```

以上有两个错误：

1. b不能被修改
2. 定义const必须初始化(i)

## 4、指针与const

```cpp
const char * a; //指向const对象的指针或者说指向常量的指针。
char const * a; //同上
char * const a; //指向类型对象的const指针。或者说常指针、const指针。
const char * const a; //指向const对象的const指针。
```

如何区分？

- 如果const在`*`左侧，那么`const`修饰的是指针指向的变量。

- 如果const在`*`右侧，那么`const`修饰的是指向变量的指针本身。

具体使用：

（1） **指向常量的指针**

```cpp
const int *ptr;
*ptr = 10; //error
```

`const`修饰的是指针指向的变量，所以第一行指针可以不赋值，第二行中该int对象不能修改值，所以报错

---

除此之外，也不能使用void`*`指针保存const对象的地址，必须使用const void`*`类型的指针保存const对象的地址。

```cpp
const int p = 10;
const void * vp = &p;
void *vp = &p; //error
```

---

另外一个重点是：**允许把非const对象的地址赋给指向const对象的指针**，**反之则不行**。

将非const对象的地址赋给const对象的指针:

```cpp
const int *ptr;
int val = 3;
ptr = &val; //ok
```

我们不能通过ptr指针来修改val的值，即使它指向的是非const对象:

```cpp
*ptr=4  // error
```

我们不能使用指向const对象的指针修改基础对象，然而如果该指针指向了非const对象，**可用其他方式修改其所指的对象**。<font color='red'>可以修改const指针所指向的值的，但是不能通过const对象指针来进行而已！</font>如下修改：

```cpp
int *ptr1 = &val;			// 重新创建一个非const指针指向val
*ptr1=4;
cout<<*ptr<<endl;
```

小结：<br>1.对于指向常量的指针，不能通过指针来修改对象的值。<br>2.不能使用void`*`指针保存const对象的地址，必须使用const void`*`类型的指针保存const对象的地址。<br>3.允许把非const对象的地址赋值给const对象的指针，如果要修改指针所指向的对象值，必须通过其他方式修改，不能直接通过当前指针直接修改。

---

（2） **常指针**

首先要说明的是，`const`指针是指一个指针是不可变的，而不限制该指针指向的变量的内容；<font color='red'>其次，const指针ptr是一个常量，但是其仍然是指向变量的。</font>

const指针必须进行初始化，且const指针的值不能修改。

```cpp
#include<iostream>
using namespace std;
int main(){

    int num=0;
    int * const ptr=&num; //const指针必须初始化！且const指针的值不能修改
    int * t = &num;
    *t = 1;
    cout<<*ptr<<endl;
}
```

<font color='red'>上述修改ptr指针所指向的值，可以通过非const指针来修改。</font>

---



当把一个const常量的地址赋值给ptr时候，由于ptr指向的是一个变量，而不是const常量，所以会报错，出现：const int`*` -> int `*`错误！

```cpp
#include<iostream>
using namespace std;
int main(){
    const int num=0;
    int * const ptr=&num; //error! const int* -> int*
    cout<<*ptr<<endl;
}
```

上述若改为 const int `*`ptr或者改为const int `*`const ptr(指向常量的常指针)，都可以正常！

（3）**指向常量的常指针**

理解完前两种情况，下面这个情况就比较好理解了：

```cpp
const int p = 3;
const int * const ptr = &p; 
```

ptr是一个const指针，然后指向了一个int 类型的const对象。

## 6、函数中使用const

主要是在`const`修饰函数参数

（1）传递过来的参数及指针本身在函数内不可变，无意义！

```cpp
void func(const int var); // 传递过来的参数不可变
void func(int *const var); // 指针本身不可变
```

表明参数在函数体内不能被修改，但此处没有任何意义，var本身就是形参，在函数内不会改变。包括传入的形参是指针也是一样

输入参数采用“值传递”，由于函数将自动产生临时变量用于复制该参数，该输入参数本来就无需保护，所以不要加`const `修饰。

（2）**参数指针所指内容为常量不可变**

```cpp
void StringCopy(char *dst, const char *src);
```

其中src 是输入参数，dst 是输出参数。给src加上const修饰后，如果函数体内的语句试图改动src的内容，编译器将指出错误。这就是加了const的作用之一。

（3）**参数为引用，为了增加效率同时防止修改。**

```cpp
void func(const A &a)
```

对于<font color='red'>非内部数据类型的参数而言，像void func(A a) 这样声明的函数注定效率比较低。</font>因为函数体内将产生A 类型的临时对象用于复制参数a，而临时对象的构造、复制、析构过程都将消耗时间。

为了提高效率，可以将函数声明改为void func(A &a)，因为“引用传递”仅借用一下参数的别名而已，不需要产生临时对象。

`但是函数void func(A &a) 存在一个缺点：“引用传递”有可能改变参数a，这是我们不期望的。解决这个问题很容易，加const修饰即可，因此函数最终成为void func(const A &a)。`

以此类推，<font color='red'>是否应将void func(int x) 改写为void func(const int &x)，以便提高效率？完全没有必要</font>，因为**内部数据类型的参数不存在构造、析构的过程，而复制也非常快，“值传递”和“引用传递”的效率几乎相当。**

---



<font color='blue'>以上解决了两个面试问题：</font>

+ 如果函数需要传入一个指针，是否需要为该指针加上const，把const加在指针不同的位置有什么区别；

  **答**：对函数的指针本身添加const是没有意义的`func(int * const a)`;

  如果是按指针传递，应该保证指针指向的内存区域是不可变的，也就是这样`func (cont int * a )`;

  `const` 加在`*`前面是指针指向的变量为不可变，`const`加在`*`后面是指针不可变，<font color='red'>指向的对象的值可以改变，可以通过非const指针来修改指向变量的值。</font>

  ---

  

+ 如果写的函数需要传入的参数是一个复杂类型的实例，传入值参数或者引用参数有什么区别，什么时候需要为传入的引用参数加上`const`。 

  **答：**复杂类型的实例，如果按值传递会对参数进行复制，这样会调用类的构造、复制、析构函数，会消耗时间；

  所以对于自定义的类别，采取引用传递，为了保证引用传递不会改变传入实例的值，所以使用`const`修饰：`func(const A& a)`

---

## 7、类中使用const

在一个类中，<font color='red'>任何不会修改数据成员的函数都应该声明为const类型</font>。如果在编写const成员函数时，不慎修改数据成员，或者调用了其它非const成员函数，编译器将指出错误，这无疑会提高程序的健壮性。

使用`const`关键字进行说明的成员函数，称为**常成员函数**。只有常成员函数才有资格操作**常量或常对象，**没有使用`const`关键字进行说明的成员函数不能用来操作常对象。

**类中的**`const`成员变量必须通过**初始化列表进行初始化**:

```cpp
class Apple{
private:
    int people[100];
public:
    Apple(int i); 
    const int apple_number;
};

Apple::Apple(int i):apple_number(i)
{

}
```

---



`const`对象(或函数)只能访问`const`成员函数，非`const`对象可以访问任意的成员函数，包括`const`成员函数

例如：

```cpp
//apple.cpp
class Apple
{
private:
    int people[100];
public:
    Apple(int i); 
    const int apple_number;
    void take(int num) const;
    int add(int num);
	int add(int num) const;
    int getCount() const;

};
//main.cpp
#include<iostream>
#include"apple.cpp"
using namespace std;

Apple::Apple(int i):apple_number(i)
{

}
int Apple::add(int num){
    take(num);
}
int Apple::add(int num) const{
    take(num);
}
void Apple::take(int num) const
{
    cout<<"take func "<<num<<endl;
}
int Apple::getCount() const
{
    take(1);
//    add(); //error
    return apple_number;
}
int main(){
    Apple a(2);
    cout<<a.getCount()<<endl;
    a.add(10);
    const Apple b(3);
    b.add(100);
    return 0;
}
```

`a`为非`const`成员，可以调用`const`成员函数`getCount`，但是在`getCount`内部调用了非`const`成员函数`add`，所以报错，这说明，**非`const`可以调用`const`，但是`const`不能调用非`const`**

如果你使用c++11进行编译，直接可以在定义处进行`const`成员变量的初始化(而不需要通过初始化列表进行初始化)，可以直接写成：

```cpp
static const int apple_number=10;
// 或者
const int apple_number=10;
```

这两种都在c++11中支持！

---

这里提到了`static`，下面简单的说一下：

在C++中，`static`静态成员变量**不能在类的内部初始化**。**在类的内部只是声明，定义必须在类定义体的外部，通常在类的实现文件中初始化**。

类中声明：

```cpp
static int ap;
```

在类实现文件中使用：

```cpp
int Apple::ap=666
```

对于此项，**c++11**不能进行声明并初始化，也就是说只能使用上述的方法（**声明在类中，定义在类的实现文件中**）。