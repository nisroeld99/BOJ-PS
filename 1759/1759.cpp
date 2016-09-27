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
    if (now == c ) {
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
    scanf("%d%d", &l, &c);
    for (int i = 0; i < c; i++){
        cin >> a[i];
    }
 
    sort(a, a + c);
     
     
    go(0,0,"");
 
    return  0;
 
}
