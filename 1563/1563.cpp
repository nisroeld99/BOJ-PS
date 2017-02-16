#include <cstdio>
#include <cstring>
using namespace std ;
const int mod= 1000000;
int cache[1111][4][4] ; // cache[n][결석][지각]
int n ;

int go (int day, int abs, int late){
    if ( day >n || abs>= 3 || late >= 2 ) return 0 ;
    if (day ==n) return 1;
    int &ret = cache[day][abs][late] ;
    
    if (ret > 0 )return ret ;
    
    ret += go (day+1, 0,late)%mod;
    ret += go (day+1, abs+1, late)%mod;
    ret += go (day+1, 0, late+1 )%mod;
    
    return ret%mod ;
}

int main()
{
    
    scanf("%d",&n);
    memset (cache,0,sizeof(cache));
    printf("%d\n",go (0,0,0));
}
