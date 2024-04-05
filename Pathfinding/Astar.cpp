#include "Astar.h"


#include <iostream>

using namespace std;


Astar::Astar()
{
	for (int i = 0; i < GRID_COLS * GRID_ROWS; i++)
	{
		Node* node = new Node;

		gridNodes.push_back(node);

	}

	

}

int Astar::isBrickAtTileCoord(int gridTileCol, int gridTileRow) {
	int	gridIndex = gridTileCol + GRID_COLS * gridTileRow;

	

	if (grid[gridIndex] == -1)
		return -1;

	if (grid[gridIndex] == 0)
		return 0;

	if (grid[gridIndex] == 1)
		return 1;

	if (grid[gridIndex] == 2)
		return 2;

	if (grid[gridIndex] == 3)
	{
		
		return 3;
	}

	return 0;

}


void Astar::drawGrid(Node* startNode)
{
	int vectorIndex = 0;

	for (int eachCol = 0; eachCol < GRID_COLS; eachCol++)
	{
		for (int eachRow = 0; eachRow < GRID_ROWS; eachRow++)
		{
			
			if (isBrickAtTileCoord(eachCol, eachRow) == -1)
			{
				int	brickLeftEdgeX = eachCol * GRID_W;
				int	brickTopEdgeY = eachRow * GRID_H;

				DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, Color{ 60, 120, 30, 255 });

				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = false;


			}

			if (isBrickAtTileCoord(eachCol, eachRow) == 0)
			{
				int	brickLeftEdgeX = eachCol * GRID_W;
				int	brickTopEdgeY = eachRow * GRID_H;

				DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, Color{ 110, 160, 225, 255 });

				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = false;


			}

			if (isBrickAtTileCoord(eachCol, eachRow) == 1)
			{
				int	brickLeftEdgeX = eachCol * GRID_W;
				int	brickTopEdgeY = eachRow * GRID_H;

				
				if (gridNodes.at(vectorIndex)->isStartNode == true)
				{
					tileColor = DARKBLUE;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);
				}
				else if (gridNodes.at(vectorIndex)->isTargetNode == true)
				{
					tileColor = MAROON;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);
				}
				else if (!path.empty() && (find(path.begin(), path.end(), gridNodes.at(vectorIndex)) != path.end()))
				{
					
					tileColor = GRAY;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);
					

				}
				else
				{
					tileColor = GREEN;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);  //Color{ 150, 200, 125, 255 }

				}


				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = true;
				gridNodes.at(vectorIndex)->weight = 1;

			}

			if (isBrickAtTileCoord(eachCol, eachRow) == 2)
			{
				int	brickLeftEdgeX = eachCol * GRID_W;
				int	brickTopEdgeY = eachRow * GRID_H;

				if (gridNodes.at(vectorIndex)->isStartNode == true)
				{
					tileColor = DARKBLUE;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);
				}
				else if (gridNodes.at(vectorIndex)->isTargetNode == true)
				{
					tileColor = MAROON;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);
				}
				else if (!path.empty() && (find(path.begin(), path.end(), gridNodes.at(vectorIndex)) != path.end()))
				{
					
					tileColor = GRAY;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);
					
				}
				else
				{
					tileColor = Color{ 200, 150, 0, 255 }; //Light Brown Bridge
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor); 

				}

				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = true;
				gridNodes.at(vectorIndex)->weight = 2;


			}

			if (isBrickAtTileCoord(eachCol, eachRow) == 3)
			{
				int	brickLeftEdgeX = eachCol * GRID_W;
				int	brickTopEdgeY = eachRow * GRID_H;

				if (gridNodes.at(vectorIndex)->isStartNode == true)
				{
					tileColor = DARKBLUE;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);
				}
				else if (gridNodes.at(vectorIndex)->isTargetNode == true)
				{
					tileColor = MAROON;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);
				}
				else if (!path.empty() && (find(path.begin(), path.end(), gridNodes.at(vectorIndex)) != path.end()))
				{
					
					tileColor = GRAY;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);
					

				}
				else
				{
					tileColor = Color{ 130, 100, 0, 255 }; //Dark Brown Bridge
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, GRID_W - BRICK_GAP, GRID_H - BRICK_GAP, tileColor);  

				}


				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = true;
				gridNodes.at(vectorIndex)->weight = 1.5;

			}

			
			vectorIndex++;

		}

	

	}
	

}

void Astar::FindPath(Node* startNode, Node* targetNode)
{
	
	vector<Node*> openSet;
	vector<Node*> closedSet;

	openSet.push_back(startNode);

	

	while (!openSet.empty())
	{
		Node* currentNode = openSet.at(0);
		int i;

		for (i = 1; i < openSet.size(); i++)
		{
			if (fCost(openSet.at(i)) < fCost(currentNode) || fCost(openSet.at(i)) == fCost(currentNode) && openSet.at(i)->hCost < currentNode->hCost)
			{
				currentNode = openSet.at(i);

			}
		}


		openSet.erase(find(openSet.begin(), openSet.end(), currentNode));
		closedSet.push_back(currentNode);

		if (currentNode == targetNode)
		{
		
			RetracePath(startNode, targetNode);

			pathFound = true;

			return;

		}
		

		for (Node* neighbour : GetNeighbours(currentNode))
		{

			if (!neighbour->isWalkable || find(closedSet.begin(), closedSet.end(), neighbour) != closedSet.end())
				continue;

			int newMovementCost = currentNode->gCost + GetDistance(currentNode, neighbour) * neighbour->weight;

			if (newMovementCost < neighbour->gCost || !(find(openSet.begin(), openSet.end(), neighbour) != openSet.end()))
			{
				neighbour->gCost = newMovementCost;
				neighbour->hCost = GetDistance(targetNode, neighbour);
				neighbour->parent = currentNode;

				
				if (!(find(openSet.begin(), openSet.end(), neighbour) != openSet.end()))
					openSet.push_back(neighbour);
				//Need to add condition if neighbour is already in the openSet
				//Have to update the content of that element with the new neighbour
			}

		}
		
	}

}

void Astar::RetracePath(Node* startNode, Node* endNode)
{
	
	Node* currentNode = endNode;

	while (currentNode != startNode)
	{
		path.push_back(currentNode);
		currentNode = currentNode->parent;

		
	}
	reverse(path.begin(), path.end());

}

int Astar::GetDistance(Node* nodeA, Node* neighbour)
{


	int distX = abs(nodeA->gridX - neighbour->gridX);
	int distY = abs(nodeA->gridY - neighbour->gridY);

	if (distX > distY)
		return 14 * distY + 10 * (distX - distY);

	return 14 * distX + 10 * (distY - distX);

}

vector<Node*> Astar::GetNeighbours(Node* currentNode)
{
	vector<Node*> neighbours;

	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			if (x == 0 && y == 0)
				continue;

			int checkX = currentNode->gridX + x;
			int checkY = currentNode->gridY + y;

			if (checkX >= 0 && checkX < GRID_ROWS && checkY >= 0 && checkY < GRID_COLS)
			{
				neighbours.push_back(findNode(checkX, checkY));
			}
		}

	}

	return neighbours;

}

Node* Astar::findNode(int x, int y)
{
	
	for (int i = 0; i < gridNodes.size(); i++)
	{

		if (gridNodes.at(i)->gridX == x && gridNodes.at(i)->gridY == y)
		{
			
			return gridNodes.at(i);

		}
	
	}

}

int Astar::fCost(Node* currentNode)
{
	int fCost = currentNode->gCost + currentNode->hCost;

	return fCost;

}
