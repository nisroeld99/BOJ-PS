#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii ;
typedef pair<ii,ii> iiii ;
typedef pair<ii,int> iii ;
typedef pair<long,long >lili;
typedef pair<double,double> dd;
const int inf =987654231;
const int mod = 1000000007;
struct Point {
    int ypos ,xpos,cnt;
    Point(){}
    Point(int _y, int _x, int _c){
        ypos =_y, xpos = _x;
        cnt =_c;
    }
};
int n ;

bool c[200010];
vector<vector<int> > g(200010);


int ans = 0;

int d[200011];

void bfs(int start){
    queue<int>q;
    c[start]=true;
    q.push(start ) ;
    d[start] = 0;
    while (!q.empty()){
        
        int size =(int) q.size();
        for (int i = 0 ; i<size ;i++){
            
            int now =q.front();
            q.pop();
            if ( now == n) {
                ans =1 ;
                break;
            }
            for (int i =0 ; i<g[now].size(); i++){
                int next = g[now][i];
                if ( c[next]) continue;
                c[next] =true ;
                q.push((next));
                d[next] =d[now]+1;
            }
        }
        
    }

}

int main(){
    int  k , m;
    scanf("%d%d%d", &n , &k, &m );
    for (int i =0 ; i<m; i++){//튜브1
        for (int a = 0 ; a<k ;a++){
            int v;
            scanf("%d",&v);
            g[v].push_back(i+100001);
            g[i+100001].push_back(v);
        }
    }
    bfs(1);
    if (ans ==0 ) printf("-1");
    else printf("%d\n",d[n]/2+1);
}

