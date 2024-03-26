#include <iostream>
#include <stack>
#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const &instance) { *this = instance; }
RPN::~RPN() {}

RPN &RPN::operator=(RPN const &rhs) {
    (void)rhs;
    return *this;
}

bool RPN::m_checkValidRPN(std::string const &rpn) {
    std::string operators = "+*-/";
    int i = -1;
    while (rpn[++i]) {
        if (rpn[i] != ' ' and operators.find(rpn[i]) == std::string::npos and 
                !std::isdigit(rpn[i]))
            return false;
    }
    return true;
}

void RPN::doCalculations(std::string const &rpn) {
    if (m_checkValidRPN(rpn) == false) {
        std::cerr << "Error.\n";
        exit(1);
    }
    std::stack<int> stack;
    int res;
    for (int i = 0; i < static_cast<int>(rpn.size()); i++)
        m_operations(rpn[i], stack, res);
    if (stack.size() != 1) {
        std::cerr << "Error.\n";
        exit(1);
    }
    std::cout << res << '\n';
}

void RPN::m_operations(char const &c, std::stack<int> &stack, int &res) {
    std::string nums = "0123456789";
    std::string op = "+-/*";
    if (std::isdigit(c)) {
        int num = nums.find(c);
        stack.push(num);
    } else if (op.find(c) != std::string::npos) {
        if (stack.size() < 2) {
            std::cerr << "Error.\n";
            exit(1);
        }
        int rVal = stack.top();
        stack.pop();
        int lVal = stack.top();
        stack.pop();
        m_doOperations(lVal, rVal, c, res);
        stack.push(res);
    }
}

void RPN::m_doOperations(int &lVal, int &rVal, char const &c, int &res) {
    switch (c) {
        case '+':
            res = lVal + rVal;
            break;
        case '-':
            res = lVal - rVal; 
            break;
        case '*':
            res = lVal * rVal;
            break;
        case '/':
            res = lVal / rVal; 
            break;
    }
}

std::ostream &operator<<(std::ostream &o, RPN const &instance) {
    (void)instance;
    o << "fill me";
    return o;
}
