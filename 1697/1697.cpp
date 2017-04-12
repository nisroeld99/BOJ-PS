#include <iostream>
#include <queue>
using namespace std ;
queue<int> q;
int d[111111];
int n, m ;
bool inRange(int x){
    if ( x < 0 || x > 100000) return false; 
    return true ; 
}
int dx[2] ={1,-1};
void bfs(int start){
   int cnt = 0 ; 
    memset (d,-1,sizeof(d));
    q.push(start);
    d[start] = 0 ;
    while (!q.empty){
        int now = q.front(); q.pop();
         for (int i =0 ; i<2; i++){
            int nx = now + dx[i];
            if ( !inRange(nx)) continue;
            if ( d[nx] != -1 ) continue; 
            if ( nx == m  ){
                cnt ++ ;
                continue; 
            }else {
                d[nx] = d[now] + 1; 
                q.push (nx);
            }
         } 
       int nx = 2*now;
       if ( !inRange(nx) ) continue;
       if  (d[nx]!= -1 )continue;
       if ( nx == m){
            cnt ++ ;
       }else {}
       d[nx] = d[now] + 1;
       q.push (nx);
    }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    bfs(n);
}
