#include<iostream>
#include<fstream>
#include<cstring>
#include "stdafx.h"
#include "lex.h"
#include <iostream>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
 
class lexword
{
	public:
	int num;
	char word[10];	
	int type;
} ;

class Temp
{
public:
	char newtemp;
	int newtemp_num; 
	Temp()
	{
		newtemp='t';
		newtemp_num=1;
	};
};

void newtemp();
void Next(); 
void Before();
void A();
void B();
void C();
void D();
bool F(); 
void H();
void I();
void J();
void K();
void N();
void O();
void P();
void Q();
void R();
void S();
void T();
void U();
void X();
void Y();
void Z();
void putstart(int pop);
void putEqual(int pop);
void putAdd(int pop);
int lookup(int num);

int sym_num=0,countword=0,flag=0;
int operator_flag = 0;
int operator_confirm = 0;
int sort=0;
lexword lw[400];
Temp ntemp;
ofstream fouterr("F:\\grammarerror.txt ",ios::out);//�����Լ��趨·�������ļ�
ofstream four("F:\\fourout.txt ",ios::out);//�����Լ��趨·�������ļ� 
typedef struct 
{
	int stack[10];
	int first;
	int end;
}Four;
Four start;
Four Equal;
Four Judge;
Four Add;
typedef struct 
{
	int name[100];
	int name_count;
	int key[100];
	int key_count;
	int num[100];
	int num_count;
}symbol;
symbol symbollist;

void newtemp()
{
	ntemp.newtemp_num++;
} 

void Next()//�õ���һ��ʶ���ַ� 
{
	if (sym_num < countword)
    {
        sym_num++;
    }
}

void Before()
{
    if (sym_num > 0)
    {
        sym_num--;
    }
}

void putstart(int pop)
{
   start.end=0;
   four<<"("<<sort<<")";
   four<<"<";
   while(start.end!=pop-1)
   {
		 if(start.stack[start.end]==100)
		{
			four<<"_";
   		}
   		else
   		{
   			four<<lw[start.stack[start.end]].word;
		}
		   start.end++;
		   four<<",";
	}
	
   if(start.stack[start.end]==100)
		{
			four<<"_";
   		}
	
	four<<">"<<endl;
	sort++;	
}

void putEqual(int pop)
{
	
	 Equal.end=1;
	four<<"("<<sort<<")";
	four<<"<";
	while(Equal.end!=pop)
	{
		 if(Equal.stack[Equal.end]==100)
		{
			four<<"_";
   		}
		 else if (Equal.stack[Equal.end] == 120)
		 {
			 four << ntemp.newtemp<<ntemp.newtemp_num;
			 newtemp();
		}
		 else
   		{
   			four<<lw[Equal.stack[Equal.end]].word;
		}
		   Equal.end++;
		   four<<",";
	}
	four<<lw[Equal.stack[0]].word;
	four<<">"<<endl;
	sort++;	
}

void putAdd(int pop)
{
	Add.end = 0;
	four << "(" << sort << ")";
	four << "<";
	while (Add.end != pop-1)
	{
		if (Add.stack[Add.end] == 120)
		{
			four << ntemp.newtemp<<ntemp.newtemp_num;
		}
		else
		{
			four << lw[Add.stack[Add.end]].word;
		}
		Add.end++;
		four << ",";
	}
	if (Add.stack[Add.end] == 120)
	{
		four << ntemp.newtemp<<ntemp.newtemp_num;
	}
	four << ">" << endl;
	sort++;
	operator_flag = 0;
	operator_confirm = 0;


}
//�����򡵡�start��AB#

void A()
{
	start.first=0;
	if (lw[sym_num].num == 1)//����start
    {
    	start.stack[start.first++]=sym_num;
        Next();
        if(lw[sym_num].num==26)
        {
        	start.stack[start.first++]=sym_num;
		}
		else
		{
			 flag=1;
            fouterr<<"�ó���start��ȱ��ð��"<<endl; 
		}
        Next();
        if (lw[sym_num].num == 37)//�Ǳ�ʶ��
        {
            //ִ�г�����
            start.stack[start.first++]=sym_num;
            start.stack[start.first++]=100;
            putstart(start.first);
            Next();
            B(); 
        }
        else
        {
            flag=1;
            fouterr<<"�ó���startȱ�ٷ�����"<<endl; 
        }
    }
    else
    {
        flag=1;
        fouterr<<"�ó���ȱ�ٹؼ��֣�start"<<endl; 
    }
}

