#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector<int> g[1001];
bool c[1001];
void go (int now) {
    printf("%d ",now) ;
    c[now] = true;
    for (auto x : g[now] ) {
        if ( c[x] ) continue ;
        c[x] = true;
        go (x) ;
        
    }
    
}
queue<int> q;
void go2(int start){
    memset(c, false ,sizeof(c)) ;
    q.push(start) ;
    while (!q.empty()) {
        int now = q.front() ;
        q.pop() ;
        if (c[now] ) continue ;
        c[now] = true;
        printf("%d ",now);
        for (auto x : g[now] ) {
            q.push (x) ;
        }
    }
    
}


int main(){
    int n,m , v ;
    cin >> n>> m>> v;
    while (m--){
        int from,to;
        scanf("%d%d",&from,&to) ;
        g[from].push_back(to) ;
        g[to].push_back(from) ;
    }
    for (int i =1 ; i<=n ; i++ ) {
        sort( g[i].begin() , g[i].end() ) ;
    }
    
    go(v);  
    printf("\n");
    
    go2(v);
}

