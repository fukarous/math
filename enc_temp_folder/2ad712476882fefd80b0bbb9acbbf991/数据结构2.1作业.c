#include<stdio.h>
#define LISTINCREAMENT 10
#pragma warning(disable : 4996)
/*����ṹ�����*/
typedef struct
{
        int *elem;
        int length;
        int listsize;
}List;

/*��ʼ��˳���*/
void InitList(List* L)
{
    L->elem=(int*)malloc(100*sizeof(int));
    if(!L->elem)
        {
            printf("��������\n"); //����ռ��������޷������ڴ�.
            return 0;
        }
    L->length =0;
    L->listsize = 100;
}

/*1.ɾ����С��Ԫ��*/
void DeleteminList(List *L)
{
    int i,t,min;
    min=L->elem[0];
    t=0;
    for(i=0;i<L->length;i++)
    {
        if(L->elem[i]<min)
        {
            min=L->elem[i];
            t=i;
        }
    }
    L->elem[t]=L->elem[L->length-1];
    L->length--;
    printf("��ɾ����ֵΪ��%d\n",min);
}

/*2.˳�����뺯��*/
void InsertList(List*L,int i, int data)
{
    int* newbase =(int *)realloc(L->elem,(L->listsize+LISTINCREAMENT)*sizeof(int));
    if(i<1||i>L->length+1)
        {
            printf("�������д���!\n");
            return 1;
        }
    if(!newbase)
    {
        return 0;
    }
    int j;
    for(j=L->length-1;j>=i-1;j--)
    {
        L->elem[j+1]=L->elem[j];
    }
    L->elem[i-1]=data;
    L->length++;
}

/*3.ɾ��ֵΪx������Ԫ�غ���*/
void DeleteList(List *L,int x)
{
    int i,j;
    for(i=0;i<L->length;i++)
    {
        if(L->elem[i]==x)
        {
            for(j=i;j<L->length;j++)
            {
                L->elem[i]=L->elem[i+1];
            }
            L->length--;
            i=i-1;
        }
        else continue;
    }
}

/*4.ɾ����ֵ���亯��*/
void DeleteareaList(List *L,int s,int t)
{
    int i,j;
    if(s>=t||L->length==0)
    {
        printf("�����������ǰһ����ӦС�ں�һ��������\n");
        return 1;
    }
    for(i=0;i<L->length;i++)
    {
        if(L->elem[i]>=s&&L->elem[i]<=t)
        {
            for(j=i;j<L->length;j++)
            {
                L->elem[j]=L->elem[j+1];
            }
            L->length--;
            i=i-1;
        }
        else continue;
    }
}

/*5.ɾ��˳����������ظ���Ԫ�غ���*/
void DeleterepeatList1(List *L)
{
    int i,j,k;
    for(i=0;i<L->length;i++)
    {
        for(j=i+1;j<L->length;j++)
        {
            if(L->elem[i]==L->elem[j])
            {
                for(k=j;k<L->length;k++)
                {
                    L->elem[k]=L->elem[k+1];
                }
                L->length--;
                j=i;
            }
        }
    }
}

/*6.ɾ������˳����������ظ���Ԫ�غ���*/
void DeleterepeatList2(List *L)
{
    int i,j,k,t;
    for(i=0;i<L->length-1;i++)
    {
        for(j=0;j<L->length-i-1;j++)
        {
            if(L->elem[j]>L->elem[j+1])
            {
                t=L->elem[j];
                L->elem[j]=L->elem[j+1];
                L->elem[j+1]=t;
            }
        }
    }
    for(i=0;i<L->length;i++)
    {
        for(j=i+1;j<L->length;j++)
        {
            if(L->elem[i]==L->elem[j])
            {
                for(k=j;k<L->length;k++)
                {
                    L->elem[k]=L->elem[k+1];
                }
                L->length--;
                j=i;
            }
        }
    }
}

/*7.���˳�����*/
void PrintList(List *L)
{
	int i,n;
	n = L->length;
	printf("���潫���Ŀǰ˳������ֵ��\n\n");
	for(i=0;i<n;i++)
    {
        printf("%5d",L->elem[i]);
        printf("\n");
    }
}

/*������*/
int main()
{
    List La;
    InitList(&La);
    int a,b,size,i,m,N;
/*8.���¹���˳���*/
loop0:
    printf("��������Ҫ˳����ȣ�");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        printf("���������Ա�ĵ�%d��Ԫ��:",i+1);
        scanf("%d",&m);
        La.elem[i]=m;
    }
    La.length=size;
/*�������˵�*/
loop:
        printf("\n1.ɾ��˳�������С��Ԫ��\n2.��˳����в���һ����\n3.ɾ��˳�����ֵΪxԪ��\n");
        printf("4.ɾ��˳���һ�������ڵ���\n5.ɾ��˳����������ظ���ֵ\n6.ɾ������˳����������ظ���ֵ\n");
        printf("7.�����ǰ˳���\n8.���¹���˳���\n9.��������\n\n");
        printf("��������ʹ�õĺ�����");
        scanf("%d",&N);
        switch(N)
        {
        case 1: DeleteminList(&La);
                PrintList(&La);
                goto loop;
                break;
        case 2: printf("������Ҫ�������ֵ�λ�ã�");
                scanf("%d",&a);
                printf("������Ҫ��������֣�");
                scanf("%d",&b);
                InsertList(&La,a,b);
                PrintList(&La);
                goto loop;
                break;
        case 3: printf("������Ҫɾ��������");
                scanf("%d",&a);
                DeleteList(&La,a);
                PrintList(&La);
                goto loop;
                break;
        case 4: printf("����������Ҫɾ��������\n");
                printf("�������С������");
                scanf("%d",&a);
                printf("������ϴ������");
                scanf("%d",&b);
                DeleteareaList(&La,a,b);
                PrintList(&La);
                goto loop;
                break;
        case 5: DeleterepeatList1(&La);
                PrintList(&La);
                goto loop;
                break;
        case 6: DeleterepeatList2(&La);
                PrintList(&La);
                goto loop;
                break;
        case 7: PrintList(&La);
                goto loop;
                break;
        case 8: goto loop0;
                break;
        case 9: printf("�ټ���ף��������죡");
                return 0;
                break;
        }
        return 0;
}
