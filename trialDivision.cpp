vi fattori;
void trialDivision(ll n) {
    fattori.clear();
    // trial division
    for(ll i=2; i*i<=n; i++) {
        while(n%i==0) {
            // i è un fattore primo di n
            n /= i;
            fattori.pb(i);
        }
    }
    if(n>1)fattori.pb(n);
}