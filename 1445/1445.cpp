#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

int near[55][55];
int visit[55][55];
char g[55][55];
int fy, fx, sy, sx;
const int inf = 987654321;
//큐에는   ypos, xpos , garbage, garb_near
int n, m;
struct Point {
    int ypos, xpos, gar, gar_near;
    Point() {}
    Point(int _y ,int _x , int _g , int _gn ):ypos(_y), xpos(_x), gar(_g), gar_near(_gn){}
};

struct cmp {
    bool operator() (Point a, Point b) {
        if (a.gar == b.gar) return a.gar_near > b.gar_near;
        return a.gar > b.gar;
    }
};

bool inRange(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= m) return false;
    return true;
}
int dy[4] = { 0,0,-1,1 }, dx[4] = { -1,1,0,0 };
priority_queue <Point,vector<Point>, cmp > pq;
int ans1=inf, ans2=inf ;
void bfs() {
    for (int i = 0 ; i<55 ;i++){
        for (int j= 0 ;j<55 ;j++){
            near[i][j] = visit[i][j] = inf ;
        }
    }
    pq.push(Point(sy, sx, 0, 0));
    while (!pq.empty()) {
        Point now = pq.top(); pq.pop();
        if ( now.gar > ans1) continue;
        if ( now.gar == ans1 ){
            if (now.gar_near > ans2){
                continue;
                
            }
        }
   // printf("%d %d %d %d\n", now.ypos, now.xpos, now.gar, now.gar_near);
        if (now.ypos == fy && now.xpos == fx) {
            if ( ans1 == now.gar){
                if ( ans2 > now.gar_near){
                    ans1= now.gar;
                    ans2 = now.gar_near;
                }
            }
            if ( ans1 > now.gar){
                ans1= now.gar;
                ans2 = now.gar_near;
            }
            
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            
            int ny = now.ypos + dy[i];
            int nx = now.xpos + dx[i];
         
            if (!inRange(ny, nx)) continue;
            

            if (g[ny][nx] == 'g') {
                if (visit[ny][nx] < now.gar+1) continue;
                if (visit[ny][nx] == now.gar+1) {
                    if (near[ny][nx] <= now.gar_near) continue;
                }
                pq.push(Point(ny, nx, now.gar + 1, now.gar_near));
                visit[ny][nx] = now.gar + 1;
                near[ny][nx] = now.gar_near;
            }
            else if (g[ny][nx] == 'G') {
                if (visit[ny][nx] < now.gar) continue;
                if (visit[ny][nx] == now.gar) {
                    if (near[ny][nx] <= now.gar_near+1) continue;
                }
                pq.push(Point(ny, nx, now.gar, now.gar_near+1));
                visit[ny][nx] = now.gar;
                near[ny][nx] = now.gar_near+1;
            }
            else if (g[ny][nx] == '.')  {
                if ( visit[ny][nx] == now.gar && near[ny][nx] == now.gar_near) continue;
                if (visit[ny][nx] < now.gar) continue;
                if (visit[ny][nx] == now.gar) {
                    if (near[ny][nx] <= now.gar_near) continue;
                }
                pq.push(Point(ny, nx, now.gar, now.gar_near));
                visit[ny][nx] = now.gar;
                near[ny][nx] = now.gar_near;
            }
            else if (g[ny][nx] == 'F' ) {
                if ( visit[ny][nx] == now.gar && near[ny][nx] == now.gar_near) continue;
                if (visit[ny][nx] < now.gar) continue;
                if (visit[ny][nx] == now.gar) {
                    if (near[ny][nx] <= now.gar_near) continue;
                }
                pq.push(Point(ny, nx, now.gar, now.gar_near));
                visit[ny][nx] = now.gar;
                near[ny][nx] = now.gar_near;
            }
            else if (g[ny][nx] == 'S' ) {
                continue;
            }
        }
    }
}

void Print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", g[i][j]);
        }printf("\n");
    }
}
int main() {
//freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j=0 ;j<m; j++){
            scanf("%c",&g[i][j]);
        }getchar();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ( g[i][j] == 'S') {
                sy = i, sx = j;
            }
            else if  (g[i][j] == 'F') {
                fy = i, fx = j;
            }
            else if (g[i][j] == 'g') {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dy[k];
                    int nj = j + dx[k];
                    if (!inRange(ni, nj)) continue;
                    if (g[ni][nj] != '.') continue;
                    g[ni][nj] = 'G';
                }
            }
        }
    }
   // Print();
    bfs();
    cout << ans1 << " " << ans2 << endl;
    
    
}  

