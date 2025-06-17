bool isPrime(i128 n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    i128 d = n - 1;
    int s = 0;
    while ((d & 1) == 0) d >>= 1, ++s;

    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (a >= n) continue;
        i128 x = 1, p = a;
        for (i128 t = d; t > 0; t >>= 1) {
            if (t & 1) x = x * p % n;
            p = p * p % n;
        }
        if (x == 1 || x == n - 1) continue;
        bool witness = false;
        for (int r = 0; r < s - 1; ++r) {
            x = x * x % n;
            if (x == n - 1) {
                witness = true;
                break;
            }
        }
        if (!witness) return false;
    }
    return true;
}
