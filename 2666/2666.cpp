#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[21];
int d[21][21][21];
int n ;
int len ;
int go (int pos , int p ,int q){
    if ( pos == len+1 ){
        return 0;
    }
    int & ret = d[pos][p][q];
    if (d[pos][p][q] != -1 )
        return ret;
    return ret =  min ( abs (p-a[pos]) +go(pos+1, a[pos],q )   , abs(q-a[pos] ) + go(pos+1,p, a[pos]) );
    
}

int main(){

    memset(d, -1 ,sizeof(d));
    scanf("%d",&n);
    int p,q;
    
    scanf("%d%d",&p,&q);
    
    scanf("%d",&len);
    for (int i =1 ; i<= len; i++){
        scanf( "%d", &a[i]) ;
    }
    
    printf("%d\n",go (1, p, q));
}
