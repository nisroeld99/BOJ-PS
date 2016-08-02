#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int> g[100001];
bool c [100001];
queue<int> q;
int go (int start){
    memset(c, false , sizeof(c));
    q.push(start);
    int cnt = 0 ;
    while (!q.empty()){
        int now  = q.front(); q.pop();
        if ( c[now])continue;
        c[now] = true ;
        cnt ++ ;
        for (auto next : g[now]){
            q.push(next);
        }
    }
    return cnt ;
}

int main(){
    int n , m ;
    cin >> n >> m ;
    
    for (int i = 0 ; i<m ;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[b].push_back(a);
    }
    vector<int> dab ;
    int temp [100001];
    int maxx = -100000;
    for (int i = 1; i <=n; i++){
        temp[i]=go(i);
        maxx = max(temp[i], maxx);
    }
    for (int i = 1 ; i<=n; i++){
        if ( temp [ i] == maxx){
            dab.push_back(i);
        }
    }
    for (auto x : dab){
        printf("%d ",x);
    }printf("\n");
    
    
    
}



