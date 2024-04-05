#include <iostream>
#include <queue>

using namespace std;

class point {
public:
	int x;
	int y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class BFS {
private:
	bool** visited;
	bool** graph;
	queue<point> queue;
	int maxX;
	int maxY;
public:
	BFS(bool** graph, int x, int y) {
		this->graph = graph;
		visited = new bool* [x];
		for (int i = 0; i < x; i++) {
			visited[i] = new bool[y];
		}
		maxX = x;
		maxY = y;
	}

	void BFS_Calc(int x, int y) {
		if (graph[x][y] == true) {
			queue.push(point(x, y));
			visited[x][y] = true;
		}
		else return;
		while (!queue.empty()) {
			point temp = queue.front();
			queue.pop();

			for (int i = 0; i < 4; i++) {
				if (temp.x - 1 >= 0) {
					if (graph[temp.x - 1][temp.y] == true && visited[temp.x - 1][temp.y] == false) {
						queue.push(point(temp.x - 1, temp.y));
						visited[temp.x - 1][temp.y] == true;
					}
				}
				if (temp.x + 1 < maxX) {
					if (graph[temp.x + 1][temp.y] == true && visited[temp.x + 1][temp.y] == false) {
						queue.push(point(temp.x + 1, temp.y));
						visited[temp.x + 1][temp.y] == true;
					}
				}
				if (temp.y - 1 >= 0) {
					if (graph[temp.x][temp.y - 1] == true && visited[temp.x][temp.y - 1]==false) {
						queue.push(point(temp.x, temp.y - 1));
						visited[temp.x][temp.y - 1] == true;
					}
				}
				if (temp.y + 1 < maxY) {
					if (graph[temp.x][temp.y - 1] == true && visited[temp.x][temp.y + 1]==false) {
						queue.push(point(temp.x, temp.y + 1));
						visited[temp.x][temp.y + 1] == true;
					}
				}
			}
		}
	}
};