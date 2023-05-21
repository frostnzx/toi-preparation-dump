#include<bits/stdc++.h>

using namespace std;

//0 , 1 , ... 8

int w[4] , key , q , k[4] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> key ;

    int i = 3 ;
    while(i >= 1){
        w[i] = (key-1)%10 ;
        k[i--] = (key-1)%10 ;
        key/=10 ;
    }

    string q ; cin >> q ;
    for(auto x : q){
        int now = x - '0' - 1 ;
        for(int i=1;i<=3;i++){
            now = (w[i] + now) % 9 ;
        }

        cout << now+1 ;

        w[1] = ((w[1] + k[1]) % 9) + 1 ;
        w[2] = ((w[2] - 1) % 9)  ;
        w[3] = ((w[3] + k[3]) % 9) + 1  ;

    }
}
