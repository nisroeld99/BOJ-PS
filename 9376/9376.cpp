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

int n , m;
struct Point{
    int ypos ,xpos ;
    Point(){}
    Point(int _y ,int _x ) {
        ypos = _y;
        xpos = _x;
    }
};
char g[111][111];


bool inRange (int y , int x){
    if ( y<0||x<0 ||y>n+1||x>m+1) return false;
    return true ;
}
queue<Point> q;
int dy[4] ={0,-1,1,0} , dx[4]={1,0,0,-1};
vector<vector<int>> bfs(Point & start) {
    //임시 배열 생성
    vector<vector<int>> temp ;
    temp.resize(111);
    for (int i = 0 ; i<111;i++)
        temp[i].resize(111);
    //
    
    for (int i =0  ; i<111;i++){
        for (int j=0;j<111;j++){
            temp[i][j] = -1;
        }
    }
    temp[start.ypos][start.xpos]= 0;
    q.push(start) ;
    while (!q.empty()){
        Point now =q.front(); q.pop();
        for (int i = 0 ; i<4 ; i++){
            int ny = now.ypos+dy[i];
            int nx = now.xpos+dx[i];
            if ( !inRange(ny, nx))  continue;
            if ( g[ny][nx] == '*' ) continue;
            if ( g[ny][nx] == '#'){
                if ( temp[ny][nx] == -1 || temp[ny][nx] > temp[now.ypos][now.xpos]+1 ){
                    temp[ny][nx] = temp[now.ypos][now.xpos]+1;
                    q.push(Point(ny,nx));
                }
            }
            else {
                if ( temp[ny][nx] ==-1 || temp[ny][nx] > temp[now.ypos][now.xpos]){
                    temp[ny][nx] = temp[now.ypos][now.xpos];
                    q.push(Point(ny,nx));
                }
            }
        }
    }
    
    
    return temp ;
}
int main(){
   //freopen("input.txt","r",stdin);
    int tc;
    cin >> tc;
    while (tc--){
        
        scanf("%d%d",&n,&m);
        for (int i =0  ; i<=n+1 ;i++){
            for (int j=0 ;j<=m+1; j++){
                g[i][j] = '.';
            }
        }
        vector<Point> start ;
        start.push_back(Point(0,0)) ;
        for (int i =1 ;i<=n; i++){
            string str;
            cin >> str;
            for (int j=0 ;j<m; j++){
                g[i][j+1]=str[j];
                if (g[i][j+1] == '$'){
                    start.push_back(Point(i,j+1));
                }
            }
        }
        vector<vector<int>> d1;
        vector<vector<int>> d2;
        vector<vector<int>> d3;

        d1= bfs(start[0]); // 상근이
        d2= bfs(start[1]); // 죄수 1
        d3= bfs(start[2]); // 죄수 2
        
        
        int ans = inf ;
        for (int i = 0 ; i<=n+1; i++){
            for (int j=0 ;j<=m+1; j++){
                if ( g[i][j] == '*') continue;
                int sum = d1[i][j] + d2[i][j] + d3[i][j];
                if ( g[i][j] == '#')
                    sum-=2;
                ans = min(sum,ans);
            }
        }
        printf("%d\n",ans);
        
        
    }// tc loop end

} //main  end
