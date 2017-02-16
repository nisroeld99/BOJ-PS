#include <iostream>

using namespace std;
int d[1111];
const int mod = 10007;
int main(){
    int n;
    scanf("%d",&n);
    
    d[1] = 1; 
    d[2] = 3;

    for (int i =3 ; i<=n; i++)
        d[i] = (d[i-1]%mod +2 *d[i-2]%mod)%mod;
    
    printf("%d\n",d[n]%mod);

}
