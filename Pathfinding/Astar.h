#pragma once

#include <vector>
#include <raylib.h>

using namespace std;

struct Node
{
	int gridX = 0;
	int gridY = 0;

	bool isWalkable;
	bool Visited = false;
	// f(n) = g(n) + h(n)
	//float fCost;
	int gCost = 0;
	int hCost = 0;
	int fCost = 0;

	float weight;

	bool isStartNode = false;
	bool isTargetNode = false;

	//vector <Node*> inTheHood;
	Node* parent;

};


class Astar
{
public:

	Astar();
	void FindPath(Node* startNode, Node* targetNode);
	int fCost(Node* currentNode);
	vector<Node*> GetNeighbours(Node* currentNode);

	void RetracePath(Node* startNode, Node* endNode);
	int GetDistance(Node* nodeA, Node* nodeB);
	int isBrickAtTileCoord(int gridTileCol, int gridTileRow);
	void drawGrid(Node* startNode);

	Color tileColor = GREEN;

	Node* findNode(int x, int y);

	//Node* gridNodes[20][15];
	vector<Node*> gridNodes;
	vector<Node*> path;
	
	bool pathFound = true;
	int GRID_COLS = 15;
	int GRID_ROWS = 20;

	int GRID_W = 40;
	int GRID_H = 40;
	int BRICK_GAP = 1;

private:
	int grid[20 * 15] = {
		1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, -1, -1, 1, 1,
		1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, -1, -1, 1, 1,
		1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, -1, -1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, -1, -1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 2, 2, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
		1, 1, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1,
		1, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
		2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
		2, 2, 2, 2, 1, 3, 3, 0, 0, 0, 1, 1, 0, 0, 0,
		2, 2, 2, 2, 1, 3, 3, 3, 0, 1, 1, 1, 1, 0, 0,
		2, 1, 1, 1, 1, 0, 3, 3, 3, 1, 1, 1, 1, 1, 0,
		1, 1, 1, 1, 0, 0, 0, 3, 3, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, -1, -1,
		1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1,
		0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 1, 1, 1, 1, 1, 1, 1, -1, -1, 1, 1, 1,
		0, 0, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, 1, 1, 1,
		0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};

	

};

