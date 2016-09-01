/*
 *  11724
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector<int> g[1001];
bool c[1001];
queue<int> q ;
void go (int start) {
    
    q.push(start);
    while (!q.empty()){
        int now = q.front() ; q.pop() ;
        if (c[now] ) continue;
        c[now] = true;
        for (auto x  : g[now]) {
            
            q.push(x);
            
        }
    }
}

int main() {
    int n , m ;
    cin >> n >> m ;
    while (m--){
        int from ,to ;
        scanf("%d%d",&from , &to ) ;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    int dab = 0 ;
    for (int i =1 ; i<=n;  i++ ){
        if (!c[i]) {
            dab ++ ;
            go(i);
        }
    }
    cout << dab << endl ;
}
