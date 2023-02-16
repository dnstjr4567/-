///우선순위 큐, 
///1927
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tageHeapNode {
    ElementType Data;
} HeapNode;

typedef struct tagHeap {
    HeapNode* Nodes;
    int Capacity;
    int UsedSize;
} Heap;

Heap* HEAP_Create(int InitialSize);
void      HEAP_Destroy(Heap* H);
void      HEAP_Insert(Heap* H, ElementType NewData);
void      HEAP_DeleteMin(Heap* H, HeapNode* Root);
int       HEAP_GetParent(int Index);
int       HEAP_GetLeftChild(int Index);
void      HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void      HEAP_PrintNodes(Heap* H);

Heap* HEAP_Create(int IntitialSize)
{
    Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
    NewHeap->Capacity = IntitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * NewHeap->Capacity);

   /// printf("size : %d\n", sizeof(HeapNode));

    return NewHeap;
}

void  HEAP_Destroy(Heap* H)
{
    free(H->Nodes);
    free(H);
}

void  HEAP_Insert(Heap* H, ElementType NewData)
{
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);

    if (H->UsedSize == H->Capacity)
    {
        H->Capacity *= 2;
        H->Nodes = (HeapNode*)
            realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }

    H->Nodes[CurrentPosition].Data = NewData;

    //  후속 처리. 
    while (CurrentPosition > 0
        && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
    {
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }

    H->UsedSize++;
}

void      HEAP_SwapNodes(Heap* H, int Index1, int Index2)
{
    int CopySize = sizeof(HeapNode);
    HeapNode* Temp = (HeapNode*)malloc(CopySize);

    memcpy(Temp, &H->Nodes[Index1], CopySize);
    memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
    memcpy(&H->Nodes[Index2], Temp, CopySize);

    free(Temp);
}

