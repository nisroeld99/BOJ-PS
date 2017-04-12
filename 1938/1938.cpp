#include<cstdio>
#include<vector>
#include <cstring>
#include <iostream>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii ;
typedef pair<ii,ii> iiii ;
typedef pair<ii,int> iii ;
typedef pair<long,long >lili;
typedef pair<double,double> dd;

struct Tree{
    int ypos,xpos, dir , cnt ;
    Tree(){}
    Tree(int _y , int _x , int _d, int _c){
        ypos = _y , xpos = _x , dir = _d , cnt = _c ;
    }
};

int n;
char g[111][111];

bool inRange(int y, int x){
    if ( y<0 || x < 0 || y>=n || x>=n)return false;
    return true ;
}


bool checknine(int y, int x){
    for (int i = y-1; i<=y+1 ; i++){
        for (int j= x-1 ; j<=x+1 ; j++){
            if ( !inRange(i, j)) {
                return false ;
            }
            if ( g[i][j] == '1'){
                return false;
            }
        }
    }
    return true;
}

bool checkRange(int y, int x, int dir){
    if ( dir == 0 ){
        if ( !inRange(y, x-1) || g[y][x-1] =='1') return false;
        if ( !inRange(y, x+1 )|| g[y][x+1] == '1')return false;
        if ( !inRange(y, x )|| g[y][x] == '1')return false;
    }else {
        if ( !inRange(y-1, x) || g[y-1][x] == '1' ) return false;
        if ( !inRange(y+1, x)|| g[y+1][x] =='1')return false;
        if ( !inRange(y, x )|| g[y][x] == '1')return false;
    }
    return true ;
}

int dy[4]={1,-1,0,0} ,dx[4]={0,0,-1,1};


void input(){
    scanf("%d",&n);
    for (int i = 0; i<n; i++){
        cin >> g[i];
    }
}
queue<Tree>q;
bool visit[111][111][2];
int ey, ex , ed;
const int inf = 987653421;
int ans = inf;
void bfs(){
    
    while (!q.empty()){
        const Tree now = q.front(); q.pop();
        
        if (now.ypos== ey && now.xpos == ex && now.dir == ed){
            ans = min ( ans , now.cnt);
            break;
        }
        if ( now.ypos ==3 && now.xpos == 0 ){
        
        }
        
        for (int i =0 ;i<4; i++){ // 상하좌우 이동 구현
            int ny = now.ypos+dy[i];
            int nx = now.xpos+dx[i];
            int ncnt = now.cnt + 1 ;
            int ndir = now.dir;
            if ( !checkRange(ny, nx, ndir)) continue;
            
            if  ( visit[ny][nx][ndir] == true )continue;
            q.push(Tree(ny,nx,ndir,ncnt)) ;
            visit[ny][nx][ndir] =true ;
        }
        
        // 90도 전환 구현
        if ( !checknine(now.ypos, now.xpos )) continue;
        if(visit[now.ypos][now.xpos][(now.dir+1)%2] ) continue;
        visit[now.ypos][now.xpos][(now.dir+1)%2] = true;
        q.push(Tree(now.ypos,now.xpos, (now.dir+1)%2 , now.cnt+1 )) ;
    }


}

int main(){
    //freopen("input.txt", "r", stdin);
    input();
    bool cc = false ;
    bool cc2= false;
    for (int i = 0 ; i<n; i++){
        for (int j=0 ;j<n; j++){
            if ( g[i][j] == 'B' ){
                
                if ( inRange(i+1,j)){
                    if ( cc== false && g[i+1][j] == 'B' ){ // |
                        q.push(Tree(i+1,j, 1 , 0));
                        visit[i+1][j][0] = true ;
                        cc= true ;
                    }
                }if ( inRange(i, j+1)){  // -
                    if ( cc== false&& g[i][j+1] == 'B' ){ // -
                        q.push(Tree(i,j+1, 0 , 0));
                        visit[i][j+1][1]= true ;
                        cc= true ;
                    }
                }
            }else if ( g[i][j] == 'E'){
                if ( inRange(i+1,j)){
                    if (cc2==false && g[i+1][j] == 'E' ){ // -
                        ey = i+1 , ex = j, ed = 1;
                        cc2= true;
                    }
                }if ( inRange(i, j+1)){  // |
                    if (cc2==false && g[i][j+1] == 'E' ){ // -
                        ey = i , ex = j+1 , ed = 0 ;
                        cc2= true;
                    }
                }
            }
        }
    }
    
    bfs();
    if ( ans == inf ) ans = 0 ;
    printf("%d\n",ans);
    
}
