/*
 *  1939   
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;

vector<ii> g[10001];
int d1,d2;
bool c[10001];
queue<int >q ;
bool go (int wei){
    
    memset(c, false,sizeof (c));
    while (!q.empty())q.pop();
    q.push(d1);
    while (!q.empty()){
        int now = q.front();q.pop();
        if (c[now])continue;
        c[now]= true;
        if ( now == d2 ) return true;
        for (auto x : g[now]){
            int next = x.first;
            int next_wei = x.second;
            if (next_wei <= wei){
                continue;
            }
            q.push(next);
            
        }
    }
    return false ;
}
int main(){
    int n , m ;
    cin >> n >> m ;
    
    for (int i =0 ;  i< m ;++i){
        int from,to,cost;
        scanf("%d%d%d",&from,&to,&cost);
        g[from].push_back(ii(to,cost));
        g[to].push_back(ii(from,cost));
    }
    cin >> d1>> d2;
    
    int left, right,mid;
    left = 0 , right = 1000000000;
    while ( left <=right){
        mid = (left+ right)/2;
        if ( go (mid) ){
            left= mid +1;
        }else {
            right = mid -1;
        }
    }
    printf("%d\n",left);
    
}
