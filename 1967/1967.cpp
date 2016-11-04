/*
 * 1967.cpp
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
vector<ii> g[111111];
int d[111111];
bool c[111111];
int n;
bool bo=false ;  ;
void input(){
    
    cin >> n;
    
    for (int i = 0 ;  i < n-1 ; i++){
        int from,to,size;
        scanf("%d%d%d",&from,&to,&size);
        g[from].push_back(ii(size,to));
        g[to].push_back(ii(size,from));
    }
}
queue<ii> q ;
int proc(int start){
    memset ( d,0,sizeof(d));
    memset (c, false, sizeof(c));
    d[start]= 0 ;
    q.push( ii(0,start) );
    while (!q.empty()){
        ii temp = q.front();
        int size= temp.first;
        int now = temp.second;
        q.pop();
        if (c[now])continue;
        c[now]=true;
        for (auto x : g[now]){
            int next_cost = size + x.first;
            int next = x.second;
            if ( c[next])continue;
            q.push(ii(next_cost,next));
            d[next]= next_cost;
        }
    }
    int ret1 = -1000;
    int ret2 = 1;
    for (int i =1 ; i <= n; i++){
        if ( ret1 < d[i]){
            ret1= d[i];
            ret2= i;
        }   
    }
    if ( bo ){
        return ret1;   
    }
    else{
        bo= true; ;
        return ret2;       
    }
}

int main(){
    input();
    printf("%d\n", proc(proc(1)) ) ;    
}
