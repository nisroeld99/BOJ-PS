#include <iostream>

using namespace std;
const int inf = -987654321;
int a[1111];
int d[1111];
int main(){
    int n ;
    scanf("%d",&n);
    for (int i =1 ; i<=n ;i++)
        scanf("%d",&a[i]);
    d[1] = 1;
    for (int i = 2; i<=n; i++){
        d[i] = 1 ;
        for (int j= i-1 ; j>=1; j--){
            if ( a[i] < a[j] ){
                if ( d[j] +1 > d[i]){
                    d[i] = d[j]+ 1;
                }
            }
        }
    }
    int ans = -10 ;
    for (int i= 1; i<=n; i++){
        ans =  d[i] > ans? d[i] : ans ;
    }
    printf("%d\n",ans);
}

