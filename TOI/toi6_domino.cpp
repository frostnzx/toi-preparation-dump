#include<bits/stdc++.h>

using namespace std;

int n ; vector<int> ans ;

void solve(int s){
    if(s == n){
        for(int x : ans){
            if(x == 1){
                cout << "--" ;
            }
            else cout << "||" ;
            cout << "\n" ;
        }
        cout << "E\n" ;

        return ;
    }
    if(s < n){
        ans.push_back(1) ;
        solve(s + 1) ;
        ans.pop_back() ;

        ans.push_back(2) ;
        solve(s + 2) ;
        ans.pop_back() ;
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;

    solve(0) ;
}

