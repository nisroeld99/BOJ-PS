/*
 * 9663.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int inf = 987654321;
int cols[16];
int n ;
bool promise (int now){
    bool ok =true;
    for (int i=1; i<now && ok;i++){
        if (cols[now] == cols[i] || abs(cols[now]-cols[i]) == abs(now-i)){
            ok =false;
            break;
        }
    }
    return ok;
}
int dab=0;
void nqueen(int now){
    if (promise(now)){
        if (now == n){
            dab++;
        }
        else {
            for (int i=1 ; i<=n ;i++){
                cols[now+1] = i;
                nqueen(now+1);
            }
        }
     
     
    }
}
int main(){
    cin >> n;
    nqueen(0);
     
    cout << dab<< endl;
}
