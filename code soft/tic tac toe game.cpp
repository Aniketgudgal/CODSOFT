#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

// Function to display the game board
void drawBoard()
{
  cout << "  |  |  " << endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
	{
      cout << board[i][j] << " | ";
    }
    cout << endl;
    if (i < 2) {
      cout << "-----+-----+-----" << endl;
    }
  }
  cout << "  |  |  " << endl;
}

// Function to check if a player has won
bool checkWin(char player)
{
  // Check rows
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
	{
      return true;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++)
  {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
	{
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
  {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
  {
    return true;
  }

  return false;
}

// Function to check if the board is full
bool isBoardFull() 
{
  for (int i = 0; i < 3; i++)
   {
    for (int j = 0; j < 3; j++)
	{
      if (board[i][j] == ' ')
	  {
        return false;
      }
    }
  }
  return true;
}

int main()
 {
  char currentPlayer = 'X';
  int choice;

  while (true) 
  {
    // Draw the board
    drawBoard();

    // Get player's choice
    cout << currentPlayer << "'s turn. Enter a number (1-9): ";
    cin >> choice;

    // Validate user input
    while (choice < 1 || choice > 9 || board[(choice - 1) / 3][(choice - 1) % 3] != ' ')
	{
      cout << "Invalid choice. Please try again: ";
      cin >> choice;
    }

    // Update the board
    board[(choice - 1) / 3][(choice - 1) % 3] = currentPlayer;

    // Check for win or draw
    if (checkWin(currentPlayer))
	{
      drawBoard();
      cout << currentPlayer << " wins!" << endl;
      break;
    } else if (isBoardFull())
	{
      drawBoard();
      cout << "It's a draw!" << endl;
      break;
    }

    // Switch player
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  return 0;
}
