#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,char> ic;
typedef pair<int,int> ii;
int g[111][111];

int n ;
int dy[4]={0,1,0,-1}, dx[4] ={1,0,-1,0};
struct Snake{
    deque<ii> dq;
    int time, dir; // 0(동),1(남),2(서),3(북)
    
    Snake() {}
    Snake(int _y,int _x){
        dq.push_back(ii(_y,_x));
        dir = 0 ;
        time = 0 ;
    }
    bool check_range(int y,int x){
        if ( y<1 || x< 1 || y> n || x> n) return true;
        return false ;
    }
    bool go(){ //한걸음 앞으로 가는 연산
        int next_y = dq.front().first +dy[dir];
        int next_x = dq.front().second +dx[dir];
        if (check_range(next_y, next_x)){
            time ++ ;
            return false;
        }
        time ++ ;
        if ( g[next_y][next_x] == 1) { //사과면,
            //몸통은 변화가 없다
            g[next_y][next_x] = 2; // 몸통으로 갱신
            dq.push_front(ii(next_y,next_x));
            
        }else if (g[next_y][next_x] ==0  ){ //빈칸이면, 머리 차지하고, 꼬리는 날려준다.
            g[next_y][next_x] = 2;
            g[dq.back().first][dq.back().second]= 0; //비워주기
            
            dq.push_front(ii(next_y,next_x));
            dq.pop_back();
        }else { //꼬리이면 , 부딪치고 겜 끝남
            
            return false; //작업실패!
        }
        
        return true ; //작업성공!
    }
    
    void turn(char c){//방향전환하는 함수
        if (c == 'L'){
            dir = (dir-1);
            if (dir < 0 )
                dir+=4;
        }else {
            dir =(dir+1)%4;
        }
        
    }
};

int main(){
    int k;
    cin >> n >>k;
    for (int i =0 ; i<k ;i++){
        int y,x;
        scanf("%d%d",&y,&x);
        g[y][x] = 1; //사과 채우기
        
    }
    int l ;
    scanf("%d",&l);
    vector<ic> instruction;
    for (int i = 0 ; i<l ; i++){
        int a; char b;
        cin >> a>>b;
        instruction.push_back(ic(a,b ));
    }
    Snake sn(1,1) ;
    g[1][1] = 2 ;  // 뱀 몸통
    int idx = 0 ;
    int total = 0 ;
    bool chk= true;
    while (chk && idx < instruction.size() ) {
        ic now = instruction[idx++ ];
        int now_sec = now.first;
        char dir_trans = now.second;
        
        now_sec-= total;
        total += now_sec;
        
        while (now_sec--){
            if (!sn.go()) {
                chk =false;
                break;
            }
        }
        sn.turn(dir_trans) ;
    }
    if ( chk ){
        while ( sn.go());
        
    }       
    
    printf("%d\n",sn.time);
    
}

