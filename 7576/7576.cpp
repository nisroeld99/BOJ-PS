/*
 * 7576.cpp
 *
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii ;
int g[1001][1001];
int d[1001][1001];
int dy [4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1} ;
queue<ii>q;
int main() {
    
    int m,n ; // x, y축
    cin >> m>> n;
    bool cc =false  ;
    
    for (int i =1 ; i<=n ;i++ ){
        for (int j=1; j<=m ;j++ ){
            
            scanf("%d",&g[i][j] ) ;
            if (g[i][j]  == 1 ) {
                cc= true ;
                q.push(ii(i,j));
            }
            
        }
    }
    if (cc == false ){
        printf("0\n");
        return 0 ;
    }
    
    while (!q.empty()) {
        ii temp =q.front() ;
        q.pop() ;
        int y = temp.first ;
        int x=  temp.second ;
        g[y][x] = 1;
        for (int i = 0 ; i< 4 ; i++ )
        {
            int ny = y + dy[i];
            int nx = x + dx[i] ;
            if (ny < 1 || nx <1 || ny > n || nx > m  ) {
                continue;
            }
            if ( g[ny][nx] == 1|| g[ny][nx] ==-1  ) continue ;
            d[ny][nx] = d[y][x] + 1 ;
            q.push (ii (ny,nx));
            
        }
    }
    int dab = -1 ;
    bool c = false ;
    for (int i =1 ; i<=n ; i++ ){
        for (int j=1 ;j<=m ;j++ ) {
            if (g[i][j] == 0 ){
                c= true ;
                break;
            }
            dab = max ( d[i][j] , dab ) ;
        }
    }
    if (c) {
        cout << "-1\n"<<endl;
    }else
        cout <<dab << endl ;
    
    return 0  ;
}

