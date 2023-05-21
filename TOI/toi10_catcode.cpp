#include<bits/stdc++.h>

using namespace std;

int n , m , q ;

map<deque<char> , int> mp ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        deque<char> dq ;
        for(int j=1;j<=m;j++){
            char x ; cin >> x ;
            dq.push_back(x) ;
        }
        mp[dq] = i ;
    }
    cin >> q ;
    while(q--){
        int x ; string s ;
        set<int> ans ;
        cin >> x >> s ;

        deque<char> window ;
        for(int i=0;i<m;i++){
            window.push_back(s[i]);
        }
        for(int r=m;r<x;r++){
            if(mp.count(window)){
                ans.insert(mp[window]) ;
            }
            window.pop_front() ;
            window.push_back(s[r]) ;
        }
        if(mp.count(window)){
            ans.insert(mp[window]);
        }
        if(ans.empty()){
            cout << "OK" << "\n" ;
        }
        else {
            for(int i : ans){
                cout << i << " " ;
            }
            cout << "\n" ;
        }
    }
}


//use hashing
