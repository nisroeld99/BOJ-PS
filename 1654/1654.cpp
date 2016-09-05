/*
 * 1654.cpp
 *
 */
 
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
long long a[10001];
 
long long n,k ; 
 
bool check(long long mid){
    int sum  = 0  ;
    for (int i =1;  i<= k; i++ ) {
        sum+=(a[i] / mid);
    }
    if (sum >= n) return true ;
    else return false ;
}
 
int main() {
     
  
    scanf("%lld%lld",&k,&n) ;
 
    for (int i = 1;  i<=k ; i++ ){
        scanf("%lld",&a[i] ) ;      
    }
    sort(a+1 ,a+k + 1 ) ;
    long long s = 0 ; long long  e = (1<<31)-1 ;
    long long ans = -1000000;
    while ( s<= e) {
        long long mid = (s+e)   /2 ;
        if (check(mid) ) {//길이를 늘려도됨
            ans = max (ans, mid) ; 
            s=mid+1;
        }else {// 길이를 줄여야함
            e= mid-1; 
        }
    }
     
    printf("%lld", ans ) ;
 
 
    return 0  ;
}
