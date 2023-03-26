# NULL，null和nullptr的区别

## 1.首先讨论一下NULL

在C语言中，NULL的定义为空指针

#define NULL ((void*)0)

所以在C语言中将其他类型的指针赋值为NULL时，将会将NULL的类型隐式转换为相应的类型。

在C++语言中，NULL的定义为

#ifdef _cplusplus

#define NULL 0

#else

#define NULL ((void*)0)

#endif 

在用下图所示main函数里的代码调用func函数时，NULL会以常数0传入参数而不是空指针。

![](C:\Users\25768\Desktop\作业\训练营作业\笔记\笔记示例代码01.jpg)

所以在C++中用NULL定义空指针会带来问题

## 2.null

null是C#中引用类型的默认值，当一个引用类型未初始化时，其值为null，不指向任何内存空间。

## 3.什么是nullptr

nullptr是为了解决C++中NULL的问题，在C++11引入的关键字，作用是代指空指针，当出现像上面函数传参的情况，可以正确地传入空指针的参数。

