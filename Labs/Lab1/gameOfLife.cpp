#include "gameOfLife.h"

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < boardSize; i++) {
        for (int j=0; j < boardSize; j++) {
            board[i][j] = new Cell;
            board[i][j]->x; //making it to an x, y coordinate plane
            board[i][j]->y;
            board[i][j]->state = 0;
            board[i][j]->numLiveNeighbors = 0;
        }
    }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{
    string fileName;
    cout << "Enter board #: ";
    cin >> fileName; //getline to get entire thing.
    cin.ignore(); //clear buffer

    ifstream inputFromFile(fileName); //Open File
    if (!inputFromFile.is_open()) {     //Debug incase file doesn't open, could add do{}while() loop but this fine for now
        cerr << "Failed to open file: " << fileName << endl;
        return 1;
    }
    for (int i = 0; i < boardSize; i ++) {      //Nested loop to iterate through entire array.
        string line;
        getline(inputFromFile, line); //getline through each iteration of a column to read each row
        for (int j = 0; j < boardSize; j++) {
            // read the information from the row dictating either 0 or 1 while casting to int
            if (line[j] == '1') {
                board[i][j]->state = 1;
            } else {
                board[i][j]->state = 0;
            }
        }
    }
    inputFromFile.close();
}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize) //easiest function, Just printing the information out
{
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << board[i][j]->state;
        }
    }
    cout << endl;
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{

}

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], int boardSize) 
{
    return false;
}