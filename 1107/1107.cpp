/*
 *  1107   
 */
#include <iostream>
#include <cstring>
using namespace std;


int button[11];


int possible (int num){
    if ( num == 0){
        if ( button[0] )
            return 1;
        else
            return 0;
    }
    
    int ret = 0 ;
    while (num!=0){
        if (!button[num%10] ){
            return 0 ;
        }
        num/=10;
        ret++;
    }
    return ret ;
}

int main(){
    int n;
    cin >> n;
    
    int m ;
    scanf("%d",&m);
    
    
    memset (button, true, sizeof(button));
    for (int i = 0 ; i<m; i++){
        int sc;
        scanf("%d",&sc);
        button[sc] = false;
    }
    
    int ans = abs(n - 100); //단순히 버튼 이동
    
    for (int i=0 ;i<=1000000; i++){
        int c = i ;
        int len = possible (c) ;
        if ( len > 0 ){ //0이면 impossible 반환)
            int press = abs(c - n );
            if ( ans > len + press){
                ans =len + press;
                
            }
            
        }
    
    }
    printf("%d\n",ans);

}
