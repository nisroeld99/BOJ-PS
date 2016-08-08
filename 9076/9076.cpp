/*
 *  9076   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(){
 int n ;
 cin >> n ;
vector<int>v ;
	for (int i = 0  ; i< n ; i++){
 		for (int j= 0; j<5 ;j++){
			int sc;
			scanf("%d",&sc);
 			v.push_back(sc);
		}
		sort(v.begin(), v.end());
		if (v[3] - v[1] >=4){
			printf("KIN\n");
		}else {
			printf("%d\n", v[1]+v[2]+v[3]);
		}
		v.clear();
 }
	
}
