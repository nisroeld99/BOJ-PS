#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll ;

const int inf = 987654321;
int n , m ;
ll d[888][888];
vector<ii>v[888];
bool visit[888];
priority_queue<ii,vector<ii>,greater<ii> > pq;

void dijk(int start){
    memset (visit, false ,sizeof(visit));
    for (int i = 0 ; i<=n ; i++){
        d[start][i] = inf ;
    }
    d[start][start] = 0 ;
    pq.push(ii(0 , start))  ;
    
    while(!pq.empty() ){
        ii temp = pq.top();
        int cost = temp.first;
        int now = temp.second;
        pq.pop();
        if (visit[now] )continue;
        visit[now] = true;
        for (auto x : v[now]){
            int next_cost =x.first + cost;
            int next = x.second;
            
            if ( d[start][next ] > next_cost){
                d[start][next] = next_cost;
                pq.push(ii( next_cost, next ) );
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i =0  ;i<m; i++){
        int from,to,cost;
        scanf("%d%d%d",&from,&to,&cost);
        v[from].push_back(ii(cost,to));
        v[to].push_back(ii(cost,from));
    }
    int r1,r2;
    scanf("%d%d",&r1,&r2);
    
    dijk (1);
    dijk (r1);
    dijk (r2);
    
    ll ans = min(d[1][r1] + d[r1][r2] + d[r2][n], d[1][r2] + d[r2][r1] + d[r1][n]);
    
    if (ans < inf )
        printf("%lld\n", ans  );
    else
        printf("-1\n");
    
    
    
    
}

