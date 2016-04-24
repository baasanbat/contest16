#include <cstdio>
#include <cstdlib>
#define N 1010
using namespace std;
int n, m;
char xx[] = {1, 0, -1, 0};
char yy[] = {0, 1, 0, -1};
int bounce1[] = {3, 2, 1, 0}; //  / helbertei toliig tus buriin chiglelees irj murguvul ali zugruu
int bounce2[] = {1, 0, 3, 2};
char board[N][N];

int max(int a, int b) {
	return a>b?a:b;
}

int count(int x, int y, int bounce) {
	int ret = 0;
	while (x>=0 && x<n && y>=0 && y<m) {
		if (board[x][y] == '/') bounce = bounce1[bounce];
		else bounce = bounce2[bounce];
		x += xx[bounce];
		y += yy[bounce];
		ret++;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", board[i]);

	int ret = -11;
	for (int i = 0; i < n; i++) {
		ret = max(ret, count(i, 0, 1));
		ret = max(ret, count(i, m-1, 3));
	}
	for (int i = 0; i < m; i++) {
		ret = max(ret, count(0, i, 0));
		ret = max(ret, count(n-1, i, 2));
	}
	printf("%d\n", ret);
	return 0;
}
