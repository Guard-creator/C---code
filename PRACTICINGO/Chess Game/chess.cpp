#include <iostream>
using namespace std;

// Base class for all chess pieces
class Piece {
public:
    char symbol;  // 'P' for Pawn, 'K' for King, etc.
    bool isWhite; // True = White, False = Black

    Piece(char sym, bool white) : symbol(sym), isWhite(white) {}

    virtual bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) = 0;

    virtual string getName() {
        return isWhite ? "W" : "B"; // White = "W", Black = "B"
    }
};

// Pawn Class
class Pawn : public Piece {
public:
    Pawn(bool white) : Piece('P', white) {}

    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) override {
        int direction = isWhite ? -1 : 1;

        // we are using white as -1
        // and black as +1
        // because white is going 7 to 0 up that's why we are do minus
        // and black is going 0 to 7 down that's why we are adding to forward 

        // take one step 
        if (startY == endY && endX == startX + direction && board[endX][endY] == nullptr)
            return true;

        // take two step for first move
        if (startY == endY && ((isWhite && startX == 6) || (!isWhite && startX == 1)) &&
            endX == startX + 2 * direction && board[endX][endY] == nullptr)
            return true;
        
        // capture diagonal Pawn
        if (abs(startY - endY) == 1 && endX == startX + direction && board[endX][endY] != nullptr &&
            board[endX][endY]->isWhite != isWhite)
            return true;

        return false;
    }

    string getName() override { return isWhite ? "WP" : "BP"; }
};

// King Class
class King : public Piece {
public:
    King(bool white) : Piece('K', white) {}

    // The King in chess moves only one step in any 
    // direction (vertically, horizontally, or diagonally).

    // This ensures the King can only move one step in any direction:
    // abs(startX - endX) <= 1 → Moves one step up/down (or stays in place).
    // abs(startY - endY) <= 1 → Moves one step left/right (or stays in place).
    // Both conditions together allow movement in all 8 possible directions.

    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) override {
        return abs(startX - endX) <= 1 && abs(startY - endY) <= 1;
    }

    string getName() override { return isWhite ? "WK" : "BK"; }
};

// Queen Class
class Queen : public Piece {
public:
    Queen(bool white) : Piece('Q', white) {}

    //  The Queen is the most powerful piece in chess because it 
    //  can move like both a Rook and a Bishop.
    // it moving horizontally and vertically and diagonally.

    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) override {
        return (startX == endX || startY == endY || abs(startX - endX) == abs(startY - endY));
    }  

    string getName() override { return isWhite ? "WQ" : "BQ"; }
};

// Rook Class
class Rook : public Piece {
public:

    // Rook always moee straight horizontally and vertically and it doesn't jump over pawn
    // Moving in straight line means start & end position of x or y will be same.
    // if moving horizontally it vertical position change but horizontal remain same
    // if moving vertically it horizontal postion change but vertically remain same.

    Rook(bool white) : Piece('R', white) {}

    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) override {
        return (startX == endX || startY == endY);
    }

    string getName() override { return isWhite ? "WR" : "BR"; }
};

// Bishop Class
class Bishop : public Piece {
public:
    // A Bishop moves diagonally, meaning it moves an equal number of steps 
    // in both the X (row) and Y (column) directions. This is why the absolute difference 
    // between startX and endX is always equal to the absolute difference between startY and endY.
    
    Bishop(bool white) : Piece('B', white) {}

    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) override {
        return abs(startX - endX) == abs(startY - endY);
    }

    string getName() override { return isWhite ? "WB" : "BB"; }
};

// Knight Class
class Knight : public Piece {
public:
    Knight(bool white) : Piece('N', white) {}

    // The knight can move two squares in one direction and one square in the perpendicular direction.
    // that why no matter what start & end X and start & end Y will always have a difference 
    // of 1 or 2

    bool isValidMove(int startX, int startY, int endX, int endY, Piece* board[8][8]) override {
        return (abs(startX - endX) == 2 && abs(startY - endY) == 1) ||
               (abs(startX - endX) == 1 && abs(startY - endY) == 2);
    }
  
    // This ensures that the knight moves two squares in the vertical direction (X) 
    // and one square in the horizontal direction (Y).

    string getName() override { return isWhite ? "WN" : "BN"; }
};

// ChessBoard Class
class ChessBoard {
public:
    Piece* board[8][8]; // 8x8 grid
    // This creates a 2D array of pointers, not actual pieces
    //Why use Piece* pointers
    // Every chess piece (Pawn, Rook, Knight, etc.) inherits from Piece.
    // Since all pieces are stored as Piece*, we can use polymorphism to call isValidMove() 
    // on any piece, no matter if it’s a Pawn, Bishop, or King.
    // board[8][8] stores memory addresses, so we don’t need to store different types separately.

    ChessBoard() { initializeBoard(); }

    void initializeBoard() {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                board[i][j] = nullptr;

        for (int i = 0; i < 8; i++) {
            board[1][i] = new Pawn(false);
            board[6][i] = new Pawn(true);
        }

        board[0][0] = new Rook(false);
        board[0][7] = new Rook(false);
        board[7][0] = new Rook(true);
        board[7][7] = new Rook(true);

        board[0][1] = new Knight(false);
        board[0][6] = new Knight(false);
        board[7][1] = new Knight(true);
        board[7][6] = new Knight(true);

        board[0][2] = new Bishop(false);
        board[0][5] = new Bishop(false);
        board[7][2] = new Bishop(true);
        board[7][5] = new Bishop(true);

        board[0][3] = new Queen(false);
        board[7][3] = new Queen(true);

        board[0][4] = new King(false);
        board[7][4] = new King(true);

        // new Pawn(false); creates a new Pawn object in heap memory.
        // It returns the memory address where the pawn is stored.
        // board[1][i] (which is a Piece*) stores this memory address.
    }

    void displayBoard() {
        cout << "   0   1   2   3   4   5   6   7  \n";
        cout << "  --------------------------------\n";
        for (int i = 0; i < 8; i++) {
            cout << i << "|";
            for (int j = 0; j < 8; j++) {
                if (board[i][j])
                    cout << " " << board[i][j]->getName() << " ";
                else
                    cout << " .  ";
            }
            cout << "|\n";
        }
        cout << "  --------------------------------\n";
    }
};

// ChessGame Class
class ChessGame {
private:
    ChessBoard board;
    bool whiteTurn = true;

public:
    void play() {
        int startX, startY, endX, endY;
        while (true) {
            board.displayBoard();
            cout << (whiteTurn ? "White's turn" : "Black's turn") << endl;

            cout << "Enter start row, start col, end row, end col: ";
            cin >> startX >> startY >> endX >> endY;

            if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
                endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
                cout << "Invalid input. Try again.\n";
                continue;
            }

            Piece* selectedPiece = board.board[startX][startY];
            // Piece* means a pointer to a Piece object.
            // We are storing the result of board.board[startX][startY] into selectedPiece.
            // If there is a piece at (startX, startY), selectedPiece now holds that piece’s memory address.
            // If the square is empty, selectedPiece will be nullptr.
            if (!selectedPiece || selectedPiece->isWhite != whiteTurn) {
                cout << "Invalid selection. Try again.\n";
                continue;
            }

            if (!selectedPiece->isValidMove(startX, startY, endX, endY, board.board)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board.board[endX][endY] = selectedPiece;
            board.board[startX][startY] = nullptr;

            whiteTurn = !whiteTurn;
        }
    }
};

int main() {
    ChessGame game;
    game.play();
    return 0;
}
