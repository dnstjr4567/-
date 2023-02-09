22234번(C#)
using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using System.IO.Pipes;

namespace bjex
{

    class Program
    {

        static void Main(string[] args)
        {
            int[] NTW = Array.ConvertAll(ReadLine().Split(), int.Parse);
            int N = NTW[0];
            int T = NTW[1];
            int W = NTW[2];
            int time = 0;
            StringBuilder sb = new StringBuilder();
            Queue<int> idq = new Queue<int>();
            Queue<int> timeq = new Queue<int>();
            List<(int,int)> list = new List<(int,int)> ();
            for(int i =0;i<N;i++)
            {
                int[] pt = Array.ConvertAll(ReadLine().Split(), int.Parse);
                list.Add((pt[0], pt[1]));
                idq.Enqueue(list[i].Item1);
                timeq.Enqueue(list[i].Item2);
            }
            int M = int.Parse(ReadLine());
            List<(int,int,int)> list2 = new List<(int,int,int)> ();
            for(int i =0;i<M;i++)
            {
                int[] ptc = Array.ConvertAll(ReadLine().Split(), int.Parse);
                list2.Add((ptc[0], ptc[1], ptc[2]));

            }
            
            List<(int, int, int)> list3 = list2.OrderBy(x => x.Item3).ToList();
            int j = 0;
            int ans = 0;
        
            while (true)
            {
                if (j < M && list3[j].Item3 == ans)
                {
                    idq.Enqueue(list3[j].Item1);
                    timeq.Enqueue(list3[j].Item2);
                    j++;

                }
                if (time == T)
                {
                    if (timeq.Peek() >= time)
                    {
                        int t = timeq.Dequeue();
                        t = t - T;
                        if (t == 0)
                        {
                            
                            idq.Dequeue();
                        }
                        else
                        {
                            timeq.Enqueue(t);
                            idq.Enqueue(idq.Dequeue());
                        }
                        time = 0;
                    }



                }
                else if (timeq.Peek() <= time)
                {

                    timeq.Dequeue();
                    idq.Dequeue();

                    time = 0;
                }



                //WriteLine($"time {time}");
                //WriteLine($"idq {idq.Peek()} tq{timeq.Peek()}");
                sb.Append(idq.Peek() +"\n");
                if (ans == W-1) { break; }
                ans++;
                time++;
               
                
            }
            WriteLine(sb.ToString());
        }
    }
}
13335번 (C)
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
int main()
{
	int truck[1001];
	int m,w,l;
    int cnt = 0,idx=1;
    int distance[1001], time = 0, weight = 0;
	scanf("%d %d %d", &m, &w, &l);
	
	for (int i = 0; i < m;i++)
	{
		int d;
		scanf("%d", &d);
	    truck[i] = d;
        distance[i] = 0;
        ///printf("truck %d, dist %d\n", truck[i], distance[i]);
	}
    int i = 0, j = 0;
    CircularQueue* bridge = NULL;
    CQ_CreateQueue(&bridge, m);
    while(1)
    {
        time++;
        
        if (distance[j] >=w)///여기서 해치웠다!!!!=이포인트
        {   
            weight -= CQ_Front(bridge);
            CQ_Dequeue(bridge);
            j++;
            cnt++;
        }
        if (truck[i] + weight <= l && CQ_GetSize(bridge)+1 <= w)///조건확인
        {
            CQ_Enqueue(bridge, truck[i]);
            weight += CQ_Back(bridge);
            if (i < m)
            {
                i++;
            }
        }
        for (int k = j;k< i;k++)///거리이동
        {
            distance[k]++;
        }
 
        if (cnt == m) { break; }

    }
    printf("%d", time);
	
	return 0;

}
1874번 (C)
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef int ElementType;

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
    return (Stack->Top + 1 == Stack->Capacity);

}


