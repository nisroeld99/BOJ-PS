/*
 * 1759.cpp
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 
 
int l, c;
char a[16];
 
void go(int now ,int cnt ,string s ){
    if (now == c ) {  // 길이가 c 만큼되면 완료 제약조건.. 
        if (cnt == l){  
            int ja = 0, mo = 0;
            for (int i = 0; i < s.size(); i++){
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') mo++;
                else ja++;
            }
            if (mo >= 1 && ja >= 2){
                cout << s << endl;
            }
        }
        return;
    }
    go(now + 1, cnt + 1, s + a[now]);
    go(now + 1, cnt, s);
     
 
}
int main(void) {
/*
 *  앞서 풀었던 부분집합의 합과 유사하지만, 
 *  탈출 제약조건이 복잡한 문제이다. 코드 줄 따라 잘 읽어보면된다.
 *
 *
 * */ 


    scanf("%d%d", &l, &c);
    for (int i = 0; i < c; i++){
        cin >> a[i];
    }
 
    sort(a, a + c);
     
     
    go(0,0,"");
 
    return  0;
 
}
