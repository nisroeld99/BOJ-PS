/*
 * 1520.cpp
 *
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int,int> ii;
const int inf = 987654321;

int g[555][555];
int d[555][555];
int n , m ;

int dy[4] = {0,0,1,-1} ,dx[4] = {1,-1,0,0};
int go (int ypos,int xpos){
    if (ypos == 1 && xpos ==1)return 1;
    
    
    int & ret = d[ypos][xpos] ;
    if (ret != -1 ) return ret;
    ret = 0 ;
    
    
    for (int i = 0; i<4; i++){
        int ny = ypos + dy[i];
        int nx = xpos +dx[i];
        if (ny <1 || nx< 1 || ny > n ||nx >m )continue;
        if (g[ny][nx] <= g[ypos][xpos] ) continue;
        ret += go (ny,nx);
    }
    return ret ;
    
}

int main(){
    memset (d, -1 ,sizeof(d)) ;
    
    scanf("%d%d",&n,&m);
    for (int i =1 ; i<=n ; i++){
        for (int j=1 ;j<= m ;j++){
            scanf("%d",&g[i][j]);
        }
    }
    printf("%d\n",go (n,m));
}