//   B��CD
void B()// 
{
	 if (lw[sym_num].num == 4)//�ж�var
    {
        Next();
        C();
    }
    else if (lw[sym_num].num == 8)//�ж�begin
    {
        Next();
		D();
    }
    else
    {
        flag=1;
        fouterr<<"������ȱ��var��begin"<<endl;  
    }
}

//C�� var E|��
//E��F��G����F��G��E
void C()//
{
    if (F())
    {
        Next();
        if (lw[sym_num].num == 26)//��
        {
        	Next();
            if (lw[sym_num].num == 5 || lw[sym_num].num == 6 || lw[sym_num].num == 7)//integer,bool,real
            {
                int j = sym_num;
                j = j - 2;
                lw[j].type = lw[sym_num].num;
                symbollist.key[symbollist.key_count++]=lw[j].type;
                j--;
                while (lw[sym_num].num == 27)
                {
                    j--;
                    lw[j].type = lw[sym_num].num;
                    symbollist.key[symbollist.key_count++]=lw[j].type;
                }
                Next();
                if (lw[sym_num].num == 28)
                {
                    Next();
                    if (lw[sym_num].num == 8)
                    {
                        Next();
                        D();
                    }
                    else if(lw[sym_num].num == 4)
                    {
                    	Next(); 
                        C();
                    }
                    else
                    {
                    	flag=1;
                        fouterr<< "�����������ȱ��var��begin"<<endl; 
					}
                }
                else
                {
                	flag=1;
                    fouterr<< "�����������ȱ�٣�"<<endl; 
                }
            }
            else
            {
                flag=1;
       			fouterr<< "��������ȱ�����ͻ����Ͷ������"<<endl;
                return;
            }
        }
        else
        {
            flag=1;
       		fouterr<<"���������ʶ������ȱ��ð��"<<endl;       
        }
    }
    else
    {
        flag=1;
        fouterr<<"���������ʶ������"<<endl;   
    }

}

//D�� begin H end
void D()//
{
	H();
    if (flag == 0)
    {
        if (lw[sym_num].num == 9)
        {
            return;
        }
        else
        {
        	flag=1;
        	fouterr<<"���Ͼ�ĩβȱ��end"<<endl;
        }
    }
} 

//H��I��H��I
void H()//
{
	I();
    if (flag==0)
    {
        Next();
        if (lw[sym_num].num == 28)
        {
            Next();
            H();
        }
    }
}

int lookup(int num)
{
	int i = 0;
	int flag = 0;
	for (int i = 0; i < symbollist.name_count; i++)
	{
		if (strcmp(lw[symbollist.name[i]].word, lw[num].word) == 0)
		{
			flag = 1;
			break;
		}
		else
			flag = 0;
	}
	return flag;
}

// I��J��K
void I()//
{
	int flag_work=0;
	Equal.first=0;
	if (lw[sym_num].num == 37)
    {
    
		flag_work = lookup(sym_num);
		if(flag_work==1)
       {
         Equal.stack[Equal.first++]=sym_num;
		 Next();
        J();
       }
       else
       {
       	flag=1;
        fouterr<<"δ�������"<<endl;  
	   }
    }
    else if (lw[sym_num].num == 8 || lw[sym_num].num == 14 || lw[sym_num].num == 10)
    {
        K();
    }
    else 
    {
        Before();
    }
}

// J��A����N
void J()//
{
	if (lw[sym_num].num == 32)//:=
    {
    	Equal.stack[Equal.first++]=sym_num;
        Next();
		
        N();
    }
    else
    {
        flag=1;
        fouterr<<"��ֵ�������ȱ�٣�="<<endl; 
    }
}

//N��R��Q
void N()//
{
	if (lw[sym_num].num == 12 || lw[sym_num].num == 13 || (lw[sym_num].num == 37&&lw[sym_num].type == 7))
    {
        Q();
    }
    else
    {
		Next();
		if (lw[sym_num].num == 19 || lw[sym_num].num == 20||lw[sym_num].num==21||lw[sym_num].num==22)
		{
			operator_flag = 1;
		}
		Before();
        R();
	
    }
}

//Q��X or Q��X
void Q()//
{
	 X();
    if (flag == 0)
    {
        Next();
        if (lw[sym_num].num == 17)
        {
            Next();
            Q();
        }
        else
        {
            Before();
        }
    }
    else
    {
        return;
    }
}

//X��Y and X��Y
void X()//
{
	Y();
    if (flag == 0)
    {
        Next();
        if (lw[sym_num].num == 36)
        {
            Next();
            X();
        }
        else
        {
            Before();
        }
    }
}

