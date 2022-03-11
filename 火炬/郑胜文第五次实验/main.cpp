#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <cstring>
using namespace std;


void BubbleSort(double *pArray,int n)
{
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n-i-1; j++)
        {
            if(pArray[j]>pArray[j+1])
            {
                double tmp = pArray[j];
                pArray[j] = pArray[j+1];
                pArray[j+1] = tmp;
            }
        }
    }
}
void QuickSort(double *pArray,int iBegin,int iEnd)
{
    if(iBegin<iEnd)
    {
        int iLeft = iBegin;
        int iRight = iEnd;
        double k = pArray[iBegin];
        while(iLeft<iRight)
        {
            while(iLeft<iRight&&pArray[iRight]>=k)
                iRight--;
            if(iLeft<iRight)
                pArray[iLeft++] = pArray[iRight];
            while(iLeft<iRight&&pArray[iLeft]<=k)
                iLeft++;
            if(iLeft<iRight)
                pArray[iRight--] = pArray[iLeft];
        }
        pArray[iLeft] = k;
        QuickSort(pArray,iBegin,iLeft-1);
        QuickSort(pArray,iRight+1,iEnd);
    }
    else
        return;
}
double randN(double E,double D)
{
    double U1,U2,W,mult;
    static double X1,X2;
    static int call = 0;
    if(call == 1)
    {
        call = !call;
        return (E+D*(double)X2);
    }
    do
    {
        U1 = -1+((double)rand()/RAND_MAX)*2;
        U2 = -1+((double)rand()/RAND_MAX)*2;
        W = pow(U1,2)+pow(U2,2);
    }
    while(W>=1 || W == 0);
    mult = sqrt((-2*log(W))/W);
    X1 = U1*mult;
    X2 = U2*mult;
    call = !call;
    return (E+D*(double)X1);
}
double randU(double a,double b,long int *seed)
{
    double t;
    *seed = 2045*(*seed)+1;
    *seed = *seed-(*seed/1048576)*1048576;
    t = (*seed)/1048576.0;
    t = a+(b-a)*t;
    return t;
}
int n;
double a[10000000];
double f[10000000];
clock_t start,stop;
double duration;
int main()
{
    int z;
    printf("1.ѡ�����ɾ��ȷֲ�����̬�ֲ����ݣ���ѡ������ʽ���鿴�������ݵ���������ʱ��\n");
    printf("2.���ɾ������ݺ���̬�ֲ��ֱ���ð������Ϳ������������ʱ��Աȱ�\n");
    printf("3.����\n");
    printf("����ָ����룺");
    scanf("%d",&z);
    while(z!=3)
    {
        if(z == 1)
        {
            int w;
            printf("1.���ɾ��ȷֲ�����\n");
            printf("2.������̬�ֲ�����\n");
            printf("3.����\n");
            printf("����ָ����룺");
            scanf("%d",&w);
            while(w!=3)
            {
                if(w==1)
                {
                    printf("����������������");
                    scanf("%d",&n);
                    memset(a,0,sizeof(a));
                    memset(f,0,sizeof(f));
                    double c,b,x;
                    printf("�����������ݵ����䣨��a b����ʽ����");
                    scanf("%lf%lf",&c,&b);
                    long int s;
                    srand(time(NULL));
                    s = rand();
                    printf("���ɵ������ǣ�");
                    for(int i =0; i<n; i++)
                    {
                        a[i]=randU(c,b,&s);
                        printf("%lf ",a[i]);
                    }
                    printf("\n");
                    printf("1.��ð������������\n");
                    printf("2.�ÿ�������������\n");
                    printf("3.����\n");
                    printf("����ָ����룺");
                    int q;
                    scanf("%d",&q);
                    while(q!=3)
                    {
                        for(int i =0; i<n; i++)
                        {
                            f[i] = a[i];
                        }
                        if(q == 1)
                        {
                            start = clock();
                            BubbleSort(f,n);
                            stop = clock();
                            duration = ((double)(stop - start))/CLK_TCK;
                            for(int i =0; i<n; i++)
                            {
                                printf("%lf ",f[i]);
                            }
                            printf("\n");
                            printf("����ʱ��Ϊ��%lf\n",duration);
                        }
                        else if(q == 2)
                        {
                            start = clock();
                            QuickSort(f,0,n-1);
                            stop = clock();
                            duration = ((double)(stop - start))/CLK_TCK;
                            for(int i =0; i<n; i++)
                            {
                                printf("%lf ",f[i]);
                            }
                            printf("\n");
                            printf("����ʱ��Ϊ��%lf\n",duration);
                        }
                        else
                        {
                            printf("1.��ð������������\n");
                            printf("2.�ÿ�������������\n");
                            printf("3.����\n");
                            printf("����ָ����룺");
                            scanf("%d",&q);
                            continue;
                        }
                        printf("1.��ð������������\n");
                        printf("2.�ÿ�������������\n");
                        printf("3.����\n");
                        printf("����ָ����룺");
                        scanf("%d",&q);
                    }
                }
                else if(w == 2)
                {
                    printf("����������������");
                    scanf("%d",&n);
                    memset(a,0,sizeof(a));
                    memset(f,0,sizeof(f));
                    double E,D;
                    printf("���������������ݵ������ͷ��");
                    scanf("%lf%lf",&E,&D);
                    for(int i =0; i<n; i++)
                    {
                        a[i]=randN(E,D);
                        printf("%lf ",a[i]);
                    }
                    printf("\n");
                    printf("1.��ð������������\n");
                    printf("2.�ÿ�������������\n");
                    printf("3.����\n");
                    printf("����ָ����룺");
                    int q;
                    scanf("%d",&q);
                    while(q!=3)
                    {
                        for(int i =0; i<n; i++)
                        {
                            f[i] = a[i];
                        }
                        if(q == 1)
                        {
                            start = clock();
                            BubbleSort(f,n);
                            stop = clock();
                            duration = ((double)(stop - start))/CLK_TCK;
                            for(int i =0; i<n; i++)
                            {
                                printf("%lf ",f[i]);
                            }
                            printf("\n");
                            printf("����ʱ��Ϊ��%lf\n",duration);
                        }
                        else if(q == 2)
                        {
                            start = clock();
                            QuickSort(f,0,n-1);
                            stop = clock();
                            duration = ((double)(stop - start))/CLK_TCK;
                            for(int i =0; i<n; i++)
                            {
                                printf("%lf ",f[i]);
                            }
                            printf("\n");
                            printf("����ʱ��Ϊ��%lf\n",duration);
                        }
                        else
                        {
                            printf("1.��ð������������\n");
                            printf("2.�ÿ�������������\n");
                            printf("3.����\n");
                            printf("����ָ����룺");
                            scanf("%d",&q);
                            continue;
                        }
                        printf("1.��ð������������\n");
                        printf("2.�ÿ�������������\n");
                        printf("3.����\n");
                        printf("����ָ����룺");
                        scanf("%d",&q);
                    }
                }
                else
                {
                    printf("1.���ɾ��ȷֲ�����\n");
                    printf("2.������̬�ֲ�����\n");
                    printf("3.����\n");
                    printf("����ָ����룺");
                    scanf("%d",&w);
                    continue;
                }
                printf("1.���ɾ��ȷֲ�����\n");
                printf("2.������̬�ֲ�����\n");
                printf("3.����\n");
                printf("����ָ����룺");
                scanf("%d",&w);
            }
        }
        else if(z == 2)
        {
            printf("    ������              ����ð��        ���ȿ���        ��̬ð��        ��̬����\n");
            for (int i = 10000; i<=1000000; i+=10000)
            {
                printf("%d����������ʱ��\t",i);
                memset(a,0,sizeof(a));
                memset(f,0,sizeof(f));
                double c = 1;
                double b = 10;
                long int s;
                srand(time(NULL));
                s = rand();
                for(int j =0; j<i; j++)
                {
                    a[j]=randU(c,b,&s);
                }
                for(int j =0; j<i; j++)
                {
                    f[j] = a[j];
                }
                start = clock();
                BubbleSort(f,i);
                stop = clock();
                duration = ((double)(stop - start))/CLOCKS_PER_SEC;
                printf("%lf\t",duration);
                for(int j =0; j<i; j++)
                {
                    f[j] = a[j];
                }
                start = clock();
                QuickSort(f,0,i-1);
                stop = clock();
                duration = ((double)(stop - start))/CLOCKS_PER_SEC;
                printf("%lf\t",duration);
                memset(a,0,sizeof(a));
                memset(f,0,sizeof(f));
                double E = 1;
                double D = 5;
                for(int j =0; j<i; j++)
                {
                    a[j]=randN(E,D);
                }
                for(int j =0; j<i; j++)
                {
                    f[j] = a[j];
                }
                start = clock();
                BubbleSort(f,i);
                stop = clock();
                duration = ((double)(stop - start))/CLOCKS_PER_SEC;
                printf("%lf\t",duration);
                for(int j =0; j<i; j++)
                {
                    f[j] = a[j];
                }
                start = clock();
                QuickSort(f,0,i-1);
                stop = clock();
                duration = ((double)(stop - start))/CLOCKS_PER_SEC;
                printf("%lf\n",duration);
            }
        }
        else
        {
            printf("�����ڵ�ָ�\n");
            printf("1.ѡ�����ɾ��ȷֲ�����̬�ֲ����ݣ���ѡ������ʽ���鿴�������ݵ���������ʱ��\n");
            printf("2.���ɾ������ݺ���̬�ֲ��ֱ���ð������Ϳ������������ʱ��Աȱ�\n");
            printf("3.����\n");
            printf("����ָ����룺");
            scanf("%d",&z);
            continue;
        }
        printf("1.ѡ�����ɾ��ȷֲ�����̬�ֲ����ݣ���ѡ������ʽ���鿴�������ݵ���������ʱ��\n");
        printf("2.���ɾ������ݺ���̬�ֲ��ֱ���ð������Ϳ������������ʱ��Աȱ�\n");
        printf("3.����\n");
        printf("����ָ����룺");
        scanf("%d",&z);
    }
    return 0;
}
