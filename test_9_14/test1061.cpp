#include <iostream>
#include <cstdio> 
using namespace std;
void exgcd(long long a, long long b, long long& d, long long& x, long long& y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
int main() {
    long long x, y, m, n, L;
    while (scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L) != EOF) {
        long long d, a, b, c, x0, y0;
        a = n - m;
        b = L;
        c = x - y;

        exgcd(a, b, d, x0, y0);

        if (c % d != 0) {
            printf("Impossible\n");
        }
        else {
            x0 = x0 * (c / d);
            long long Lg = b / d;
            x0 = (x0 % Lg + Lg) % Lg;
            printf("%lld\n", x0);
        }
    }
    return 0;
}
