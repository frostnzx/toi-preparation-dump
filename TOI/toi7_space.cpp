#include<bits/stdc++.h>

using namespace std;

int d ;
string str ;

void solve(int c){
    if(c == d){
        for(int i=d-1;i>=0;i--){
            if(str[i] == '0'){
                string s2 = str ; s2[i] = '1' ;
                cout << str << " " << s2 << "\n" ;
            }
        }
        return ;
    }
    str += '0' ;
    solve(c+1);
    str[c] = '1' ;
    solve(c+1);

    str.pop_back();
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> d ;

    solve(0);
}
