/*
 *  2217   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(){
  int n ;
	scanf("%d",&n);
	vector<int>v;
	for (int i =0 ; i<n ;i++){
		int sc1;
		scanf("%d",&sc1);
		v.push_back(sc1);
	}
	sort(v.begin(),v.end());
	int maxx = -100;
	for (int i = 0 ; i<n; i++){
		maxx= max ( v[i] *(n-i)  , maxx); 
	}
	cout << maxx << endl;

}
