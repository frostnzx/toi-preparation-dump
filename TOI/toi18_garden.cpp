#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+5 ;

int n , q , H[N] , lisL[N] , lisR[N] ;

vector<int> l , r ;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;

    for(int i=0;i<n;i++){
        cin >> H[i] ;
    }

    for(int i=0;i<n;i++){ // L
        int idx = lower_bound(l.begin() , l.end() , H[i]) - l.begin() ;
        if(idx == l.size()){
            l.push_back(H[i]) ;
        }
        else l[idx] = H[i] ;

        lisL[i] = idx + 1 ;
        // use idx because we want lis that the last element in lis is H[i]
        // if use lis.size() it would be the best lis that ends at (1 -> i)

        // so the definition of our lis array would be similars to the dp approach array
        // that is dp[i] = longest increasing subsequence that the last element in subsequence is v[i]
    }
    for(int i=n-1;i>=0;i--){ // R
        int idx = lower_bound(r.begin() , r.end() , H[i]) - r.begin() ;
        if(idx == r.size()){
            r.push_back(H[i]) ;
        }
        else r[idx] = H[i] ;

        lisR[i] = idx + 1 ;
    }

    while(q--){
        int x ; cin >> x ;

        cout << min(lisL[x] , lisR[x]) - 1 << "\n" ;

        // use lisL[x] and lisR[x] because we want lis that the last element ( biggest element )
        // in the subsequence be H[x]
    }

}
