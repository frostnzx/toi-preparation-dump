#include<bits/stdc++.h>

using namespace std;

int k , a , b;
string ans ;

void solve(int a , int b){
    if(a == k || b == k){
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " " ;
        }
        cout << "\n" ;
        return ;
    }
    ans += "W" ;
    solve(a+1 ,b);
    ans.pop_back();

    ans += "L" ;
    solve(a , b+1);
    ans.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k >> a >> b ;
    solve(a , b) ;
}