void      HEAP_DeleteMin(Heap* H, HeapNode* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    memset(&H->Nodes[0], 0, sizeof(HeapNode));

    H->UsedSize--;
    HEAP_SwapNodes(H, 0, H->UsedSize);

    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1)
    {
        int SelectedChild = 0;

        if (LeftPosition >= H->UsedSize)
            break;

        if (RightPosition >= H->UsedSize)
        {
            SelectedChild = LeftPosition;
        }
        else {
            if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;
        }

        if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data)
        {
            HEAP_SwapNodes(H, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    if (H->UsedSize < (H->Capacity / 2))
    {
        H->Capacity /= 2;
        H->Nodes =
            (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }
}

int HEAP_GetParent(int Index)
{
    return (int)((Index - 1) / 2);
}

int HEAP_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

void      HEAP_PrintNodes(Heap* H)
{
    int i = 0;
    for (i = 0; i < H->UsedSize; i++)
    {
        printf("%d ", H->Nodes[i].Data);
    }
    printf("\n");
}


int main(void)
{
    int n;
    scanf("%d", &n);
    Heap* H = HEAP_Create(n);
    HeapNode MinNode;
    ///printf("%d", H->UsedSize);
    for (int i = 0;i < n;i++)
    {
        int d;
        scanf("%d", &d);
        if (d == 0)
        {
            if (H->UsedSize != 0)
            {
                printf("%d\n", H->Nodes[0]);
                HEAP_DeleteMin(H, &MinNode);
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            HEAP_Insert(H, d);
        }
    }
    

    return 0;
}


///11279
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tageHeapNode {
    ElementType Data;
} HeapNode;

typedef struct tagHeap {
    HeapNode* Nodes;
    int Capacity;
    int UsedSize;
} Heap;

Heap* HEAP_Create(int InitialSize);
void      HEAP_Destroy(Heap* H);
void      HEAP_Insert(Heap* H, ElementType NewData);
void      HEAP_DeleteMin(Heap* H, HeapNode* Root);
int       HEAP_GetParent(int Index);
int       HEAP_GetLeftChild(int Index);
void      HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void      HEAP_PrintNodes(Heap* H);

Heap* HEAP_Create(int IntitialSize)
{
    Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
    NewHeap->Capacity = IntitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * NewHeap->Capacity);

    /// printf("size : %d\n", sizeof(HeapNode));

    return NewHeap;
}

void  HEAP_Destroy(Heap* H)
{
    free(H->Nodes);
    free(H);
}

void  HEAP_Insert(Heap* H, ElementType NewData)
{
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);

    if (H->UsedSize == H->Capacity)
    {
        H->Capacity *= 2;
        H->Nodes = (HeapNode*)
            realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }

    H->Nodes[CurrentPosition].Data = NewData;

    //  후속 처리. 
    while (CurrentPosition > 0
        && H->Nodes[CurrentPosition].Data > H->Nodes[ParentPosition].Data)///부등호 바꿈
    {
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }

    H->UsedSize++;
}

void      HEAP_SwapNodes(Heap* H, int Index1, int Index2)
{
    int CopySize = sizeof(HeapNode);
    HeapNode* Temp = (HeapNode*)malloc(CopySize);

    memcpy(Temp, &H->Nodes[Index1], CopySize);
    memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
    memcpy(&H->Nodes[Index2], Temp, CopySize);

    free(Temp);
}

void      HEAP_DeleteMin(Heap* H, HeapNode* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    memset(&H->Nodes[0], 0, sizeof(HeapNode));

    H->UsedSize--;
    HEAP_SwapNodes(H, 0, H->UsedSize);

    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1)
    {
        int SelectedChild = 0;

        if (LeftPosition >= H->UsedSize)
            break;

        if (RightPosition >= H->UsedSize)
        {
            SelectedChild = LeftPosition;
        }
        else {
            if (H->Nodes[LeftPosition].Data < H->Nodes[RightPosition].Data)///부등호
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;
        }

        if (H->Nodes[SelectedChild].Data > H->Nodes[ParentPosition].Data)///부등호
        {
            HEAP_SwapNodes(H, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    if (H->UsedSize < (H->Capacity / 2))
    {
        H->Capacity /= 2;
        H->Nodes =
            (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }
}

int HEAP_GetParent(int Index)
{
    return (int)((Index - 1) / 2);
}

int HEAP_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

void      HEAP_PrintNodes(Heap* H)
{
    int i = 0;
    for (i = 0; i < H->UsedSize; i++)
    {
        printf("%d ", H->Nodes[i].Data);
    }
    printf("\n");
}


int main(void)
{
    int n;
    scanf("%d", &n);
    Heap* H = HEAP_Create(n);
    HeapNode MinNode;
    ///printf("%d", H->UsedSize);
    for (int i = 0;i < n;i++)
    {
        int d;
        scanf("%d", &d);
        if (d == 0)
        {
            if (H->UsedSize != 0)
            {
                printf("%d\n", H->Nodes[0]);
                HEAP_DeleteMin(H, &MinNode);
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            HEAP_Insert(H, d);
        }
    }


    return 0;
}


///11286
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef float      PriorityType;

typedef struct tagePQNode
{
    PriorityType Priority;
    void* Data;
} PQNode;

typedef struct tagPriorityQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PriorityQueue;

PriorityQueue* PQ_Create(int InitialSize);
void           PQ_Destroy(PriorityQueue* PQ);
void           PQ_Enqueue(PriorityQueue* PQ, PQNode NewData);
void           PQ_Dequeue(PriorityQueue* PQ, PQNode* Root);
int            PQ_GetParent(int Index);
int            PQ_GetLeftChild(int Index);
void           PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2);
int            PQ_IsEmpty(PriorityQueue* PQ);


PriorityQueue* PQ_Create(int IntitialSize)
{
    PriorityQueue* NewPQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    NewPQ->Capacity = IntitialSize;
    NewPQ->UsedSize = 0;
    NewPQ->Nodes = (PQNode*)malloc(sizeof(PQNode) * NewPQ->Capacity);

    return NewPQ;
}

void  PQ_Destroy(PriorityQueue* PQ)
{
    free(PQ->Nodes);
    free(PQ);
}

void  PQ_Enqueue(PriorityQueue* PQ, PQNode NewNode)
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition = PQ_GetParent(CurrentPosition);

    if (PQ->UsedSize == PQ->Capacity)
    {
        if (PQ->Capacity == 0)
            PQ->Capacity = 1;

        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
    }

    PQ->Nodes[CurrentPosition] = NewNode;

    //  후속 처리
    while (CurrentPosition > 0
        && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority)
    {
        PQ_SwapNodes(PQ, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = PQ_GetParent(CurrentPosition);
    }

    PQ->UsedSize++;
}

void      PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2)
{
    int CopySize = sizeof(PQNode);
    PQNode* Temp = (PQNode*)malloc(CopySize);

    memcpy(Temp, &PQ->Nodes[Index1], CopySize);
    memcpy(&PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize);
    memcpy(&PQ->Nodes[Index2], Temp, CopySize);

    free(Temp);
}

void      PQ_Dequeue(PriorityQueue* PQ, PQNode* Root)
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
    memset(&PQ->Nodes[0], 0, sizeof(PQNode));

    PQ->UsedSize--;
    PQ_SwapNodes(PQ, 0, PQ->UsedSize);

    LeftPosition = PQ_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1)
    {
        int SelectedChild = 0;

        if (LeftPosition >= PQ->UsedSize)
            break;

        if (RightPosition >= PQ->UsedSize)
        {
            SelectedChild = LeftPosition;
        }
        else {
            if (PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority)
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;
        }

        if (PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority)
        {
            PQ_SwapNodes(PQ, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition = PQ_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;
    }

    if (PQ->UsedSize < (PQ->Capacity / 2))
    {
        PQ->Capacity /= 2;
        PQ->Nodes =
            (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
    }
}

int PQ_GetParent(int Index)
{
    return (int)((Index - 1) / 2);
}

int PQ_GetLeftChild(int Index)
{
    return (2 * Index) + 1;
}

int PQ_IsEmpty(PriorityQueue* PQ)
{
    return (PQ->UsedSize == 0);
}


void PrintNode(PQNode* Node)
{
    printf("%d\n", Node->Data);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    PriorityQueue* PQ = PQ_Create(n);
    PQNode Popped;
    float x = 0;
    for (int i = 0;i < n;i++)
    {
        int d; 
        scanf("%d", &d);
        if (d != 0)
        {
            if (d < 0)
            {
                x = (d * -1)-0.5;
                
            }
            else { x = d; }
            PQNode Nodes = { x, (void*) d };
            PQ_Enqueue(PQ, Nodes);
            ///printf("x %f\n", x);
            
        }
        else
        {
            if (PQ_IsEmpty(PQ))
            {
                printf("0\n");
            }
            else
            {
                PQ_Dequeue(PQ, &Popped);
                PrintNode(&Popped);

            }
        }
    }
   
    return 0;
}


///이진 탐색
///1920
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


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
    int n, m;
    scanf("%d", &n);
    int arr[100000];
    int arr2[100000];
    for (int i = 0; i < n;i++)
    {
        int d;
        scanf("%d", &d);
        arr[i] = d;
    }
    scanf("%d", &m);
    for (int i = 0; i < m;i++)
    {
        int d;
        scanf("%d", &d);
        arr2[i] = d;
    }
    
    qsort((void*)arr, n, sizeof(int), ComparePoint);
    for (int i = 0; i < m;i++)
    {
        int find = bsearch(
            (void*)&arr2[i],
            (void*)arr,
            n,
            sizeof(int),
            ComparePoint);
        if (find != NULL)
        {
            printf("1\n");
        }
        else { printf("0\n"); }
    }
    return 0;
}
///10816
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int arr[500000];
int arr2[500000];

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
int bs(int arr[], int n, int target)
{
    int right = n-1;
    int left = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target == arr[mid])
        {
            /// printf("idx %d\n",mid);
            return mid;
        }
        else if (target > arr[mid])
        {
            left = mid+1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;


}
int lowerbound(int arr[], int n,int target)
{
    int right = n;
    int left = 0;
    while (left < right)
    {
        int mid = (left+right)/ 2;
        
        if (target > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return right+1;


}
int upperbound(int arr[], int n, int target)
{
    int right = n;
    int left = 0;
    while (left < right)
    {
        int mid = (left + right) / 2;
    
        if (target >= arr[mid])
        {
            left = mid+1;
        }
        else
        {
            right = mid ;
        }
    }
    return right+1;


}


int main(void)
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        int d;
        scanf("%d", &d);
        arr[i] = d;
    }
    scanf("%d", &m);
    for (int i = 0; i < m;i++)
    {
        int d;
        scanf("%d", &d);
        arr2[i] = d;
    }
    
    qsort((void*)arr, n, sizeof(int), ComparePoint);
    ///printf("idx %d\n",bs(arr, n, 0));
    for (int i = 0; i < m;i++)
    {
        
        int cnt = 0;
        int u ;
        int l ;
        ///printf("%d\n", bs(arr, n, arr2[i]));
        if (bs(arr, n, arr2[i]) != -1)
        {
            u = upperbound(arr, n, arr2[i]);
            ///printf("u%d\n", u);
            l = lowerbound(arr, n, arr2[i]);
           ///printf("l%d\n", l);
            cnt = u - l;
        }
        else { cnt = 0; }
      
  
        
        printf("%d ", cnt);

    }
    return 0;
}
///1654
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


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
    int k, n;
    scanf("%d ", &k);
    scanf("%d", &n);
    int arr[10001];
    for (int i = 0; i < k;i++)
    {  
        scanf("%d", &arr[i]);
      
    }
    qsort((void*)arr, k, sizeof(int), ComparePoint);
    int cmax = 0;
    int cnt = 0;
    long long int left = 1;
    long long int right = arr[k-1];
    long long int mid = 0;
    int ans = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        cnt = 0;
        for (int i = 0;i < k;i++)
        {
            cnt = cnt + (arr[i] / mid);
        }
        if (cnt >= n)
        {
            left = mid+1;
            if (cmax < mid)
            {
                cmax = mid;
            }
        }
        else
        {
            right = mid-1;
        }
        ///printf("mid %d, cnt %d\n", mid, cnt);
        ///printf("l %d r %d\n", left, right);

    }

    printf("%d", cmax);


    return 0;
}
///2805
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

    int arr[1000001];

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
    int k, n;
    scanf("%d ", &k);
    scanf("%d", &n);
    for (int i = 0; i < k;i++)
    {  
        int d;
        scanf("%d", &d);
        arr[i] = d;
      
    }
    qsort((void*)arr, k, sizeof(int), ComparePoint);
    long long int cmax = 0;
    long long int cnt = 0;
    long long int left = 1;
    long long int right = arr[k-1];
    long long int mid = 0;
    
    while (left <= right)
    {
        mid = (left + right) / 2;
        cnt = 0;
        for (int i = 0;i < k;i++)
        {
            if (mid <= arr[i])
            {
                cnt = cnt + arr[i]-mid;
            }
        }
        if (cnt >= n)
        {
            left = mid+1;
            if (cmax < mid)
            {
                cmax = mid;
            }
        }
        else
        {
            right = mid-1;
        }
        ///printf("mid %d, cnt %d\n", mid, cnt);
        ///printf("l %d r %d\n", left, right);

    }

    printf("%d", cmax);


    return 0;
}


