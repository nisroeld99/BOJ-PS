#include <iostream>
#include <cstring>
using namespace std;

int from,to,cost;
int g[111][111];
int main(){
    int n, road  ;
    scanf("%d%d",&n,&road);
    
    for (int i =1; i<=n ;i++)
        for (int j=1 ;j<=n ;j++)
            g[i][j] = 987654321;
        
    
    
    for (int i = 0; i<road ; i++){
        scanf("%d%d%d",&from,&to,&cost);
        g[from][to] = min (cost, g[from][to])  ;
    }
    
    
    for (int k =1; k<=n ; k++){
        for (int i=1 ; i<=n ;i++ ){
            for (int j=1 ;j<=n ;j++){
                if ( g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] +g[k][j] ;
            }
        }
    }
    for (int i =1; i<=n;  i++){
        for (int j= 1; j<=n; j++){
            if ( i==j )printf("0 ");
            else printf("%d ",g[i][j]);
        }printf("\n");
    }
    
}

