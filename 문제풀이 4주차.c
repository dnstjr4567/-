//10989
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int main()
{
	int n;
	scanf("%d", &n);
	int len = n;
	int f[10001] = { 0 , };
	

	for (int i = 0; i < len;i++)
	{
		int d;
		scanf("%d", &d);
		f[d]++;

	}
	for (int i = 0; i < 10001; i++)//순서대로 
	{
		for (int j = 0;j < f[i];j++)//갯수만큼 출력
		{
			printf("%d\n", i);
		}
	}

}
//2108
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#define num 5000001
int DataSet[num];
int cda[num];
void Swap(int* A, int* B)
{
    int Temp = *A;
    *A = *B;
    *B = Temp;
}

int Partition(int DataSet[], int Left, int Right)
{
    int First = Left;
    int Pivot = DataSet[First];

    ++Left;

    while (Left <= Right)
    {
        while (DataSet[Left] <= Pivot && Left < Right)
            ++Left;

        while (DataSet[Right] >= Pivot && Left <= Right)
            --Right;

        if (Left < Right)
            Swap(&DataSet[Left], &DataSet[Right]);
        else
            break;
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
    if (Left < Right)
    {
        int Index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, Index - 1);
        QuickSort(DataSet, Index + 1, Right);
    }
}
typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
} Node;

typedef struct tagCircularQueue
{
    int   Capacity;
    int   Front;
    int   Rear;

    Node* Nodes;
} CircularQueue;

void        CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void        CQ_DestroyQueue(CircularQueue* Queue);
void        CQ_Enqueue(CircularQueue* Queue, ElementType Data);
ElementType CQ_Dequeue(CircularQueue* Queue);
int         CQ_GetSize(CircularQueue* Queue);
int         CQ_IsEmpty(CircularQueue* Queue);
int         CQ_IsFull(CircularQueue* Queue);
int         CQ_Front(CircularQueue* Queue);
int         CQ_Back(CircularQueue* Queue);


void  CQ_CreateQueue(CircularQueue** Queue, int Capacity)
{
    //  큐를 자유 저장소에 생성 
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

    //  입력된 Capacity+1 만큼의 노드를 자유 저장소에 생성 
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));

    (*Queue)->Capacity = Capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}

void CQ_DestroyQueue(CircularQueue* Queue)
{
    free(Queue->Nodes);
    free(Queue);
}

void CQ_Enqueue(CircularQueue* Queue, ElementType Data)
{
    int Position = 0;

    if (Queue->Rear == Queue->Capacity)
    {
        Position = Queue->Rear;
        Queue->Rear = 0;
    }
    else
        Position = Queue->Rear++;

    Queue->Nodes[Position].Data = Data;
}

ElementType CQ_Dequeue(CircularQueue* Queue)
{
    int Position = Queue->Front;

    if (Queue->Front == Queue->Capacity)
        Queue->Front = 0;
    else
        Queue->Front++;

    return Queue->Nodes[Position].Data;
}

int CQ_GetSize(CircularQueue* Queue)
{
    if (Queue->Front <= Queue->Rear)
        return Queue->Rear - Queue->Front;
    else
        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

int CQ_IsEmpty(CircularQueue* Queue)
{
    return (Queue->Front == Queue->Rear);
}
int CQ_IsFull(CircularQueue* Queue)
{
    if (Queue->Front < Queue->Rear)
        return (Queue->Rear - Queue->Front) == Queue->Capacity;
    else
        return (Queue->Rear + 1) == Queue->Front;
}
int CQ_Front(CircularQueue* Queue)
{
    return Queue->Nodes[Queue->Front].Data;
}
int CQ_Back(CircularQueue* Queue)
{
    return Queue->Nodes[Queue->Rear - 1].Data;
}
int ComparePoint(const void* _elem1, const void* _elem2)
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if (*elem1 > *elem2)
        return 1;
    else if (*elem1 < *elem2)
        return -1;
    else
        return 0;
}

