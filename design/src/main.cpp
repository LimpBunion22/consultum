
#include <iostream>
#include <string>

int main() {
    std::string state = "Main Menu";

    std::cout << "\n\n      Welcome to CONSULTUM" << "\n\n";
    std::cout << "            ---\n"
              << "          /  o\\ \\" << "\n"
              << "         |  /|   |" << "\n"
              << "          \\ / \\ /" << "\n"
              << "            ---  " << "\n\n";


    while (true){
        std::cout << "\n" << state << ": ";
        std::string input_cmd;
        std::getline(std::cin, input_cmd);
        
        if(input_cmd.find("help") != std::string::npos){
            std::cout << "\n      Help yourself, useless piece of sh*t" << "\n";
            continue;
        }

        if(input_cmd.find("exit") != std::string::npos){
            std::cout << "\n      See you soon!" << "\n";
            return 0;
        }


    }
}