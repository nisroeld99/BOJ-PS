/*
 *  2662   
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int path[301][22];
int a[301][22], d[301][22];
int main(){
    int n , m ;
    cin >> n >> m ;
    for (int i = 1; i<= n; i++){
        int sc;scanf("%d",&sc);
        for (int j= 1;j<=m; j++){
            scanf("%d",&a[i][j]);//i원으로 j번째 투자했을때 값.
        }
    }
    
    
    for (int k = 1;k<=m; k++){  //k번째 기업까지 최대값
        for (int now =1 ;now<=n ;now++){
            
            for ( int money = 0; money<=now ;money ++){
                int now_val=  d[now-money][k-1] + a[money][k];
                if (now_val > d[now][k]){
                    d[now][k]= now_val;
                    path[now][k] = money ; // now 원으로 k번째까지 최대값일때, money원 썼다.
                }
            }
        }
    }
    
    printf("%d\n",d[n][m]);
    vector<int>ans;
    int pos = m ;
    int mo = n;
    while (true){
        if (pos ==0 ){
            break;
        }
        ans.push_back(path[mo][pos]);
        
        mo-= path[mo][pos];
        pos--;
    
    }
    for (int i = (int)ans.size()-1; i>=0 ;i--){
        printf("%d ",ans[i]);
    }
    
    
}
