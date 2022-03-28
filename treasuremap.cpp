//Daniel Farone
//CSCI 3110-001
//Project #4
//Due: 03/22/22
//This file implements the TreasureMap class and defines the TreasureMap() constructor to build the map,
// getMove() function to retrieve the next move, ThePrintMap() function to output the map and its current state, 
//and the FindTreasure() function to search the map to find the treasure.
#include "treasuremap.h"
#include <fstream>
//The constructor for the TreasureMap class open the input file and reads it.
// The first line is the order of directions for exploring. The secon line is the size of the map.
//The remaining lines are the contents of the map (excluding the boundaries)

TreasureMap::TreasureMap()
{
  std::ifstream infile;
  infile.open("treasuremap.txt");
  infile >> xplor;
  infile >> maxRows >> maxCols;
//Creates a 10 x 10 map of X
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      tmap[i][j] = 'X';
//Fills in the desired area with the map from the file
  for(int i = 1; i <= maxRows; i++)
    for(int j = 1; j <= maxCols; j++)
      infile >> tmap[i][j];
}

//This function takes no arguments and returns nothing. It ouputs the map's current state after each move.
void TreasureMap::PrintMap()
{
  std::cout << "Current map:" << std::endl;
  for(int rowIndex = 1; rowIndex <= maxRows; rowIndex++)
  {
    for(int colIndex = 1; colIndex <= maxCols; colIndex++)
    {
      std::cout << tmap[rowIndex][colIndex];
    }
    std::cout << std::endl;
  }
  
}
//This function is a recursive function to explore the map. After a "bad" move, the function naturally backtracks.
//Nothing is returned, but it takes the integer "row", the integer "column", and a bool reference variable "located" to say if treasure is found
void TreasureMap::FindTreasure(int row, int col, bool& isFound)
{
  if(isFound == false)
  {
    std::pair<int,int> moveTo;
    if(tmap[row][col] == 'L' || tmap[row][col] == 'T')
    {
      std::cout << "Searching " << row << "," << col << std::endl;
      if(tmap[row][col] == 'T')
        isFound = true;
      else
      {
        tmap[row][col] = '*';
        PrintMap();
        for(int i = 0; i < 4; i++)
        {
          moveTo = getMove(xplor[i]); 
          FindTreasure(row + moveTo.first, col + moveTo.second, isFound);
        }
      }
    }
  }
}
//This function takes a single char "direction" as an argument which is an element of the xplor sting (N,E,S,W)
//Returns a std::pair of 2 ints which indicate to go up, down, or stay for the row and left, right, or stay for the column
std::pair<int,int> TreasureMap::getMove(char direction)
{
  std::pair<int,int> move;
  if(direction == 'N')
    move = std::make_pair(-1, 0);
  else if(direction == 'E')
    move = std::make_pair(0, 1);
  else if(direction == 'S')
    move = std::make_pair(1, 0);
  else
    move = std::make_pair(0, -1); 
  return move;
}