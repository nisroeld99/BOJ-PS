/*
 * 1854.cpp
 *
 */
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int,int > ii ;
const int inf = 987654321;
vector< ii> g[1111];
bool c[1111];

int n, m,k;
priority_queue<ii , vector<ii> , greater<ii> >pq;
priority_queue<int > kth[1111];
void dijkstra ( int start ){
    memset(c,false ,sizeof(c));
    
    kth[start] .push (0 );
    
    pq.push(ii(0,start ));
    while (!pq.empty()){
        ii temp = pq.top() ; pq.pop();
        int now = temp.second;
        int now_cost = temp.first;
        
        for (auto x : g[now]){
            int next = x.second;
            int next_cost = x.first+now_cost;
            
            if ( kth[next].size() < k ){
                kth[next].push(next_cost);
                pq.push(ii(next_cost, next));
            }else {
                if ( kth[next].top() < next_cost ){
                    continue;
                }
                else{
                    kth[next].pop();
                    kth[next].push(next_cost);
                    pq.push(ii(next_cost, next));
                }
            }
            
            
        }
        
        
    }
    
    
}

int main () {
    
    
    cin >> n >> m >> k  ;
    for (int i = 0 ; i< m ; i++ ){
        int from , to ,cost ;
        scanf("%d%d%d" ,&from ,&to , &cost ) ;
        g[from].push_back( ii(cost, to ));
        
    }
    
    dijkstra(1);
    
    for (int i =1 ; i<= n ; i++){
        if ( kth[i].size() < k)
            printf("-1\n");
        else {
            printf("%d\n",kth[i].top());
        }
    }
    return 0 ;
    

}


