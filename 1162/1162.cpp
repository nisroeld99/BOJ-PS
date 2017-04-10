#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 987654321;
typedef pair<int,int> ii ;
typedef pair<int,ii> iii ;
vector<ii> g[11111];
bool c[11111][22];
int d[11111][22]; //i번째 , k번 포장 갈때 최단거리
int main(){
 //   freopen("input.txt", "r", stdin);
    for (int i =0 ; i<11111;i++)
        for (int j= 0 ;j<22; j++){
            d[i][j] = inf ;
        }
    
    int n ,m , k ;
    cin >> n >> m >> k;
    for (int i = 0 ;i<m ;i++){
        int from,to ,cost ;
        scanf("%d%d%d", &from, &to , &cost );
        g[from].push_back(ii(cost,to));
        g[to].push_back(ii(cost,from));
    }
    
    priority_queue<iii,vector<iii>,greater<iii> >pq;
    pq.push(iii(0,ii(1,0))); // cost, now, pavecnt ;
    d[1][0] = 0;
    while (!pq.empty()){
        iii temp = pq.top();
        int now_cost = temp.first;
        int now = temp.second.first;
        int now_pave = temp.second.second;
        pq.pop();
        
        if ( c[now][now_pave] ) continue;
        c[now][now_pave]= true;
        
        //포장하지 않는 경우  k 는 그대로 ( 일반적인 dijkstra )
        for (auto x : g[now]){
            int next_cost = now_cost + x.first;
            int next = x.second;
            if ( c[next][now_pave] ) continue;
            if ( d[next][now_pave]  >  next_cost ){
                d[next][now_pave] = next_cost ;
                pq.push(iii( next_cost ,ii(next, now_pave) ) );
            }
        }
        
        //포장하는 경우 k+1 이고 이번 도로는 추가되지 않는다. 근데 k 조건보다 많으면 더이상 포장할수 없으므로 ..
        if ( now_pave <= k ){
            for (auto x : g[now ]){
                int next_cost = now_cost;
                int next = x.second;
                if ( c[next][now_pave+1] ) continue;
                if ( d[next][now_pave+1]  >  next_cost ){
                    d[next][now_pave+1 ] = next_cost ;
                    pq.push(iii( next_cost ,ii(next, now_pave + 1 ) ) );
                }
            }
        }
    }
    int ans = inf ;
    for (int i = 0 ; i<=k ; i++){
        if ( d[n][i] < ans )
            ans = d[n][i];
    }
    cout << ans << endl ;
    
}
