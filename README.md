# 类Fortran语言编译器

## 编译器界面

<img src="https://raw.githubusercontent.com/Thornhill-GYL/markdownpicture/master/20201002140808.png"/>

<img src="https://raw.githubusercontent.com/Thornhill-GYL/markdownpicture/master/c"/>

## 项目说明

该编译器与本科同学合作完成

## 项目介绍

1. 该项目包含了词法分析、语法分析、语义分析和解释程序四个部分，也是一般编译器含有的四个部分。
2. 该项目使用的编程语言是C#和C++，其中的调用方法是使用dll文件（动态链接库）进行调用。

## 编译器语言介绍

源语言文法定义和保留字表基本与Fortran语言和C语言相似。

单词的识别模型-有穷自动机DFA。

## 词法分析

用于存储源程序的文件                  source.txt

用于存储词法输出结果的文件            shuchu.txt

用于存储词法错误的文件                error.txt

用于存储源程序字符的数组                         char a[400]       

用于存储写入输出文件单词的数组             string b[400]

通过将输入的文件存为字符来进行处理。

## 语法分析

&emsp;&emsp;递归子程序法是比较简单易与构造的一种自顶向下的语法分析方法。它的实现思想是对应文法中每个非终结符编写一个递归过程，每个过程的功能是识别由该终结符推出的串，当某非终结符的产生式有多个候选时能够按LL(1)形式可唯一确定选择某个候选进行推导。然而递归子程序法要求文法必须满足LL(1)文法，因此为了能实现递归子程序法，需先将文法化为LL(1)文法。

## 语义分析

&emsp;&emsp;由于语义的正确性已经在语法分析中完成了，因此在语义分析中，我们需要做的就是四元式的生成。因此，如何生成四元式，如何通过设置临时变量和设置label值进行拉链回填，是我们需要着重注意处理的问题。

## 解释程序

&emsp;&emsp;解释程序的目的，就是将四元式部分的内容转化为最终的结果。通过识别语义分析产生的四元式，根据符号字符来判断赋值语句，赋值语句和if/while语句。该解释程序是将自定义的源语言转化为机器识别的C语言，然后顺利的得出解释程序结果。

## 相关测试结果

1. 词法分析成功

<img src="https://raw.githubusercontent.com/Thornhill-GYL/markdownpicture/master/20201002135514.png"/>

2. 词法错误分析例子

<img src="https://raw.githubusercontent.com/Thornhill-GYL/markdownpicture/master/20201002140258.png"/>

3. 语法分析

&emsp;由于语法分析错误分析过多，不做展示，可直接参考程序。

4. 语义分析成功

<img src="https://raw.githubusercontent.com/Thornhill-GYL/markdownpicture/master/20201002140514.png"/>

5. 语义错误分析截图

<img src="https://raw.githubusercontent.com/Thornhill-GYL/markdownpicture/master/20201002141120.png"/>



5. 解释程序成功

<img src="https://raw.githubusercontent.com/Thornhill-GYL/markdownpicture/master/20201002140641.png"/>





