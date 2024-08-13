vi arr;
int N, tmp1, lsb_pos;

int insert(int index, vi &fenwick) {
    lsb_pos = (int) log2(index & (~index + 1))+1;
    for(int i=0; i!=lsb_pos; i++) fenwick[index] += arr[index-i-1];
}

int res;
int prefix_sum(int a, vi &fenwick) {
    while(a>0) {
        res += fenwick[a];
        a -= a & (-a);
    }
    return res;
}

int sum_query(int a, int b, vi &fenwick) {
    if(a>b) swap(a, b);
    return (prefix_sum(b, fenwick) - prefix_sum(a, fenwick));
}

void add(int index, int a, vi &fenwick) {
    while(index<fenwick.size()) {
        // aggiungo valore
        fenwick[index] += a;
        // aggiungo potenza di due meno significativa all'index
        index += index & (-index);
    }
}

void range_add(int a, int b, int val, vi &fenwick) {
    add(a, val, fenwick);
    add(b+1, -val, fenwick);
}