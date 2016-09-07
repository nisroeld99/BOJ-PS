/*
 * 1931.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
typedef pair<int,int> ii ;
vector<ii> v; 

bool cmp (ii   a, ii  b   ){
	if ( a.second == b.second ) {
		return a.first < b.first ; 
	}
	return a.second < b.second ;
}
int main() {

	int n ;
	cin >> n;
	while (n--)  {
		int from , to ;
		scanf( "%d%d",&from, &to ) ;
		v.push_back(ii(from,to) );

	}
	sort (v.begin(), v.end(), cmp ) ;
	
	int now = 0 ; 
	int cnt = 0 ; 
	for (int i = 0 ; i<v.size()  ;i++ ) {
		int now_e=v[i].second ;
		int now_f=v[i].first ; 
		if ( now_f >= now ) {
			cnt ++ ;
			now = now_e ; 
		}
	}
	printf("%d\n", cnt ) ; 

	return 0  ;
}
