#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define  maxlen 100
using namespace std;
struct STACK_CHAR
{
    int top_char;
    char element[maxlen];
} op_s;
struct STACK_NUM
{
    int top_num;
    double element[maxlen];
} num_s;
char mid[100],end[100];//�����׺�ͺ�׺
void makenull_char(STACK_CHAR &S)
{
    S.top_char=maxlen;
}
void makenull_num(STACK_NUM &S)
{
    S.top_num=maxlen;
}
bool empty_char(STACK_CHAR S)
{
    if (S.top_char>maxlen-1)   return true;
    else return false ;
}
bool empty_num(STACK_NUM S)
{
    if (S.top_num>maxlen-1)   return true;
    else return false ;
}
char top_char(STACK_CHAR S)
{
    if (empty_char(S)) return NULL;
    else return(S.element[S.top_char]);
}
double top_num(STACK_NUM S)
{
    if (empty_num(S)) return NULL;
    else return(S.element[S.top_num]);
}
void pop_char(STACK_CHAR &S)
{
    if (empty_char(S))  cout << "STACK_CHAR is empty" << endl;
    else
    {
        S.top_char =S.top_char+1;
        cout << "����ջ��Ԫ�أ�" ;
        for(int i=maxlen-1; i>=S.top_char; i--)  cout << S.element[i] << " ";
        cout << endl;
    }
}
void pop_num(STACK_NUM &S)
{
    if (empty_num(S))  cout << "STACK_NUM is empty" << endl;
    else
    {
        S.top_num =S.top_num+1;
        cout << "����ջ��Ԫ�أ�";
        for(int i=maxlen-1; i>=S.top_num; i--)   cout << S.element[i] << " ";
        cout << endl;
    }
}
void push(char x,STACK_CHAR &S)
{
    if (S.top_char==0)   cout << " STACK_CHAR  is full " << endl;
    else
    {
        S.top_char=S.top_char-1;
        S.element[S.top_char]=x;
        cout << "����ջ��Ԫ�أ�" ;
        for(int i=maxlen-1; i>=S.top_char; i--)  cout << S.element[i] <<  " ";
        cout << endl;
    }
}
void push_num(double x,STACK_NUM &S)
{
    if (S.top_num==0)   cout << " STACK_NUM is full " << endl;
    else
    {
        S.top_num=S.top_num-1;
        S.element[S.top_num]=x;
        cout << "����ջ��Ԫ�أ�";
        for(int i=maxlen-1; i>=S.top_num; i--)    cout << S.element[i] << " ";
        cout << endl;
    }
}
/*ջ��һϵ�л�����������*/
int pre_judge(char x);//���ȼ��ж�
void mid_to_end(char a[],int n);//ת���ĺ���
double calculate_end(char end[],int n);//�����׺���ʽ����
int main()
{
    int j;
    makenull_char(op_s);
    cout << "������ǰ׺���ʽ:";
    gets(mid);
    cout << "ǰ׺���ʽΪ:";
    puts(mid);
    mid_to_end(mid,100);
    cout << endl << "��׺���ʽΪ��" ;
    for (j=0; end[j]!='\0'; j++)
    {
        if(end[j]=='#') cout << '-';//ɨ������������ô��ʾ����
        else  cout << end[j];    //��ʾ��׺���ʽ
    }
    cout << endl << endl;
    cout <<"���ʽ�ļ�����Ϊ��"<< calculate_end(end,100) << endl;
    return 0;
}
int pre_judge(char x)//�������ȼ��ж�
{
    int flag=0;
    switch(x)
    {
    case '(':
        flag=1;
        break;
    case ')':
        flag=1;
        break;
    case '+':
        flag=2;
        break;
    case '-':
        flag=2;
        break;
    case '*':
        flag=3;
        break;
    case '/':
        flag=3;
        break;
    default :
        break;
    }
    return flag;
}
void mid_to_end(char a[],int n)//��׺ת��׺����
{
    int end_count=0,i,m=0;
    if(a[0]=='-')//��׺���ʽ���ǵ�һ��Ϊ����
    {
        end[end_count]='#';//�ã��ű�Ǹ���
        end_count++;
        m=1;//���Ϊ���ţ�����ѭ��ɨ���ʱ��ʹӵڶ����ַ���ʼ
    }
    for (i=m; a[i]!='\0'; i++)
    {
        if (a[i]<='9'&&a[i]>='0'&&(a[i+1]>'9'||a[i+1]<'0')&&a[i+1]!='.')
        {
            end[end_count]=a[i];
            end_count++;
            end[end_count]=' ';
            end_count++;
        }//��ǰ�ַ�Ϊ0~9������һ��Ϊ���������Ϊ���ֵ����һλ����ô��ո�����һ�����ַֿ���
        else if((a[i]<='9'&&a[i]>='0'&&((a[i+1]<='9'&&a[i+1]>='0')||a[i+1]=='.'))||a[i]=='.')
        {
            end[end_count]=a[i];
            end_count++;
        }//�����ֶ��Ҳ������ֵ����һλ�������в���ո�
        else if(a[i-1]=='('&&a[i]=='-')
        {
            end[end_count]='#';
            end_count++;
        }//��׺���ʽɨ�赽�����ֵ�ǰһ�����������򵱸��Ŵ���
        else if((a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')&&a[i-1]!='(')
        {
            while(!empty_char(op_s))
            {
                if(pre_judge(top_char(op_s))>=pre_judge(a[i]))
                {
                    end[end_count]=top_char(op_s);
                    pop_char(op_s);
                    end_count++;
                    end[end_count]=' ';
                    end_count ++;
                }
                else break;
            }
            push(a[i],op_s);
        }/*��������������������ջ���Ƚϣ�����������ջ����������ջ��
        �����˳�ջ��Ԫ�ز�����ں�׺���ʽ�У�Ȼ�����һ���ո����ָ�����*/
        else if (a[i]=='(') push(a[i],op_s);//�����������ţ���ջ��
        else  if(a[i]==')')
        {
            while(1)
            {
                if(top_char(op_s)=='(')
                {
                    pop_char(op_s);
                    break;
                }
                else
                {
                    end[end_count]=top_char(op_s);
                    pop_char(op_s);
                    end_count++;
                    end[end_count]=' ';//ע�����ÿո�
                    end_count++;
                }
            }
        }//�����������ţ���һֱ��ջ�����ֱ���˵�������ֹ��
        else  continue;
    }
    while(!empty_char(op_s))//��ջ��ʣ�µ�Ԫ�ص���
    {
        end[end_count]=top_char(op_s);
        pop_char(op_s);
        end_count++;
        end[end_count]=' ';
        end_count++;
    }
    end[end_count]='\0';//�����ַ���������ʶ
}
double calculate_end(char a[],int n)        //�����׺���ʽ��ֵ
{
    double top,sec,ans=0,number;
    int i=0,j=0,k,x;
    bool flag=true;//flag���ڱ���Ƿ�Ϊ��������ʼʱ�趨Ϊ���Ǹ���
    char num[100];
    STACK_NUM num_s;
    makenull_num(num_s);
    for(i=0; end[i]!='\0'; i++)
    {
        if(end[i]=='#')
        {
            flag=false;
            j=i+1;
        }
        if(end[i]==' '&&end[i-1]>='0'&&end[i-1]<='9')
        {
            for(k=j,x=0; k<=i; k++,x++) num[x]=end[k];
            //�ڽ�ȡ����������ŵ�num�У�������ʱ��������char�ģ�������atof��������ת��
            number=atof(num);//��char�͵���ת��Ϊdouble
            if(flag==false)
            {
                number=(-1)*number;
                flag=true;//������Ϊ����֮����ô�ѱ�ʶ����Ϊ���Ǹ�������һ��ѭ��ʹ��
            }
            push_num(number,num_s);
            memset(num,' ',sizeof(num));
            number=0;
        }//�������ǲ���������ջ��
        else if(end[i-1]==' '&&end[i]<='9'&&end[i]>='0')  j=i;
        //ɨ�赽���ֵĵ�һ������ô��j���ó�iһ��ѭ��ʱ��num�н�ȡ�ַ���
        else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
        {
            top=top_num(num_s);
            pop_num(num_s);
            sec=top_num(num_s);
            switch (a[i])  /*�Բ�ͬ��������зֱ���*/
            {
            case'+':
                ans=sec+top;
                break;
            case'-':
                ans=sec-top;
                break;
            case'*':
                ans=sec*top;
                break;
            case'/':
                ans=sec/top;
                break;
            }
            pop_num(num_s);
            push_num(ans,num_s);
        }
           /*��������������ջ���˳�����Ԫ�أ�
            ���˳��ķŵ���������ұߣ����˳��ķŵ��������ߣ�
            �����Ľ���ٽ�ջ*/
        else continue;
    }
    return  top_num(num_s);//ջ��ֻ��һ��Ԫ����������Ϊ���
}



