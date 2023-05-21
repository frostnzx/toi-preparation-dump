#include<bits/stdc++.h>

using namespace std;

const int N = 5e5+5;

int lps[N] , n , m , ans ;
string pat , txt ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> txt >> pat ;
    n = txt.size() , m = pat.size() ;

    for(int i=1 , j=0;i<m;i++){
        while(j > 0 && pat[i] != pat[j]){
            j = lps[j-1] ;
        }
        if(pat[i] == pat[j]){
            lps[j] = ++j ;
        }
    }
    for(int i=1 , j=0;i<n;i++){
        while(j > 0 && txt[i] != pat[j]){
            j = lps[j-1] ;
        }
        if(txt[i] == pat[j]){
            ++j ;
        }
        if(j == m){
            ans = i-j+1 ;
        }
    }

    cout << ans ;
}
