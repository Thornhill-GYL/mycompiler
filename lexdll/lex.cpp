#include "stdafx.h"
#include "lex.h"
#include <iostream>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int add(int a, int b)
{

	return a + b;
}
int out(int a, int b)
{
	return a - b;
}
int lex(void)
{
	char a[200];
	string b[200];
	static int j = 0;
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
			b[j] = a[i];
			fout << "<1," << b[j] << ">" << endl;
			break;
		}
		case ')'://识别符号） 
		{
			b[j] = a[i];
			fout << "<2," << b[j] << ">" << endl;
			break;
		}
		case '+':
		{
			if (a[i + 1] == '=')//识别符号+= 
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<3," << b[j] << ">" << endl;
			}
			else if (a[i + 1] == '+')//识别符号++ 
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<22," << b[j] << ">" << endl;
			}
			else//识别符号+ 
			{
				b[j] += a[i];
				fout << "<4," << b[j] << ">" << endl;
			}
			break;
		}
		case '-':
		{
			if (a[i + 1] == '=')//识别符号-= 
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<5," << b[j] << ">" << endl;
			}
			else if (a[i + 1] == '-')//识别符号--
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<23," << b[j] << ">" << endl;
			}
			else//识别符号- 
			{
				b[j] += a[i];
				fout << "<6," << b[j] << ">" << endl;
			}
			break;
		}
		case '*':
		{
			if (a[i + 1] == '=')//识别符号*= 
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<7," << b[j] << ">" << endl;
			}
			else//识别符号* 
			{
				b[j] += a[i];
				fout << "<8," << b[j] << ">" << endl;
			}
			break;
		}
		case '/':
		{
			if (a[i + 1] == '=')//识别符号 /= 
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<9," << b[j] << ">" << endl;
			}
			else if (a[i + 1] == '/')//识别符号 // 
			{
				while (a[i + 2] != '\n')
				{
					i++;
				}
				fout << "<10(1)," << "注释" << ">" << endl;
			}
			else////识别符号 / 
			{
				b[j] += a[i];
				fout << "<10," << b[j] << ">" << endl;
			}
			break;
		}
		case ';'://识别符号 ； 
		{
			b[j] = a[i];
			fout << "<11," << b[j] << ">" << endl;
			break;
		}
		case '<':
		{
			if (a[i + 1] == '=')//识别符号<= 
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<12," << b[j] << ">" << endl;
			}
			else//识别符号 <
			{
				b[j] += a[i];
				fout << "<13," << b[j] << ">" << endl;
			}
			break;
		}
		case '>':
		{
			if (a[i + 1] == '=')//识别符号 >=
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<14," << b[j] << ">" << endl;
			}
			else//识别符号 >
			{
				b[j] += a[i];
				fout << "<15," << b[j] << ">" << endl;
			}
			break;
		}
		case '=':
		{
			if (a[i + 1] == '=')//识别符号 ==
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<16," << b[j] << ">" << endl;
			}
			else//识别符号 =
			{
				b[j] += a[i];
				fout << "<17," << b[j] << ">" << endl;
			}
			break;
		}
		}
		if (a[i] == ' ' || a[i] == '\n') //识别符号空格及换行 
		{
			j++;
		}
		if (a[i] >= '0'&&a[i] <= '9' || a[i] == '.')//识别小数及整数  
		{
			b[j] += a[i];
			if (a[i + 1] == ' ' || a[i + 1] == '\n')//识别小数，下面语句进行位数控制 
			{
				if (a[i - 1] == '.' || a[i - 2] == '.' || a[i - 3] == '.' || a[i - 4] == '.' || a[i - 5] == '.' || a[i - 6] == '.')
					fout << "<18(1)," << b[j] << ">" << endl;
				else
					fout << "<18," << b[j] << ">" << endl;//识别整数
			}
		}
		if (a[i] >= 'a'&&a[i] <= 'z') //关键字识别，自己添加需要的关键字 
		{
			b[j] += a[i];
			if (a[i + 1] == ' ' || a[i + 1] == '\n')
			{
				if (b[j] == "while")
					fout << "<19(1)," << b[j] << ">" << endl;
				else if (b[j] == "int")
					fout << "<19(2)," << b[j] << ">" << endl;
				else if (b[j] == "float")
					fout << "<19(3)," << b[j] << ">" << endl;
				else if (b[j] == "do")
					fout << "<19(4)," << b[j] << ">" << endl;
				else if (b[j] == "public")
					fout << "<19(5)," << b[j] << ">" << endl;
				else if (b[j] == "void")
					fout << "<19(6)," << b[j] << ">" << endl;
				else if (b[j] == "if")
					fout << "<19(7)," << b[j] << ">" << endl;
				else
					fout << "<19," << b[j] << ">" << endl;//识别自定义变量 
			}
		}
		if (a[i] == ':')
		{
			if (a[i + 1] == '=')//识别符号 := 
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				fout << "<20," << b[j] << ">" << endl;
				i++;
			}
			else//识别符号 :
			{
				b[j] += a[i];
				fout << "<21," << b[j] << ">" << endl;
			}
		}
	}
	if (fout)
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
	fout.close();//关闭文件 
	fin.close();//关闭文件 
	return flag;
}