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

   

    Vector2 startPos;
    Vector2 targetPos;

    Astar* path = new Astar();

    InitWindow(screenWidth, screenHeight, "Pathfinding!");
    SetTargetFPS(60);

   
    //startNode = targetNode;

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(White);

        path->drawTrack(startNode);
       

        if (IsMouseButtonPressed(0))
        {
            mouseY = GetMousePosition().x / 40;
            mouseX = GetMousePosition().y / 40;

            startNode = path->findNode(mouseX, mouseY);

            startNode->isStartNode = true;

            cout << startNode->gridX << " " << startNode->gridY << endl;

        }
        else if (IsMouseButtonPressed(1))
        {
            mouseY = floor(GetMousePosition().x / 40);
            mouseX = floor(GetMousePosition().y / 40);

            targetNode = path->findNode(mouseX, mouseY);

           targetNode->isTargetNode = true;

           path->pathFound = false;

            cout << targetNode->gridX << " " << targetNode->gridY << endl;

        }
        EndDrawing();
       

        if(path->pathFound == false)
            path->FindPath(startNode, targetNode);
       
        
    }


    CloseWindow();
    return 0;
}

