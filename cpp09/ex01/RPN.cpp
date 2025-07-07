/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:46:18 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/19 20:37:49 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {
    PRINT GREEN "RPN created" CENDL;
}

RPN::RPN( cref(RPN) src ) {
    PRINT GREEN "RPN Copy constructor operator called" CENDL;
    *this = src;
}

RPN &RPN::operator = ( cref(RPN) rhs ) {
    PRINT GREEN "RPN Copy assignment operator called" CENDL;
    if (this == &rhs)
        return (*this);
    this->_stack = rhs._stack;
    return (*this);
}

RPN::~RPN( void ) {
    PRINT YELLOW "RPN destroyed" CENDL; 
}

std::stack<float>   RPN::getStack( void ) {
    return (this->_stack);
}

void    RPN::pushInStack( int number ) {
    this->_stack.push(number);
}

bool    RPN::makeOperation( char sign ) {
     if (this->_stack.size() < 2) {
        ERROR RED "Error: Can't do the operation. Too few arguments" CENDL;
        return (false);
    }

    float rhs = this->_stack.top();
    this->_stack.pop();
    float lhs = this->_stack.top();
    this->_stack.pop();

    switch (sign) {
        case '+': {
            this->_stack.push(lhs + rhs);
            break;
        }
        case '-': {
            this->_stack.push(lhs - rhs);
            break;
        }
        case '*': {
            this->_stack.push(lhs * rhs);
            break;
        }
        case '/': {
            if (rhs == 0) {
                PRINT RED "Error: Can't divide by 0" CENDL;
                return (false);
            }
            this->_stack.push(lhs / rhs);
            break;
        }
        default: {}
    }
    return (true);
}

bool    RPN::checkStack( void ) {
    if (this->_stack.size() > 1 || this->_stack.size() <= 0) {
        ERROR RED "Error: Your Polish Reverse Notation isn't finished" CENDL;
        return (false);
    }
    PRINT CYAN "Result: " AND BLUE AND this->_stack.top() CENDL;
    return (true);
}
