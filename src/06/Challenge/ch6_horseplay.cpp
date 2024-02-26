// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>


class Move {
private:
    int rank_delta;
    int file_delta;

public:
    Move(int rank_delta_in, int file_delta_in) : rank_delta(rank_delta_in), file_delta(file_delta_in) {}
    int get_rank() const { return rank_delta; }
    int get_file() const { return file_delta; }
};

class Square {
private:
    int rank;
    int file;

public:
    Square(std::string pos) {
        rank = static_cast<int>(pos[0]) - 'a';
        file = static_cast<int>(pos[1]) - '1';
    }

    Square(int rank_in, int file_in) : rank(rank_in), file(file_in) {}

    bool is_valid() {
        return rank >= 0 && rank <= 7 && file >= 0 && file <= 7;
    }

    Square operator+(const Move& move) {
        return Square(rank + move.get_rank(), file + move.get_file());
    }

    std::string to_string() {
        std::string result = "";
        result += static_cast<char>(rank) + 'a';
        result += static_cast<char>(file + '1');
        return result;
    }
};

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<Move> moves {Move(-1, -2), Move(-2, -1), Move(-1, 2), Move(-2, 1), Move(1, -2), Move(2, -1), Move(1, 2), Move(2, 1)};
    std::vector<std::string> dest;

    // Write your code here
    Square start = Square(knight);
    for(Move move: moves) {
        if((start + move).is_valid()) {
            dest.push_back((start + move).to_string());
        }
    }

    return dest;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
