/*
 *  2605   
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;
int a[111];
int  main() {
	freopen("input.txt", "r", stdin);
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int sc;
		scanf("%d", &sc);
		if (sc == 0) {
			a[i] = i;
		}
		else {
			vector<int> temp; 
			for (int j = i - sc; j < i;j++) {
				temp.push_back(a[j]);
			}
			a[i - sc] = i; 
			int p = 0; 
			for (int j = i - sc + 1; p<temp.size() ; j++) {
				a[j] = temp[p++];
			}
			temp.clear();
		}
			
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;

}
