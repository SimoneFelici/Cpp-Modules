#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const std::string& line)
    : raw_line(line)
{
}

RPN::RPN(const RPN& other)
    : stack(other.stack)
    , op(other.op)
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other) {
        stack = other.stack;
        op = other.op;
    }
    return (*this);
}

RPN::~RPN() { }

bool RPN::translateOP(char c)
{
    switch (c) {
    case '+':
        op = ADD;
        return true;
    case '-':
        op = SUB;
        return true;
    case '/':
        op = DIV;
        return true;
    case '*':
        op = MULT;
        return true;
    default:
        return false;
    }
}

void RPN::addition()
{
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    stack.push(b + a);
}

void RPN::subtraction()
{
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    stack.push(b - a);
}

void RPN::division()
{
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    stack.push(b / a);
}

void RPN::multiplication()
{
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    stack.push(b * a);
}

void RPN::action()
{
    switch (op) {
    case ADD:
        addition();
        break;
    case SUB:
        subtraction();
        break;
    case DIV:
        division();
        break;
    case MULT:
        multiplication();
        break;
    }
}

int RPN::eval()
{
    for (size_t i = 0; i < raw_line.length(); ++i) {
        if (translateOP(raw_line[i])) {
            if (stack.size() >= 2)
                action();
            else {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
        } else if (isdigit(raw_line[i])) {
            stack.push(raw_line[i] - '0');
        } else {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    return stack.top();
}
