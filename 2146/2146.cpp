/*
 * 2146.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii ;
int g[111][111];
int n ;
int islCnt = 2 ;
int dab = 99999999;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};
void go ( int ypos , int xpos ) {
    
    g[ypos][xpos] = islCnt   ;
    for (int i = 0 ; i<4 ; i++  ) {
        int ny = ypos + dy[i];
        int nx = xpos + dx[i] ;
        if (ny <1 || nx < 1 || ny >n || nx > n ) continue ;
        if (g[ny][nx] == islCnt ) continue ;
        if (g[ny][nx] == 0 ) continue;
        g[ny][nx] = islCnt;
        go(ny,nx) ;
    }
}
queue <ii>q ;
int d[111][111];
bool c[111][111];
void go2 (int sy, int sx ) {
    memset (d, 0 ,sizeof(d)) ;
    memset (c, false ,sizeof(c)) ;
    int start = g[sy][sx] ;
    q.push (ii(sy,sx));
    d[sy][sx] = 0 ;
    bool out = false ;
    while (!q.empty() ) {
        if (out)break ;
        int y = q.front().first ;
        int x= q.front().second;
        q.pop() ;
        if (c[y][x] ) continue;
        c[y][x] = true;
        for (int i = 0 ; i< 4  ;i ++ ) {
            int ny = y + dy[i] ;
            int nx = x + dx[i];
            if (ny <1 || nx < 1 || ny > n || nx > n || c[ny][nx] ) continue ;
            if (g[ny][nx]==start   ) continue ;
            if (g[ny][nx]) {
                dab = min ( dab , d[y][x] ) ;
                out = true ; 
                break;
            }
            q.push({ny,nx});
            d[ny][nx] = d[y][x] +1 ;
        }
    }
    while (!q.empty()){
        q.pop() ;
    }
}
int main() {
    
    cin >> n;
    for (int i = 1 ; i<= n; i ++ ) {
        for (int j =1 ; j<=n ;j ++ ) {
            scanf("%d",&g[i][j] ) ;
        }
    }
    for (int i =1 ; i<=n ; i++ ) {
        for (int j=1 ; j  <=n ;j++ ){
            if (g[i][j] ==1) {
                go (i,j) ;
                islCnt ++ ; 
            }
        }
    }
    
    for (int i =1 ; i<=n ; i++ ) {
        for (int j=1 ;j<=n ;j++ )
        {
            if (g[i][j] != 0 )
                go2 (i,j) ;
        } 
    }
    for (int i =1 ; i<=n ; i++ ) {
        for (int j=1 ;j<=n ;j++ )
        {
            printf("%d ",d[i][j]);
        }printf("\n");
    }
    
    cout << dab << endl;
    
    return 0  ;
}

