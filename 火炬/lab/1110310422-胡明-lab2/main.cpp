#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define  maxlen 100
using namespace std;
struct BTtree
{
    char data;
    BTtree  *lchild;
    BTtree  *rchild;
};
char genelist[100];//��������
int i;
BTtree* pre_creat_bt()//������������
{
    char ch;
    BTtree  *T;
    cin >> ch;
    if(ch=='#')  T=NULL;
    else
    {
        T=(BTtree*)malloc(sizeof(BTtree));
        T->data=ch;
        T->lchild=pre_creat_bt();
        T->rchild=pre_creat_bt();
    }
    return T;
}
BTtree * level_create()//��ν�����������
{
    BTtree* s[maxlen];
    int j;
    char ch;
    BTtree *T,*p;
    while(cin >> i >> ch&&(i!=0||ch!='#'))
    {
        p=(BTtree*)malloc(sizeof(BTtree));
        p->data=ch;
        p->lchild=NULL;
        p->rchild=NULL;
        s[i]=p;
        if(i==1)T=p;
        else
        {
            j=i/2;
            if(i%2==0)s[j]->lchild=p;//�ڵ�Ϊż����iΪj�������
            else    s[j]->rchild=p;//�ڵ�Ϊż����iΪj�������
        }
    }
    return T;
}
void pre_order(BTtree *T)//�ݹ��ȸ�����������
{
    if(T!=NULL)
    {
        cout << T->data;
        pre_order(T->lchild);
        pre_order(T->rchild);
    }
}
void in_order(BTtree *T)//�ݹ��������������
{
    if(T!=NULL)
    {
        in_order(T->lchild);
        cout << T->data;
        in_order(T->rchild);
    }
}
void post_order(BTtree *T)//�ݹ�������������
{
    if(T!=NULL)
    {
        post_order(T->lchild);
        post_order(T->rchild);
        cout << T->data;
    }
}
void npre_order(BTtree *T)//�ǵݹ��ȸ�����������
{
    BTtree* STACK[maxlen];
    int top=maxlen;
    while(T!=NULL||top!=maxlen)
    {
        while(T!=NULL)
        {
            cout << T->data;
            STACK[--top]=T;
            T=T->lchild;
        }
        if(top!=maxlen)
        {
            T=STACK[top++];
            T=T->rchild;
        }
    }
}
/*
�����ǿ���ôѭ�������ʣ�����
��S���գ�ȡջ������
*/
void nin_order(BTtree *T)//�ǵݹ��������������
{
    BTtree* STACK[maxlen];
    int top=maxlen;
    while(T!=NULL||top!=maxlen)
    {
        if(T!=NULL)
        {
            STACK[--top]=T;
            T=T->lchild;
        }
        else
        {
            T=STACK[top++];
            cout << T->data ;
            T=T->rchild;
        }
    }
}
/*
  �����գ�����һ��������
  ��ջ���գ�ȡ��ջ������ �ٷ��ʸ��ף�������
*/
void npost_order(BTtree *T)//�ǵݹ�������������
{
    struct STACK
    {
        BTtree*  tree;
        int  flag;
    } S[maxlen];
    int top=maxlen;
    BTtree * temp;
    temp=T;
    while(temp!=NULL||top!=maxlen)
    {
        if(temp!=NULL)
        {
            S[--top].tree=temp;
            S[top].flag=1;
            temp=temp->lchild;
        }
        else
        {
            if(S[top].flag==2)
            {
                T=S[top++].tree;
                cout << T->data;
            }
            else
            {
                S[top].flag=2;
                temp=S[top].tree->rchild;
            }
        }
    }
}
void lev_order(BTtree* T)
{
    BTtree* Q[maxlen],*q=NULL;
    int front=0,rear=0;//����һ���յĶ���
    if(T==NULL)return;
    Q[rear++]=T;//����ָ�����
    while(front!=rear)
    {
        q=Q[front];
        cout << q->data;
        if(q->lchild!=NULL)
        {
            Q[rear]=q->lchild;//����Ӳ��ǿգ����������
            rear++;
        }
        if(q->rchild!=NULL)
        {
            Q[rear]=q->rchild;//�ұ߶��Ӳ��ǿգ����������
            rear++;
        }
        front++;//�������֮�󽫶���Ԫ�ؾͿ��Գ��ӽ�����һ��ѭ������
    }
}
void  order(BTtree * T)//������������
{
    printf("********�ݹ������������***********\n");
    printf("\n����ݹ������������:");
    pre_order(T);
    printf("\n����ݹ������������:");
    in_order(T);
    printf("\n����ݹ������������:");
    post_order(T);
    printf("\n********�ǵݹ������������***********\n");
    printf("\n����ǵݹ������������:");
    npre_order(T);
    printf("\n����ǵݹ������������:");
    nin_order(T);
    printf("\n����ǵݹ������������:");
    npost_order(T);
    printf("\n**********��α�����������***********:\n");
    lev_order(T);
}
void print_tree(BTtree *T) /*�������ʽ��ӡ*/
{
    if(T!=NULL)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
        {
            genelist[i]=T->data;
            i++;
        }
        else
        {
            genelist[i]=T->data;
            i++;
            genelist[i]='(';
            i++;
            print_tree(T->lchild);
            genelist[i]=',';
            i++;
            print_tree(T->rchild);
            genelist[i]=')';
            i++;
        }
    }
}
void print(BTtree *T)
{
    BTtree *t=T;
    i=0;
    genelist[i]='(';
    i++;
    print_tree(t);
    genelist[i]=')';
    i++;
    genelist[i]='\0';
}
int main()
{
    BTtree *pre_t=NULL,*lev_t=NULL;
    int N;
    printf("********����1��������������***********\n********����2��ν�����������***********\n********����0�˳�***********\n");
    while(cin >> N)
    {
        switch(N)
        {
        case 1:
            pre_t=pre_creat_bt();
            order(pre_t);//������������
            printf("\n********�������ù�����ʾΪ********:\n");
            print(pre_t);
            for(i=0; genelist[i]!='\0'; i++) cout << genelist[i];
            printf("\n");
            break;
        case 2:
            printf("********��ν�����������***********\n����ڵ�����Ԫ��:");
            lev_t=level_create();
            order(lev_t);//������������*/
            printf("\n********�������ù�����ʾΪ********:\n");
            print(lev_t);
            for(i=0; genelist[i]!='\0'; i++)cout << genelist[i];
            printf("\n");
            break;
        case 0:
            break ;
        default :
            break;
        }
        memset(genelist,' ',sizeof(genelist));
        printf("********����1��������������***********\n********����2��ν�����������***********\n********����0�˳�***********\n");
    }
    return 0;
}
/*1A 3C 4D 5E 6F 7G 8H 9I 10J 0#*/


