#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int c[100001];
int d[100001];
int main(){
    int n ;
    scanf("%d",& n);
    
    for (int i =1 ; i<=n ;i++){
        scanf("%d",&c[i]);
    }
    d[1]=c[1];
    
    for (int i=2 ; i<=n; i++){
        if (d[i-1] >= 0 ){
            d[i]= d[i-1]+c[i];
        }
        else {
            d[i]=c[i];
        }
    }
    int maxx = -10000;
   
    for (int i =1 ; i<=n ;i++){
        if (d[i]> maxx){
            maxx = d[i];
     
        }
    }printf("%d\n",maxx);
}
