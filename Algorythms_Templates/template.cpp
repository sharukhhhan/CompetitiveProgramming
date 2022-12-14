//
// Created by sharukhhhan on 9/30/22.
//
#include<bits/stdc++.h>
#include <cctype>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long
#define ld long double

#define AllVec(v) v.begin(), v.end()
#define AllArr(v) v, v+sizeArr(v)
#define sizeArr(arr) sizeof(arr)/sizeof(arr[0])
#define foreach(a, b) for(auto a : b)
#define forn(i , a, b) for(int i = a; i < b; i++)
#define fornq(i, a, b) for(int i = a; i <= b; i++)
#define inputArr(arr) for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){cin >> arr[i];}
#define inputVec(vec, size) for(int i = 0; i < size; i++){int tmp; cin >> tmp; vec.pushback(tmp)}
#define outputArr(arr) for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){cout << arr[i] << " ";} cout << '\n';
#define outputVec(vec) for(int i = 0; i < vec.size(); i++) {cout << vec[i] << " ";} cout << '\n';
#define outputMap(map) for(auto const& x: map) {cout << x.first << " " << x.second << "\n";}
#define outputDeque(deque) foreach(i, deque){cout << i << ' ';}cout << "\n";
#define toLower(string) for(int i = 0; i < string.length(); i++){if (string[i] >= 65 and string[i] <= 90){string[i] += 32;}}
#define toUpper(string) for(int i = 0; i < string.length(); i++){if (string[i] >= 97 and string[i] <= 122){string[i] -= 32;}}
#define charToInt(character) (int)character - 48;
#define strToInt(string) stoi(string)

void solve(){

    int n = 8;
    vector<vector<int>> vp(8, vector<int>(8));
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cin >> vp[i][j];
        }
    }
    vector<vector<int>> dp(8, vector<int>(8, inf));
    dp[7][0] = 1;
    vector<pair<int, int>> steps = {{0, -1}, {1, 0}, {1, -1}};

    for(int i = 7; i >= 0; --i){
        for(int j = 0; j < 8; ++j){
            for(auto& [dx, dy]: steps){
                int x = dx+i;   int y = dy+j;
                if(x >= 8 or y < 0) continue;

                dp[i][j] = min(dp[x][y], dp[i][j]);
            }
            if (dp[i][j] != inf){
                dp[i][j] += vp[i][j];
            }
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << dp[0][7];

}



int main(){
    #ifdef ONLINE_JUDGE
    freopen(".in", "rt", stdin);
    freopen(".out", "wt", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << setprecision(20) << fixed;
    int t;
//    cin >> t;
    t = 1;
    while(t--){
        solve();
    }

}