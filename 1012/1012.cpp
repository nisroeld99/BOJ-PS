/*
 * 1012.cpp
 *
 */


#include <iostream>

using namespace std;

bool g[55][55];

int dy[4] = {0,0,-1,1}, dx[4] ={1,-1,0,0};

int x, y,k;

void go ( int ypos , int xpos ){   //
    g[ypos][xpos] = false ;
    
    for (int i = 0 ; i<4 ; i++){  //상하좌우를 dy,dx , ny,nx 로 표현함
        int ny = ypos + dy[i];
        int nx = xpos + dx[i];
        if ( ny < 0|| nx< 0 || ny >=y || nx >= x ) continue; //g [][] 범위 이탈시,
        if ( g[ny][nx] == false )continue;
        go (ny,nx);
    }
}


int main(){
    
    
    
    int tc;
    cin >> tc;
    
    while (tc--){
        memset (g,false, sizeof(g)) ;  //기존의 g[][] 그래프를 모두 false로 초기화 #include <cstring>
        
        scanf("%d%d%d",&x,&y,&k);  //
        while (k--){
            int xx,yy;
            scanf("%d%d",&xx,&yy);
            g[yy][xx] = true ;  //배추가 심어진 위치 g[][] 그래프에 넣기
        }
        int ans = 0 ;  //배추 지렁이 개수
        for (int i = 0 ; i< y; i++){
            for (int j= 0 ;j<x ;j++){
                if ( g[i][j] == true ){  // 다 돌면서 , 배추만나면
                    ans ++ ;             // 지렁이 추가
                    go ( i,j );          // 그리고 주변 배추도 이번에 추가된 지렁이가 다 먹으므로, dfs로 주변을 추적함
                }
            }
        }
        printf("%d\n",ans);
    }
}
