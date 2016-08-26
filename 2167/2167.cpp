/*
 * 2167.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int a[301][301];
int d[301][301];
int main() {
    
    int n , m ;
    cin >> n>>m;
    for (int i = 1 ; i<=n ; i++ ) {
        for (int j= 1 ;j<=m; j++){
            scanf("%d",&a[i][j]);
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + a[i][j] ;
        }
    }
    int k ;
    cin >> k  ;
    
    for (int i = 0 ; i<k ;i++ )
    {
        int a,b,c,dd;
        scanf("%d%d%d%d",&a,&b,&c,&dd);
        printf("%d\n" , d[c][dd] - d[a-1][dd] - d[c][b-1] + d[a-1][b-1] ) ;
    }
    
    
    return 0  ;
}
