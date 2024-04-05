#include <iostream>
#include <stack>

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

class DFS {
private:
	bool** visited;
	bool** graph;
	stack<point> stack;
	int maxX;
	int maxY;
public:
	DFS(bool** graph, int x, int y) {
		this->graph = graph;
		visited = new bool* [x];
		for (int i = 0; i < x; i++) {
			visited[i] = new bool[y];
		}
		maxX = x;
		maxY = y;
	}

	void DFS_Calc(int x, int y) {
		if (graph[x][y] == true) {
			visited[x][y] = true;
			stack.push(point(x, y));
		}
		else return;

		while (!stack.empty()) {
			point temp = stack.top();

			for (int i = 0; i < 4; i++) {
				if (temp.x - 1 >= 0) {
					if (graph[temp.x - 1][temp.y] == true && visited[temp.x - 1][temp.y] == false) {
						stack.push(point(temp.x - 1, temp.y));
						visited[temp.x - 1][temp.y] == true;
					}
				}
				if (temp.x + 1 < maxX) {
					if (graph[temp.x + 1][temp.y] == true && visited[temp.x + 1][temp.y] == false) {
						stack.push(point(temp.x + 1, temp.y));
						visited[temp.x + 1][temp.y] == true;
					}
				}
				if (temp.y - 1 >= 0) {
					if (graph[temp.x][temp.y - 1] == true && visited[temp.x][temp.y - 1] == false) {
						stack.push(point(temp.x, temp.y - 1));
						visited[temp.x][temp.y - 1] == true;
					}
				}
				if (temp.y + 1 < maxY) {
					if (graph[temp.x][temp.y - 1] == true && visited[temp.x][temp.y + 1] == false) {
						stack.push(point(temp.x, temp.y + 1));
						visited[temp.x][temp.y + 1] == true;
					}
				}
			}
			stack.pop();
		}
	}
};