int main(void)
{
    int n,max=-4000,min=4000;
    int cmax = 0;
    int cnt = 0;
    scanf("%d", &n);
    CircularQueue* queue;
    CQ_CreateQueue(&queue, n);
    int sum = 0;


    for (int i = 0; i < n;i++)
    {
        int d;
        scanf("%d", &d);
        DataSet[i] = d;
        sum += d;
        if (max < d) { max = d; }
        if (min > d) { min = d; }

    }
    qsort((void*)DataSet, n, sizeof(int), ComparePoint);
    
    int k = DataSet[0];
    for (int i = 0; i < n;i++)
    {
        if (k == DataSet[i])
        {
            cnt++;
            if (cnt >= cmax) { cmax = cnt; }
        }
        else
        {
            cnt = 1;
            k = DataSet[i];
        }
        cda[i] = cnt;
        ///printf("data i %d cnt %d cmax %d cda %d\n", DataSet[i], cnt, cmax,cda[i]);
    }
    for (int i = 0;i < n;i++)
    {
        if (cda[i] == cmax)
        {
            CQ_Enqueue(queue, DataSet[i]);
        }
    }
    
    float avg = sum / (float)n;
    int ravg = round(avg);
    printf("%d\n", ravg);
    printf("%d\n", DataSet[n / 2]);
    if (CQ_GetSize(queue)<= 1)
    {
        printf("%d\n", CQ_Dequeue(queue));
    }
    else
    {
        CQ_Dequeue(queue);
        printf("%d\n", CQ_Dequeue(queue));
    }
    printf("%d",max - min);
    return 0;
}
//2750
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void Swap(int* A, int* B)
{
    int Temp = *A;
    *A = *B;
    *B = Temp;
}

int Partition(int DataSet[], int Left, int Right)
{
    int First = Left;
    int Pivot = DataSet[First];

    ++Left;

    while (Left <= Right)
    {
        while (DataSet[Left] <= Pivot && Left < Right)
            ++Left;

        while (DataSet[Right] >= Pivot && Left <= Right)
            --Right;

        if (Left < Right)
            Swap(&DataSet[Left], &DataSet[Right]);
        else
            break;
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
    if (Left < Right)
    {
        int Index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, Index - 1);
        QuickSort(DataSet, Index + 1, Right);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int DataSet[1001];
    
    
    for (int i = 0; i < n;i++)
    {
        int d;
        scanf("%d", &d);
        DataSet[i] = d;
        
    }
    int Length = sizeof DataSet / sizeof DataSet[0];
    QuickSort(DataSet, 0, n-1);
    for (int i = 0; i < n;i++)
    {
        printf("%d\n", DataSet[i]);
    }
    return 0;
}
//2587
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void Swap(int* A, int* B)
{
    int Temp = *A;
    *A = *B;
    *B = Temp;
}

int Partition(int DataSet[], int Left, int Right)
{
    int First = Left;
    int Pivot = DataSet[First];

    ++Left;

    while (Left <= Right)
    {
        while (DataSet[Left] <= Pivot && Left < Right)
            ++Left;

        while (DataSet[Right] >= Pivot && Left <= Right)
            --Right;

        if (Left < Right)
            Swap(&DataSet[Left], &DataSet[Right]);
        else
            break;
    }

    Swap(&DataSet[First], &DataSet[Right]);

    return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
    if (Left < Right)
    {
        int Index = Partition(DataSet, Left, Right);

        QuickSort(DataSet, Left, Index - 1);
        QuickSort(DataSet, Index + 1, Right);
    }
}

int main(void)
{
    int DataSet[5];
    int sum = 0;
    for (int i = 0; i < 5;i++)
    {
        int d;
        scanf("%d", &d);
        DataSet[i] = d;
        sum += d;
    }
    int Length = sizeof DataSet / sizeof DataSet[0];
    QuickSort(DataSet, 0, Length - 1);
    printf("%d\n%d", sum / 5, DataSet[2]);
    return 0;
}
