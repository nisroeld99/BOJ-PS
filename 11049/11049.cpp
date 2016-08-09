/*
 * 11049.cpp
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii> iii ; 
int main(){
	int n ;
	scanf("%d",&n);
	vector<ii> v (1+n); 
	for (int i =1 ; i<=n ; i++){
		int a,b;
		scanf("%d%d",&a,&b) ;
		v[i].first = a;
		v[i].second = b; 
	}
	int d[555][555];
	for (int l = 1 ; l<n; l++){
		for (int i = 1 ; i+l<=n ;i++){
			int end = i+ l ;
			d[i][end] = 987654321;
			for (int j =i ;j<end ; j++){
				d[i][end] = min ( d[i][j] + d[j+1][end] +v[i].first* v[j].second*v[end].second , d[i][end]);
			}
		} 
	}
	cout << d[1][n] << endl;
	return 0 ;
}
