/*
 *  1074   
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll ;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;


ll go (ll n, ll r, ll c){
    if (n==0 )return 0;
    ll k = 1<<(n-1);
    if ( r < k){
        if ( c < k) return go(n-1,r,c);
        else return go(n-1,r,c-k) +k*k ;
    }
    else {
        if (c<k) return go(n-1,r-k,c)+k*k*2;
        else return go(n-1,r-k,c-k)+k*k*3;
    }
    
}


int main(){
    ll n,r,c;
    while (scanf("%lld%lld%lld",&n,&r,&c ) !=EOF){
        printf("%lld\n",go(n,r,c));
    }
    
    
}
