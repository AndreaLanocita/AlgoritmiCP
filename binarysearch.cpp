int binary_search(int N) {
    int l=0, r=N;
    int mid;
    while(l<r) {
        mid =(l+r)/2;
        // non rispetta la condizione --> ce ne sono troppi pochi --> alzo il prezzo
        if(...) l = mid+1;
        // rispetta la condizione --> ce ne sono troppi --> abbasso il prezzo
        else r = mid;
    }
    return r-1; // return r;
}