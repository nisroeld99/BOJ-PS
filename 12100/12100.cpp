nclude <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii ;
typedef pair<ii,int> iii ;
int n ;
int ans = -10;

void cal_max(vector<vector<int>> & g ){
    for (int i=1; i<=n; i++)
        for (int j=1 ;j<=n ;j++)
            if (g[i][j] > ans ) ans = g[i][j];
}

void set_copy(vector<vector<int>> &pcopy, const vector<vector<int>> & p){
    for (int i=1; i<=n;i++){
        for (int j=1;j<=n;j++){
            pcopy[i][j] = p[i][j];
        }
    }
}

void go (int cnt , vector<vector<int>>& v ){
//    for (int i =1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            printf("%d ",v[i][j]);
//        }printf("\n");
//    }printf("\n");
//    
    
    if ( cnt ==5 ){ //탈출 조건 4^5
        cal_max(v);
        return ;
    }
    
    vector<vector<int>> copy(22);
    for (int i =0 ; i<22; i++){  //복사본 생성
        copy[i].resize(22);
    }
    
    queue <int> q;
    
    //위
    set_copy(copy,v);
    for (int i =1; i<=n; i++){ // 1줄 copy하기
        const int now_x = i;
        for (int j=1; j<=n; j++){
            if (copy[j][now_x]!=0){
                q.push(copy[j][now_x] );
            }
        }
        
        int idx= 1;
        while (!q.empty()){
            int now = q.front(); q.pop();
            if ( !q.empty()){ // 2개이상남아있을때,
                int next = q.front(); q.pop();
                if (next == now){ //같을 경우? -->합친다
                    copy[idx++][now_x] = now*2;
                    
                }else { // 다를 경우,
                    copy[idx++][now_x] = now;
                    if (!q.empty()){ //그다음꺼도 확인,
                        if ( next == q.front() ){
                            copy[idx++][now_x] = next*2;
                            q.pop();
                        }else {
                            copy[idx++][now_x] = next;
                        }
                        
                    }else {
                        copy[idx++][now_x] =next;
                    }
                    
                }
                
            }else { //1개 짜리일때 무조건 넣기,
                copy[idx++][now_x] = now;
            }
        }
        while (idx<=n){
            copy[idx++][now_x]= 0;
        }
        
    }
    go(cnt+1, copy);
    
    //아래
    set_copy(copy,v);
    
    for (int i =1; i<=n; i++){ // 1줄 copy하기
        const int now_x = i;
        for (int j=n; j>=1; j--){
            if (copy[j][now_x]!=0){
                q.push(copy[j][now_x] );
            }
        }
        
        int idx= n;
        while (!q.empty()){
            int now = q.front(); q.pop();
            if ( !q.empty()){ // 2개이상남아있을때,
                int next = q.front(); q.pop();
                if (next == now){ //같을 경우? -->합친다
                    copy[idx--][now_x] = now*2;
                    
                }else { // 다를 경우,
                    copy[idx--][now_x] = now;
                    if (!q.empty()){ //그다음꺼도 확인,
                        if ( next == q.front() ){
                            copy[idx--][now_x] = next*2;
                            q.pop();
                        }else {
                            copy[idx--][now_x] = next;
                        }
                        
                    }else {
                        copy[idx--][now_x] =next;
                    }
                    
                }
                
            }else { //1개 짜리일때 무조건 넣기,
                copy[idx--][now_x] = now;
            }
        }
        while (idx>=1){
            copy[idx--][now_x]= 0;
        }
        
    }
    go(cnt+1,copy);
    
    
    
    
    // 왼
    set_copy(copy,v);
    for (int i =1; i<=n; i++){ // 1줄 copy하기
        const int now_y = i;
        for (int j=1; j<=n; j++){
            if (copy[now_y][j]!=0){
                q.push(copy[now_y][j] );
            }
        }
        
        int idx= 1;
        while (!q.empty()){
            int now = q.front(); q.pop();
            if ( !q.empty()){ // 2개이상남아있을때,
                int next = q.front(); q.pop();
                if (next == now){ //같을 경우? -->합친다
                    copy[now_y][idx++] = now*2;
                    
                }else { // 다를 경우,
                    copy[now_y][idx++] = now;
                    if (!q.empty()){ //그다음꺼도 확인,
                        if ( next == q.front() ){
                            copy[now_y][idx++] = next*2;
                            q.pop();
                        }else {
                            copy[now_y][idx++] = next;
                        }
                        
                    }else {
                        copy[now_y][idx++] =next;
                    }
                    
                }
                
            }else { //1개 짜리일때 무조건 넣기,
                copy[now_y][idx++] = now;
            }
        }
        while (idx<=n){
            copy[now_y][idx++]= 0;
        }
        
    }
    go(cnt+1,copy);
    
    
    
    
    //오
    set_copy(copy,v);
    
    
    for (int i =1; i<=n; i++){ // 1줄 copy하기
        const int now_y = i;
        for (int j=n; j>=1; j--){
            if (copy[now_y][j]!=0){
                q.push(copy[now_y][j] );
            }
        }
        
        int idx= n;
        while (!q.empty()){
            int now = q.front(); q.pop();
            if ( !q.empty()){ // 2개이상남아있을때,
                int next = q.front(); q.pop();
                if (next == now){ //같을 경우? -->합친다
                    copy[now_y][idx--] = now*2;
                    
                }else { // 다를 경우,
                    copy[now_y][idx--] = now;
                    if (!q.empty()){ //그다음꺼도 확인,
                        if ( next == q.front() ){
                            copy[now_y][idx--] = next*2;
                            q.pop();
                        }else {
                            copy[now_y][idx--] = next;
                        }
                        
                    }else {
                        copy[now_y][idx--] =next;
                    }
                    
                }
                
            }else { //1개 짜리일때 무조건 넣기,
                copy[now_y][idx--] = now;
            }
        }
        while (idx>=1){
            copy[now_y][idx--]= 0;
        }
        
    }
    go(cnt+1,copy);
    
    
    
}


int main(){
    
    vector<vector<int>> g(22);
    
    scanf("%d",&n);
    for (int i =1; i<=n; i++){
        g[i].push_back(0);
        for (int j=1; j<=n; j++){
            int sc;
            scanf("%d",&sc);
            g[i].push_back(sc);
        }
    }
    go (0,g);
    printf("%d\n",ans);
}
