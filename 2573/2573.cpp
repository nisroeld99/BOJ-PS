/*
 * 2573.cpp
 *
 */
#include <iostream>
#include <vector>
using namespace std;
int n  ,m;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
int dab = 0 ;
int arr[301][301];
int temp[301][301];
vector<iii> v;
int cnt=0;
 
 
int WC(int ypos, int xpos){
    int ret = 0 ;
    if (!arr[ypos+1][xpos] ) ret++;
    if (!arr[ypos-1][xpos] ) ret++;
    if (!arr[ypos][xpos+1]) ret++;
    if (!arr[ypos][xpos-1])ret++;
    return ret;
}
int dy[4]={0,0,-1,1};
int dx[4] = {1,-1,0,0};
void dfs(int ypos, int xpos){
     
     
    for (int i = 0 ; i < 4 ;i++){
        int ny= dy[i] + ypos;
        int nx = dx[i] +xpos;
        if  ( ny < 0 || nx<0 || ny>=n || nx>= m )continue;
        if (!arr[ny][nx]) continue;
        arr[ny][nx]=0;
 
        dfs(ny,nx);
    }
     
}
 
int main(){
    cin>>n>>m;
    for (int i = 0 ; i<n ; i++)
        for (int j=  0 ; j<m ; j++){
            scanf("%d" , &temp[i][j] );
            arr[i][j]=temp[i][j];
        }
     
    while (true){
         
        for (int i = 0 ; i<n ; i++)
            for (int j=  0 ; j<m ; j++){
                arr[i][j]=temp[i][j];
            }
         
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ;j < m ;j++){
                if ( arr[i][j] ){
                    v.push_back( iii( WC(i,j), ii(i,j) ))   ;
                }
            }
         
        while (!v.empty()){
            if ( arr[v.back().second.first][v.back().second.second] - v.back().first <0 ) {
                arr[v.back().second.first][v.back().second.second] = 0;
                temp[v.back().second.first][v.back().second.second] = 0;
            }
            else {
                arr[v.back().second.first][v.back().second.second] -= v.back().first;
                temp[v.back().second.first][v.back().second.second] -= v.back().first;
            }
            v.pop_back();
             
        }
        dab++;
        cnt = 0;
         
    
         
         
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ;j < m ;j++){
                if (arr[i][j]){
                    cnt++;
                    arr[i][j]=0;
                    dfs(i,j);
                }
            }
         
         
         
        if (cnt>=2 ){cout<<dab<<endl; return 0;}
        if (cnt==1) continue;
        if (cnt==0) {
            cout<<"0"<<endl;
            return 0;}
    }
}
