/*
 * 9086.cpp
 *
 */
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n ;
    while (n--){
        string s;
        cin >> s;
        printf("%c%c\n",s[0],s[s.size()-1]);
    }
}

