#include <bits/stdc++.h>
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> omset;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, j, n) for (int i = j; i < n; i++)
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define vi vector<int>
#define vvi vector<vi>
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define nl cerr << endl;
template <typename T> 
using heap = priority_queue<T, vector <T>, greater<T>>;
void solve();
const int maxn = 1e6 + 5;
static int mod = 1e9 + 7;
int32_t main(){
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms\n";
    return 0;
}
#define debug(x) cerr << "[" << #x << "] = [" << x << "] ";
int beauty(vector <int> &A) {
    int N = A.size();
    omset st;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        st.insert(A[i]);
        int x = st.order_of_key(i + 1);
        if(x == i) {
            ans++;
        }
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for(int &i : a) {
        cin >> i;
        i--;
    }
    set <int> st;
    for(int i = 0; i < n; i++) {
        if(a[i] != i) {
            if((i + 1 < n && a[i] == i + 1) or (i - 1 >= 0 && a[i] == i - 1)) {
                st.insert(a[i]);
            } 
        }
    }
    if(st.empty()) {
        cout << beauty(a) << endl;
        return;
    }
    int x = (*st.begin());
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if(i == x) {
            idx = i;VV 
        }
    }
    assert(idx != -1);
    cout << x << " " << idx << endl;
    for(int i : a) cout << i << " ";
    cout << endl;
    // while(idx < n - 1) {
    //     if(a[idx] != idx && a[idx + 1] != idx + 1) {
    //         if(idx + 1 < n) {
    //             swap(a[idx], a[idx + 1]);
    //         }
    //         idx += 2;
    //     }else break;
    // }
    cout << beauty(a) << endl;
}
