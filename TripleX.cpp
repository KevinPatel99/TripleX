// "# inlcude" is the Prepocessor Directive followed by the Header File
// this portion gives instruction to the compiler to include a library before compiling
// iostream is the directory header file inlcuding the input/output stream
#include <iostream> 

// allows to call code related to computer's time
#include <ctime>


// Game: Triplex
// Description: Game that randomly generates 3 numbers and player has to guess all three numbers based on the  sum and product of the 3 randomly generated numbers
// Author: Kevin M Patel

//prints introduction to game
//input: current game difficulty
void PrintIntroduction(int Difficulty) {
    // standard format to print a line to the user
    // std is the namespace, used to prevent name conflicts in code. Avoids functions with same names
    // :: is the Scope Operator which tells the compiler to check for code inside the namespace
    // "\n" informs the compiler to go to next line ( could also do " std::cout << std::endl; ")
    std::cout << "\nYou are a secret agent breaking into a level " << Difficulty ;
    std::cout << " secure server room...\nEnter the correct codes to continue...\n\n";
    
}

// starts games at current level
// input: current game difficulty 
bool PlayGame(int Difficulty) 
{

    PrintIntroduction(Difficulty);

    // "const" keyword signals compiler to not let the variable be overridden with another value
      // variables become well protected
        
    // varaibles are each assigned a random number from a certain range where the range increases as the difficulty increases
    // adding Difficulty also avoids the issue of zero values in the code variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "-o- There are 3 numbers in the code\n";
    std::cout << "-o- The sum of the codes is " << CodeSum << "\n";
    std::cout << "-o- The product of the codes is " << CodeProduct << "\n";

    std::cout << "\nEnter the code\n";

    int GuessA, GuessB, GuessC;

    // "cin >>" represents character input and extraction operator allowing users to give an input
    // user input is stored in PlayerGuess
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;


    //player moves onto the next level
    if (GuessProduct == CodeProduct && GuessSum == CodeSum)
        {

            // all levels have been completed and player has beat the entire game
            if (Difficulty == 5) 
            {
              std::cout << "You've passed level " << Difficulty << " and have successfully won the game!\n";
              return true;  
            }

         std::cout << "You've passed level " << Difficulty << "!\n";
         return true;
        }
        else 
        {
            std::cout << "You lose! Try again.\n";
            return false;
        }
    
}

// int return type ( always will be of this format)
// main is the name of the function, obv.
int main() 
//function body
{
    //creates new random sequence based on the time of day
    srand(time(NULL));

    int LevelDifficulty = 1;

    while (LevelDifficulty <= 5) {
    
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear();   // clears any errors
    std::cin.ignore();  // discards the buffer

    //Increase level difficulty
    if (bLevelComplete) {
        LevelDifficulty++;
    }

    }

    //used as an exit status
    //returning 0 indicates that the program has successfully executed, any other number would indicate an error
    return 0;
}

// run code by right-clicking file name then hitting open in terminal
// in compiler: (1) type "cl triplex.cpp" to complile code  then  (2) type "triplex"