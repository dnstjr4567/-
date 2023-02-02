조건문
2884번
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace bjex
{
     
class Program
    {
        
        static void Main(string[] args)
        {
            int[] hm = Array.ConvertAll(ReadLine().Split(), int.Parse);
            int h = hm[0];
            int m = hm[1];
            if (m - 45 < 0)
            { 
                m = 60 + m - 45;h = h - 1;
                if (h < 0) { h = 24 + h; }
            }
            else { m = m - 45; }
            WriteLine($"{h} {m}");
        }

            
    }

}
2525번
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using System.Numerics;


namespace Ex
{
    class MainApp
    {

        static void Main()
        {
            int[] HM = Array.ConvertAll(ReadLine().Split(), int.Parse);
            int H = HM[0];
            int M = HM[1];
            int time = int.Parse(ReadLine());
            int minute = M + time;
            if (minute < 60) { WriteLine($"{H} {M + time}"); }
            else if(time+M >= 60) 
            {
                H = H + (minute / 60);
                if (H > 23) { H = H - 24; }
                minute = minute % 60;
                WriteLine($"{H} {minute}");
            }
        }
    }
}


반복문
2439번
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace ConsoleApp37
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            for (int i = 1; i <= n; i++)
            {
                for (int j = n; j >i; j--)
                {
                    Write(" ");
                }
                for (int j = 0; j < i; j++)
                {
                    Write('*');
                }
                
                WriteLine();
            }
            

        }
    }
}
1110번
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 백준
{
    class MainApp
    {
        static void Main()
        {
            int i = int.Parse(ReadLine());
            int cnt = 1;
            int sum = 0;
            int n = i / 10 + i % 10;
            sum = i % 10*10 + n % 10;
            if (i == 0) { cnt = 0; }
            while (true)
            {
                
                sum = (sum / 10 + sum % 10) % 10 + sum % 10 * 10;
                cnt++;
                if (sum == i) { break; }
            }
            WriteLine(cnt);
        }
    }
}
기본 수학 단계
2839번
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Ex
{
    class MainApp
    {

        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());
            int ans = 0;
            
            
            
                for(int i = 0; i < N/3+1; i++)
                {

                    if (ans == N) {  break; }
                    for (int j = 0; j < N/5+1; j++)
                    {
                        ans = 3 * i + 5 * j;
                        if(ans == N) { WriteLine(i + j); break; }
                    }
                    

                }
            if (ans != N) { WriteLine(-1); }

            
            
        }
    }  } 
    1193번
    class Program
{
    static void Main(string[] args)
    {
        string X = Console.ReadLine();
        int x = int.Parse(X);

        int lineCount = 0;
        int sum = 0;

        // 몇번째 대각선에 있는지 계산
        while (x > sum)
        {
            lineCount++;
            sum += lineCount;
        }

        // 해당 줄에 몇번째인지 계산
        int index = x - (sum - lineCount);

        // 홀수
        if (lineCount % 2 == 1)
            Console.Write($"{lineCount - index + 1}/{index}");
        // 짝수
        else
            Console.Write($"{index}/{lineCount - index + 1}");
    }
}
1차원 배열 단계
4344번
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


    
int main()
{
    int num[1000], n, TC, sum;
    float avg, ans,cnt;
    scanf("%d", &TC);
    while (TC > 0)
    {
        sum = 0;
        cnt = 0;
        scanf("%d", &n);
        for (int i = 0;i < n;i++)
        {
            scanf("%d", &num[i]);
            sum = sum + num[i];
        }
        avg = sum / (float)n;
       
        for(int i = 0; i<n;i++)
        {
            if (num[i] > avg) { cnt++; }
        }
        printf("%.3f%% \n", (cnt / n)*100);
        TC--;
    }
    return 0;
}
10818번
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int num[1000000];
int main()
{
    int n, min = 1000000, max = -1000000;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
   
    for (int i = 0; i < n;i++)
    {
        if (num[i] >= max) { max = num[i]; }
        if (num[i] <= min) {min = num[i]; }
    }
    printf("%d %d", min, max);
    return 0;
}
알고리즘
1-1. 알고리즘이란?

어떤 문제를 풀기 위한 단계적 절차.
어떠한 행동을 하기 위해서 만들어진 명령어들의 유한집합
유한 시간 내에 특정 문제를 해결하기 위한 일련의 순차적인 계산 / 풀이 절차, 실행의 집합
수학이나 컴퓨터과학에서 말하는 알고리즘은 문제를 풀기 위한 반복적인 진행 절차를 의미
알고리즘을 구현한다는 것은 프로그래밍 언어를 이용해서 문제 풀이 절차를 실제로 동작하는 코드로 작성한다는 의미
1-2. 알고리즘의 특징

입력 : 0 또는 그 이상의 외부에서 제공된 자료가 존재
출력 : 최소 한 개 이상의 결과
명확성 : 알고리즘의 각 단계는 명확하여 애매함이 없어야 함
유한성 : 알고리즘은 단계들을 유한한 시간 안에 정확하게 수행할 수 있을 정도로 충분히 단순해야함
일반성 : 정의된 입력들에 의해 일반적으로 적용할 수 있어야 함
타당성 : 구현할 수 있고 실용적이어야 함
1-3. 알고리즘 구성 요소

Sequence : 순차적으로 프로그램 코드를 수행
Decision : 특정 조건에 따라 수행을 다르게 함
Repetition : 수행을 1회 이상 반복
1-4. 알고리즘 평가

컴퓨터에서는 시간과 메모리라는 두 자원을 얼마나 소모하는지가 효율성의 중점
시간복잡도 : 절대적인 실행시간을 나타내는 것이 아닌 알고리즘을 수행하는 데 연산들이 몇 번 이루어지는지를 숫자로 표기
-> 여기서 연산의 종류는 산술, 대입, 비교, 이동을 뜻함
-> 빅오 표기법(big-O notation)
자료구조와 배열
2-1. 자료구조란?

컴퓨터가 데이터를 효율적으로 다룰 수 있게 도와주는 데이터 보관 방법과 데이터에 관한 연산의 총체
데이터 값의 모임, 데이터 간의 관계, 데이터에 적용할 수 있는 함수나 명령을 의미
효율적인 알고리즘을 위한 핵심
자료구조에 따라 애플리케이션 성능이 달라짐
단순 자료구조와 복합 자료구조로 구분
복합 자료구조는 선형과 비선형으로 구분
선형 자료구조-배열, 링크드 리스트, 스택, 큐, 힙
비선형 자료구조-트리, 그래프
2-2. 자료구조의 특징

효율성 : 효율적인 데이터의 관리 및 사용->적절한 자료구조 선택한다면 데이터 처리 효율 상승
추상화 : 복잡한 자료, 모듈, 시스템 등으로부터 핵심적인 개념만 간추려내는 과정->문제의 복잡성을 제어하고 코드 관리를 용이하게 함
재사용성 : 자료구조를 설계할 때 특정 프로그램에서만 동작하게 설계하지 않음->다양한 프로그램에서 동작할 수 있도록 범용성있게 설계
2-3. 배열(Array)

가장 기본적인 데이터 구조
생성시 설정된 셀의 수가 고정
각 셀에는 인덱스 번호가 부여, 이를 통해 셀 안에 데이터에 접근
장점 : 바로 만들어서 활용하기 쉬움
더 복잡한 자료구조의 기초가 될 수 있음,
원하는 데이터를 효율적으로 탐색
단점 : 데이터를 저장 할 수 있는 메모리 크기가 고정
데이터 추가 / 삭제 방법이 비효율적
구조 재구성 시 정렬하는 방식이 비효율적