int main(void)
{
    int n,num=1;
    int j=0, idx = 0;
    ArrayStack* Stack = NULL;
    scanf("%d", &n);
    AS_CreateStack(&Stack, 100001);
    int *arr;
    char* ans;
    int d;
    arr = (int*)malloc(sizeof(int) * n);
    ans = (char*)malloc(sizeof(char) * n*2);
    for (int i = 0;i < n;i++)
    {
        scanf(" %d", &d);
        arr[i] = d;
       ///printf("arr[%d] : %d\n",i, d);
    }
    while (1 > 0)
    {
        AS_Push(Stack, num);
        ans[j] = '+';
        j++;
        while(AS_Top(Stack) == arr[idx])
        {
            AS_Pop(Stack);
            ans[j] = '-';
            j++;
            idx++;
            if (AS_IsEmpty(Stack)) { break; }
        }
         
        num++;
        
        if (AS_GetSize(Stack) > n||idx==n) { break; }
        
        
    }
    ///printf("%d %d", sizeof(arr), AS_GetSize(Stack));???
    if (AS_GetSize(Stack) > n)
    {
        printf("NO");
       
    }
    else
    {
        for (int i = 0;i < 2 * n;i++)
        {
            printf("%c\n", ans[i]);
        }
        
    }
    
    AS_DestroyStack(Stack);

    
    return 0;
}
15820번 (C#)
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using static System.Console;
namespace ddddd
{
    class Voca
    {
       public string spell;
       public string mean;
    }
    ///1번
    class MainApp
    {
        static void Main(string[] args)
        {
            int[] s12 = Array.ConvertAll(ReadLine().Split(), int.Parse);
            int s1 = s12[0];
            int s2 = s12[1];
            string ans = "";
            while(s1>0)
            {
                int[] test = Array.ConvertAll(ReadLine().Split(), int.Parse);
                
                if (test[0] == test[1] && s2 == 0) { ans ="Accepted"; }
                if (test[0] != test[1]) { ans = "Wrong Answer"; break; }
                s1--;
            }
            while (s2 > 0)
            {
                if (ans != "Wrong Answer")
                {
                    int[] test = Array.ConvertAll(ReadLine().Split(), int.Parse);
                    if (test[0] != test[1]) { ans = "Why Wrong!!!"; }
                    if (test[0] == test[1]&& ans != "Why Wrong!!!") { ans = "Accepted"; }
                }
                s2--;
            }
            WriteLine(ans);
        }
        
    }
}
14593번 (C#)
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using static System.Console;
namespace ddddd
{
    class Voca
    {
       public string spell;
       public string mean;
    }
    ///1번
    class MainApp
    {
        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());
            int maxs = 0;
            int maxc = 0;
            int maxl = 0;
            int ans = 0;
            for(int i =1;i<=n;i++) 
            {
                int[] scl = Array.ConvertAll(ReadLine().Split(), int.Parse);
                int s = scl[0]; 
                int c = scl[1];
                int l = scl[2];
                if (s > maxs)
                {
                    maxs = s;
                    maxc = c;
                    maxl = l;
                    ans = i;
                }
                else if (s == maxs)
                {
                    if(c<maxc)
                    {
                        maxs = s;
                        maxc = c;
                        maxl = l;
                        ans = i;
                    }
                    else if (c == maxc)
                    {
                        if(l<maxl)
                        {
                            maxs = s;
                            maxc = c;
                            maxl = l;
                            ans = i;
                        }
                    }
                }
                
            }
            WriteLine(ans);
            


        }
        
    }
}

트리 : 나무를 닮은 자료구조. 단순 순환을 갖지 않는 연결 비방향성 그래프

 

구성요소

뿌리(root) : 트리 자료구조의 가장 위에 있는 노드
가지(branch) : 뿌리와 잎 사이에 있는 모든 노드
잎(leaf) : 가지의 끝에 매달린 노드 (터미널 노드), 자식이 없는 노드
용어

부모 : 아래로 뻗어가는 노드가 있는 노드
자식 : 위로 뻗어가는 노드가 있는 노드
형제 : 같은 부모를 가진 노드
경로 : 한 노드에서 다른 한 노드까지 이르는 길 사이에 있는 노드들의 순서N
조상 : 루트로부터 그 정점에 이르는 경로상의 노드들
자손 : x의 자손은 x를 조상으로 갖는 모든 노드들
길이 : 경로의 속성. 출발 노드에서 목적지 노드까지 거쳐야하는 노드의 개수
깊이 : 루트에서 특정 노드까지 이르는 경로의 길이
레벨 : 깊이가 같은 노드의 집합
높이 : 루트에서 잎까지 경로중 가장 긴 경로의 길이
차수 : 특정 노드의 차수는 그 노드의 자식 노드 개수. 트리의 차수는 노드의 차수 중 가장 큰 것.
트리 표현 방법

