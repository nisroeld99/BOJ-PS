/*
 * 7569.cpp
 *
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int>ii;

typedef pair<ii,ii>iiii;
int n,m,h;

int dz[6]= {1,-1,0,0,0,0}, dy[6]={0,0,1,-1,0,0} ,dx[6] ={0,0,0,0,1,-1};

int g[111][111][111];
bool visit[111][111][111];
int ans = -1000;
queue<iiii>q;
void bfs(){
    
    while (!q.empty()){
        int now_z = q.front().first.first;
        int now_y = q.front().first.second;
        int now_x = q.front().second.first;
        int now_cost = q.front().second.second;
        ans = max (ans,now_cost);
        q.pop();
        for (int i = 0  ; i<6; i++){
            int nz = now_z + dz[i];
            int ny = now_y + dy[i];
            int nx = now_x + dx[i];
            if  (visit[nz][ny][nx] )continue; //이미 방문
            if ( nz<1 ||nx<1||ny <1|| nz> h || ny >m || nx >n) continue; //배열범위
            if ( g[nz][ny][nx] == -1 ) continue; //벽
            
            visit[nz][ny][nx] =true ;
            q.push(iiii( ii( nz,ny ) , ii(nx, now_cost+1 ) ));
        }
        
        
    }
}



int main(){
    cin>> n>>m>>h; // xpos,ypos,zpos 순 // 값 주의 x,y,z햇갈리지않기
    
    for (int i= 1; i<=h; i++)
        for (int j=1 ;j<=m; j++)
            for (int k=1; k<=n ;k++)
                scanf("%d",&g[i][j][k]); //1익은 토마토,0 안익 토, -1 비어있음
    
    
    
    for (int i= 1; i<=h; i++)
        for (int j=1 ;j<=m; j++)
            for (int k=1; k<=n ;k++){
                if ( g[i][j][k] == 1){
                    q.push(iiii( ii(i,j) ,ii(k,0)  ) ); //시작 토마토 입력
                    visit[i][j][k] = true ;
                }
                if ( g[i][j][k] == -1 )
                    visit[i][j][k] =true;
            }
    
    
    bfs();
    for (int i= 1; i<=h; i++)
        for (int j=1 ;j<=m; j++)
            for (int k=1; k<=n ;k++)
                if (visit[i][j][k] ==false ){
                    printf("-1\n");
                    return 0;
                }
            
    
    printf("%d\n",ans);
    
        
    
}
