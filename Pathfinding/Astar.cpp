#include "Astar.h"


#include <iostream>

using namespace std;


Astar::Astar()
{
	for (int i = 0; i < TRACK_COLS * TRACK_ROWS; i++)
	{
		Node* node = new Node;

		gridNodes.push_back(node);

	}

	

}

int Astar::isBrickAtTileCoord(int trackTileCol, int trackTileRow) {
	int	trackIndex = trackTileCol + TRACK_COLS * trackTileRow;

	

	if (grid[trackIndex] == -1)
		return -1;

	if (grid[trackIndex] == 0)
		return 0;

	if (grid[trackIndex] == 1)
		return 1;

	if (grid[trackIndex] == 2)
		return 2;

	if (grid[trackIndex] == 3)
	{
		
		return 3;
	}

	return 0;

}


void Astar::drawTrack(Node* startNode)
{
	int vectorIndex = 0;

	
	/*gridNodes.at(0)->isStartNode = true;
	gridNodes.at(299)->isTargetNode = true;*/
	

	for (int eachCol = 0; eachCol < TRACK_COLS; eachCol++)
	{
		for (int eachRow = 0; eachRow < TRACK_ROWS; eachRow++)
		{
			

			if (isBrickAtTileCoord(eachCol, eachRow) == -1)
			{
				int	brickLeftEdgeX = eachCol * TRACK_W;
				int	brickTopEdgeY = eachRow * TRACK_H;

			

				DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, Color{ 60, 120, 30, 255 });

				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = false;


			}

			if (isBrickAtTileCoord(eachCol, eachRow) == 0)
			{
				int	brickLeftEdgeX = eachCol * TRACK_W;
				int	brickTopEdgeY = eachRow * TRACK_H;

				DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, Color{ 110, 160, 225, 255 });

				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = false;


			}

			if (isBrickAtTileCoord(eachCol, eachRow) == 1)
			{
				int	brickLeftEdgeX = eachCol * TRACK_W;
				int	brickTopEdgeY = eachRow * TRACK_H;

				
				if (gridNodes.at(vectorIndex)->isStartNode == true)
				{
					tileColor = DARKBLUE;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);
				}
				else if (gridNodes.at(vectorIndex)->isTargetNode == true)
				{
					tileColor = MAROON;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);
				}
				else if (!path.empty() && (find(path.begin(), path.end(), gridNodes.at(vectorIndex)) != path.end()))
				{
					
					tileColor = GRAY;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);
					
				
				}
				else
				{
					tileColor = GREEN;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);  //Color{ 150, 200, 125, 255 }

				}


				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = true;

			}

			if (isBrickAtTileCoord(eachCol, eachRow) == 2)
			{
				int	brickLeftEdgeX = eachCol * TRACK_W;
				int	brickTopEdgeY = eachRow * TRACK_H;

				if (gridNodes.at(vectorIndex)->isStartNode == true)
				{
					tileColor = DARKBLUE;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);
				}
				else if (gridNodes.at(vectorIndex)->isTargetNode == true)
				{
					tileColor = MAROON;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);
				}
				else if (!path.empty() && (find(path.begin(), path.end(), gridNodes.at(vectorIndex)) != path.end()))
				{
					
					tileColor = GRAY;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);
					
				}
				else
				{
					tileColor = Color{ 200, 150, 0, 255 };
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);  //Color{ 150, 200, 125, 255 }

				}

				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = true;


			}

			if (isBrickAtTileCoord(eachCol, eachRow) == 3)
			{
				int	brickLeftEdgeX = eachCol * TRACK_W;
				int	brickTopEdgeY = eachRow * TRACK_H;

				if (gridNodes.at(vectorIndex)->isStartNode == true)
				{
					tileColor = DARKBLUE;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);
				}
				else if (gridNodes.at(vectorIndex)->isTargetNode == true)
				{
					tileColor = MAROON;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);
				}
				else if (!path.empty() && (find(path.begin(), path.end(), gridNodes.at(vectorIndex)) != path.end()))
				{
					
					tileColor = GRAY;
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);
					

				}
				else
				{
					tileColor = Color{ 130, 100, 0, 255 };
					DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, tileColor);  //Color{ 150, 200, 125, 255 }

				}

				//DrawRectangle(brickLeftEdgeX, brickTopEdgeY, TRACK_W - BRICK_GAP, TRACK_H - BRICK_GAP, Color{ 130, 100, 0, 255 });

				gridNodes.at(vectorIndex)->gridX = eachRow;
				gridNodes.at(vectorIndex)->gridY = eachCol;
				gridNodes.at(vectorIndex)->isWalkable = true;


			}

			//cout << gridNodes.at(vectorIndex)->gridX << "  " << gridNodes.at(vectorIndex)->gridY << "  " << gridNodes.at(vectorIndex)->isWalkable << endl;
			vectorIndex++;

		}

	

	}

}

