#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;


char g[13][7];
typedef pair<int,int> ii;
int dy[4] ={0,0,-1,1}, dx[4]={1,-1,0,0};
queue<ii>q;
bool visit[13][7];

bool inRange (int y, int x){
    if ( y< 1 || x < 1 || y> 12 || x > 6 )return false;
    return true ;
}
bool change = false;
int ans = 0 ;
void Print(){
    for (int i =1 ; i<=12; i++){
        for (int j= 1; j<=6; j++){
            printf("%c", g[i][j] ) ;
        }printf("\n");
    }
}
void bfs(char a,int sy, int sx){
    memset (visit, false ,sizeof(visit));
    q.push(ii(sy,sx));
    int cnt = 0 ;
    while (!q.empty()){
        ii temp = q.front() ; q.pop();
        
        for (int i =0 ; i<4 ;i++){
            int ny = temp.first + dy[i];
            int nx = temp.second + dx[i];
            if ( !inRange(ny, nx)) continue;
            if ( visit[ny][nx]  ) continue;
            if ( g[ny][nx] == a ){
                cnt ++ ;
                q.push(ii(ny,nx));
                visit[ny][nx] = true ;
            }
        }
    }
    if ( cnt >= 4 ) {

        change = true;
        memset (visit, false ,sizeof(visit));
        q.push(ii(sy,sx));
        while (!q.empty()){
            ii temp = q.front() ; q.pop();
            g[temp.first][temp.second] = '.';
            for (int i =0 ; i<4 ;i++){
                int ny = temp.first+dy[i];
                int nx = temp.second+dx[i];
                if ( !inRange(ny, nx)) continue;
                if ( g[ny][nx] == a ){
                    q.push(ii(ny,nx));                 
                }else {
                    continue;
                }
            }
        }
    }
}
bool check(){
    for (int i =1 ; i<=12; i++){
        for (int j= 1; j<=6; j++){
            if ( !(g[i][j] == '.' )){
                return false;
            }
            
        }
    }
    return true ;
}

int main(){

    for (int i = 1 ; i<=12; i++){
        string str;
        cin >> str;
        for (int j= 0 ;j<6; j++){
            g[i][j+1] = str[j];
        }
    
    }
    
    while (true){
        change = false ;
        
        for (int i = 1; i<=12; i++){
            for (int j= 1 ;j<=6 ;j++){
                if ( g[i][j] !=  '.'){
                    bfs(g[i][j],i,j);
                }
            }
        }
        
        for (int i= 12 ; i>=2 ; i--){
            for (int j= 1 ;j<=6 ; j++){
                if ( g[i][j] == '.' && g[i-1][j] !='.' ){
                    int now_y = i-1;
                    const int now_x = j;
                    while ( true  ){
                        if(now_y == 12 || g[now_y+1][now_x] != '.' ) break;
                        now_y ++ ;
                    }
                    g[now_y][now_x] = g[i-1][now_x];
                    g[i-1][now_x] = '.' ;
                }
            }
        }
        
//        Print();        
        if ( !change  ){
            break ;
        }
        ans ++ ;
        if ( check() ) break ;
       
        
        
    }
    cout << ans << endl;
    
}
