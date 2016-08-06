/*
 *  1068   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int par[55];
vector<int>g[55];
int cnt = 0 ;
void go(int v){
    if (g[v].size()==0) cnt++;
    if (g[v].size()==1 && g[v][0] == -2) {
        if (  par[v]==-1  ){
            return;
        }
        if ( g[ par[ v] ].size() == 1 )
            cnt++;
        return;
    }
    for (int i = 0 ;i<g[v].size() ; i++){
        go ( g[v][i] );
    }
    
}


int main(){
    int n ;
    vector<int> start;
    scanf("%d",&n);
    for (int i = 0 ;i<n; i++){
        int sc1;
        scanf("%d",&sc1);
        if (sc1==-1){
            start.push_back(i);
            par[i]=-1;
        }
        if (sc1!=-1){
            g[sc1].push_back(i);
            par[i]=sc1;
        }
        
    }
    int m ;
    scanf("%d",&m);
    
    g[m].clear();
    g[m].push_back(-2);
    
    for (auto x : start){
        go(x);
    }
    cout << cnt<<endl;	

}
