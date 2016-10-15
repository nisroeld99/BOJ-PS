/*
 * 2638.cpp
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int>ii;
int n , m;

int g[111][111];
bool c[111][111];


bool check(){
    
    for (int i = 1 ; i<=n; i++)
        for (int j=1 ;j<=m;j++){
            if (g[i][j] ==1)
                return true ;
        }

    return false ;
    
}
int dy[4] ={1,-1,0,0}, dx[4]={0,0,-1,1};
bool check_melt (int ypos,int xpos){
    int cnt = 0 ;
    for (int i = 0 ; i<4; i++){
        int ny = ypos + dy[i];
        int nx = xpos + dx[i];
        if ( g[ny][nx] ==3 )cnt++;
    }
    if (cnt >=2) return true;
    else  return false;
}

vector<ii> temp ;
vector<ii> temp2;
int ans = -1 ;

queue<ii> q;
void go (int ypos, int xpos){
    memset(c,false, sizeof(c));
    q.push(ii(ypos,xpos));
    while (!q.empty() ){
        int now_y = q.front().first ;
        int now_x = q.front().second ;
        q.pop();
        if (c[now_y][now_x])continue;
        c[now_y][now_x] =true ;
        if ( g[now_y][now_x] ==1 ){
            temp.push_back(ii(now_y,now_x));
            continue;
        }
        g[now_y][now_x] = 3;
        
        for (int i = 0 ; i<4; i++){
            int ny = now_y + dy[i];
            int nx = now_x + dx[i];
            if (ny< 1 || nx < 1 || ny>n || nx >  m)continue ;
            q.push({ny,nx});
        
        }
    }
    
    while (!temp.empty()){
        if ( check_melt( temp.back().first,temp.back().second ) ){
            temp2.push_back(ii(temp.back().first, temp.back().second) ) ;
        }
        temp.pop_back();
    }
    while (!temp2.empty()) {
        g[temp2.back().first][temp2.back().second] = 3;
        temp2.pop_back();
    }
    
    
}


int main(){
    
    scanf("%d%d",&n,&m);
    for (int i =1;i<=n;i++)
        for(int j=1 ;j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    int cnt = 0;
    while ( check () ) {
        go (1,1);
//        for (int i =1;i<=n;i++){
//            for(int j=1 ;j<=m;j++){
//                printf("%d ",g[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
        cnt ++ ;
    }
    printf("%d\n",cnt);
}
