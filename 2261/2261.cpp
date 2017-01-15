/*
 * 2261.cpp
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
const int inf = 987654321;

/* Point 구조체 */
struct Point {
    int x,y;
    Point() {
    
    }
    Point(int _ypos, int _xpos){
        x= _xpos ;
        y= _ypos;
    }
    
    bool operator < (const Point &v )const {
        if (x ==v.x){
            return y < v.y;
        }
        else {
            return x < v.x;
        }
    }
};

bool cmp (const Point &a , const Point & b ){
    return a.y < b.y;
}

int dist (const Point & a , const Point & b ){
    return (a.y-b.y) * (a.y-b.y) + (b.x- a.x) * (b.x- a.x);
}

int brute_force (vector<Point> & a , int x ,int y ){  // 많이 쪼개지면 이 범위 애들 중에 가장 짧은 값 구해라
    int ans = inf ;
    for (int i = x  ; i <= y-1 ; i++){
        for (int j=i+1 ;j<=y ;j++){
            int d = dist ( a[i], a[j]);
            ans = min ( ans  ,d );
        }
    }
    return ans ;
}

int closest (vector<Point> & a, int x , int y){ // x축 기준 정렬 기준 ,x번째부터 y번째 까지 중 가장 짧은 distance
    int n = y-x + 1;
    if ( n <=3 ){
        return brute_force(a, x, y);
    }
    
    int mid = (x+y) /2;
    int left = closest(a, x, mid);
    int right = closest(a, mid+1, y);
    int ans = min ( left , right);
    vector<Point>  b;
    for (int i = x; i <=y; i++){
        int d = a[i].x - a[mid].x;
        if ( d*d < ans ){
            b.push_back(a[i]);
        }
    }
    sort (b.begin(), b.end(), cmp);
    
    int m = (int)b.size();
    for (int i =0;  i< m-1 ;i++){
        for (int j=i+1 ;j<m ;j++){
            int y = b[j].y- b[i].y;
            if ( y*y < ans ){
                int d = dist(b[i],b[j]);
                ans = min ( ans , d );
            }else {
                break ;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    vector<Point> a;
    scanf("%d",&n);
    for (int i =0 ; i<n; i++){
        int x, y ;
        scanf("%d%d",&x,&y);
        a.push_back(Point(x,y)) ;
        
    }
    sort ( a.begin() , a.end() );
    printf("%d\n" ,closest (a, 0 ,n-1 )) ;
    
}
