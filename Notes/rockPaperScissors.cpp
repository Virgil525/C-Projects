#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main(){
    char player;
    char computer;

    player = getUserChoice();
    std::cout << "Your choice is: ";
    showChoice(player);
    computer = getComputerChoice();
    std::cout << "Computer choice is: ";
    showChoice(computer);
    chooseWinner(player, computer);

    return 0;
}

char getUserChoice(){
    std::cout << "ROCK-PAPER-SCISSORS Game!\n";
    char player;
    do{
        std::cout << "*************************\n";
        std::cout << "r for rock\n";
        std::cout << "p for paper\n";
        std::cout << "s for scissors\n";
        std::cin >> player;
    }while(player != 'r' && player != 'p' && player !='s');
    return player;
}
char getComputerChoice(){
    srand(time(NULL));
    int computerChoice = rand() % 3 + 1;
    char choice;
    switch (computerChoice) {
        case 1: 
            choice = 'r';
            break;
        case 2: 
            choice = 'p';
            break;
        case 3: 
            choice = 's';
            break;
    }
    return choice;
}

void showChoice(char choice){
    switch (choice)
    {
    case 'r':std::cout<< "Rock\n";
        break;
    case 'p': std::cout<< "Paper\n";
        break;
    case 's': std::cout<< "Scissors\n";
        break;
    }
}

void chooseWinner(char player, char computer){
    switch (player)
    {
    case 'r':
        switch (computer)
        {
            case 'r': std::cout << "Draw!\n";
                break;
            case 'p': std::cout << "Lose!\n";
                break;
            case 's': std::cout << "Win!\n";
                break;
        }
        break;
    case 'p':
        switch (computer)
        {
            case 'r': std::cout << "Win!\n";
                break;
            case 'p': std::cout << "Draw!\n";
                break;
            case 's': std::cout << "Lose!\n";
                break;
        }
        break;
    case 's':
        switch (computer)
        {
            case 'r': std::cout << "Lose!\n";
                break;
            case 'p': std::cout << "Win!\n";
                break;
            case 's': std::cout << "Draw!\n";
                break;
        }
        break;
    }
}