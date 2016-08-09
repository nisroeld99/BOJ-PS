/*
 * 2410.cpp
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii> iii ; 
const int inf =987654321;
const int mod = 1000000000;

int d[1000001];
int main(){
	int n ;
	cin >> n;
	d[0] =1 ;
	for (int i =1 ; i <= n; i*=2 ) {
		int nowCoin = i ;
		for (int j= nowCoin ;j<=n  ;j++ ){
			d[j] += d[j-nowCoin];
			d[j]%=mod;
		}
	}
	cout << d[n]<<endl;
	return 0 ;
}
