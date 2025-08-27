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
void printCells(Cell* board[][10], int boardSize) {
    for (int i = 0; i < boardSize; ++i) { //nested loop to go through all cells
        for (int j = 0; j < boardSize; ++j) {
            cout << board[i][j]->state;
        }
        // Move to the next line after each row
        cout << endl;
    }
}
/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) {
    int x = curCell->x;  // Current cell's row index
    int y = curCell->y;  // Current cell's column index
    int count = 0;       // Counter for live neighbors

    for (int dx = -1; dx <= 1; ++dx) { //loops through all neighbors because coordinates based on home cell
        for (int dy = -1; dy <= 1; ++dy) { //so (-1,-1) is first tested which would be bottom left cell when compared in a 3x3 grid to home cell
            // Skip the current cell itself
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx;  // neibhor's x based on home cell
            int ny = y + dy;  // neighbor's y based on home cell

            //check if neighbor is within bounds
            if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                // If neighbor is alive, increment count
                if (board[nx][ny]->state == 1) {
                    ++count;
                }
            }
        }
    }
    // Store the result in the cell's numLiveNeighbors field
    curCell->numLiveNeighbors = count;
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
bool updateCellState(Cell* board[][10], int boardSize) {
    bool changed = false;  // Tracks if any cell's state changed

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            int liveNeighbors = board[i][j]->numLiveNeighbors; //local variables for typing and readability
            int currentState = board[i][j]->state;
            int newState = currentState; // Will hold the updated state

            // Rule 1: Underpopulation — dies
            if (currentState == 1 && liveNeighbors < 2) {
                newState = 0;
            }
            // Rule 2: Survival — lives on
            else if (currentState == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                newState = 1; //shouldn't need anything but I decided to put it just for reference
            }
            // Rule 3: Overpopulation — dies
            else if (currentState == 1 && liveNeighbors > 3) {
                newState = 0;
            }
            // Rule 4: Reproduction — becomes alive
            else if (currentState == 0 && liveNeighbors == 3) {
                newState = 1;
            }

            // If the state changed, update and mark the board as changed
            if (newState != currentState) {
                board[i][j]->state = newState;
                changed = true;
            }
        }
    }

    cout << "\nSimulation Complete" << std::endl;
    return changed;
}