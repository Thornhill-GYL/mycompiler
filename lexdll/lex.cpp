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
	ifstream fin("F:\\source.txt ", ios::in);//�����Լ��趨·�������ļ� 
	ofstream fout("F:\\lexout.txt", ios::out);//�����Լ��趨·������ļ� 
	for (i = 0; i < 200; i++)
	{
		a[i] = fin.get();//�����ļ���ȡ������a[]��  
	}
	for (i = 0; i < 200; i++)//��ʼ��������a[]���ַ�ʶ�� 
	{
		switch (a[i])
		{
		case '('://ʶ����ţ� 
		{
			b[i][j] = a[i];
			b[i][j + 1] = '\0';
			fout << "<1," << b[i] << ">" << endl;
			break;
		}
		case ')'://ʶ����ţ� 
		{
			b[i][j] = a[i];
			b[i][j + 1] = '\0';
			fout << "<2," << b[i] << ">" << endl;
			break;
		}
		}
	}
	fout.close();//�ر��ļ� 
	fin.close();//�ر��ļ� 
}