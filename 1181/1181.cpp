/*
 * 1181.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace  std;
const int mod = 1000000000;
const int inf = 987654321;
typedef long long ll;
typedef pair<int,int> ii;

bool cmp (string s1, string s2){
    
    if ( s1.length() == s2.length()) // 길이가 같으면
        return s1 < s2;  // 사전 순서대로정렬해라 
    
    return s1.length()<s2.length();  // 길이 기준으로 정렬해라 ( 짧은거 먼저) 
}

int main(void){
    /*
	집합 set을  통해 중복을 확인하고 vector에추가해서 유일성 조건 충족		
	그다음에 cmp 를 통해 sort해주기   	

	*/

    set <string >s;
    vector<string> v;
    
    int tc;
    cin >> tc;
    
    while (tc--){
        string s1;
        cin >> s1;
        if ( s.find(s1) != s.end() ){ //set 안에 존재하면 cf) s.find() 는 인자가 존재 하지않을 때, s.end()를 반환합니다   
            continue;
        }
        s.insert(s1);
        v.push_back(s1);
    }
    sort(v.begin(),v.end(), cmp); // cmp () 주석 참고
    
    for (int i = 0 ; i<v.size() ; i++ ){
    	printf("%c ",v[i] ) ;
    }
    
}
