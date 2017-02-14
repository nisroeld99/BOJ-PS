#include <iostream>

using namespace std;


int tc;
int n ;
int arr[2][100001];
int d[2][100001];
int main(){
    scanf("%d", &tc);
    
    while (tc--){
        scanf("%d",&n);
        for (int i = 0 ;  i <2 ;i++){
            for (int j=1 ; j<=n;j++){
                scanf("%d",&arr[i][j] );
            }
        }
        for (int i = 0 ;  i <2 ;i++){
            for (int j= 1 ; j<=n;j++){
                d[i][j]=0;
            }
        }
        
        d[0][1]= arr[0][1];
        d[1][1]= arr[1][1];
        d[0][2]= arr[1][1]+ arr[0][2];
        d[1][2]= arr[0][1] + arr[1][2];
        for (int i = 3; i<=n ; i++){
            d[0][i]= max (d[1][i-1]+arr[0][i] , max (d[0][i-2] ,d[1][i-2]) +arr[0][i]  )  ;
            d[1][i]= max (  d[0][i-1]+arr[1][i] , max (d[0][i-2], d[1][i-2] ) +arr[1][i]  )   ;
        }
        
        printf("%d\n",max(d[0][n],d[1][n])) ;
        
        
    
    }
    
}

