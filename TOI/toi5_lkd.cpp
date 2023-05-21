#include<bits/stdc++.h>

using namespace std;

using pii = pair<int , string> ;

const int N = 40 ;

int n ; string s[N] , decode[N] ;

map<string , pii> mp[10] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;

    string x ;
    for(int i=1;i<=n;i++){
        cin >> x ;
        if(x.size() == 16){
            s[i] = x ;
        }
        else n--;
    }

    mp[1]["00"] = {1 , "0"} ;
    mp[1]["11"] = {2 , "1"} ;
    mp[2]["10"] = {3 , "0"} ;
    mp[2]["01"] = {4 , "1"} ;
    mp[3]["11"] = {1 , "0"} ;
    mp[3]["00"] = {2 , "1"} ;
    mp[4]["01"] = {3 , "0"} ;
    mp[4]["10"] = {4 , "1"} ;

    int u = 1 ;

    for(int i=1;i<=n;i++){
        for(int j=0;j<15;j+=2){
            string t ; t.push_back(s[i][j]) ; t.push_back(s[i][j+1]) ;
            decode[i] += mp[u][t].second ;
            u = mp[u][t].first ;
        }
    }

    for(int i=1;i<=n;i++){
        int p = pow(2 , decode[i].size() - 1 ) ;
        int val = 0 ;
        for(char x : decode[i]){
            val += (p * (x - '0')) ;
            p /= 2 ;
        }
        cout << char(val) ;
    }



}