//Y�� not Y��Z
void Y()//
{
	if (lw[sym_num].num == 18)
    {
    	Next();
        Y();
    }
    else
    {
        Z();
    }
}

//Z��B'��A��Q��M
//M��A L A
//L��<|<�� | ��| >��| >
//B'�� true��false
void Z()//
{
	Judge.first = 0;
	if (lw[sym_num].num == 12 || lw[sym_num].num == 13)
    {
		
        return;
    }
    else if (lw[sym_num].num == 37)
    {
		Judge.stack[Judge.first++] = sym_num;
        Next();
        if (lw[sym_num].num == 34 || lw[sym_num].num == 33 || lw[sym_num].num == 30 || lw[sym_num].num == 31 || lw[sym_num].num == 29 || lw[sym_num].num == 35)
        {
            Next();
            if (lw[sym_num].num == 37)
            {
            }
            else
            {
                flag=1;
                fouterr<<"��ϵ�������ȱ�ٱ�ʶ��"<<endl; 
            }
        }
        else
        {
            Before();
        }
    }
    else if (lw[sym_num].num == 23)
    {
        Q();
        if (lw[sym_num].num == 24)
        {
            return;
        }
        else
        {
            flag=1;
            fouterr<<"�������еĲ������ʽȱ��һ����"<<endl; 
        }
    }
    else
    {
        flag=1;
        fouterr<<"����������"<<endl;  
    }
}

//F��A��F��A
bool F()//�ж��Ƿ��Ǳ�ʶ���� 
{
	
    if (lw[sym_num].num == 37)
    {
    	symbollist.name[symbollist.name_count++]=sym_num;
        Next();
        if (lw[sym_num].num == 27)//,
        {
            Next();
            return F();
        }
        else
        {
            Before();
            return true;
        }
    }
    else
    {
        return false;
    }
}
 
//R��S+R��S-R��S
void R()//
{
	
	S();
    if (flag == 0)
    {
        Next();
        if (lw[sym_num].num == 19 || lw[sym_num].num == 20)
        {
			
			operator_confirm = 1;
			Add.first = 0;
			Add.stack[Add.first++] = sym_num;
            Next();
            R();
        }
        else
        {
            Before();
            return;
        }
    }
    else
    {
    	return;
    }
}

//S��T*S��T/S��T
void S()
{
	
	T();
    if (flag == 0)
    {
        Next();
        if (lw[sym_num].num == 21|| lw[sym_num].num == 22)
        {
			operator_confirm = 1;
			Add.first = 0;
			Add.stack[Add.first++] = sym_num;
            Next();
            S();
        }
        else
        {
            Before();
            return;
        }
    }
    else
    {
        return;
    }
}

//T��U����R��
void T()//
{
	if (lw[sym_num].num == 23)
    {
        Next();
        R();
        Next();
        if (lw[sym_num].num == 24)
        {
            return;
        }
        else
        {
            flag=1;
            fouterr<<"�������������ʽȱ�٣�"<<endl;  
        }
    }
    else
    {
        U();
    }
}

