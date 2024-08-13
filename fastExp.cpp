long long fastExp(int numero, int esponente) {
    // caso base
    if(esponente == 0) return 1;
    // caso ricorsivo
    long long ricorsione = fastExp(numero, esponente/2);
    ricorsione = (ricorsione % MOD * ricorsione % MOD)%MOD;
    // l'esponente è dispari --> esponente = esponente / 2 + esponente / 2 + 1 --> res = res_precedente^(esponente/2) * res_precedente^(esponente/2) * numero
    if(esponente % 2 == 1) return (ricorsione%MOD * numero % MOD)%MOD;
    // l'esponente è pari --> esponente = esponente / 2 + esponente / 2 --> res = res_precedente^(esponente/2) * res_precedente^(esponente/2)
    return ricorsione%MOD;
}