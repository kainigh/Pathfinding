// Pathfinding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include "Astar.h"

int main()
{
    Color White = Color{ 255, 255, 255, 255 };

    const int screenWidth = 600;
    const int screenHeight = 800;
    int mouseX;
    int mouseY;

    Node* startNode = new Node;
    Node* targetNode = new Node;

    Node* previousStartNode = new Node;
    Node* previousTargetNode = new Node;

   

    Vector2 startPos;
    Vector2 targetPos;

    Astar* path = new Astar();

    InitWindow(screenWidth, screenHeight, "Pathfinding!");
    SetTargetFPS(60);

   
    //startNode = targetNode;

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(White);

        path->drawGrid(startNode);
       

        if (IsMouseButtonPressed(0))
        {
            mouseY = GetMousePosition().x / 40;
            mouseX = GetMousePosition().y / 40;

            previousStartNode = startNode;
            previousStartNode->isStartNode = false;

            previousTargetNode = targetNode;
            previousTargetNode->isTargetNode = false;

            startNode = path->findNode(mouseX, mouseY);

            if(startNode->isWalkable == true)
                startNode->isStartNode = true;
            

            cout << startNode->gridX << " " << startNode->gridY << endl;

            path->path.clear();

        }
        else if (IsMouseButtonPressed(1))
        {
            mouseY = floor(GetMousePosition().x / 40);
            mouseX = floor(GetMousePosition().y / 40);

            previousTargetNode = targetNode;
            previousTargetNode->isTargetNode = false;

            path->path.clear();

            targetNode = path->findNode(mouseX, mouseY);

            if (targetNode->isWalkable == true)
                targetNode->isTargetNode = true;


            path->pathFound = false;

            cout << targetNode->gridX << " " << targetNode->gridY << endl;

        }
        EndDrawing();
       

        if(path->pathFound == false && startNode->isWalkable == true && targetNode->isWalkable == true)
            path->FindPath(startNode, targetNode);
       
        
    }


    CloseWindow();
    return 0;
}

