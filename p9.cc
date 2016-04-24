#include <cstdio>
#include <cstdlib>
#include <cstring>
#define M 10010
#define N 11
#define INF 1<<30
using namespace std;
int a[N], dp[M][N];

int min(int x, int y) {
	return x<y?x:y;
}

int rec (int i, int j) {
	if (!j) return i==0?0:INF;
	if (dp[i][j] != -1) return dp[i][j];

	int ret = INF;
	for (int k = 1; k*k <= i; k++)
		ret = min(ret, rec(i-k*k, j-1)+(k-a[j])*(k-a[j]));
	return dp[i][j]=ret;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	memset(dp, -1, sizeof dp);
	if (rec(m, n) == INF) printf("-1\n");
	else printf("%d\n", dp[m][n]);
	return 0;
}
