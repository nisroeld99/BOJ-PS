nclude <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int d[1000001];
 
int go (int n ){
    if (n==1) {
        return 0;
    }
    int &ret = d[n];
    if (ret != -1) return ret; 
    if ( n%3==0 && n%2 == 0 ) {
        return ret=min(1+ go(n/3)  ,min( 1+go(n/2) , 1+go(n-1) ));
    }else if ( n%3==0){
        return ret=min( 1+ go(n-1) , 1+ go(n/3));
    }else if (n%2==0){
        return ret=min( 1+ go(n-1) , 1+ go(n/2));
    }else {
        return ret=1+go(n-1);
    }
}
 
int main(){
    int n;
    cin >> n;
    memset(d,-1,sizeof(d));
    printf("%d\n", go(n));
    return 0 ;
}
