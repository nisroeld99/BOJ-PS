#include <iostream>
using namespace std;

int main(){
    long long d[99][2];
    int n;
   cin >>n ;

    d[1][1] = 1; 
    for (int i =2 ; i<= n; i++){
        d[i][0] = d[i-1][1] + d[i-1][0];
        d[i][1] = d[i-1][0] ;
    }
    
    printf("%lld\n", d[n][0] +d[n][1]);

}
