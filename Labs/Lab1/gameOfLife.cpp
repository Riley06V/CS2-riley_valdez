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
            board[i][j]->x = i; //making it to an x, y coordinate plane
            board[i][j]->y = j;
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
        return;
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
        cout << endl;
    }
    cout << endl;
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) {
    int x = curCell->x;
    int y = curCell->y;
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) { //dx for x axis values
        for (int dy = -1; dy <= 1; ++dy) { //dy for y axis values
            //Starts at -1 so it checks the cell behind on x, below on y
            //Than goes to (-1, 0) which is just the one behind, than to (-1,1)... so on so forth
            if (dx == 0 && dy == 0) continue; //Skip self because the point where that would be is the cell getting neighbor counted

            int neighborX = x + dx; //Calculating coordinate points based on xy of current cell
            int neighborY = y + dy;

            if (neighborX >= 0 && neighborX < boardSize && neighborY >= 0 && neighborY < boardSize) { //check bounds of board to avoid errors
                if (board[neighborX][neighborY]->state == 1) {
                    ++count; //count of Live neighbors because checking if it is a 1 (live)
                }
            }
        }
        curCell->numLiveNeighbors = count; //finds the number of neighbors.
    }
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
    bool changed = false;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            int liveNeighbors = board[i][j]->numLiveNeighbors; //setting to local variable to make it easier to read and to type
            int currentState = board[i][j]->state;
            int newState = currentState; //New variable to check to make sure changes happened AFTER the conditional.
            if (currentState == 1 && liveNeighbors < 2) {
                newState = 0;
            }else if (currentState == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                newState = 1; //no change? Idk if i need to put anything but no change would still represent 1 cuz current state
            } else if (currentState== 1 && liveNeighbors > 3) {
                newState = 0;
            } else if (currentState == 0 && liveNeighbors == 3) {
                newState = 1;
            }
            if (newState != currentState) {
            board[i][j]->state = newState;
            changed = true;
            }
        }
    }
    cout << "\n Simulation Complete" << endl;
    return changed;
}