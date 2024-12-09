#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main(){
    double balance = 69;
    int choice = 0;
    int userInput;

    do{
        std::cout << "******************\n";
        std::cout << "Enter your choice:\n";
        std::cout << "******************\n";

        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Balance\n";
        std::cout << "3. Withdraw Balance\n";
        std::cout << "4. Exit\n";
        std::cin >> userInput;

        // clear flags from not interpreted cin
        std::cin.clear();
        // clear the buffer
        fflush(stdin);

        switch (userInput)
        {
            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit();
                showBalance(balance);
                break;
            case 3:
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            case 4:
                std::cout <<"Thanks for visiting";
                break;
            
            default:
                std::cout <<"invalid input";
                break;
        }
    }while(userInput != 4);
    return 0;

}

void showBalance(double balance){
    std::cout << "Your balance is: $"<< std::setprecision(2) << std::fixed << balance << std::endl;
}
double deposit(){
    double depositAmount;
    std::cout << "how much would you like to deposite? ";
    std::cin >> depositAmount;
    depositAmount = depositAmount > 0 ? depositAmount : 0;
    return depositAmount;
}
double withdraw(double balance){
    double withdrawAmount;
    std::cout << "how much would you like to withdraw? ";
    std::cin >> withdrawAmount;
    if(withdrawAmount > balance){
        std::cout << "insufficient funds\n";
        return 0;
    }
    withdrawAmount = withdrawAmount > 0 ? withdrawAmount : 0;
    return withdrawAmount;
}