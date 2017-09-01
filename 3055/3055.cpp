nclude <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair <int , int>  ii;
typedef pair<int ,ii> iii;
int n , m;
const int inf =987654321;

char a[55][55];
int d[55][55];
int SY, SX;
int DY, DX;
bool c[10000];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
deque<ii> tempwater;
void water(){
    for (int i =1; i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]=='*'){
                tempwater.push_back(ii(i,j));
            }
        }
    }
    while (!tempwater.empty()){
        int i= tempwater[0].first;
        int j = tempwater[0].second;
        for (int k = 0 ; k<4; k++){
            int y = i+dy[k];
            int x = j+dx[k];
            if (y<1 || x<1 || y>n || x > m) continue;
            if (a[y][x] == 'X' || a[y][x]=='D')continue;
            a[y][x]='*';
        }
        tempwater.pop_front();
    }
}

priority_queue<iii,vector<iii>,greater<iii> > pq;
void go (int ypos, int xpos){
    d[ypos][xpos]= 0 ;
    pq.push(iii(0,ii(ypos,xpos)));
    while(!pq.empty()){
        
        iii temp = pq.top(); pq.pop();
        int nowW=temp.first;
        int nowY= temp.second.first;
        int nowX = temp.second.second;
        if (!c[nowW]){
            water();
        }
        c[nowW]=true;
        for (int i = 0 ; i<4 ; i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            if (nextY > n || nextX >m || nextY <1 || nextX < 1 )continue;
            if (a[nextY][nextX] == '*' || a[nextY][nextX]=='X') continue;
            if (d[nextY][nextX] > d[nowY][nowX] + 1){
                d[nextY][nextX] = d[nowY][nowX] + 1;
                pq.push(iii(d[nextY][nextX] , ii(nextY,nextX)));
            }
                
        }
        
    }
    
    
    
}

int main(){
    scanf("%d%d",&n,&m);
    
    for (int i = 1 ; i<=n ; i++){
        string s;
        cin >> s;
        for (int j=0;j<m; j++){
            a[i][j+1]=s[j];
            if (s[j]=='S') {
                SY=i, SX=j+1;
            }
            if (s[j]=='D'){
                DY=i, DX=j+1;
            }
        }
    }
    for (int i = 1 ; i<=n;i++)
        for (int j=1;j<=m;j++)
            d[i][j] = inf;
    
    go(SY,SX);
    
//    for (int i = 1 ; i<=n;i++){
//        for (int j=1;j<=m;j++){
//            if (d[i][j]==987654321)
//                cout<<"inf"<<' ';
//            else {
//                cout <<d[i][j]<<' ';
//            }
//        }
//        printf("\n");
//    }
//    for (int i = 1 ; i<=n;i++){
//        for (int j=1;j<=m;j++){
//            
//            
//            
//                cout <<a[i][j]<<' ';
//           
//        }
//        printf("\n");
//    }
    if (d[DY][DX]<inf){
        printf("%d\n",d[DY][DX]);
    }
    else {
        printf("KAKTUS\n");
    }
}
