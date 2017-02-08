/*
 * 2468.cpp
 *
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int>ii;

int n ;
int g[111][111];
bool temp [111][111];
int ans =1;

int dy[4] ={1,-1,0,0}, dx[4]={0,0,-1,1};
queue<ii>q;
void go (int ypos,int xpos){ //bfs로 구현
    temp[ypos][xpos] = false;
    q.push(ii(ypos,xpos));
    while (!q.empty()){
        int now_y = q.front().first;
        int now_x = q.front().second;
        q.pop();
        for (int i = 0 ; i<4 ; i++){
            int ny = now_y + dy[i];
            int nx = now_x + dx[i];
            if ( temp[ny][nx] == false) continue;
            if ( ny < 1 || nx < 1 || ny > n || nx > n )continue;
            temp[ny][nx]=false;
            q.push(ii(ny,nx));
        }
    }
    
}

int main(){
    
    /*유기농 배추랑 똑같다. */
    cin >> n;
    for (int i =1 ; i<=n; i++){
        for (int j=1 ;j<=n; j++){
            scanf("%d",&g[i][j]);
        }
    }
    
    
    
    for (int i =1 ;i<=100; i++){// 강수량
        int cnt = 0 ;
        memset (temp,false,sizeof(temp));
        for (int k = 1; k<=n; k++){
            for (int j = 1 ; j<=n ;j++){
                if ( g[k][j] > i){ //고지대
                    temp[k][j] = true ;
                }
            }
        }
        
        
        
        for (int k = 1; k<=n; k++){
            for (int j = 1 ; j<=n ;j++){
                if ( temp[k][j] == true ){
                    cnt ++ ;
                    go (k,j);
                }
            }
        }
        ans = max (cnt,ans ) ;
    }
    printf("%d\n",ans);
    
}
