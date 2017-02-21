#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

/* u&f 구현 */


int par[1111];

void init(){
    for (int i =0 ; i<1111;i++)
        par[i] = i;
}
int find(int a){
    if ( a != par[a] ){//부모가 아니면
        return par[a] = find (par[a]);
    }else {
        return a; //부모
    }
}
void _union(int a, int b){
    a = find(a);
    b = find(b);
    if (a==b){ //이미 같은 그룹 집합일 경우 아무것도 하지 않는다.
        
    }else {
        par[a]= b;
    }
    return ;
}



int main(){
    
    init();
    
    
    int n , m ,k;
    scanf("%d%d%d",&n,&m,&k);
    
    
    int sc1;
    scanf("%d",&sc1);
    _union(sc1, 0);
    
    for (int i = 0 ;i<k-1; i++){
        int sc1;
        scanf("%d",&sc1);
        _union(sc1, 0);
    }
    
    vector<iii> v;
    for (int i = 0 ; i<m ; i++){
        int from,to ,cost;
        scanf("%d%d%d",&from,&to,&cost);
        v.push_back(iii(cost,ii(from,to)));
    }
    sort(v.begin(),v.end());
    int ans = 0 ;
    for (int i = 0 ;i<v.size(); i++){
        if ( find(v[i].second.first ) == find(v[i].second.second)) { //같으면 continue;
            continue;
        }else {
            ans += v[i].first;
            _union(v[i].second.first , v[i].second.second);
        }
    }
    
    printf("%d\n",ans);
    
}

