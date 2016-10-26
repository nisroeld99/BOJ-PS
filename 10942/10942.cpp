/*
 *  10942   
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int a[2222];
int d[2222][2222];

int isPal(int s, int e ){
	int &ret = d[s][e];
	if ( d[s][e] !=-1 ) return ret; 
	if ( s +1 == e ) {
		if (a[s] == a[e] ) {
			return ret=  2; 
		}else {
			return ret=1 ;
		}
	}
	if ( s==e ) {
		return ret=  2;
	}

	if ( a[s] == a[e] ) {
		return ret = isPal ( s+1 ,e-1) ;
	}
 	else 
		return ret ;
}

int main(){
	memset ( d, -1, sizeof(d)) ;
	int n ;
	scanf("%d",&n);
	for (int i =1 ; i<=n; i++){
		scanf("%d",&a[i]);	
	}
	int tc;
	scanf("%d",&tc);
	for (int i =1;  i<= tc ;i++){
		int s, e ;
		scanf("%d%d", &s,&e);
		if ( isPal(s,e) ==2 ) {
					printf("1\n") ;
		}else {
					printf("0\n") ;
		}
	}

	return 0 ;

}
