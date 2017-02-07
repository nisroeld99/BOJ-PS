/*
 * 2178_2.cpp
 *
 */


#include <iostream>
#include <algorithm>
using namespace std;
int g[111][111];       // 그래프 matrix
bool visited[111][111]; // 방문 matrix

int dy[4] = {0,0,-1,1}, dx[4] ={1,-1,0,0};
int n , m;
int dab = 987654231;
void go ( int ypos ,int xpos ,int sum){
    if ( ypos == n && xpos == m) {
        dab= min ( dab, sum) ;
        return ;
    }
    
    for (int i =0 ; i<4 ;i++){
        int ny = dy[i] + ypos ;
        int nx = dx[i] + xpos ;
        if ( ny < 1 || nx < 1 || ny > n || nx > m || visited[ny][nx] ) continue;
        if ( g[ny][nx] == 0 ) continue ; //길이 없을때,
        visited[ny][nx] =true ;
        go ( ny,nx, sum+1 );
        visited[ny][nx] =false ;
    }
    
}


int main(){
    /*
        dfs로 미로속 최단거리 구해본다
	하지만 TLE 뜸 ;; BFS로 구해야만하는 문제, (혹은 dp 사용 ) 
     */
    
    
    
    scanf("%d%d",&n,&m);
    
    
    
    for (int i = 1;  i<=n ; i++){
        string s;
        cin >> s;
        for (int j= 1; j<= m;j++){
            g[i][j] = s[j-1]-'0' ;
        }
    }
    
    go ( 1, 1 , 0  ); // (1,1)에서 출발해서 (n,m) 으로 가는 최단거리 go
    printf("%d\n",dab + 1  );
    
}
