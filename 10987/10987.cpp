/*
 * 10987.cpp
 *
 */



#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
typedef long long ll ;
const int mod = 1000000;

int main(){
 	/*
		모음 발견때마다 cnt++ 그후 출력 
	*/
   string s;
    cin >> s;
    int ssize =(int) s.size();  //  string 크기 저장. 
    int cnt = 0 ;
    for (int i= 0 ; i<ssize; i++){  //for문에서 매번 s.size() 호출시 시간 
        if (s[i] == 'a' || s[i]=='e' || s[i]=='o' || s[i]== 'u' || s[i]== 'i'){
            cnt ++;
        }
    }
    printf("%d\n",cnt);
}
