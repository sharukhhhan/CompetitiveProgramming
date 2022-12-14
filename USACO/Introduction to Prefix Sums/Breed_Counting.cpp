// http://www.usaco.org/index.php?page=viewproblem2&cpid=572&lang=ru

#include <bits/stdc++.h>
using namespace std;
int solve(){
    int n, q;
    cin >> n >> q;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin >> input[i];
    }
    vector<pair<int, int>> queries;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries.push_back(make_pair(a, b));
    }
    vector<vector<int>> v(n+1, vector<int>(3));
    v[0][0] = v[0][1] = v[0][2] = 0;

    for(int i = 1; i < n+1; i++){
        int tmp = input[i-1];
        v[i][0] = v[i-1][0];
        v[i][1] = v[i-1][1];
        v[i][2] = v[i-1][2];

        if(tmp == 1){
            v[i][0]++;
        }
        else if(tmp == 2){
            v[i][1]++;
        }else{
            v[i][2]++;
        }
    }
    for(int i = 0; i < q; i++){
        int a = queries[i].first;
        int b = queries[i].second;
        cout << v[b][0] - v[a-1][0] << ' ' << v[b][1] - v[a-1][1] << ' ' << v[b][2] - v[a-1][2] << '\n';
    }
}

int main(){
    freopen("bcount.in", "rt", stdin);
    freopen("bcount.out", "wt", stdout);
    solve();
}
