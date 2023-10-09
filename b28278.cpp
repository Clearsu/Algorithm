#include <stack>
#include <string>
#include <iostream>

void operationOne(std::stack<int>& stack, const std::string& inputStr) {
    int numToPush = std::stoi(inputStr.substr(2));
    
    if (numToPush < 1 || numToPush > 100000) {
        std::cout << "Error: number out of range" << '\n';
        return;
    }
    stack.push(numToPush);
}

void operationTwo(std::stack<int>& stack) {
    if (stack.empty()) {
        std::cout << "-1" << '\n';
    } else {
        std::cout << stack.top() << '\n';
        stack.pop();
    }
}

void operationThree(std::stack<int>& stack) {
    std::cout << stack.size() << '\n';
}

void operationFour(std::stack<int>& stack) {
    std::cout << (stack.empty() ? "1" : "0") << '\n';
}

void operationFive(std::stack<int>& stack) {
    if (stack.empty()) {
        std::cout << "-1" << '\n';
    } else {
        std::cout << stack.top() << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string inputStr;
    std::stack<int> stack;

    int repeatNum;
    std::cin >> repeatNum;
    std::cin.ignore();

    for (int i = 0; i < repeatNum; i++) {
        std::getline(std::cin, inputStr);
        
        switch (inputStr[0]) {
            case '1':
                operationOne(stack, inputStr);
                break;
            case '2':
                operationTwo(stack);
                break;
            case '3':
                operationThree(stack);
                break;
            case '4':
                operationFour(stack);
                break;
            case '5':
                operationFive(stack);
                break;
            default:
                std::cout << "operation does not exist" << '\n';
        }
    }

    return 0;
}
