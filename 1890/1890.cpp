
#include <iostream>
using namespace std;
typedef long long ll;
int n ;
int a[111][111];
ll d[111][111];
int dy[2] = {0,1};
int dx[2] = {1,0};
ll solve (int ypos , int xpos ){
    ll &ret = d[ypos][xpos];
    if (ret !=-1) return ret;
    
    if ( ypos == n && xpos ==n ) return 1;
    
    ret = 0 ;
    for (int i = 0 ; i <2 ;i++){
        int ny = dy[i]*a[ypos][xpos] + ypos;
        int nx = dx[i]*a[ypos][xpos] + xpos;
        if (ny > n || nx > n )continue;
        ret += solve(ny,nx);
    }
    return ret ;
}


int main() {
    cin >> n;
    for (int i = 1 ; i<=n ; i++){
        for (int j=1 ;j<=n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    memset(d,-1,sizeof(d));
    cout << solve (1,1);
    
}
