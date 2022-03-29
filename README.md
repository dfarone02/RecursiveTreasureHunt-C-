# RecursiveTreasureHunt-C++-

Description: 

A C++ program that, given a starting point on an island, finds its way to a treasure, using recursion. The treasure
map will be read from a file. The map is a rectangular grid represented as a 2D
standard C++ array (not a vector or other STL container), composed of water cells (marked by ~) and land cells (marked
with L). The treasure (if there is one) is on a special land cell marked with the letter T. The program should run until the
treasure is found or until it determines that there is no treasure (after fully exploring the map). Exploration is done by
recursively invoking a function and marking the cells visited with a special character (an electronic bread crumb to keep
from reprocessing explored cells). The legal moves are to cells adjacent to the current cell, but not diagonal to it. The
order in which adjacent cells must be explored is read from the file. The treasure should be found by using recursive
calls and backtracking, and not by looking ahead. If the specially marked treasure cell is
encountered, the game should print a message that it was found. Otherwise, after fully exploring the map, a message is
output stating that there is no treasure on the island.

Note the attributes of a legal map:

   Cells references are row # then column #. Row numbers increase in the
  downward direction, and column numbers increase to the right.
  
   The “play area” includes only the non-red cells.
  
   Cell 1,1 does not contain the treasure, and serves as the starting point for
  the treasure search.
  
   X (red) cells are non-traversable map boundary cells
  
   The cells in red are not part of the treasure map read from the file,
  but must be constructed around it and represented in the array.
  The treasure map at left has an 8x8 play area and is shown in the
  10x10 array).
  
   ~ (blue) cells are water cells and are also non-traversable.
  
   L (tan) cells are traversable land cells not yet visited.
  
   * (yellow) shows traversable land cells that have been previously visited.
  
   T (brown) cell is the treasure (if the map has one). This cell must be
  reachable from the starting point, using legal moves - it cannot be
  surrounded by water (~) or boundary (X) cell on all sides.
  
   The first line in the input file is the order of exploration. If this line is
  NESW (for North, East, South, and West) would be: N, E, S, W (in order). Any order is possible. 
  
Specifications: Program is split into 3 files (separate interface and implementation files, and a driver file):

a) The TreasureMap class – This class represents a treasure map

   Files named treasuremap.h and treasuremap.cpp

   Class named TreasureMap

   The interface (header file) is provided 

    i. implement the provided interface file in a class .cpp implementation file

    ii. All data members of the type and size specified in the header file

    iii. All member functions in the interface file is implemented as declared
    
   The constructor will open and read the input file and construct the map. The input file is named
  treasuremap.txt.The file contains a rectangular map no larger than 8 cells by 8 cells  The first line in the
  file is the exploration order: a string containing the characters N,S,E,W in any order. The next
  line holds the dimensions of the map (# of rows followed by # of columns, separated by a
  space). The remainder of the file is the treasure map play area. An example treasure file (4
  rows by 5 columns) is shown below. Note: There are no spaces between cell legend symbols in
  the file.

  NESW
  4 5
  LLL~~
  ~L~~L
  ~LLLT
  ~~LL~

   The PrintMap() function outputs the map’s current state. Only output in unvisited
  traversable cells. See sample output.

   The FindTreasure() function is a void recursive function that explores the map. It has two int
    parameters indicating the player’s row and column (in that order), and a bool reference variable
    that represents whether or not the treasure has been found. The exploration of the treasure
    map will always begin at row 1, column 1 (which is be a land cell). This function relies on
    recursion to explore the map and to backtrack. 

   The getMove() function, has a single char parameter (an element of the xplor string). It returns
  a std::pair of two ints. The first is the row offset [-1 (go up one row), 1 (go down one row), or 0
  (stay in same row)], and the second the column offset [-1 (go left one column), 1 (go right one
  column), or 0 (stay in same column)]. Here’s an example of how to declare and set a pair:
  int row_offset = 0, col_offset = 1; // row_offset and col_offset make up the pair
  std::pair<int,int> move = std::make_pair(row_offset, col_offset); // move is the variable name
  Here’s an example of how to use move: if the player is currently in cell 3, 4 and getMove
  returns the pair (0, 1), the player will proceed to cell 3, 5 (3+0, 4+1).

b) A driver, or client, file

   named proj4.cpp

   instantiate the TreasureMap object.

   invoke the FindTreasure function, beginning at cell 1,1.

   Outputs an appropriate message “Treasure Found!” or “No treasure!”, based on exploration outcome. 
