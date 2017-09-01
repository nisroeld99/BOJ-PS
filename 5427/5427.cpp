#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int,int> ii ;

int n , m ; //y , x
char g[1001][1001];
int dy[4]={0,-1,1,0}, dx[4] = {1,0,0,-1};

struct Point{
    int ypos, xpos, idx, time; // 0 일떄 상근이, 1일때 fire
    Point(){}
    Point(int _y, int _x, int _idx,int _time){
        ypos = _y;
        xpos = _x;
        idx = _idx;
        time = _time ;
    }
};
Point sg;




bool check_range (int y, int x){ //탈출 성공여부 check
    if ( 1>y || 1>x || y> n || x > m  ) return true ;
    return false;
}



vector <Point> v;
queue<Point> q;
const int inf =987654321;;
int ans = inf ;
bool check[1111][1111];
void bfs() {
    while (!q.empty()) q.pop();
    while (!v.empty()){
        q.push(v.back());
        v.pop_back();
    }
    q.push(sg);//상근이가 먼저 움직임
    
    while (!q.empty()) {
        if ( ans != inf )break;
//        for (int i =1 ;i<=n; i++){
//            for (int j=1;j<=m;j++){
//                printf("%c ",g[i][j]);
//            }   printf("\n");
//            
//            
//        }printf("\n");
        
        Point temp =  q.front();
        q.pop();
        
        
        int now_y = temp.ypos;
        int now_x = temp.xpos;
        int now_idx = temp.idx;
        int now_time = temp.time;
        
        
        
        
        for (int i =0 ; i<4; i++){
            int ny = now_y + dy[i];
            int nx = now_x + dx[i];
            
            
            if ( now_idx == 0 ){//상근이일때,
                if (check_range(ny, nx)){ //상근이가 탈출했다 !
                    ans = now_time;
                    break ;
                }
                
                if ( g[ny][nx] == '#' ||  g[ny][nx]=='*' || check[ny][nx] ) continue;
                check[ny][nx] = true ; //상근이가 여기로갈것이다.
                g[ny][nx] = '@';
                q.push(Point(ny,nx,0,now_time+1));
            }else { // 불일때,
                if ( check_range(ny, nx)) {continue;}
                if ( g[ny][nx] == '#' || g[ny][nx] =='*' )continue;
                g[ny][nx] = '*';
                q.push(Point(ny,nx,1,0 ));
            }
            
            
            
            
        }
        
        
        
    }
}

int main(){
   //freopen("input.txt", "r", stdin);
    int tc;
    
    cin >> tc;
    while (tc--){
        ans = inf;
        memset (g, 0,sizeof(g));
        memset (check,false, sizeof(check));
        while ( !v.empty())v.pop_back();
        scanf("%d%d",&m,&n); // x ,y
        
        
        
        for (int i = 1 ; i<= n ; i++){
            string s;
            cin >> s;
            for (int j =0; j<s.size(); j++){
                if ( s[j] == '@'){
                    sg.ypos = i;
                    sg.xpos = j+1;
                    sg.idx = 0 ;
                    sg.time =0 ;
                }else if(s[j]=='*'){
                    v.push_back(Point(i,j+1,1,0));
                    
                }
                g[i][j+1]=s[j];
            }
        }
        
        
        bfs();
        if ( ans == inf ){
            printf("IMPOSSIBLE\n");
        }else{
            printf("%d\n",ans+1);
        }
        
    }
    
    
    
}
