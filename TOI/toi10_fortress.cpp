#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

int q = 20 ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(q--){
        ll sum , side ; cin >> sum >> side ;
        ll b = (sum - (2*side))/2 ;
        ll ans = side - b ;

        if(ans < 0 || ans > side){
            cout << "0\n" ;
            continue;
        }

        cout << ans+1 << "\n" ;
    }
}

//keypoint : math ล้วนๆ
