/*
 * 11725.cpp
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
vector<int> g[111111];
bool c[111111];
int par[111111];
int n;
void input(){
    
    cin >> n;
    int temp = n-1;
    while (temp -- ){
        int from, to;
        cin >> from>>to;
        g[from].push_back((to));
        g[to].push_back(from);
    }
}
queue<int>q;
void proc(){
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if (c[now])continue;
        c[now]=true;
        for (auto x : g[now]){
            int next= x;
            if (c[next])continue;
            par[x] = now;
            q.push(next);
        }
    }
    
    for (int i=2;i<=n;i++){
        printf("%d\n",par[i]);
    }
}

int main(){
    input();
    proc();
}
