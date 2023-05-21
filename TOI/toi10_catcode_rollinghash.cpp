#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int B = 31 ;

int k , m , q , l ;
string s ;

unordered_map<ll , int> mp ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> m ;
    for(int i=1;i<=k;i++){
        ll hsh = 0 ;
        cin >> s ;
        for(int j=0;j<s.size();j++){
            hsh *= B ;
            hsh += (s[j] - '0') ;
        }
        mp[hsh] = i ;
    }

    ll K = 1 ;
    for(int i=0;i<m-1;i++){
        K *= B ;
    }

    cin >> q ;
    while(q--){
        cin >> l >> s ;

        ll now = 0 ;
        for(int i=0;i<m;i++){
            now *= B ;
            now += (s[i] - '0') ;
        }
        int i = 0 ;
        set<int> ans ;
        while(i < l - m){
            if(mp.count(now)){
                ans.insert(mp[now]) ;
            }
            now -= (s[i] - '0') * K ;
            now *= B ;
            now += (s[i+m] - '0') ;

            i++;
        }
        if(i == l-m && mp.count(now)){
            ans.insert(mp[now]) ;
        }

        for(int x : ans){
            cout << x << " " ;
        }
        if(ans.empty()){
            cout << "OK" ;
        }
        cout << "\n" ;
    }
}
