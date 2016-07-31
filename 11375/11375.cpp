#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct netflow{
    int n ;
    vector<int> g[1001];
    bool c[1001];
    int par[1001];
    
    
    netflow(int n) : n(n){
        memset(par,-1,sizeof(par));
        memset(c,false,sizeof(c));
    }
    
    void add_edge(int u,int v){
        g[u].push_back(v);
    }
    
    bool dfs(int x){
        if (x ==-1) return true; // sink로 빠지면
        for (int next : g[x]){
            if (c[next])continue;
            c[next]=true;
            if (dfs(par[next]) ){
                par[next]=x;
                return true;
            }
        }
            
        return false;
    
    }
    
    int flow(){
        
        int ret =0 ;
        for (int i =1 ; i<=n; i++){
            memset(c,false, sizeof(c));
            if (dfs(i)){
                ret++;
            }
        }
        return ret;
    }
};



int main(){
    int n , m ;
    scanf("%d%d",&n,&m);
    netflow nf(max(n,m));
    for (int i =1; i<=n; i++){
        int cnt ;
        scanf("%d",&cnt);
        while (cnt--){
            int num;
            scanf("%d",&num);
            nf.add_edge(i, num);
        }
    }
    printf("%d\n",nf.flow());
    
    
    
}
