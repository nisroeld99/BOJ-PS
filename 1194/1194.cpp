#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int>ii;
typedef pair<ii,int> iii;
int n,m;
char g[55][55];
int c[55][55][70]; // i,j , 1 1 1 1 1 1 (key bit mask)
int dy[4] ={0,-1,0,1}, dx[4]= {1,0,-1,0};
queue<iii> q;

bool inRange(int y , int x){
    if ( y<1 || x < 1 || y> n || x > m) return false;
    return true ;
}
int main(){
  //  freopen("input.txt","r",stdin);
    memset ( c, -1,sizeof(c));
    scanf("%d%d",&n,&m);
    for (int i =1; i<=n; i++){
        string str;
        cin >> str;
        for (int j=0 ; j<m ;j++){
            if (str[j] == '0'){
                c[i][j+1][0] = 0;
                q.push(iii( ii(i,j+1),0 ));
            }
            g[i][j+1] = str[j];
        }
    }
    
    while (!q.empty()){
        iii temp = q.front(); q.pop();
        int now_y = temp.first.first;
        int now_x = temp.first.second;
        int now_key = temp.second;
        if ( now_y ==2 && now_x ==3 ){
            
        }
        if ( g[now_y][now_x] =='1' ){
            printf("%d\n",c[now_y][now_x][now_key]);
            return 0;
        }
        for (int i = 0 ; i<4 ; i++) {
            int ny = now_y + dy[i];
            int nx = now_x + dx[i];
            
            if ( !inRange(ny, nx)) continue;
            if ( g[ny][nx] =='#') continue;
            if (  'A'<=g[ny][nx] && g[ny][nx]<='F' ){ //문일경우
                if ( (now_key & (1<<(g[ny][nx]-'A')))!=0 && c[ny][nx][now_key] == -1 ){
                    c[ny][nx][now_key] = c[now_y][now_x][now_key]+1 ;
                    q.push(iii(ii( ny,nx),now_key));
                }
            }
            else if (  'a'<=g[ny][nx] && g[ny][nx]<='f' ){ //key 일경우
                int temp = c[now_y][now_x][now_key];
               
                int temp_now_key = now_key;
                temp_now_key |=  (1<<(g[ny][nx]-'a'));
                if (c[ny][nx][temp_now_key] == -1 ){
                    c[ny][nx][temp_now_key] = temp +1;
                    q.push(iii(ii( ny,nx),temp_now_key));
                }
            }
            else if ( g[ny][nx] == '.' || g[ny][nx] =='0' || g[ny][nx] =='1'){  //빈공간
                if (c[ny][nx][now_key] == -1 ){
                    c[ny][nx][now_key] = c[now_y][now_x][now_key]+1;
                    q.push(iii(ii( ny,nx),now_key));
                }
            }
        }
        
        
    }
    printf("-1\n");

}
