#include<bits/stdc++.h>

using namespace std;

int p , hp[2] , cnt[2] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> p ;
    hp[0] = hp[1] = p ;

    int x ;
    while(true){
        cin >> x ;

        cnt[x%2]++;
        cnt[(x+1)%2] = 0 ;

        if(cnt[x%2] >= 3){
            hp[(x+1)%2] -= 3;
        }
        else {
            hp[(x+1)%2] -- ;
        }


        if(hp[0] <= 0 || hp[1] <= 0){
            cout << (hp[0] <= 0 ? '1' : '0') << "\n" ;
            cout << x ;
            break;
        }
    }
}
