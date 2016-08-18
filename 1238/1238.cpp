/*
 * 1238.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
const int inf = 987654321;
vector<ii> g [1001];
int n , m , k ;
int d[1001][1001];
bool c[1001];
priority_queue<ii,vector<ii>,greater<ii> > pq;
void dijk(int start){
    memset(c,false,sizeof(c));
    for (int i =1;  i<=n ; i++ ){
        d[start][i]=inf ;
    }
    
    d[start][start]= 0 ;
    pq.push(ii(0,start));
    while (!pq.empty()){
        ii temp = pq.top();pq.pop();
        int now_cost = temp.first ;
        int now = temp.second;
        if (c[now] ) continue;
        c[now] = true ;
        for (int i =0  ; i< g[now].size() ; i++ ) {
            int next_cost =g[now][i].first;
            int next = g[now][i].second;
            if ( d[start][next] > now_cost + next_cost) {
                d[start][next] = now_cost + next_cost ;
                pq.push(ii(d[start][next], next));
            }
        }
    }
    
}
int main() {
    
    scanf("%d%d%d", &n,&m,&k);
    for (int i = 0 ;  i < m ; i++ ) {
        int from,to ,cost;
        scanf("%d%d%d",&from, &to , &cost ) ;
        g[from].push_back (ii(cost,to));
    }
    for (int i =1 ; i<=n; i++){
        dijk(i);	
    }
    int dab = -10000;
    for (int i =1 ; i<=n ; i++ ) {
        dab= max (dab, d[i][k] + d[k][i] ) ;
    }
    
    cout <<dab <<endl;
    
    
    return 0  ;
}

