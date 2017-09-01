#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int>ii;

const int mod = 10007;
int main() {
    int n, k ;
    int d[1111][1111];
    
    scanf("%d%d",&n,&k);
    
    for( int i =0; i<=n; i++){
        d[i][i] = 1;
        d[i][0] = 1;
    }
    
    for (int i = 1; i<=n; i++){
        for (int j=1 ;j<=k; j++){
            d[i][j] = d[i-1][j-1] + d[i-1][j];
            d[i][j] %=mod;
        }
    }
    
    printf("%d\n", d[n][k] %mod );
}
