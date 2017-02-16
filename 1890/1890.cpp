#include <iostream>
#include <cstring>
using namespace std;

int a[111][111];
int d[111][111];
int dy[2] = {1,0} ;
int dx[2] = {0,1};
int n ;
int go (int ypos , int xpos){
    if ( ypos == n && xpos == n) {
        return 1;
    }
    int & ret = d[ypos][xpos] ;
    if (ret>0 ) return  ret;
    
    for (int i = 0 ; i<2; i++){
        int ny = a[ypos][xpos]* dy[i] + ypos ;
        int nx  = a [ypos][xpos] *dx[i] +xpos;
        if  (ny <1 || nx < 1 || ny > n || nx > n ) continue;
        ret+=go (ny,nx);
    }
    return ret ;
}

int main(){
    memset ( d, 0,sizeof(d));
    scanf("%d",&n);
    for (int i =1 ; i<=n ; i++){
        for (int j=1 ;j<=n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("%d\n" ,go ( 1 , 1) ) ;
}

