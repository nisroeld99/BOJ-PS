#include <iostream>
using namespace std;
typedef  long long ll;
ll d[101];
int main(){
    int n;
    scanf("%d",&n);
    d[1] =1;
    d[2] =2;
    d[3] =3;
    for (int i =4 ; i<=n; i++ ){
        d[i] = d[i-1]+1;
        for (int j = i-3 ; j>=1; j--){
            d[i] = max ( d[i] , d[j] * ( i-j-1  ) );
        }
    }
    cout <<d[n]<<endl;
    
    
}
