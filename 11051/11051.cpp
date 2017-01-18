/*
 * 11051.cpp
 *
 */
/*
 1. 서칭하면서 map에 넣는다. (
 2.
 
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;
int dp[1001][1001];
const int mod = 10007;
int go (int n, int k ){
    if ( k==0 || n == k ){
        return 1;
    }
    int & ret =dp[n][k] ;
    if (ret !=-1) return ret ;
    
    ret = go ( n-1 , k-1 )%mod + go (n-1,k)%mod;
    
    return ret %mod;
}

int main(){
    int n , m;
    scanf("%d%d",&n,&m);
    memset (dp, -1, sizeof(dp));
    printf("%d\n",go(n,m));
}
