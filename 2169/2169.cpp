#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef pair<int,int> ii;
int g[1111][1111];
int d[1111][1111];
int line[2][1111];
int dy[3]={0,1,0};
int dx[3]={1,0,-1};

int n ,m;


int main(){
    
    scanf("%d%d",&n,&m);
    for (int i =1 ; i<=n;i++){
        for (int j= 1; j<=m;j++){
            scanf("%d",&g[i][j]);
            
        }
    }
    d[1][1]=g[1][1];
    for (int i =2; i<=m; i++) {
        d[1][i]=d[1][i-1]+g[1][i];
    }
    
    
    for (int i =2 ; i<=n; i++){
        for(int j=1 ; j<=m ;j++ ){
            line[0][j]= line[1][j]= d[i-1][j]+ g[i][j];
            
        }
        for (int j=2 ; j<=m ;j++){
            line[0][j]= max ( line[0][j-1]+g[i][j] , line[0][j] );
        }
        for (int j=m-1 ;j>=1;j--){
            line[1][j]= max ( line[1][j+1]+g[i][j] ,line[1][j] );
        }
        for (int j=1 ;j<=m;j++){
            d[i][j] = max ( line[0][j] , line[1][j]);
        }
    }
    cout <<d[n][m]<<endl;
    
}
