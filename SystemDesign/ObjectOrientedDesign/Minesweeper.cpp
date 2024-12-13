class Cell {
    int row, int col, bool isBomb, bool isExposed, int number (0 for blanks), bool isGuess
    bool flipCell(){
        isExposed = true;
        return !isBomb;
    }
    void toggleGuess(){
        if(!isExposed) isGuess != isGuess;
        }
    }
}

class Board {
    int rows, int cols,int bombs, int unexposedRemaining, vector<Cells> cells, vector<Cell> bombs,

    Board(){...}
    void InitializeBoard(){...}  //setujemo numbered cells tako sto oko svake bombe inkrementiramo polja okolo koja nisu bombe
            //  ovo je brze nego da idemo za svaki cell da brojimo da li ima bombi oko nje
    void expandBlank(){...} //rekurzivno zovemo za one koje nisu visited
    void setBombs(){...} //random + shifting matrice
    void calculateRemainingCells(){...} // ovo pratimo usput kako se flipuju 
    int getRemaining(){ return unexposedRemaining;}

    bool flipCell( Cell cell){}
    UserPlayResult playFlip(UserPlay play){}

}

class UserPlay {
    int row, int col, bool isGuess;
    //ktor , getters , setters
}
class UserPlayResult {
    bool successfull;
    GameState resultingState;
}

enum GameState {
    PLAYING, LOST, WON
}

class Game{
    GameState state;
    Board* board;
    int rows, cols, bombs;
    Game(){...} //instantiate the board
    void playGame() {...}//loops until game is won or lost

    
}
