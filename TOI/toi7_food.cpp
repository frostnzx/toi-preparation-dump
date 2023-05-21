#include<bits/stdc++.h>

using namespace std;

int n, m ;
unordered_set<int> ban ;
vector<int> ans ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1 ,x;i<=m;i++){
        cin >> x ; ban.insert(x) ;
    }

    for(int i=1;i<=n;i++){
        ans.push_back(i) ;
    }

    do{
        if(ban.count(ans[0])){
            continue ;
        }
        for(int x : ans){
            cout << x << " " ;
        }
        cout << "\n" ;
    }while(next_permutation(ans.begin() , ans.end()));
}
