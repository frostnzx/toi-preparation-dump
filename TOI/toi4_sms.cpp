#include<bits/stdc++.h>

using namespace std;

int n , s , m ; stack<char> ans ;

const char d[10][4] = {{} , {} , {'A','B','C'} , {'D','E','F'} , {'G','H','I'} ,
{'J' , 'K' , 'L'} , {'M' , 'N' , 'O'} , {'P' , 'Q' , 'R' , 'S'} , {'T' , 'U' , 'V'} ,
{'W' , 'X' , 'Y' , 'Z'} } ;

const int num[3][3] = {{1,2,3} , {4,5,6} , {7,8,9}} ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s >> m ;

    int y , x ;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(num[i][j] == s){
                y = i , x = j ;
            }
        }
    }
    if(num[y][x] == 7 || num[y][x] == 9){
        ans.push(d[num[y][x]][(m-1) % 4]) ;
    }
    else if(num[y][x] != 1){
        ans.push(d[num[y][x]][(m-1) % 3]) ;
    }

    for(int i=0;i<n-1;i++){
        int h , v , m ; cin >> h >> v >> m ;
        x += h , y += v ;
        if(num[y][x] == 7 || num[y][x] == 9){
            ans.push(d[num[y][x]][(m-1) % 4]) ;
        }
        else if(num[y][x] == 1){
            while(!ans.empty() && m--){
                ans.pop() ;
            }
        }
        else {
            ans.push(d[num[y][x]][(m-1) % 3]) ;
        }
    }
    if(ans.empty()){
        cout << "null" ; return 0 ;
    }
    string s ;
    while(!ans.empty()){
        s += ans.top() ; ans.pop();
    }
    reverse(s.begin() , s.end());
    cout << s ;
}
