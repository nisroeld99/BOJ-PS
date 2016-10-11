/*
 * 2780.cpp
 *
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
const int mod = 1234567;
int d[10][1001];

int main(){
    int tc;
    cin >> tc;
    
    for (int i =0 ; i<10 ; i++)
        d[i][1]= 1;
    for (int i =2; i<=1000 ;i ++){
        d[1][i] = (d[2][i-1] +d[4][i-1])%mod;
        d[2][i]= (d[1][i-1] +d[3][i-1] +d[5][i-1])%mod;
        d[3][i] =(d[ 2][i-1] + d[6][i-1])%mod;
        d[4][i] = (d[1][i-1] +d[5][i-1] +d[7][i-1])%mod ;
        d[5][i] =(d[2][i-1] + d[4][i-1]+d[8][i-1] + d[6][i-1])%mod;
        d[6][i] =( d[3][i-1]+ d[5][i-1] +d[9][i-1])%mod;
        d[7][i]= (d[4][i-1]+d[8][i-1] +d[0][i-1])%mod;
        d[8][i]= (d[5][i-1]+d[7][i-1] +d[9][i-1])%mod;
        d[9][i]= (d[6][i-1] + d[8][i-1])%mod;
        d[0][i] =(d[7][i-1])%mod;
    }
    
    while (tc--){
     
        int n ;
        scanf("%d",&n);
       
        int ans = 0 ;
        for (int i = 0 ;i<10 ; i++){
            ans += d[i][n];
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    
}
