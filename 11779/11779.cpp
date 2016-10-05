/*
 * 11779.cpp
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;
const int inf =987654321;
typedef pair<int,int>ii;
bool c[1111];
int d[1111];
vector<ii>g[1111];
int track[1111];
int n  ,m , s ,e ;
priority_queue<ii, vector<ii>, greater<ii> >pq;
stack<int> st;
void print_track(int now){
    if (track[now]==now ){
        st.push(now);
        return ;
    }
    st.push(now);
    print_track(track[now]);
}

void dijkstra (int start){
    for (int i = 0 ; i<1111;i++){
        d[i]=inf;
        c[i]=false ;
        track[i] = i ;
    }
    d[start]=0;
    pq.push(ii(0, start));
    while (!pq.empty()){
        ii temp = pq.top(); pq.pop();
        int  now_cost = temp.first;
        int now = temp.second;
        if (c[now])continue;
        c[now] =true;
        for (auto x : g[now]){
            int next_cost = x.first + now_cost;
            int next = x.second;
            if (d[next]> next_cost ){
                d[next] = next_cost;
                pq.push(ii(next_cost, next ));
                track[next]= now;
            }
        }
        
    }

}



int main() {
    cin >> n >> m ;
    while (m--){
        int from, to ,cost;
        scanf("%d%d%d",&from,&to,&cost);
        g[from].push_back(ii(cost,to));
    }
    cin >> s >> e ;
    
    dijkstra (s);
    print_track(e);
    printf("%d\n",d[e]);
    printf("%d\n",(int)st.size());
    while (!st.empty()){
        printf("%d ",st.top());st.pop();
    }
    
    
}

