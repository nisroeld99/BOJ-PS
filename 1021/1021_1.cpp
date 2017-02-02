/*
 * 1021_1.cpp
 *
 */
#include <cstdio>
#include <cstring>

int N,M;
int L[51];
int Check[51];
int que[51];
int cnt;

int main()
{
    scanf("%d %d",&N,&M);
    for(int i = 1 ; i <= M ; i++)
    {
        scanf("%d",&L[i]);
        que[L[i]] = i;
    }
    
    cnt = 0;
    int pos = 1; /* 현재 위치를 나타내는 변수 */
    int i = 1;   /* 현재 선택해야할 숫자의 순번 */
    while(true)
    {
        int op2_cnt = 0; /* 2번 연산의 수를 저장하는 변수 */
        int op3_cnt = 0; /* 2번 연산의 수를 저장하는 변수 */
        int cur; /* op2, op3을 실행해보며  위치를 계산하기 위한 임시 변수 */
        
        cur = pos; /* 현재 위치를 임시 위치 변수에 할당 */
        /* op2로 이번에 찾아야 하는 숫자를 찾아가는 횟수 계산 */
        while(cur != L[i]) {
            cur++;if(cur > N) cur = 1;
            if(que[cur] != -1)
                op2_cnt++;
        }
        
        cur = pos; /* 현재 위치를 임시 위치 변수에 할당 */
        /* op3로 이번에 찾아야 하는 숫자를 찾아가는 횟수 계산 */
        while(cur != L[i]) {
            cur--;
            if(cur < 1)
                cur = N;
            if(que[cur] != -1)
                op3_cnt++;
        }
        
        
        /* 두 연산중 적은 수의 연산을 선택하여 답에 누적 */
        if(op2_cnt < op3_cnt) cnt += op2_cnt;
        else cnt += op3_cnt;
        
        /* 만약 M개를 선택했다면 break */
        if(i == M)break;
        
        pos = cur; /* 현재 위치를 갱신 */
        que[pos++] = -1; /* pop연산으로 빠진 숫자를 표시 */
        
        if(pos > N) pos = 1; /* 회전하는 큐이므로 현재 위치를 보정 */
        
        while(que[pos] == -1) /* 현재 자리가 비어있는 위치라면 위치 변경 */ 
        {
            pos++;
            if(pos > N) pos = 1;
        }
        i++; /* 다음 선택해야할 숫자 인덱스 */ 
    }
    printf("%d\n",cnt);
    
}

