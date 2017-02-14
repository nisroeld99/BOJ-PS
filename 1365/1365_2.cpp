#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[111111];
int d[111111];
int main()
{
    int n ;
    scanf("%d",&n);
    for (int i =1 ; i<=n ; i++)
        scanf("%d",&a[i]);
    d[1]=a[1];
    int idx = 1 ;
    for (int i =2 ; i<=n ; i++){
        if ( d[idx] < a[i]){
            d[++idx] = a[i];
            continue;
        }
        int temp = lower_bound(a+1, a+1+n , a[i]) - (a+1) ;
        d[temp] = a[i];
    }
    printf("%d\n",n-idx);
}

