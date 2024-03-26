#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
   public:
    RPN(RPN const &instance);
    ~RPN();

    RPN &operator=(RPN const &rhs);

    static void doCalculations(std::string const &rpn);

   private:
    RPN();
    static bool m_checkValidRPN(std::string const &rpn);
    static void m_operations(char const &c, std::stack<int> &stack, int &res);
    static void m_doOperations(int &lVal, int &rVal, char const &c, int &res);
};

std::ostream &operator<<(std::ostream &o, RPN const &instance);

#endif 
