#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <getopt.h>

void printUsage() {
    std::cout << "Триганометричский калькулятор :) \n" << std::endl;
    std::cout << "Выберете операцию:" << std::endl;
    std::cout << "	1. Вычисление синуса: -o sin (число)" << std::endl;
    std::cout << "	2. Вычисление косинуса: -o cos (число)" << std::endl;
}

int main(int argc, char* argv[]) {
    std::string operation;
    double result = 0;
    
    struct option longOptions[] = {
        { "операция", required_argument, nullptr, 'o' },
        { nullptr, 0, nullptr, 0 }
    };

    int optionIndex;
    int option;
    while ((option = getopt_long(argc, argv, "o:", longOptions, &optionIndex)) != -1) {
        switch (option) {
            case 'o':
                operation = optarg;
                break;
            default:
                printUsage();
                return 1;
        }
    }

    if (argc - optind < 1 || operation.empty()) {
        printUsage();
        return 1;
    }

    for (int i = optind; i < argc; i++) {
        double operand = std::stod(argv[i]);

        if (operation == "sin") {
            result += sin(operand * M_PI / 180.0);
        }
        else if (operation == "cos") {
            result += cos(operand * M_PI / 180.0);
        }
        else {
            std::cout << "Ты чаго тут понаписал, Ирод?: \n " << operation << std::endl;
            printUsage();
            return 1;
        }
    }

    std::cout << "Результат :) \n\n" << std::setprecision(4) << result << std::endl;

    return 0;
}
