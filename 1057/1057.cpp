/*
 *  1057
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

int main(){
    int n , m ,k;
    cin >> n >> m >> k;
    int cnt = 0 ;
    while (true) {
        if (m==k){
            printf("%d\n",cnt);
            return 0;
        }
        cnt ++;
        k= k-k/2;
        m= m-m/2;
    }
    
}