/*
 * 1722.cpp
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long ;


ll fact[21] = {1};
bool used[21] ;
int main(){
    ll n;
    scanf("%lld",&n);
    
    for (int i = 1 ; i <=n; i++){
        fact[i] = fact[i-1] * i ;
    }
    
    
    int m ;
    scanf("%d",&m);
    
    
    switch (m) {
        case 1:
            ll now ;
            scanf("%lld",&now);
            
            for (ll i = 1 ; i<= n; i++){  //자리 check
                
                for (ll j= 1 ; j<= n; j++){
                    if ( used[j] )continue;
                    
                    if ( fact[n-i] < now ){
                        now-= fact[n-i];
                    }else {
                        printf("%lld ",j);
                        used[j] = true ;
                        break;
                    }
                }
            }
            printf("\n");
            break;
        case 2:
            ll ans = 1 ;
            for (ll i = 1;  i<=n ; i++){ //자리 check
                
                ll now ;
                scanf("%lld",&now) ;
                used [now] =true ;
                for (ll j= 1 ;j<now ; j++ ){
                    if ( used[j ]) continue;
                    ans += fact[n-i];
                }
            }
            printf("%lld\n",ans);
            break;
            
        
    }
}

