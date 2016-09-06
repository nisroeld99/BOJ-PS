/*
 * 1654.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int>ii ;
int d[111111];
bool c [111111];
vector <ii> g[111111];
queue<int> q;
int d2,d1;
bool go (int weight ){
    memset (d, 0,sizeof(d)) ;
    memset( c, false ,sizeof(c)) ;
    q.push(d1) ;
    while (!q.empty()){
        int now = q.front();q.pop();
        
        if (c[now] ) continue;
        c[now]= true ;
        
        for (auto x : g[now]) {
            int w = x.first;
            int next = x.second;
            if ( w  <= weight ){
                continue;
            }
            q.push(next);
        }
    }
    if (c[d2])return true;
    else return false ;
        
    

    
}

int main(){
    int n , m ;
    scanf("%d%d",&n,&m) ;
    for (int i = 0 ; i< m ; i++ ) {
        int from,to,cost;
        scanf("%d%d%d",&from,&to,&cost) ;
        g[from].push_back( ii( cost , to )) ;
        g[to].push_back(ii(cost, from  )) ;
        
    }
    
    
    scanf("%d%d",&d1,&d2) ;
    
    int s = 0 ;
    int e = 1000000000;
    int mid ;
    while (s<=e ) {
        mid = (s+e)/2 ;
        if ( go (mid ) ) {//중량 오케이 올려도됨
            s= mid +1;
        }else {
            e = mid -1 ;
        }
    }
    printf("%d\n" ,s) ;
    
    
    

}


