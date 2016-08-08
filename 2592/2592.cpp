/*
 *  2592   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
using namespace std;


int main(){
	int check[101]={0} ;
	vector<int >v ;
  for (int i = 0 ; i <10 ;i++){
		int sc1;
		scanf("%d",&sc1);
		v.push_back(sc1);
		check[sc1/10] ++; 
	}
	int sum = 0 ;
	for (int i =0 ; i<10 ;i++)
	{
		sum+= v[i];
	}
	printf("%d\n",sum/10);
	sum =-10;
	int rem ;
	for (int i =1; i<=100;++i){
		if (check[i] > sum ) {
				rem = i;
				sum =check[i];
		}
	}
		
	printf("%d\n",rem*10);
}
