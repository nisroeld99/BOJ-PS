#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf =987654321;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;



vector<ii >g[888];

long long d[888][888];
priority_queue<ii,vector<ii>,greater<ii>>pq;
void dijkstra(int start){
    for (int i = 0 ; i<888;i++){
        
        d[start][i]=inf;
    }
    d[start][start]=0;
    pq.push(ii(0,start));
    while (!pq.empty()){
        ii temp = pq.top(); pq.pop();
        int nowDist = temp.first;
        int now = temp.second;


        for (int i = 0 ; i< g[now].size();i++){
            int nextDist = nowDist + g[now][i].first;
            int next = g[now][i].second;
            if ( d[start][next]> nextDist ) {
                d[start][next] =nextDist ;
                pq.push(ii(nextDist,next));
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    
    for (int i = 0 ; i<m;i++){
        int from,to,cost;
        scanf("%d%d%d",&from,&to,&cost);
        g[from].push_back(ii(cost,to));
        g[to].push_back(ii(cost,from));
    }
    
    
    
    int f,s;
    scanf("%d%d",&f,&s);
    dijkstra(1);
    dijkstra(f);
    dijkstra(s);
    
    long long dab= min({d[1][f] +d[f][s]+ d[s][n] , d[1][s]+d[s][f]+d[f][n]});
    if( dab <inf ){
        cout << dab<<"\n";
    }
    else {
        cout << -1<<"\n";
    }
    
}
