nclude <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii ;
typedef pair<ii,int> iii ;
int n , m ;
char g[12][12];

struct Point {
    int ypos,xpos;
};
Point Red,Blue,Goal;


int dy[4] ={0,0,1,-1}, dx[4] ={1,-1,0,0};
bool visit[12][12][12][12];
bool go(int ry,int rx,int by,int bx,int cnt ){
//    printf("%d %d %d %d\n",ry,rx,by,bx);
    if (( by ==Goal.ypos && bx ==Goal.xpos ) ){
        return false ;
    }
    if (ry == Goal.ypos && rx==Goal.xpos ){
        return true;
    }
    if (cnt ==10 )return false;
    
    
    for(int i = 0 ;i<4; i++){
        int nry =ry , nby =by , nbx =bx ,nrx=  rx;
        bool flag= false;
        while ( g[nry+dy[i]][nrx+dx[i]] == '.' ){
            nry+=dy[i];
            nrx+=dx[i];
            
            
            if (nry == Goal.ypos && nrx ==Goal.xpos){
                break;
            }
            if ( nry ==nby && nrx ==nbx){
                nry-=dy[i];
                nrx-=dx[i];
                flag =true;
                break ;
            }
        }
        
        while ( g[nby+dy[i]][nbx+dx[i]]=='.' ){
            nby+=dy[i];
            nbx+=dx[i];
            
            if (nby ==Goal.ypos && nbx==Goal.xpos)break;
            if ( nby ==nry && nbx ==nrx){
                nby-=dy[i];
                nbx-=dx[i];
                break ;
            }
        }
        if (flag){
            while ( g[nry+dy[i]][nrx+dx[i]] == '.' ){
                nry+=dy[i];
                nrx+=dx[i];
                
                if (nry == Goal.ypos && nrx ==Goal.xpos) break;
                if ( nry == nby && nrx == nbx){
                    nry-=dy[i];
                    nrx-=dx[i];
                    break ;
                }
            }
        }
        
        if ( visit[nry][nrx][nby][nbx] ) continue;
        visit[nry][nrx][nby][nbx]=true;
        if ( go(nry,nrx,nby,nbx,cnt+1) ) return true;
        visit[nry][nrx][nby][nbx]=false;;
    }
    return false;

}
    

int main(){
    
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++){
        
        string str;
        cin >> str;
        for (int j=0;j<m;j++){
            g[i][j+1] = str[j];
            if (str[j] == 'B'){
                Blue.ypos = i;
                Blue.xpos = j+1;
                g[i][j+1] = '.';
            }else if ( str[j] =='R'){
                Red.ypos = i;
                Red.xpos = j+1;
                g[i][j+1] = '.';
            }else if ( str[j] =='O'){
                Goal.ypos = i;
                Goal.xpos = j+1;
                g[i][j+1] = '.';
            }
        }
    }
    
    printf("%d\n",go (Red.ypos,Red.xpos,Blue.ypos,Blue.xpos,0));
    
}