//U��A��CONSTANT��FLOAT
void U()//
{
	int flag_work = 0;
	int tag = 0;
	int num_temp = 0;
	if (lw[sym_num].num == 2 || lw[sym_num].num == 3 || lw[sym_num].num == 37)
    {
    	if(lw[sym_num].num==2||lw[sym_num].num==3)
    	{
			if (operator_flag==1)
			{
				int a = Equal.first - 1;
				int temp = Equal.stack[a];
				flag_work = lookup(temp);
				if (flag_work == 1)
				{
					Equal.first--;
					Add.stack[Add.first++] = temp;
				}
				else
				{
					flag = 1;
					fouterr << "��ֵ����δ����" << endl;
				}
				if (operator_confirm == 1)
				{
					Add.stack[Add.first++] = sym_num;
					Add.stack[Add.first++] = 120;
					putAdd(Add.first);
					Equal.stack[Equal.first++] = 120;
					Equal.stack[Equal.first++] = 100;
					putEqual(Equal.first);
				}
			}
			else
			{
				symbollist.num[symbollist.num_count++] = sym_num;
				Equal.stack[Equal.first++] = sym_num;
				Equal.stack[Equal.first++] = 100;
				putEqual(Equal.first);
			}
    		
		}
		else if (lw[sym_num].num == 37)
		{
			if (operator_flag == 1)
			{
				
				if (operator_confirm==1)
				{
					int a = Equal.first - 1;
					int temp = Equal.stack[a];
					flag_work = lookup(temp);
					if (flag_work == 1)
					{
						Equal.first--;
						Add.stack[Add.first++] = temp;
					}
					else
					{
						flag = 1;
						fouterr << "��ֵ����δ����" << endl;
					}
					flag_work = lookup(sym_num);
					if (flag_work == 1)
					{
						Add.stack[Add.first++] = sym_num;
						Add.stack[Add.first++] = 120;
						putAdd(Add.first);
						Equal.stack[Equal.first++] = 120;
						Equal.stack[Equal.first++] = 100;
						putEqual(Equal.first);
					}
					else
					{
						flag = 1;
						fouterr << "��ֵ����δ����" << endl;
					}
					
				}
				else
				{
					flag_work = lookup(sym_num);
					if (flag_work == 1)
					{
						Equal.stack[Equal.first++] = sym_num;
					}
					else
					{
						flag = 1;
						fouterr << "��ֵ����δ����" << endl;
					}
				}
				
					
				
			}
			else
			{
				for (int i = 0; i < symbollist.name_count; i++)
				{
					if (strcmp(lw[symbollist.name[i]].word, lw[sym_num].word) == 0)
					{
						Equal.stack[Equal.first++] = sym_num;
						Equal.stack[Equal.first++] = 100;
						putEqual(Equal.first);
						flag_work = 1;
						tag = i;
						break;
					}
					else
						flag_work = 0;
				}
				if (flag_work == 1)
				{
					symbollist.num[symbollist.num_count++] = symbollist.num[tag];
				}
				else
				{
					flag = 1;
					fouterr << "��ֵ����δ����" << endl;
				}
			}
			

		}
        return;
    }
    else
    {
        flag=1;
        fouterr<<"�����������ȱ��������"<<endl; 
    }
}

// K��D��O��P
void K()
{
	if (lw[sym_num].num == 8)
    {
        Next();
        D();
    }
    else if (lw[sym_num].num == 14)
    {			
			  
        Next();   
        O();
    }
    else if (lw[sym_num].num == 10)
    {
        Next();
        P();
    }
}

// O�� if Q then I| if Q then I else I
void O()//
{
	Q();
    if (flag == 0)
    {
        Next();
        if (lw[sym_num].num == 15)
        {
            Next();
            I();
            Next();
            if (lw[sym_num].num == 16)
            {
                Next();
                I();
            }
            else
            {
                Before();
                return;
            }
        }
        else
        {
            flag=1;
        	fouterr<<"if...then���ȱ��then"<<endl; 
        }
    }
    else
    {
        flag=1;
        fouterr<<"if��䲼�����ʽ����"<<endl;  
    }
}

// P�� while Q do I
void P()
{
	Q();
    if (flag == 0)
    {
        Next();
        if (lw[sym_num].num == 11)
        {
            Next();
            if(lw[sym_num].num == 8)
            {
            	Next();
            	D();
			}
			else
				I();
        }
        else
        {
            flag=1;
        	fouterr<<"while���ȱ��do"<<endl;  
        }
    }
}


int senmatic()
{
	char gettxt[1000];
	int i,j=0,k=0;
	symbollist.key_count=0;
    symbollist.name_count=0;
    symbollist.num_count=0;

	ifstream fin("F:\\shuchu.txt ",ios::in);//�����Լ��趨·�������ļ�  
	for(i=0;i<1000;i++)
 		gettxt[i] =fin.get();//�����ļ���ȡ������a[]��
    fin.close();
    i=0;
	while(gettxt[i]=='<')
	{
		i++;k=0;
		if(gettxt[i+1]!=',')
		{
			lw[j].num=(gettxt[i]-'0')*10+(gettxt[i+1]-'0');
			i=i+3;
		}
		else 
		{
			lw[j].num=gettxt[i]-'0';
			i++;i++;
		}
		if(lw[j].num==30)
		{
			lw[j].word[k++]=gettxt[i];
 			i++;
		}
		while(gettxt[i]!='>')
 		{
 			lw[j].word[k++]=gettxt[i];
 			i++;
		}
		lw[j].word[k]='\0';
		i++;i++;
		j++;
	}
	countword=j;
	for(int x=0;x<j;j++)
	{
		lw[x].type=0;
	}
    A();
	/*if(flag==0)
		cout<<"����ɹ�"<<endl;
	else
		cout<<"�������"<<endl;*/
	four << "(" << sort++ << ")";
    four<<"<sys,_,_,_>"<<endl; 
 	fouterr.close();	
 	four.close();
	system("pause");
 	return flag;
}






