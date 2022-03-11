#include <iostream>
#include <cstdio>
#define maxlen 100
using namespace std;
bool visited[maxlen];
struct Link
{
    int v;//vΪ�ڵ���

    Link * next;
};
struct node
{
    char element;
    struct Link* firstedge;
};//ͷ���
struct Adgraph
{
    int n,e;
    node Ad[maxlen];
};//�ڽӱ�
struct matrix_graph
{
    int n,e;
    int mat[maxlen][maxlen];
    char element[maxlen];
};
void cre1(matrix_graph  &G)//����ͼ�ڽӾ���
{
    int i,j,x,y;
    cin >> G.n >> G.e;
    for(i=0; i<G.n; i++)  cin >> G.element[i];
    for(i=0; i<G.n; i++)
        for(j=0; j<G.n; j++)
            G.mat[i][j]=0;
    for(i=0; i<G.e; i++)
    {
        cin >> x >> y;
        G.mat[x][y]=1;
        G.mat[y][x]=1;
    }
    for(i=0; i<G.n; i++)
    {
        for(j=0; j<G.n; j++)
            cout << G.mat[i][j] << " ";
        cout << endl;
    }
}
void DFS1(matrix_graph *G,int i)//�ڽӾ���������ȣ��ݹ飩
{
    int j;
    cout << G->element[i] << " ";
    visited[i]=true;
    for(j=0; j<G->n; j++)if(G->mat[i][j]==1&&!visited[j])  DFS1(G,j);
}
void DFS1_nonrec(matrix_graph *G,int v)//�ڽӾ���������ȣ��ǵݹ飩
{
    int STACK[maxlen];
    int top=maxlen;
    STACK[--top]=v;//��һ��ѹջ
    while(top!=maxlen)
    {
        int w=STACK[top++];
        if(!visited[w])
        {
            cout <<  G->element[w] <<  " ";
            visited[w]=true;
        }//ȡջ���ж�
        for(int i=0; i<G->n; i++)if(!visited[i]&&G->mat[w][i])
                STACK[--top]=i;//����һ��û�з��ʵģ�ѹջ,��������
    }
}
void BFS1(matrix_graph *G,int v)//�ڽӾ���Ĺ������
{
    int Queue[maxlen],front=0,rear=0,w;
    visited[v]=true;
    Queue[rear++]=v;
    cout << G->element[v] << " ";
    while(front!=rear)
    {
        v=Queue[front++];
        for(w=0; w<G->n; w++)
        {
            if(!visited[w]&&G->mat[v][w])
            {
                cout <<G->element[w] << " ";
                visited[w]=true;
                Queue[rear++]=w;
            }
        }
    }
}
void cre2(Adgraph* G)
{
    int k,i,j;
    cin >> G->n >> G->e;
    for (k=0; k<G->n; k++)
    {
        cin >> G->Ad[k].element;
        G->Ad[k].firstedge=NULL;
    }//ͷ���ĳ�ʼ��
    for(k=0; k<G->e; k++)
    {
        cin >> j >> i;
        Link* p=new Link;
        p->v=i;
        p->next=G->Ad[j].firstedge;
        G->Ad[j].firstedge=p;//�ڱ�ͷ����
        p=new Link;//��������ͼ�����Ի�Ҫ����������
        p->v=j;
        p->next=G->Ad[i].firstedge;
        G->Ad[i].firstedge=p;
    }
    for(i=0; i<G->n; i++)
    {
        cout << G->Ad[i].element;
        Link *m=G->Ad[i].firstedge;
        while(m!=NULL)
        {
            printf("->%c",G->Ad[m->v].element);
            m=m->next;
        }
        printf("->NULL\n");
    }
}
void DFS2(Adgraph* G,int v)
{
    Link *p;
    cout << G->Ad[v].element << " ";
    visited[v]=true;
    p=G->Ad[v].firstedge;
    while(p!=NULL)
    {
        if(!visited[p->v]) DFS2(G,p->v);
        p=p->next;
    }
}
void DFS2_nonrec(Adgraph* G,int v)
{
    int STACK[maxlen],top=maxlen;
    Link *p=NULL;
    STACK[--top]=v;//��һ��ѹջ
    while(top!=maxlen)
    {
        int w=STACK[top++];
        if(!visited[w])
        {
            cout <<  G->Ad[w].element << " ";
            visited[w]=true;
        }
        for(p=G->Ad[w].firstedge; p!=NULL; p=p->next)
            if(!visited[p->v])
                STACK[--top]=p->v;//����һ��û�з��ʵģ�ѹջ,��������
    }
}
void BFS2(Adgraph* G,int v)
{
    int Queue[maxlen],front=0,rear=0;
    struct Link *p=NULL;
    visited[v]=true;
    Queue[rear++]=v;
    cout << G->Ad[v].element << " ";
    while(front!=rear)
    {
        v=Queue[front++];
        p=G->Ad[v].firstedge;
        while(p!=NULL&&!visited[p->v])
        {
            cout <<G->Ad[p->v].element << " ";
            visited[p->v]=true;
            Queue[rear++]=p->v;
            p=p->next;
        }
    }
}
int main()
{
    struct Adgraph G2;
    int i,N;
    struct matrix_graph G1;
    printf("1----�ڽӾ���(����ͼ)\n2----�ڽӱ�����ͼ��\n");
    cin >> N;
    switch(N)
    {
    case 0:
        return 0;
    case 1:
        freopen("lab3.txt", "r", stdin);
        cre1(G1);//�����ڽӾ���
        printf("DFS:");
        for(i=0; i<G1.n; i++) visited[i]=false;
        for(i=0; i<G1.n; i++)if(!visited[i]) DFS1(&G1,i);//�ݹ�����
        printf("\nDFS_NONREC:");
        for(i=0; i<G1.n; i++) visited[i]=false;
        for(i=0; i<G1.n; i++)if(!visited[i])DFS1_nonrec(&G1,i);//�ǵݹ�����
        printf("\nBFS:");
        for(i=0; i<G1.n; i++) visited[i]=false;
        for(i=0; i<G1.n; i++)if(!visited[i])BFS1(&G1,i);
        fclose(stdin);
        break;
    case 2:
        freopen("lab3.txt", "r", stdin);
        cre2(&G2);
        printf("DFS:");
        for(i=0; i<G2.n; i++) visited[i]=false;
        for(i=0; i<G2.n; i++)if(!visited[i]) DFS2(&G2,i);//�ݹ�����
        printf("\nDFS_NONREC:");
        for(i=0; i<G2.n; i++) visited[i]=false;
        for(i=0; i<G2.n; i++)if(!visited[i]) DFS2_nonrec(&G2,i);
        printf("\nBFS:");
        for(i=0; i<G2.n; i++) visited[i]=false;
        for(i=0; i<G2.n; i++)if(!visited[i]) BFS2(&G2,i);
        fclose(stdin);
        break;
    default: break;
    }
    return 0;
}


