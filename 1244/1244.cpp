/*
 * 1244.cpp
 *
 */
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int a[101];
int n ;
void go ( int now ){
    a[now] = 1-a[now];
    int cnt = 1;
    while ( a[now-cnt] == a[now+cnt] && now-cnt >=1 && now+cnt <=n){
        a[now-cnt] = 1- a[now-cnt];
        a[now+cnt] = 1- a[now+cnt];
        cnt ++ ;
    }
    return ;
}
int main(int argc, char** argv) {
    
    freopen("input.txt", "r", stdin);
    
    scanf("%d",&n);
    for (int i = 1 ; i<=n ; i++){
        scanf("%d", &a[i]) ;
    }
    
    
    int k ;
    scanf("%d",&k);
    for (int i = 0 ;i <k ;i++){
        int g, sc;
        scanf("%d%d",&g, &sc);
        if ( g == 1 ){
            
            for (int i =sc ;i<=n ; i= i+sc ){
                a[i]  = 1-a[i];
            }
            
        }
        else if (g==2){
            go ( sc );
            
        }else {
            
        }
        
    }
    
    for (int i =1 ; i<=n ;i++){
        if (  i%20 == 1 ){
            if (i==1){}
            else printf("\n");
        }
        printf("%d ",a[i]);
        
        
    }
    printf("\n");
}
