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
	char a[400];
	string b[400];
	static int j = 0;
	int i;
	int error_r = 1;
	int count = 0;
	int flag = 0;
	ifstream fin("F:\\source.txt ", ios::in);//�����Լ��趨·�������ļ� 
	ofstream fout("F:\\lexout.txt", ios::out);//�����Լ��趨·������ļ� 
	ofstream fouterr("F:\\error.txt", ios::out);//�����Լ��趨·������ļ�
	for (i = 0; i < 400; i++)
	{
		a[i] = fin.get();//�����ļ���ȡ������a[]��
		count++;
		if (a[i] == '#')
			break;
	}
	for (i = 0; i < (count - 2); i++)//��ʼ��������a[]���ַ�ʶ�� 
	{
		switch (a[i])
		{
		case '('://ʶ����ţ� 
		{
			b[j] = a[i];
			fout << "<23," << b[j] << ">" << endl;
			break;
		}
		case ')'://ʶ����ţ� 
		{
			b[j] = a[i];
			fout << "<24," << b[j] << ">" << endl;
			break;
		}
		case '+':
		{
			b[j] += a[i];
			fout << "<19," << b[j] << ">" << endl;
			break;
		}
		case '-':
		{
			b[j] += a[i];
			fout << "<20," << b[j] << ">" << endl;
			break;
		}
		case '*':
		{
			b[j] += a[i];
			fout << "<21," << b[j] << ">" << endl;
			break;
		}
		case '/':
		{
			b[j] += a[i];
			fout << "<22," << b[j] << ">" << endl;
			break;
		}
		case ';'://ʶ����� �� 
		{
			b[j] = a[i];
			fout << "<28," << b[j] << ">" << endl;
			break;
		}
		case ','://ʶ����� ,
		{
			b[j] = a[i];
			fout << "<27," << b[j] << ">" << endl;
			break;
		}
		case '<':
		{
			if (a[i + 1] == '=')//ʶ�����<= 
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<33," << b[j] << ">" << endl;
			}
			else//ʶ����� <
			{
				b[j] += a[i];
				fout << "<31," << b[j] << ">" << endl;
			}
			break;
		}
		case '>':
		{
			if (a[i + 1] == '=')//ʶ����� >=
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<34," << b[j] << ">" << endl;
			}
			else//ʶ����� >
			{
				b[j] += a[i];
				fout << "<30," << b[j] << ">" << endl;
			}
			break;
		}
		case '=':
		{
			if (a[i + 1] == '=')//ʶ����� ==
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				i++;
				fout << "<35," << b[j] << ">" << endl;
			}
			else//ʶ����� =
			{
				b[j] += a[i];
				fout << "<29," << b[j] << ">" << endl;
			}
			break;
		}
		case ':':
		{
			if (a[i + 1] == '=')//ʶ����� := 
			{
				b[j] = a[i];
				b[j] += a[i + 1];
				fout << "<32," << b[j] << ">" << endl;
				i++;
			}
			else//ʶ����� :
			{
				b[j] += a[i];
				fout << "<26," << b[j] << ">" << endl;
			}
			break;
		}
		case ' ':
		{
			j++;
			break;
		}
		case '\n':
		{
			j++;
			error_r++;
			break;
		}
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
		{
			if (a[i] >= '0'&&a[i] <= '9' || a[i] == '.')//ʶ��С��������  
			{
				b[j] += a[i];
				if (a[i + 1] == ' ' || a[i + 1] == '\n')//ʶ��С��������������λ������ 
				{
					if (a[i - 1] == '.' || a[i - 2] == '.' || a[i - 3] == '.' || a[i - 4] == '.' || a[i - 5] == '.' || a[i - 6] == '.')
						fout << "<3," << b[j] << ">" << endl;
					else
						fout << "<2," << b[j] << ">" << endl;//ʶ������
				}
			}
			break;
		}
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
		{
			b[j] += a[i];
			if (a[i + 1] == ' ' || a[i + 1] == '\n')
			{
				if (b[j] == "while")
					fout << "<10," << b[j] << ">" << endl;
				else if (b[j] == "int")
					fout << "<5," << b[j] << ">" << endl;
				else if (b[j] == "float")
					fout << "<6," << b[j] << ">" << endl;
				else if (b[j] == "bool")
					fout << "<7," << b[j] << ">" << endl;
				else if (b[j] == "do")
					fout << "<11," << b[j] << ">" << endl;
				else if (b[j] == "true")
					fout << "<12," << b[j] << ">" << endl;
				else if (b[j] == "false")
					fout << "<13," << b[j] << ">" << endl;
				else if (b[j] == "var")
					fout << "<4," << b[j] << ">" << endl;
				else if (b[j] == "begin")
					fout << "<8," << b[j] << ">" << endl;
				else if (b[j] == "if")
					fout << "<14," << b[j] << ">" << endl;
				else if (b[j] == "else")
					fout << "<16," << b[j] << ">" << endl;
				else if (b[j] == "then")
					fout << "<15," << b[j] << ">" << endl;
				else if (b[j] == "end")
					fout << "<9," << b[j] << ">" << endl;
				else if (b[j] == "and")
					fout << "<36," << b[j] << ">" << endl;
				else if (b[j] == "or")
					fout << "<17," << b[j] << ">" << endl;
				else if (b[j] == "not")
					fout << "<18," << b[j] << ">" << endl;
				else if (b[j] == "start")
					fout << "<1," << b[j] << ">" << endl;
				else
					fout << "<37," << b[j] << ">" << endl;//ʶ���Զ������ 
			}
			break;
		}
		default:
		{
			b[j] = a[i];
			fouterr << "����ʧ�ܣ�" << endl;
			fouterr << "��" << error_r << "�зǷ��ַ���" << "�Ƿ��ַ�Ϊ" << b[j] << endl;//����԰����ĳ�flag���Ǹ���������Ǵʷ������Ĵ���ʶ�� 
			flag = 1;
		}
		}
	}
	fouterr.close();
	fout.close();//�ر��ļ� 
	fin.close();//�ر��ļ� 
	return flag;
}