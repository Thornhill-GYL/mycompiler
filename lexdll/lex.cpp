#include "stdafx.h"
#include "lex.h"
#include <iostream>
#include<iostream>
#include<fstream>
using namespace std;
int add(int a, int b)
{

	return a + b;
}
int out(int a, int b)
{
	return a - b;
}
void lex(void)
{
	char a[200];
	char b[200][10];
	int j = 0;
	int i;
	int count;
	int flag;
	ifstream fin("F:\\source.txt ", ios::in);//载入自己设定路径输入文件 
	ofstream fout("F:\\lexout.txt", ios::out);//载入自己设定路径输出文件 
	for (i = 0; i < 200; i++)
	{
		a[i] = fin.get();//输入文件读取到数组a[]中  
	}
	for (i = 0; i < 200; i++)//开始进行数组a[]内字符识别 
	{
		switch (a[i])
		{
		case '('://识别符号（ 
		{
			b[i][j] = a[i];
			b[i][j + 1] = '\0';
			fout << "<1," << b[i] << ">" << endl;
			break;
		}
		case ')'://识别符号） 
		{
			b[i][j] = a[i];
			b[i][j + 1] = '\0';
			fout << "<2," << b[i] << ">" << endl;
			break;
		}
		}
	}
	fout.close();//关闭文件 
	fin.close();//关闭文件 
}