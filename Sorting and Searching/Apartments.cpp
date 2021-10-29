/*
Sabuj Jana / @greenindia
https://www.janasabuj.github.io
*/
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int
#define double long double
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
#define endl "\n"
void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;} 
void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}
const int mod = 1e9 + 7;
const int N = 1e5 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i){
        cin >> b[i];
    }

    sort(a.begin(), a.end());// 45 60 60 80
    multiset<int> houses(b.begin(), b.end());// 30 40 60 75
    int cnt = 0;
    for(auto x: a) {
        auto lb = houses.lower_bound(x - k);
        if(lb != houses.end() and *lb <= x + k) {
            // assign
            cnt++;
            houses.erase(houses.find(*lb));
        }
    }

    cout << cnt << endl;
}

#define SABUJ_JANA_WxF 1
signed main() {
    crap;    
#ifdef SABUJ_JANA_WF
    auto start = chrono::high_resolution_clock::now();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif

    int t = 1; 
    // cin >> t;
    while(t--) solve();  
    
#ifdef SABUJ_JANA_WF
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cerr << "Time taken :\n" << duration.count() / 1000000.0 << "s" << "\n";
#endif
    return 0;
}