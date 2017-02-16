#include <iostream>

using namespace std;

const int mod = 9901;

int d[111111][3]; //0 , 1 , 2 
int main(){
    int n ;
    scanf("%d",&n);
    
    d[1][0] = 1; d[1][1]= 1; d[1][2] = 1; 

   for (int i =2; i <=n ; i++) 
   {
         d[i][0] =( d[i-1][0] + d[i-1][1] + d[i-1][2] )%mod;
         d[i][1] = (d[i-1][0] + d[i-1][2] )%mod;
         d[i][2] = (d[i-1][0] + d[i-1][1] )%mod; 
   }

   printf("%d\n", (d[n][0] + d[n][1] + d[n][2])%mod );
   return 0 ;   
}
