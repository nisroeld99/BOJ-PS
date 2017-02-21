#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int a[111][111];



int main(){
    int n ,m ;
    scanf("%d%d",&n,&m);
    for (int i=0 ;i<m; i++){
        int fi,se;
        scanf("%d%d",&fi,&se);
        a[fi][se] = 1;
    }
    for (int k =1; k<=n ;k++)
        for (int i = 1 ; i<=n; i++)
            for (int j=1 ;j<=n ;j++)
                if ( a[i][k] + a[k][j] ==2 )
                    a[i][j] = 1;
        
    
    for (int i = 1; i<=n ; i++){
        int cnt = 0 ;
        for (int j= 1; j<=n; j++){
            if ( a[j][i] ==1 && j!=i)
                cnt ++;
            if ( a[i][j] ==1 && j!=i)
                cnt ++ ;
        }
        printf("%d\n",n-cnt-1);
    
    }
    
    
    
}
