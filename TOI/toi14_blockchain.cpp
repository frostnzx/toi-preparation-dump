#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

int t , q ;

map<vector<pii> , int> mp ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t >> q ;
    for(int i=1 , n;i<=t;i++){
        vector<pii> vec ;
        cin >> n ;
        for(int j=1 , u , v;j<=n-1;j++){
            cin >> u >> v ;
            vec.push_back({min(u , v) , max(u , v)});
        }
        sort(vec.begin() , vec.end());
        mp[vec]++ ;
    }

    int n ;
    while(q--){
        vector<pii> vec ;
        cin >> n ;
        for(int j=1 , u , v;j<=n-1;j++){
            cin >> u >> v ;
            vec.push_back({min(u , v) , max(u , v)});
        }
        sort(vec.begin() , vec.end());

        if(mp.count(vec)){
            cout << mp[vec] << "\n" ;
        }
        else {
            cout << "0\n" ;
        }
    }
}
