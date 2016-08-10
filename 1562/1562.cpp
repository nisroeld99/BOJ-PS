/*
 * 1562.cpp
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii> iii ;
typedef long long ll;
const int inf = 987654321;
const ll mod = 1000000000 ;

ll d[111][11][ (1<<10)+1 ];
int main(){
    int n ;
    scanf("%d",&n);
    d[1][0][1] = 0 ;
    for (int i =1; i<=9 ;i++ ){
        d[1][i][1<<i] =1 ;
    }
    for (int i =2 ; i<=n; i++ ){
        for (int j= 0; j< (1<<10) ;j++){
            d[i][0][j|(1<<0)]  += (d[i-1][1][j] %mod)%mod ;
            d[i][1][j|(1<<1)] += (d[i-1][0] [j]%mod +d[i-1][2][j]%mod)%mod;
            d[i][2][j|(1<<2)] += (d[i-1][1][j]%mod +d[i-1][3][j]%mod)%mod;
            d[i][3][j|(1<<3)] += (d[i-1][2][j] %mod+d[i-1][4][j] %mod)%mod;
            d[i][4][j|(1<<4)] += (d[i-1][3][j]%mod +d[i-1][5][j] %mod)%mod;
            d[i][5][j|(1<<5)] += (d[i-1][4][j]%mod +d[i-1][6][j] %mod)%mod;
            d[i][6][j|(1<<6)] += (d[i-1][5][j]%mod +d[i-1][7][j] %mod)%mod;
            d[i][7][j|(1<<7)] += (d[i-1][6][j]%mod +d[i-1][8][j] %mod)%mod;
            d[i][8][j|(1<<8)] += (d[i-1][7][j]%mod +d[i-1][9][j] %mod)%mod;
            d[i][9][j|(1<<9)] += (d[i-1][8][j] %mod);
        }
    }
    
    
    ll sum = 0;
    for (int i = 0 ; i <=9 ; i++){
        sum+= d[n][i][(1<<10)-1] %mod ;
    }
    cout << sum %mod << endl ;
    
}

