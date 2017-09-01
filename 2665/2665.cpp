#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair <int , int>  ii;
typedef pair<int ,ii> iii;
const int inf = 97654321;
int a[55][55];
int d[55][55];


int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int n ;
priority_queue<iii>pq;
void go (int ypos , int xpos ){
    d[1][1]= 0;
    pq.push(iii( 0,ii(ypos,xpos)));
    while (!pq.empty()){
        iii now = pq.top(); pq.pop();
        int nowW=now.first;
        int nowY=now.second.first;
        int nowX=now.second.second;
      
        
        for (int i = 0 ;i<4;i++){
            int nextY= nowY + dy[i];
            int nextX= nowX + dx[i];
            if (nextY <1 || nextX < 1 || nextY >n ||nextX>n) continue;
            int cost;
            if (a[nextY][nextX] == 0)cost = 1;
            else cost =0;
            
            if (d[nextY][nextX] > cost + nowW  ){
                d[nextY][nextX] = cost + nowW;
                pq.push(iii(d[nextY][nextX],ii(nextY,nextX)));
                
            }
            
            
        }
    }
}

int main(){
    
    
    scanf("%d",&n);
    
    //그래프 입력
    for (int i = 1; i <=n ; i++){
        string s;
        cin>> s ;
        for (int j=0;j<=n-1;j++){
            a[i][j+1]= s[j]-48;
        }
    }
    for (int i = 0 ; i<=n;i++){
        for (int j=0;j<=n ;j++){
            d[i][j]=inf;
        }
        
    }
    
    go ( 1 , 1 );
   
    cout << d[n][n]<< endl;
}
