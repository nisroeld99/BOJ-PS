/*
 *  10988   
 */
#include <iostream>
#include <cstring>
using namespace std;
string s;
string temp ;


bool isPal(int f,int l ){
    if ( f +1  == l){
        if (temp[f] == temp[l]){
            return true;
        }
        else
            return false;
    }
    if ( f == l ){
        return true;
    }
    
    if ( temp[f] == temp[l]){
        return isPal (f+1 , l- 1);
    }
    else {
        return false ;
    }
    
}

int main(){
    cin >> temp;
    
    if ( isPal(0, (int)temp.size()-1 )){
        printf("1\n");
    }else {
        printf("0\n");
    }
 
    
    
    
}
