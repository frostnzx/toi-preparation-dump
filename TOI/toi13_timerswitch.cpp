#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 5e6+5 ;
const int B = 37 ;

int n , ans ;
ll pat , now ;
string s ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s ;
    for(int i=0;i<n;i++){
        pat *= B ;
        pat += (s[i] - '0') ;
    }

    ll k = 1 ;
    for(int i=0;i<n-1;i++){
        k *= B ;
    }
    now = pat ;

    int i = 0 ;
    while(i < n){
        if(now == pat && i != 0){
            ans = i ;
            break;
        }
        now -= ((s[i] - '0') * k) ;
        now *= B ;
        now += (s[i] - '0') ;
        i++;
    }
    if(ans == 0){
        ans = n ;
    }
    cout << ans ;
}
//sometimes function pow is invalid
