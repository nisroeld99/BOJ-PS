#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

/* u&f 구현 */


int par[1111111];

void init(){
    for (int i =0 ; i<1111111;i++)
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
    
    int n , m ;
    scanf("%d%d",&n,&m);
    for (int i = 0 ; i< m ;i++){
        int sc1;
        scanf("%d",&sc1);
        int sc2,sc3;
        scanf("%d%d",&sc2,&sc3);
        if (sc1==0){
            _union(sc2, sc3);
        }else{
            if ( find (sc2 ) ==find(sc3)){
                printf("YES\n");
            }else {
                printf("NO\n");
            }
                
                
        }
    }
    
}
