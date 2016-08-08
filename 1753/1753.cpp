nclude <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;
const int inf = 987654321;
vector<ii> g[20001];
bool c[20001];
int d[ 200001 ];
priority_queue<ii , vector<ii> , greater<ii> > pq;
void dijk(int start ){
    memset(c,false,sizeof(c));
    for (int i = 0 ; i<200001;i++){
        d[i]=inf ;
    }
    pq.push(ii(0,start));
    while (!pq.empty()){
        ii temp = pq.top(); pq.pop();
        int now_cost= temp.first;
        int now =temp.second;
        if (c[now])continue;
        c[now]= true ;
        for (int i= 0 ;i< g[now].size(); i++){
            int next_cost = now_cost + g[now][i].first;
            int next = g[now][i].second;
            if (d[next] > next_cost ){
                d[next] = next_cost;
                pq.push({next_cost,next});
            }
        }
    }
}

int main(){
    int n , m;
    scanf("%d%d",&n,&m);
    int start ;
    scanf("%d",&start);
    
    while (m--){
        int from,to,cost;
        scanf("%d%d%d",&from,&to, &cost);
        g[from].push_back({cost,to});
    }
    dijk(start);
    for (int i = 1 ; i<=n;i++ ){
        if (i==start) printf("0\n");
        else if ( d[i] >=inf) {
            printf("INF\n");
        }
        else{printf("%d\n",d[i]);}
    }
}
