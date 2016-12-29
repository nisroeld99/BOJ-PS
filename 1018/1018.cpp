/*
 * uc18.cpp
 *
 */

/*
 
Brute force 문제
 
 1. 8*8의 모든 경우를 찾는다. n이 50이므로 42*42  = 1726 경우
 2. 8*8의 체스판을 뽑으면 그 중 최소 수정 값을 갱신해준다.
 3. 최소값 출력 해준다 .
 
 */

#include <iostream>
#include <algorithm>

using namespace std ;

const int inf = 987654321;

char a[51][51];


int dab=inf;
int n , m ;


int checkPerfectRow ( int row , int col ,int IDX ) {//몇번째줄이 perfect인지 확인하는 함수
    
    string WB = "WBWBWBWB";
    string BW = "BWBWBWBW";
    
    string now ;
    int cnt = 0 ;
    
    IDX%2 ==0 ? now =WB : now=BW;
    
    for (int i = col ; i< col + 8 ; i++){
        if  (now[i-col]  != a[row][i] ){
            cnt ++ ;
        }
    }
    return cnt ;
}

void go ( ){
    
    /* 50*50 중 8*8 시작지점 찾기   */
    
    for (int i = 1; i<=n-7 ; i++){
        for (int j=1 ;j<=m-7; j++){
            int cnt = 0 ;
            
            //첫번째 row가 WBWB 패턴
            for (int k = i ;   k <= i+7  ; k++){
                cnt += checkPerfectRow(k , j, k-i );
            }
            dab= min ( dab, cnt );
            cnt = 0 ;
            
            //첫번째 row가 BWBW 패턴
            for (int k= i ;  k<= i+7 ; k++){
                cnt += checkPerfectRow(k, j,  1+k-i );
            }
            dab= min ( dab, cnt );
        }
    }
}

void input (){

    for (int i = 1; i<=n;  i++){
        for (int j=1 ;j<=m;j ++){
            scanf("%c", &a[i][j]  );
        }getchar();
    }
    
    
}


int main()

{
    freopen("input.txt", "r",stdin);

    scanf("%d%d",&n,&m);
    getchar();
    input() ;
    
    go();
    
    
    printf("%d\n",dab);
    
}
