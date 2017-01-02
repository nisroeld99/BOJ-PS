/*
 * 13900.cpp
 * 
 *  1. O(n ^2) 돌리면 TEL
 *  2. 배열을 파서 i번째 IDX까지의합을 미리 저장해놓음
 *  3. 자료형 주의 하기 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> ii ;
priority_queue<int> pq ;



long long a[100001];
long long sum_A[100001];
int main(){
    int n ;
    cin >> n;
    for (int i =0 ; i <n; i++){
        scanf("%lld",&a[i]);
        if ( i!=0 )
            sum_A[i] += a[i] + sum_A[i-1];
    }
    long long sum = 0 ;
    for (int i = 0 ; i<n; i++){
        sum+= a[i] * (sum_A[n-1] - sum_A[i]);
    }
        
    printf("%lld\n",sum);
}
