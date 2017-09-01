#include<cstdio>
#include<vector>
#include <cstring>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii ;
typedef pair<ii,ii> iiii ;
typedef pair<ii,int> iii ;
typedef pair<long,long >lili;
typedef pair<double,double> dd;

#define E 1
#define W 2
#define N 3
#define S 4



const int inf =987654231;
const int mod = 1000000007;
int g[22][22];
struct Point {
    int ypos ,xpos;
    int now[7] ={0,0,0,0,0,0,0};
    
    Point(){}
    Point(int _y, int _x){
        ypos =_y, xpos = _x;
    }
    void Change(int dir, int idx  ){
        int temp [7] ={0,};
        for (int i = 0 ; i<7 ;i++){
            temp[i] = now[i];
        }
        switch (dir){
            case E : //동  3-->6 , 6-->4 , 4-->2 , 2-->3 , 1-->1 , 5-->5
                now[1] = temp[1];
                now[2] = temp[3];
                now[3] = temp[6];
                now[4] = temp[2];
                now[5] = temp[5];
                now[6] = temp[4];
                break;
                
            case W : // 서   4-->6 , 6-->3 ,  3-->2 , 2-->4
                now[1] = temp[1];
                now[2] = temp[4];
                now[3] = temp[2];
                now[4] = temp[6];
                now[5] = temp[5];
                now[6] = temp[3];
                break;
            case S :   // 남 5-->6 , 2-->5 , 1-->2 , 6-->1
                now[1] = temp[2];
                now[2] = temp[5];
                now[3] = temp[3];
                now[4] = temp[4];
                now[5] = temp[6];
                now[6] = temp[1];
                break;
            case N :     //북 6-->5 , 5-->2 , 2-->1 , 1-->6
                now[1] = temp[6];
                now[2] = temp[1];
                now[3] = temp[3];
                now[4] = temp[4];
                now[5] = temp[2];
                now[6] = temp[5];
                break;
        }
        if ( idx == 1){  // 만약에 바닥에 원래 숫자가 있었더라면
            now[6] = g[ypos][xpos] ;
            g[ypos][xpos] =0;
        }else {
            g[ypos][xpos]=now[6];
        }
        printf("%d\n",now[2]);
        
    }
};


int n , m ,sy,sx , instr ;
bool inRange(int y ,int x){
    if (y<0 || x< 0 || y>=n || x>=m) return false;
    return true ;
}

int dy[5] = {0,0,0,-1,1} , dx[5] ={0,1,-1,0,0};  // 1 동 2 서 3 북 4 남
int main(){
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d%d",&n,&m,&sy,&sx,&instr);
    for (int i =0  ;i<n; i++)
        for (int j=0;j<m; j++)
            scanf("%d",&g[i][j]);
    
    
    Point dice = Point(sy,sx);
    g[sy][sx] = 0 ;
    for (int i = 0 ;i< instr; i++){
        int sc;
        scanf("%d",&sc);
        Point now = dice;
        
        int now_y = now.ypos;
        int now_x = now.xpos;
        int ny = now_y + dy[sc];
        int nx = now_x + dx[sc];
        
        if ( !inRange(ny,nx ))continue;
        
        dice.ypos=ny , dice.xpos = nx;
        
        if ( g[ny][nx]== 0){
            switch (sc){
                case E : //동
                    dice.Change(E,0);
                    
                    break;
                    
                case W :
                    dice.Change(W,0);
                    break;
                case N :
                    dice.Change(N,0);
                    break;
                    
                case S :
                    dice.Change(S,0);
                    break;
                    
            }
        }else {  //주사위를 바닥에 복사해야함
            switch (sc){
                case E : //동
                    dice.Change(E,1);
                    
                    break;
                    
                case W :
                    dice.Change(W,1);
                    break;
                case N :
                    dice.Change(N,1);
                    break;
                    
                case S :
                    dice.Change(S,1);
                    break;
                    
            }
        }
        
    }
    
}
