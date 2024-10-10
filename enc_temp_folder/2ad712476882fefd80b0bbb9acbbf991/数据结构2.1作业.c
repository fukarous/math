#include<stdio.h>
#define LISTINCREAMENT 10
#pragma warning(disable : 4996)
/*定义结构体变量*/
typedef struct
{
        int *elem;
        int length;
        int listsize;
}List;

/*初始化顺序表*/
void InitList(List* L)
{
    L->elem=(int*)malloc(100*sizeof(int));
    if(!L->elem)
        {
            printf("储存已满\n"); //储存空间已满，无法分配内存.
            return 0;
        }
    L->length =0;
    L->listsize = 100;
}

/*1.删除最小的元素*/
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
    printf("被删除的值为：%d\n",min);
}

/*2.顺序表插入函数*/
void InsertList(List*L,int i, int data)
{
    int* newbase =(int *)realloc(L->elem,(L->listsize+LISTINCREAMENT)*sizeof(int));
    if(i<1||i>L->length+1)
        {
            printf("输入序列错误!\n");
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

/*3.删除值为x的所有元素函数*/
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

/*4.删除数值区间函数*/
void DeleteareaList(List *L,int s,int t)
{
    int i,j;
    if(s>=t||L->length==0)
    {
        printf("输入区间错误，前一个数应小于后一个数！！\n");
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

/*5.删除顺序表中所有重复的元素函数*/
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

/*6.删除有序顺序表中所有重复的元素函数*/
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

/*7.输出顺序表函数*/
void PrintList(List *L)
{
	int i,n;
	n = L->length;
	printf("下面将输出目前顺序表的数值：\n\n");
	for(i=0;i<n;i++)
    {
        printf("%5d",L->elem[i]);
        printf("\n");
    }
}

/*主函数*/
int main()
{
    List La;
    InitList(&La);
    int a,b,size,i,m,N;
/*8.重新构建顺序表*/
loop0:
    printf("请输入需要顺序表长度：");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        printf("请输入线性表的第%d个元素:",i+1);
        scanf("%d",&m);
        La.elem[i]=m;
    }
    La.length=size;
/*返回主菜单*/
loop:
        printf("\n1.删除顺序表中最小的元素\n2.在顺序表中插入一个数\n3.删除顺序表中值为x元素\n");
        printf("4.删除顺序表一个区间内的数\n5.删除顺序表中所有重复的值\n6.删除有序顺序表中所有重复的值\n");
        printf("7.输出当前顺序表\n8.重新构建顺序表\n9.结束程序\n\n");
        printf("请输入想使用的函数：");
        scanf("%d",&N);
        switch(N)
        {
        case 1: DeleteminList(&La);
                PrintList(&La);
                goto loop;
                break;
        case 2: printf("请输入要插入数字的位置：");
                scanf("%d",&a);
                printf("请输入要插入的数字：");
                scanf("%d",&b);
                InsertList(&La,a,b);
                PrintList(&La);
                goto loop;
                break;
        case 3: printf("请输入要删除的数：");
                scanf("%d",&a);
                DeleteList(&La,a);
                PrintList(&La);
                goto loop;
                break;
        case 4: printf("下面请输入要删除的区间\n");
                printf("请输入较小的数：");
                scanf("%d",&a);
                printf("请输入较大的数：");
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
        case 9: printf("再见，祝你生活愉快！");
                return 0;
                break;
        }
        return 0;
}
