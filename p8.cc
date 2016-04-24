#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#define N 50
#define INF 100000000
using namespace std;

char board[N][N];
char xx[] = {0, 1, 0, -1};
char yy[] = {1, 0, -1, 0};
vector <pair <int, int> > group[3];
int n, m;

//finds three distinct groups recursivele
//all points of first group stays in group[0]
//second group[1]..
void floodfill(int x, int y, int mark) {
	if (x<0 || x==n || y<0 || y==m || board[x][y]!='X') return;
	board[x][y] = 'V';
	group[mark].push_back(make_pair(x, y));
	for (int i = 0; i < 4; i++)
		floodfill(x+xx[i], y+yy[i], mark);
}

/*
finds manhattan distance
*/
int dist(pair <int, int> a, pair <int, int> b) {
	return abs(a.first-b.first)+abs(a.second-b.second);
}

/*
finds closest distance between given points and 
three groups
*/
int try_one(pair <int, int> a) {
	if (board[a.first][a.second] == 'V') return INF;
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		int temp = INF;
		for (int j = 0; j < group[i].size(); j++)
			temp = min(temp, dist(a, group[i][j])-1);
		ret += temp;
	}
	return ret+1;
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", board[i]);

	//floodfill
	int mark=0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		if (board[i][j] == 'X')
			floodfill(i, j, mark++);

	int ret = INF;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		ret = min(ret, try_one(make_pair(i, j)));

	// mins[0] = shortest(0-1)
	// mins[1] = shortest(1-2)
	// mins[2] = shortest(2-0)
	int mins[3];	
	for (int i = 0; i < 3; i++) {
		mins[i] = INF;
		for (int a = 0; a < group[i].size(); a++)
		for (int b = 0; b < group[(i+1)%3].size(); b++)
			mins[i] = min(mins[i], dist(group[i][a], group[(i+1)%3][b])-1);
	}
	for (int i = 0; i < 3; i++)
		ret = min(ret, mins[i]+mins[(i+1)%3]);

	printf("%d\n", ret);
	return 0;
}
