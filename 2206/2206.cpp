/*
 * 2206.cpp
 *
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int>ii;
typedef pair<ii,ii>iiii;
int n ,m;
int g[1101][1101];
bool visit[1101][1101][2];
int ans =1;

int dy[4] ={1,-1,0,0}, dx[4]={0,0,-1,1};
queue<iiii> q;
void bfs ( int fy,int fx)
{
    q.push(iiii( ii(fy,fx) , ii(1,1)   )); // 좌표 , cost, 남은 뚫기 횟수
    visit[fy][fx][1] = true ;
    bool check =false;
    while (!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int now_cost = q.front().second.first;
        int now_left = q.front().second.second;
        q.pop();
        
        if ( y == n && x == m ){
            printf("%d\n", now_cost);
            check=true;
            break ;
        }
        
        for (int i = 0 ; i<4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny<1 || nx< 1 || ny > n || nx > m )continue;
            if ( g[ny][nx] == 1 ){ //벽으로 막혀잇을때,
                if (now_left ==1 ){ // 남은 횟수가 1일때는 뚫고 가본다. 
                    if ( visit[ny][nx][now_left-1]  ) continue;
                        visit[ny][nx][now_left-1] =true ;
                    q.push(iiii( ii( ny,nx), ii( now_cost+1 , now_left-1 ) ));
                }
            }else { //갈수있다.
                if (visit[ny][nx][now_left] )
                    continue;
                visit[ny][nx][now_left]= true;
                q.push(iiii( ii( ny,nx), ii( now_cost+1 , now_left ) ));
            
            }
        }
        
    }
    if ( !check)
        printf("-1\n");



}


int main(){
    
    scanf("%d%d",&n,&m);
    for (int i = 1;  i<=n ; i++)
        for (int j=1 ;j<=m ;j++)
            scanf("%1d",&g[i][j]);
        
    bfs(1,1);
    
    
}
