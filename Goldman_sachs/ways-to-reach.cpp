#include <vector>
using namespace std;

struct Comb {
 public:
  int MOD = 1e9 + 7;
  vector<long long> fac, finv, inv;

  Comb(int maxN) {
    fac.resize(maxN);
    finv.resize(maxN);
    inv.resize(maxN);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (int i = 1; i < maxN - 1; i++) {
      fac[i + 1] = fac[i] * (i + 1) % MOD;
      inv[i + 1] = MOD - inv[MOD % (i + 1)] * (MOD / (i + 1)) % MOD;
      finv[i + 1] = finv[i] * inv[i + 1] % MOD;
    }
  }

  long long ncr(long long n, long long k) {
    if (k < 0 || n < k) return 0;
    return fac[n] * finv[k] % MOD * finv[n - k] % MOD;
  }
};

class Solution {
 public:
  int numberOfWays(int startPos, int endPos, int k) {
    int MOD = 1e9 + 7;
    Comb comb(1005);
    return (((startPos + endPos) ^ k) & 1) ? 0 : comb.ncr(k, (endPos - startPos + k) / 2) % MOD;
  }
};
