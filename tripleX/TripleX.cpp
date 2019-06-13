// Preprocessor Directive
#include <iostream>

// Based on computer's time
#include <ctime>

void PrintIntroduction(int levelDifficulty)
{
    // Expression statements
    std::cout << "\n\n ===============================================================\n";
    std::cout << "||                                                             ||\n";
    std::cout << "|| You are a secret agent breaking into a secure server room   ||\n";
    std::cout << "|| Level of difficulty: " << levelDifficulty << "                                      ||\n";
    std::cout << "|| You need to enter the correct codes to continue...          ||\n";
    std::cout << "||                                                             ||\n";
    std::cout << "|| + There are 3 numbers in the code                           ||\n";
}

bool PlayGame(int levelDifficulty)
{

    PrintIntroduction(levelDifficulty);
    
    // Declaration statements
    unsigned int CodeA = rand() % (levelDifficulty + levelDifficulty);
    unsigned int CodeB = rand() % (levelDifficulty + levelDifficulty);
    unsigned int CodeC = rand() % (levelDifficulty + levelDifficulty);

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    
    int guessA, guessB, guessC;

    // A hint to agent
    std::cout << "|| + The codes sum up to: " << CodeSum << "\n";
    std::cout << "|| + The codes multiply up to: " << CodeProduct << "\n";
    std::cout << "||                                                             ||\n";
    std::cout << " ===============================================================\n";

    // This will also work when you use space between numbers
    std::cout << ">>> Enter your guesses: ";
    std::cin >> guessA >> guessB >> guessC;
    std::cout << "You entered: " << guessA << guessB << guessC << "\n\n";

    const int guessSum = guessA + guessB + guessC;
    const int guessProduct = guessA * guessB * guessC;

    // std::cout << "The sum of all guesses is: " << guessSum << "\n";
    // std::cout << "The multiply of all guess is: " << guessProduct << "\n\n";
    
    if (guessSum == CodeSum && guessProduct == CodeProduct)
    {
        std::cout << "Correct Code\n\n";
        return true;
    }
    else
    {
        std::cout << "Incorrect Code\n\n";
        return false;
    }

}

// Main funciton
int main()
{
    // Create new random sequence based on time of day
    srand(time(NULL));
    
    int levelDifficulty = 1;
    const int maxLevel = 5;

    while (levelDifficulty <= maxLevel)
    {
        bool levelComplete = PlayGame(levelDifficulty);

        // Clears any errors
        std::cin.clear();

        // Discards the buffers
        std::cin.ignore();

        if (levelComplete)
        {
            // Increase the level difficulty
            ++levelDifficulty;
        }
        
    }

    std::cout << "Congratulation on successfully access into system!\n\n";

    // Return statement
    return 0;
}