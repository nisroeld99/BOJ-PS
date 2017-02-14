#include <iostream>

using namespace std;
int a[111];
int d[11111];
const int inf = 987654321;
int main(){
    int n , k;
    scanf("%d%d",&n,&k);
    
    for (int i =1 ;i<=n ; i++)
        scanf("%d",&a[i]);
    
    for (int i = 1 ; i<=k; i++)
        d[i]= inf ;
    
    d[0] = 0 ;
    for (int i = 1; i<=n; i ++){
        int now_val = a[i];
        for (int j= now_val ; j<=k;j++){
            d[j] =  min(d[j], d[j-now_val]+1) ;
        }
    }
    if ( d[k] != inf ) printf("%d\n", d[k]);
    else printf("-1\n");
}

