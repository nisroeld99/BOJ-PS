/*
	1726.cpp
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int>ii;
typedef pair<ii,ii> iiii;  // ( y,x좌표와 방향 , 방향과, cost ) 저장 (ii , ii 두개붙임, 총4개의 int 저장하는 iiii 변수

int g[111][111];
bool visit[111][111][5]; // ypos,xpos , 방향 체크
int dy[5] ={0,0,0,1,-1}, dx[5] ={0,1,-1,0,0};
int get_opposition (int num){
    switch (num) {
        case 1:
            return 2;
            break;
        case 2:
            return 1;
            break;
        case 3:
            return 4;
            break;
        case 4:
            return 3;
            break;
        default:
            return -1;
            break;
    }
    
}
int n , m ;
int sy,sx,sdir,ly,lx,ldir;
queue<iiii> q;  // i

void bfs(){
    memset(visit,false, sizeof(visit));
    
    visit[sy][sx][sdir]=true ;
    q.push(iiii( ii(sy,sx),ii(sdir,0) ));
    
    
    while (!q.empty()){
        int ypos  = q.front().first.first;
        int xpos = q.front().first.second;
        int now_dir  =q.front().second.first;
        int now_cnt = q.front().second.second;
        q.pop();
        if ( ypos == ly && xpos == lx && now_dir== ldir ){ //목적지 도착하면  + 방향도 같으면,
            printf("%d\n",now_cnt);
            break;  ;
        }
        
        
        //1~3만큼이동과 좌우 방향이동은 각각 똑같은 가중치 1 을 가진다. queue에 넣으면 된다
        
        // 1~3 이동 구현 , (방향전환 x)
        for (int i= 1; i<=3 ;i++){
            int ny = ypos + dy[now_dir]* i;
            int nx = xpos + dx[now_dir]* i;
            
            if ( ny<1 || nx < 1 || ny>n || nx >m) break; //범위 check
            if ( g[ny][nx] == 1){
                break ;
            }
            if ( visit[ny][nx][now_dir] ) continue; //이미 방문했으면 continue;
            visit[ny][nx][now_dir] = true ;
            q.push(iiii( ii(ny,nx) , ii(now_dir,now_cnt+1) ));
        }
        
        // 좌우 방향 전환 구현
        for (int i =1; i<= 4 ;i++){ //i idx는 방향좌표다.
            if ( i == now_dir || i == get_opposition(now_dir) )continue; //반대방향(가중치2) 혹은 지금 방향 (이미했음) 이면 continue
            
            int next_dir = i;
            if ( visit[ypos][xpos][next_dir] ) continue;
            visit[ypos][xpos][next_dir] = true ;
            q.push(iiii( ii(ypos,xpos) , ii(next_dir,now_cnt+1) ));
        }
    }
    
    
    
}


int main(){
 //   freopen("input.txt", "r", stdin);
   /*
	bfs 인데 bfs는 가중치가 1인것만 다루는것을 안다면 쉽게 풀수있다.
	(180도 회전을 한번에 구현하려고하면 꼬인다)

   */ 
    scanf("%d%d",&n,&m);
    for (int i =1; i<=n ;i++){
        for (int j=1 ;j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    
    scanf("%d%d%d%d%d%d",&sy,&sx,&sdir,&ly,&lx,&ldir);
    
    bfs();
}

