#include <cstdio>
 
int main(){
    unsigned long long x, k, ans = 0, t=1;
    scanf("%llu %llu", &x, &k);
    int id = 0;
    while( k ){
        while( t & x )
            t*=2;
        if(k%2)
            ans += t;
        k /= 2;
        t*=2;
    }
    printf("%llu", ans);
}
