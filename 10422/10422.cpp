/*
 * 10422.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace  std;

typedef long long ll;
#define MOD 1000000007LL

ll d[5555];
ll go (int now ) {
    ll &ret = d[now];
    if ( now ==0 || now ==1){
        return ret =1 ;
    }
    if ( ret !=-1 ) return ret ;
    ret = 0 ;
    for (int i =0 ; i<= now-1; i++){
        ret = (ret + go(i)* go(now-1-i) )%MOD;
    }
    return ret ;   
}

int main(void)
{
    int tc;
    scanf("%d",&tc);
    while (tc--){
        memset (d,-1,sizeof(d));
        int n;
        scanf("%d",&n);
        ll ans ;
        n%2==0 ? ans= go(n/2) :  ans = 0;
        printf("%lld\n",ans);        
    }
}