void Astar::FindPath(Node* startNode, Node* targetNode)
{
	
	vector<Node*> openSet;
	vector<Node*> closedSet;
	//Node* neighbour;


	openSet.push_back(startNode);

	

	while (!openSet.empty())
	{
		Node* currentNode = openSet.at(0);
		

		/*for (int i = 1; i < openSet.size(); i++)
		{
			if (openSet.at(i)->fCost < currentNode->fCost || openSet.at(i)->fCost == currentNode->fCost && openSet.at(i)->hCost < currentNode->hCost)
			{
				currentNode = openSet.at(i);
			}

		}*/

		for (int i = 1; i < openSet.size(); i++)
		{
			if (fCost(openSet.at(i)) < fCost(currentNode) || fCost(openSet.at(i)) == fCost(currentNode) && openSet.at(i)->hCost < currentNode->hCost)
			{
				currentNode = openSet.at(i);
			}
		}


		openSet.pop_back();
		closedSet.push_back(currentNode);

		if (currentNode == targetNode)
		{
			//openSet.clear();
			cout << "targetNode equals currentNode  "<< openSet.size() << endl;
			
			RetractPath(startNode, targetNode);

			pathFound = true;

			//path.clear();

			return;
		}
		

		for (Node* neighbour : GetNeighbours(currentNode))
		{
			

			if (!neighbour->isWalkable || find(closedSet.begin(), closedSet.end(), neighbour) != closedSet.end())
				continue;

			int newMovementCost = currentNode->gCost + GetDistance(currentNode, neighbour);

			if (newMovementCost < neighbour->gCost || !(find(openSet.begin(), openSet.end(), neighbour) != openSet.end()))
			{
				neighbour->gCost = newMovementCost;
				neighbour->hCost = GetDistance(neighbour, targetNode);
				neighbour->parent = currentNode;

				cout << neighbour->gCost << " " << neighbour->hCost << endl;

				WaitTime(.06);

				if (!(find(openSet.begin(), openSet.end(), neighbour) != openSet.end()))
					openSet.push_back(neighbour);

			}

		}


			/*if (Neighbours.at(i)->fCost < currentNode->fCost)
				currentNode = Neighbours.at(i);

			if (newMovementCost < Neighbours.at(i)->gCost || !(find(openSet.begin(), openSet.end(), Neighbours.at(i)) != openSet.end()))
			{
				Neighbours.at(i)->gCost = newMovementCost;
				Neighbours.at(i)->hCost = GetDistance(Neighbours.at(i), targetNode);
				Neighbours.at(i)->parent = currentNode;

				if (!(find(openSet.begin(), openSet.end(), Neighbours.at(i)) != openSet.end()))
					openSet.push_back(Neighbours.at(i));

			}*/

		
		

	}



}

void Astar::RetractPath(Node* startNode, Node* endNode)
{
	

	
	Node* currentNode = endNode;

	while (currentNode != startNode)
	{
		path.push_back(currentNode);
		currentNode = currentNode->parent;

		cout << currentNode->gridX << "  " << currentNode->gridY << endl;

	}
	reverse(path.begin(), path.end());

	/*for (int i = 0; i < path.size(); i++)
	{
		cout << path.at(i)->gridX << "  " << path.at(i)->gridY << endl;

	}*/

}

int Astar::GetDistance(Node* nodeA, Node* nodeB)
{


	int distX = abs(nodeA->gridX - nodeB->gridX);
	int distY = abs(nodeA->gridY - nodeB->gridY);

	if (distX > distY)
		return 14 * distY + 10 * (distX - distY);

	return 14 * distY + 10 * (distY - distX);

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

			if (checkX >= 0 && checkX < TRACK_COLS && checkY >= 0 && checkY < TRACK_ROWS)
			{
				neighbours.push_back(findNode(checkX, checkY));
			}
		}

	}

	return neighbours;

	/*for (int i = 0; i < Neighbours.size(); i++)
	{
		int CNdx = abs(currentNode->gridX - Neighbours.at(i)->gridX);
		int CNdy = abs(currentNode->gridY - Neighbours.at(i)->gridY);
		int CNdist = floor(sqrt(CNdx + CNdy) * 10);

		int TNdx = abs(targetNode->gridX - Neighbours.at(i)->gridX);
		int TNdy = abs(targetNode->gridY - Neighbours.at(i)->gridY);
		int TNdist = floor(sqrt(TNdx + TNdy) * 10);


		Neighbours.at(i)->gCost = CNdist;
		Neighbours.at(i)->hCost = TNdist;
		Neighbours.at(i)->fCost = Neighbours.at(i)->gCost + Neighbours.at(i)->hCost; 

	}*/

	//return Neighbours;

}

Node* Astar::findNode(int x, int y)
{
	

	for (int i = 0; i < gridNodes.size(); i++)
	{
		//cout << " " << gridNodes.at(i)->gridX << " " << gridNodes.at(i)->gridY << endl;

		if (gridNodes.at(i)->gridX == x && gridNodes.at(i)->gridY == y)
		{
			//cout << gridNodes.at(i)->gridX << "  " << gridNodes.at(i)->gridY << "  " << gridNodes.at(i)->isWalkable << "  " << gridNodes.size() << endl;
			return gridNodes.at(i);

		}
	
	}

	

}

int Astar::fCost(Node* currentNode)
{
	int fCost = currentNode->gCost + currentNode->hCost;

	return fCost;

}
