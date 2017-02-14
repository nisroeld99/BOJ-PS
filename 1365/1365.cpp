#include <iostream>

using namespace std;
const int inf = 987654321;
int a[111111];
int d[111111];
int main(){
    int n ;
    scanf("%d",&n);
    for (int i =1 ; i<=n ; i++){
        scanf("%d",&a[i]);
        d[i] = inf ; 
    }


    for (int i = 1; i<=n; i++){
        d[i] = 1; 
        for (int j=i-1 ; j>=1 ;j-- ){
            if  ( a[i] > a[j] ){ // 증가라면, 
                d[i] = max (d[j]+1 , d[i] ) ;  
            }
        }
    }
    int ans = -10;
    for (int i =1 ; i<=n; i++){
        ans = max ( ans , d[i] ) ;        
    }
    printf("%d\n", n-ans );
}
