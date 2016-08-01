#include <iostream>
 
using namespace std;
string s;
string temp;
bool isPal(int f,int e){
    if (f>=e) return true;
    if (temp[f]== temp[e])
        return isPal(f+1,e-1);
    else {
        return false ;
    }
}
 
 
int main(){
    cin >> s;
     
    int size ;
    size = (int)s.size();
    s= " "+s ;
    temp = s;
    int idx= 1;
    while (true){
        if (isPal( 1, size  )){
            printf("%d\n", (int)temp.size() -1 );
            break ;
        }else {
            temp =s ;
            for (int i=idx ; i>=1 ;i--){
                temp +=s[i];
            }
        }
        idx++;
        size++;
    }
     
}
