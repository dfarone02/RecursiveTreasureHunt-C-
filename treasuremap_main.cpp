//Daniel Farone
//CSCI 3110-001
//Project #4
//Due: 03/22/22
//This file is the driver for the TreasureMap class. It instantiates a TreasureMap object.
//After invoking the FindTreasure() function beginning at cell 1,1 it outputs "Treasure Found" or "No treasure!"
#include "treasuremap.h"
int main()
{
  TreasureMap tm;
  tm.PrintMap();
  bool isFound = false;
  std::cout << "Start position: 1,1" << std::endl;
  tm.FindTreasure(1, 1, isFound);
  if(isFound == true)
    std::cout << "Treasure Found!" << std::endl;
  else
    std::cout << "No Treasure!" << std::endl; 
	return 0;
}

