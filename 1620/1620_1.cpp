/*
 *  1620   
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> ii ;

struct pock{
    char s[33];  //포켓몬이름
    int num; // 도감 번호
};

pock p[111111];  //이름순으로 정렬할 포켓몬 구조체 배열

string p_n[111111];  // 인덱스 값이 곧 포켓몬넘버. 포켓몬 번호 순서대로 포켓몬이름 적힌 string 배열

int n , m ;


bool cmp (const pock & a, const pock & b){
    if ( strcmp(a.s, b.s) <0 )return true;  //
    return false ;
}


int binary_p(char a[33]){
    int left = 1 , right = n;
    
    while (left <= right){
        int mid =  ( left + right ) /2 ;
        if (   strcmp(p[mid].s , a) > 0  )
            right = mid -1;
        else if ( strcmp(p[mid].s,a) < 0  )
            left = mid+1;
        else /* strcmp(p[mid].s,a)==0*/
            return p[mid].num;
    }
    exit(-1);
    
}

int main(){
   
    
    freopen("input.txt","r", stdin);
   
    
    /*
     
        출력시 모든 포켓몬들을 검색하면서, 맞는 숫자나 이름을 검색해서 일치하면 출력하는 방식은
        O(NM)의 시간복잡도 지님 --> TLE
     
        따라서 binary_search를 이용해서 빠르게 검색해보았다.
        
        
        2개의 배열을 이용했다 . ( pock p[11111]  , string p_n[11111] )
     
        
     경우 1(이름 입력시 --> 번호 출력)
            이름순대로 정렬된 배열에서 binary_search를 통해 빠른검색한다. O(NlogN)
     
     
     경우 2(번호 입력시 --> 이름 출력)
            번호순대로 저장해놓은 배열을 통해 출력한다. 검색 O(1)
     
     */
    scanf("%d%d",&n,&m);
    
    for (int i = 1 ; i<=n; i++){
        scanf("%s",p[i].s);
        p[i].num = i ;
        p_n[i] = p[i].s;
    }
    sort ( p+1 , p+n +1 ,cmp); // 이름기준 정렬하기
   
    
    
    for (int i = 1; i<=m; i++){
        char a[33];
        scanf("%s",a);
        
        if ( '0'<=a[0] && a[0]<= '9') {//숫자일때,
            printf("%s\n", p_n[atoi(a)].c_str() );
        }
        else { // 포켓몬이 주어질 때,
            printf("%d\n",binary_p(a));
        }
    }
}
