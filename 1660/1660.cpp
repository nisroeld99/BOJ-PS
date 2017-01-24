/*
 * 1660.cpp
 *
 */
#include <iostream>
#include <algorithm>

using namespace std;
int coin[151];
int d[300001];  //d[k]  k원 만들수 있는 가장 최소의 동전 수
void fill_array(){
    int sum = 0 ;
    coin[1]= 1 ;
    for (int i = 2; i<= 130 ; i++){
        coin[i] = coin[i-1]+ (i*i+i)/2;
    }
    
    for (int i = 0 ; i<300001; i++){
        d[i] = 987651412;
    }
}


int main(){
    
    fill_array ();
    int n = 0 ;
    scanf("%d",&n);
    d[0]=0;
    d[1]= 1;
    for (int k = 1 ; k<=130 ; k++){
        int now_val = coin[k];
        for (int i = now_val ; i<= n;i++){
            d[i] = min( d[i-now_val]+1 , d[i]) ;
        }
        
    }
    
    printf("%d\n",d[n]);
    

}