중접된 괄호(Nested Parenthesis) : 같은 레벨의 노드를 괄호로 함께 묶어 표현하는 방법. 읽기 어렵지만 표현 이 쉬움 (A(B(C)D(E)(F)))(G(H))(I(J(K))))
중첩된 집합(Nested Set) : 트리가 하위 트리의 집합이라는 사실 표현 가능
들여쓰기(Indentation) : 자료의 계층적 특징 나타냄
노드 표현 방법

N-Link : 노드의 차수가 N이면 노드가 N개의 링크 갖고 링크가 각각 자식 노드를 가리키도록 구성. 차수가 다른 노드가 많으면 구현 어려움
왼쪽 자식-오른쪽 형제 : 왼쪽에 자식, 오른쪽에 형제에 대한 포인터만을 갖도록 노드 구성
트리의 기본 연산

노드 선언 : 데이터 담는 Data필드, 왼자 오형 가리키는 2개 포인터로 구성
생성 : malloc() 이용해 구조체 크기만큼 자유 저장소에 메모리 할당, 매개 변수 NewData를 Data에 저장, 노드의 메모리 주소 반환
 소멸 : free()
자식 노드 연결 : 부모 노드에게 자식 있는지 검사 -> 없다면 왼쪽 포인터에 자식 노드 주소 저장, 있다면 자식 노드중 오른쪽 포인터 NULL인 것 찾아서 주소 저장
트리 출력 : 들여쓰기 형식으로 출력
이진 트리(Binary tree) : 하나의 노드가 자식 노드 2개까지만 가질 수 있는 트리

종류

포화 이진 트리(Full Binary Tree) : 모든 노드 차수 2. 잎 노드 제외
완전 이진 트리(Complete Binary Tree) : 잎 노드들이 왼쪽부터 채워진 트리
높이 균형 트리(Height Balanced Tree) : 뿌리 기준으로 왼쪽 하위 트리와 오른쪽 하위 트리의 높이 차이가 2이하인 이진 트리
완전 높이 균형 트리(Completely Height Balanced Tree) : 왼쪽 오른쪽 높이 같은 이진 트리
이진 트리는 알고리즘의 뼈대가 되는 자료구조. 트리의 노드를 가능한 한 완전한 모습으로 유지해야 높은 성능 낼 수 있다.

 

이진 트리의 순회 

순회 : 트리 안에서 노드 사이를 이동하는 연산

전위 순회 : 뿌리-왼쪽 하위 트리-오른쪽 하위 트리 순으로 방문 
중위 순회 : 왼쪽 하위 트리-뿌리-오른쪽 하위 트리 순으로 방문
후위 순회 : 왼쪽 하위 트리-오른쪽 하위 트리-뿌리 순으로 방문
수식 트리 : 수식을 표현하는 이진 트리. 수식을 표현하는 이진 트리

피연산자는 잎 노드 -> 식 또는 수
연산자는 뿌리 또는 가지 노드
후위 순회로 계산
수식 트리 구축 방법

수식을 뒤에서부터 앞쪽으로 읽어나가며 토큰을 취한다
수식에서 제일 마지막에 있는 토큰으로 뿌리 노드를 생성, 후위 표기식에서 가장 마지막에 있는 토큰은 항상 연산자
읽어낸 토큰이 연산자인 경우 가지 노드를 생성하며 이 토큰 다음 2개의 토큰으로 각각 오른쪽 자식, 왼쪽 자식 노드 생성. 다음 토큰도 연산자인 경우 이 토큰에서 만들어지는 하위 트리가 완성된 이후에 읽어낸 토큰으로 왼쪽 자식 노드를 생성
읽어낸 토큰이 숫자인 경우 잎 노드를 생성
분리 집합

집합 : 특정 조건에 맞는 원소의 모임

분리 집합 : 교집합을 갖지 않는 복수의 집합. 서로 공통된 원소가 없는 집합

어느 집합에 소속되어 있는가 라는 정보 바탕으로 무언가 하는 알고리즘에 응용

원소가 어느 집합에 귀속되어 있는지 쉽게 알아내기 위한 목적

분리 집합 표현

자식이 부모를 가리킴, 뿌리 노드는 집합 그 자체, 뿌리 노드 자신을 포함한 트리 내의 모든 노드는 그 집합에 소속

 
