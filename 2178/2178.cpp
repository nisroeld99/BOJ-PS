/*
 *  2178
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> ii ;
int g[111][111];
bool c[111][111];
int d[111][111];
queue<ii> q;
int dy[4] = {1,-1,0,0};
int n , m ;
int dx[4] = {0,0,1,-1};
void go (int ypos, int xpos ){
    q.push(ii(ypos,xpos));
    d[1][1] = 1;
    c[1][1]=true;
    while (!q.empty() ){
        ii temp = q.front();  q.pop();
        int now_y=temp.first;
        int now_x=temp.second;
        
        for (int i = 0 ; i<4 ; i++ ){
            int next_y = now_y + dy[i] ;
            int next_x = now_x + dx[i] ;
            if ( g[next_y] [next_x]==0 || next_y <1 || next_x <1 || next_y > n || next_x > m )continue ;
            if (c[next_y][next_x] )continue ;
            c[next_y][next_x ] =true ;
            d[next_y][next_x]= d[now_y] [now_x ] +1 ;
            q.push(ii(next_y, next_x ));
        }
    }
    

}

int main() {
   
    cin >> n >> m;
    for (int i =1 ; i<=n ; i++ )
        for (int j=1 ;j<=m; j++ ){
            scanf("%1d",&g[i][j]);
        }
    
    go(1,1);

    
    cout << d[n][m] << endl;
}
