/*
 * 10026.cpp
 *
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n ;
char temp[101][101];
bool visited[101][101];
char a[101][101];
int dy[4]= {0,0,1,-1}, dx[4] ={1,-1,0,0};
int cnt = 0 ;
void solve (int ypos, int xpos , int delta ){
    
    if ( visited[ypos][xpos] )return ;
    visited[ypos][xpos]=true;
    
    for (int i = 0 ; i<4; i++){
        int ny = ypos + dy[i] ;
        int nx = xpos + dx[i] ;
        if ( ny < 1 || nx < 1 || ny> n || nx > n ) continue;
        
        if ( a[ny][nx] == a[ypos][xpos] ) {
            solve(ny,nx,delta);
        }
        if ( delta == 2 && (( a[ny][nx] =='G'&& a[ypos][xpos] =='R') || (a[ny][nx] =='R' && a[ypos][xpos] =='G') ) ){
            solve (ny,nx,delta) ;
        }
        
    }
    
}

int main() {
    
    
    scanf("%d",&n);
    
    for (int i =1; i<=n; i++){
        for (int j=1 ;j<=n;j++){
            cin >> a[i][j] ;
            temp[i][j] = a[i][j] ;
        }
    }
    
    for (int i = 1; i<=n; i++){
        for (int j=1 ;j<=n; j++){
            if ( visited[i][j] ==false  ){
                cnt ++ ;
                solve (i,j,1 );
            }
        }
    }
    printf("%d ",cnt ) ;
    
    for (int i =1; i<=n; i++){
        for (int j=1 ;j<=n;j++){
            a[i][j] = temp[i][j] ;
        }
    }
    
    memset (visited, false, sizeof(visited));
    cnt = 0 ;
    for (int i = 1; i<=n; i++){
        for (int j=1 ;j<=n; j++){
            if ( visited[i][j] == false  ){
                cnt ++ ;
                solve (i,j,2 );
            }
        }
    }
    printf("%d ",cnt ) ;
    
    return 0  ;
}

