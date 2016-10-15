/*
 * 2157.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int,int> ii;
const int inf = 987654321;
typedef long long ll ;
vector<ii> g[333];

int n , m ,k;
int d[333][333];  // d[i][j]  i에서 출발해서 목적지 n 까지 갔을 때 최대만족감, (j번째 방문 도시일때)
int go (int now,int left ){
    
    if (  left == m  ) {
        if ( now != n ) return -inf;
    }
    if ( now == n) {
        return 0 ;
    }
    int &ret =  d[now][left];
    if ( ret != -1 ) return ret ;
    ret = 0 ;
    
    for (auto x : g[now]){
        if ( x.second < now) continue;
        ret = max (ret, x.first +go ( x.second , left + 1 ) );
    }
    return ret ;
}

int main(){
    memset (d, -1,sizeof(d));
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0 ; i< k ;i++){
        int from ,to ,cost ;
        scanf("%d%d%d",&from, &to ,&cost );
        if (from >= to ) continue;
        g[from].push_back(ii(cost, to ));
    }
    printf("%d\n",go(1, 1 ));
}

