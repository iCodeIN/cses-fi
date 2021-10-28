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
    int x, n;
    cin >> x >> n;
    vi arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    set<int> s;
    multiset<int> dist;

    s.insert(0);
    s.insert(x);
    dist.insert(x);

    for(auto tl: arr) {
        auto it2 = s.upper_bound(tl);
        auto it1 = it2; --it1;        
        dist.erase(dist.find(*it2 - *it1));
        dist.insert(tl - *it1);
        dist.insert(*it2 - tl);
        s.insert(tl);
        cout << *dist.rbegin() << " ";
    }
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