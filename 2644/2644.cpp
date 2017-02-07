/*
 *  2644   
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf =987654321;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;



vector<int >g[111];

int dist =  0 ;
bool c[111];
int d[111];
queue<int>q;
void bfs(int from,int to){
    q.push(from);
    while(!q.empty()){
        int now = q.front();q.pop();
        if (c[now])continue;
        c[now]=true;
        for (int i = 0 ;i<g[now].size(); i++){
            int next = g[now][i];
            if (c[next])continue;
            d[next]= d[now]+1;
            q.push(next);
        }
    }
}


int main(){
	/*일반적인 bfs문제이다. 다만 인접리스트로 구현되어있을뿐이다:*/
    int n;
    scanf("%d",&n);
    int from,to;
    scanf("%d%d",&from,&to);
    int num;
    scanf("%d",&num);
    while (num--){
        int f,s;
        scanf("%d%d",&f,&s);
        g[f].push_back(s);
        g[s].push_back(f);
    }
    bfs(from,to);
    if (from == to){
        printf("0\n");
    }
    else if (d[to]!=0){
        cout<<d[to]<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

