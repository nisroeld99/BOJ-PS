/*
 *  1715   
 */


#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int a[100001];
int main(){ 
	int n ;
	scanf("%d",&n);
	priority_queue<int, vector<int>, greater<int> >pq;
	for (int i =1 ; i<= n; i++){
		int sc1;
		scanf("%d",&sc1);
		pq.push(sc1);
	}
	long long dab= 0 ;
	while (pq.size() != 1){
		int temp1 = pq.top(); pq.pop();
		int temp2= pq.top(); pq.pop();
		pq.push(temp1+temp2);
		dab+=temp1+temp2;
	}
	cout << dab << endl; 

}
