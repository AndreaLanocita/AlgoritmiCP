#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

vector<ll> primi;
bitset<1000000000> isprime;
 
void sieve() {
    isprime.set();
    int n=1000000000;
    for (ll i = 2; i <= n; i++) {
        if (isprime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i) isprime[j] = 0;
            primi.push_back(i);
        }
    }
}