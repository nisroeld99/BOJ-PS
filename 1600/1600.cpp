#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii ;
typedef pair<ii,ii> iiii ;
typedef pair<ii,int> iii ;
typedef pair<long,long >lili;
typedef pair<double,double> dd;
const int inf =987654231;
const int mod = 1000000007;
struct Point {
    int ypos ,xpos,cnt;
    Point(){}
    Point(int _y, int _x, int _c){
        ypos =_y, xpos = _x;
        cnt =_c;
    }
};
int n , m, k  ;
int g[222][222];
bool c[222][222][33];
int d[222][222][33];
bool inRange(int y, int x){
    if (y<1 ||x<1 ||y>n||x>m)return false;
    return true;
}
bool ok = false;
queue<Point> q;

void Print();
int dy[4] ={0,0,-1,1} , dx[4] ={1,-1,0,0};
int ddy[8] ={-1,-1, -2,-2, 1,1, 2,2} , ddx[8] ={2,-2,1,-1,-2,2, 1,-1 };
void bfs(){
    q.push(Point(1,1,0)) ;
    c[1][1][0] =true ;
    
    while (!q.empty()){
        Point now = q.front(); q.pop();
        if ( now.ypos== n &&now.xpos==m) {
            ok =true ;
            printf("%d\n",d[now.ypos][now.xpos][now.cnt]);
            break;
        }
//        Print();
        for (int i =0 ; i<4; i++){
            int ny = now.ypos +dy[i];
            int nx = now.xpos +dx[i];
            if ( !inRange(ny,nx)) continue;
            if (g[ny][nx] == 1) continue;
            
            if (  !c[ny][nx][now.cnt] || d[ny][nx][now.cnt] > d[now.ypos][now.xpos][now.cnt]+1){
                c[ny][nx][now.cnt]=true;
                d[ny][nx][now.cnt]= d[now.ypos][now.xpos][now.cnt]+1;
                q.push(Point(ny,nx,now.cnt));
            }
        
        }
        for (int i = 0;  i<8 ;i++){
            if ( now.cnt >=k) break;;
            int ny = now.ypos +ddy[i];
            int nx = now.xpos +ddx[i];
            if ( !inRange(ny,nx)) continue;
            if (g[ny][nx] == 1) continue;
            if ( !c[ny][nx][now.cnt+1] || d[ny][nx][now.cnt+1] > d[now.ypos][now.xpos][now.cnt]+1){ //가지않은 길이라면,
                c[ny][nx][now.cnt+1]=true;
                d[ny][nx][now.cnt+1] = d[now.ypos][now.xpos][now.cnt]+1;
                q.push(Point(ny,nx,now.cnt+1));
            }
        }
    }

}

int main(){
    scanf("%d",&k);
    scanf("%d%d",&m,&n); // m= 가로 , n =세로
    for (int i =1; i<=n; i++){
        for (int j=1; j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    
    bfs();
    
    if (!ok) {
        printf("-1\n");
    }
    
}
