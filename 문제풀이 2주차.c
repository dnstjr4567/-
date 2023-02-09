///스택 문제 
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef int ElementType;
///10828
typedef struct tagNode
{
    ElementType Data;
} Node;

typedef struct tagArrayStack
{
    int   Capacity;
    int   Top;
    Node* Nodes;
} ArrayStack;

void        AS_CreateStack(ArrayStack** Stack, int Capacity);
void        AS_DestroyStack(ArrayStack* Stack);
void        AS_Push(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop(ArrayStack* Stack);
ElementType AS_Top(ArrayStack* Stack);
int         AS_GetSize(ArrayStack* Stack);
int         AS_IsEmpty(ArrayStack* Stack);
int         AS_IsFull(ArrayStack* Stack);

#endif


void  AS_CreateStack(ArrayStack** Stack, int Capacity)
{
    //  스택을 자유 저장소에 생성 
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    //  입력된 Capacity만큼의 노드를 자유 저장소에 생성 
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

    //  Capacity 및 Top 초기화 
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack)
{
    //  노드를 자유 저장소에서 해제 
    free(Stack->Nodes);

    //  스택을 자유 저장소에서 해제 
    free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data)
{
    Stack->Top++;
    Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack)
{
    int Position = Stack->Top--;
    return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)
{
    return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
    return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack)
{
    return (Stack->Top == -1);
}
int AS_IsFull(ArrayStack* Stack)
{
    if (Stack->Top == Stack->Capacity)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int main(void)
{
    int n,i=0,l;
    char* input[20];
    ArrayStack* Stack = NULL;
    scanf("%d", &n);
    AS_CreateStack(&Stack, n);
    while (n >0)
    {
        scanf("%s", &input);
        if (strcmp(input, "push") == 0)
        {
            int d;
            scanf("%d", &d);
            AS_Push(Stack, d);
        }
        else if (strcmp(input, "pop") == 0)
        {
            if (AS_IsEmpty(Stack)) { printf("-1\n"); }
            else { printf("%d\n", AS_Pop(Stack)); }
        }
        else if (strcmp(input, "size") == 0)
        {
            
            printf("%d\n", AS_GetSize(Stack)); 
        }
        else if (strcmp(input, "empty") == 0)
        {
            if (AS_IsEmpty(Stack))
            {
                printf("1\n");
            }
            else { printf("0\n"); }
        }
        else if (strcmp(input, "top") == 0)
        {
            if (AS_IsEmpty(Stack)) { printf("-1\n"); }
            else { printf("%d\n", AS_Top(Stack)); }
        }
        
        n--;
    }
    AS_DestroyStack(Stack);

    return 0;
}



10773번

int main(void)
{
    int n, sum=0,input,i,k;
    ArrayStack* Stack = NULL;
    scanf("%d", &n);
    k = n;
    AS_CreateStack(&Stack, n);
    while (n > 0)
    {
        scanf("%d", &input);
        if (input != 0)
        {
            AS_Push(Stack, input);
        }
        else
        {
            AS_Pop(Stack);
            ///printf("top : %d\n", AS_Top(Stack));
        }
        n--;
    }
    for(int j = 0;j<k;j++)
    {
        
        if(Stack->Top==-1)
        {
            break;
        }
        i = AS_Pop(Stack);
        sum =sum + i ;
       
    }
    
    printf("%d", sum);
    return 0;
}

///큐 문제풀이
///18258번
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
#endif

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
    return Queue->Nodes[Queue->Rear-1].Data;
}
int main()
{
    int n;
    char* input[20];
    CircularQueue* queue;
    scanf("%d", &n);
    CQ_CreateQueue(&queue, n);
    while (n>0)
    {
        scanf("%s", &input);
        if (strcmp(input ,"push")==0)
        {
            int d;
            scanf("%d", &d);
            CQ_Enqueue(queue, d);
        }
        else if (strcmp(input, "pop") == 0)
        {
            int d;
            scanf("%d", &d);
            if (CQ_IsEmpty(queue)) { printf("-1\n"); }
            else { printf("%d\n",CQ_Dequeue(queue)); }
        }
        else if (strcmp(input, "size") == 0)
        {

            printf("%d\n", CQ_GetSize(queue));
        }
        else if (strcmp(input, "empty") == 0)
        {
            if (CQ_IsEmpty(queue))
            {
                printf("1\n");
            }
            else { printf("0\n"); }
        }
        else if (strcmp(input, "front") == 0)
        {
            if (CQ_IsEmpty(queue)) { printf("-1\n"); }
            else { printf("%d\n", CQ_Front(queue)); }
        }
        else if (strcmp(input,"back")==0)
        {
            if (CQ_IsEmpty(queue)) { printf("-1\n"); }
            else { printf("%d\n", CQ_Back(queue)); }
        }

        n--;
    }

    return 0;
}
///2164번
int main()
{
    char* input[20];
    CircularQueue* queue;
    int n, cnt=0;
    scanf("%d", &n);
    CQ_CreateQueue(&queue, n);
    for (int i = 1;i <= n;i++)
    {
        CQ_Enqueue(queue, i);
    }
    while (CQ_GetSize(queue)>1)
    {
        int x = CQ_Dequeue(queue);
        int y = CQ_Dequeue(queue);
        CQ_Enqueue(queue, y);
        if (CQ_GetSize(queue) == 1)
        {
            printf("%d", CQ_Dequeue(queue));
            break;
        }
    }
    if(CQ_GetSize(queue)==1)
        printf("%d", CQ_Dequeue(queue));

    return 0;
}
///11866번
int main()
{
    int n,k,cnt=0;
    char* input[20];
    CircularQueue* queue;
    scanf("%d %d", &n,&k);
    CQ_CreateQueue(&queue, n);
    printf("<");
    for (int i = 1;i <= n;i++)
    {
        CQ_Enqueue(queue, i);
    }
    while (!CQ_IsEmpty(queue))
    {
        cnt++;
        int x = CQ_Dequeue(queue);
        if (cnt == k)
        {
            if (CQ_IsEmpty(queue))
            {
                printf("%d", x);
            }
            else
            {
                printf("%d, ", x);
            }
            cnt = 0;
        }
        else
        {
            CQ_Enqueue(queue, x);
        }

    }
    printf(">");

    return 0;
}

연결 리스트
연결 리스트
노드를 연결해서 만든 리스트.
노드는 데이터를 보관하는 필드(data), 다음 노드와 연결 고리 역할을 하는 포인터(다음 노드의 data가 있는 주소를 저장)로 이루어짐
첫 번째 노드를 헤드, 마지막 노드를 테일. 노드를 연결하면 링크드 리스트
주요 연산
노드 생성 : 자유 저장소(malloc)이용하여 생성
노드 추가 : 노드를 리스트에 추가. 생성된 노드의 주소를 기존의 노드의 포인터에 추가
노드 탐색 : 헤드에서 시작해 다음 노드를 차례로 이동하여 원하는 요소에 접근
노드 삭제 : 노드를 리스트에서 제외하는 연산
노드 삽입 : 기존 노드 중 넣고자 하는 부분 앞의 노드의 포인터를 삽입하고자 하는 노드의 데이터 주소로 저장, 삽입된 부분 다음 노드의 데이터를 삽입한 노드의 포인터에 저장
노드 소멸 : 노드를 메모리에서 없애는 연산
링크드 리스트 장단점
단점 : 특정 노드 접근하기 위한 비용이 크고, 시간이 많이 소요됨.
장점 : 노드의 추가, 삽입, 삭제 연산은 빠름.
싱글 링크드 리스트 : 단방향으로만 이동 가능(헤드->테일) 노드가 (필드 포인터)-(필드 포인터)
더블 링크드 리스트 : 양방향으로 이동 가능 노드가 (포인터 필드 포인터)-(포인터 필드 포인터)
연산시 노드의 양쪽 포인터 변경 필요
환형 링크드 리스트 : 테일의 포인터가 헤드의 필드주소를 가리키는 것.
스택
데이터를 쌓아 올리는 구조
데이터 입/출력을 최상단에서만 진행
후입선출 구조
자동 메모리가 스택을 기반으로 동작
순서가 보존되는 선형 데이터 구조 유형
장점 : 동적인 메모리 크기, 데이터를 받는 순서대로 정렬, 바른 런타임
단점 : 가장 최신 요소만 가져옴, 한번에 하나의 데이터만 처리 가능
생성시 노드는 데이터만 담는다. 포인터 필요없다.
배열 기반 스택
구조체에 필요한 필드는 용량(capacity), 최상위 노드의 위치(top), 노드 배열(Nodes)
기능
삽입 Push : 새로운 노드를 배열에 쌓는다. 최상위 노드의 위치 최신화한다(+1).
제거 Pop : 최상위 노드를 제거 및 데이터를 호출자에 반환, top--,
확인 Peek : 최상위 노드를 반환만 함. 제거안함.
연결 리스트 기반 스택
스택 용량에 제한 두지 않아도 된다.
노드 구조는 데이터와 자신 위에 위치하는 노드의 주소 갖는 포인터로 이루어짐.
구조체에 링크드 리스트의 헤드,테일(top)포인터 필요.
노드 삽입 : 스택의 최상위 노드 top에 새 노드를 얹도록 구현.
노드 제거 : 현재 top주소를 다른 포인터에 복사-> 새 top의 바로 아래 노드 찾기->기존 top 필드에 새로운 최상위 노드 주소 등록->복사해 놓은것 반환
큐
선입선출 구조.
입력 출력 다른 곳에서 수행.
순서가 보존되는 선형 데이터 구조
동적 메모리크기, 데이터를 받는 순서대로 정렬, 빠른 런타임
가장 오래된 요소만 가져옴, 한번에 하나의 데이터만 처리 가능
삽입은 후단(테일), 제거는 전단(헤드)
순환 큐
배열 기반으로 배열 을 원처럼 생각
구조체에 용량, 전단의 위치(Front), 후단의 위치(Rear), 요소의 배열에 대한 포인터
장점-빠른 연산 가능
링크드 큐
각 노드는 이전 노드에 대한 포인터를 이용해 연결.
삽입시 삽입 하려는 노드에 후단을 연결,
제거시 전단 바로 다음 노드에서 전단에 대한 포인터 제거
장점-용량 제한이 없다
주요 기능
삽입 Enqueue : 기존의 후단 뒤에 삽입. 후단의 위치 수정
제거 Dequeue : 기존의 전단의 데이터 제거, 전단의 위치 수정

