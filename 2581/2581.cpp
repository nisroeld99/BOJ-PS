#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool sosu(int n ){
    if ( n== 1 )
        return false;
    for (int i =2; i*i<=n ; i++){
        if ( n%i==0){
            return false ;
        }
    }
    return true ;
}

int main(){
    int n ,m;
    cin >> n >> m;
    long long ret = 0 ;
    int minn = 987654321; ;
    int cnt = 0 ;
    for (int i =n ; i<=m ; ++i){
        if (sosu(i)) {
            ret+= i ;
            minn = min (minn, i );
            cnt ++;
        }
    }
    if (cnt )
        printf("%lld\n%d\n",ret,minn);
    
    else
        printf("-1\n");
    
}
