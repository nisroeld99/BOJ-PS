/*
 * 1182.cpp
 *
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long  ll;
const int inf =987654321;

int a[22];
int ans = 0 ;
int n , m ;
void go(int now,  int sum ) {
    if (now == n ) {
        if (sum == m){
            ans ++ ;
        }
        return ;
    }
    go (now+1 , sum ); // 포함 하지 않는 경우 
    go (now+1 , sum+ a[now]);  // 포함하는 경우 
}

int main () {
/*
 *  dfs이용해서 , 집합을 순회, 
 *
 * */   
    scanf("%d%d",&n,&m);
    for (int i = 0 ; i<n ; i++ ){
        scanf("%d",&a[i]);
    }
    go (0 ,0);
    if (m== 0 ) ans -- ;
    
    printf("%d\n",ans);
        
}

