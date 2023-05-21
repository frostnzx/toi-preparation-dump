#include <bits/stdc++.h>
using namespace std;

vector<int> lis;
int main(){
    int n, a;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &a);
        int idx = upper_bound(lis.begin(), lis.end(), a) - lis.begin();
        if(idx == lis.size())
            lis.push_back(a);
        else
            lis[idx] = a;
    }
    printf("%d", lis.size());
    return 0;
}