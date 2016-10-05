/*
 * 1916.cpp
 *
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
const int inf = 987654321;
vector<ii> g[1111];
bool c[1111];
int d[1111];
int ans[1111];
priority_queue<ii,vector<ii>,greater<ii> > pq;
 
void dijk(int start){
    for (int i = 0 ; i<1111;i++)
        d[i] = inf ;
    d[start]=  0 ;
    pq.push(ii(0,start));
    while (!pq.empty()){
        int now_cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (c[now])continue;
        c[now] = true ;
        for (int i = 0 ; i<g[now].size(); i ++){
            int next = g[now][i].second;
            int next_cost = g[now][i].first + now_cost ;
             
            if (d[next ] > next_cost){
                d[next ] = next_cost ;
                pq.push(ii(next_cost, next));
            }
        }
    }
 
}
 
int main(){
    int n ;
    int m ;
    scanf("%d%d",&n,&m);
    for (int i = 0 ; i<m  ;i++){
        int from,to,cost;
        scanf("%d%d%d",&from,&to,&cost);
        g[from].push_back(ii(cost,to));
    }
    int start,end;
    scanf("%d%d",&start,&end);
     
    dijk(start);
    printf("%d\n",d[end]);
}
