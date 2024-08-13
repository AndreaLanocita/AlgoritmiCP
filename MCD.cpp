int MCD(int A, int B) {
    while (A!=B) {
        if(A>B) {
            A=A-B;
        }
        else B=B-A;
    }
    return A;
}