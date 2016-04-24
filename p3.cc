#include <cstdio>
#include <cstdlib>
#define N 50
using namespace std;

char board[N][N];
int n, m, mark;

char xx[] = {0, 1, 0, -1};
char yy[] = {1, 0, -1, 0};

bool ok(int x, int y) {
	return x>=0 && y>=0 && x<n && y<m;
}

void floodfill(int x, int y) {
	if (!ok(x, y) || board[x][y]!='X') return;
	board[x][y] = (mark+'0');
	for (int i = 0; i < 4; i++)
		floodfill(x+xx[i], y+yy[i]);
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (board[i][j] == 'X') {
				floodfill(i, j);
				mark++;
			}
	int ret = 1000000000;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		if (board[i][j] == '0') {
			for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++)
				if (board[x][y] == '1')
					ret = ret>(abs(x-i)+abs(y-j))?(abs(x-i)+abs(y-j)):ret;
		}
	printf("%d\n", ret-1);
	return 0;
}
