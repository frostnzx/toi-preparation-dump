#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
const int p = 31 , MOD = 1e9+7 ;

string txt , pat ;

ll hsh_txt , now ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> txt >> pat ;
    int n = txt.size() , m = pat.size() ;

    for(int i=0;i<m;i++){
        hsh_txt = (hsh_txt * p) % MOD ;
        hsh_txt = (hsh_txt + pat[i] - 'A' + 1) % MOD ;

        now = (now * p) % MOD ;
        now = (now + txt[i] - 'A' + 1) % MOD ;
    }
    ll k = 1 ;
    for(int i=0;i<m-1;i++){
        k = (k * p) % MOD ;
    }
    int i = 0 ;
    while(i < n-m){
        if(now == hsh_txt){
            cout << "found at " << i ;
            break;
        }
        now = (now - ((txt[i] - 'A' + 1) * k) + MOD) % MOD ;
        now = (now * p) % MOD ;
        now = (now + (txt[i+m] - 'A' + 1)) % MOD ;

        i++;
    }
    if(now == hsh_txt && i == n-m){
        cout << "found at " << n-m ;
    }
}
// note unrelated to rabinkarp : always checking last window in sliding window

// rabinkarp has a small chance to be wrong by collision ( monte carlo algorithm )
// to fix that we can check o(m) everytime we found match hash value
// that would make it be ( las vegas algorithm )

// but normally we could just leave it be monte carlo
// and we don't really need to MOD because if it will overflow it will overflow to the same value
