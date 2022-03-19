int chocolateFeast(int n, int c, int m) {
    int ans = 0;
    ans += n / c;
    int x = n / c;
    while (x >= m) {
        ans += x / m;
        x = x / m + x % m;
    }

    return ans;

}