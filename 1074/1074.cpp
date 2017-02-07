/*
 * 1074.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>

using namespace  std;


int solve (int n, int r, int c){
    if ( n == 0 ) return 0 ;
    int k = (1<<(n-1));
    if ( r<k){
        if ( c <k) return solve ( n-1 , r,c );
        else return solve (n-1, r,c-k) + k*k ;
    }else {  // r 줄여줘야함
        if ( c<k ) return solve (n-1,r-k,c) + k*k*2;
        else  return solve (n-1,r-k, c-k) +k*k*3;
    }
    
}


int main(void){
    /*
       모든 경우는 항상 4등분되어 결과가 나타남
       이러한 규칙을 이용해 재귀적인 방법으로 해결한다.
     */
    
    int n , r, c;
    while (scanf("%d%d%d",&n,&r,&c) != EOF  )
        printf("%d\n",solve(n,r,c));
}
