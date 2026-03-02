#pragma once
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

class RPN {
public:
    RPN();
    RPN(const std::string& line);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    bool translateOP(char c);
    void action();
    int eval();
    void addition();
    void subtraction();
    void division();
    void multiplication();

private:
    std::stack<int> stack;
    std::string raw_line;
    enum operation { ADD,
        SUB,
        DIV,
        MULT };
    operation op;
};
