/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 05:07:25 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/16 21:28:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

template<typename T>
str to_string(const T & value);

BitcoinExchange::BitcoinExchange( void ) {
    std::ifstream data("data.csv");
    if (!data.is_open())
        throw (std::invalid_argument("Can't open data.csv"));
    data.seekg(0, std::ios::end);
    if (data.tellg() == 0) {
        data.close();
        throw (std::invalid_argument("data.csv is empty"));
    }
    data.seekg(0, std::ios::beg);
    str line;
    std::getline(data, line);
    if (line != "date,exchange_rate") {
        data.close();
        throw (std::invalid_argument("Miss header in data.csv"));
    }

    while (std::getline(data, line)) {
        std::time_t date;
        float       value;
        if (!this->parseLine(line, date, value))
            throw (std::invalid_argument("Invalid line format in data.csv"));
        this->_bitcoinValue[date] = value;
    }
    data.close();
    PRINT GREEN "BTC created" CENDL;
}

BitcoinExchange::BitcoinExchange( cref(BitcoinExchange) src ) {
    PRINT GREEN "BTC Copy constructor operator called" CENDL;
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator = ( cref(BitcoinExchange) rhs ) {
    PRINT GREEN "BTC Copy assignment operator called" CENDL;
    if (this == &rhs)
        return (*this);
    this->_bitcoinValue = rhs._bitcoinValue;
    return (*this);

}

BitcoinExchange::~BitcoinExchange( void ) {
    PRINT YELLOW "BTC destroyed" CENDL;
}

std::map<std::time_t, float>    BitcoinExchange::getBitcoinValue( void ) {
    return (this->_bitcoinValue);
}

bool    BitcoinExchange::parseLine( cref(str) line, ref(std::time_t) date, ref(float) value ) {
    int year;
    int month;
    int day;
    float val;
    
    int n = 0;
    int res = sscanf(line.c_str(), "%d-%d-%d,%f%n", &year, &month, &day, &val, &n);
    if (res != 4)
        return (false);
    
    if (n != (int)line.length())
        return (false);

    std::tm tm;
    std::memset(&tm, 0, sizeof(tm));
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0;
    tm.tm_isdst = -1;;

    date = std::mktime(&tm);
    if (date == -1)
        return (false);

    value = val;
    return (true);
}

int BitcoinExchange::parseInput( cref(str) line, ref(str) dateFormat, ref(std::time_t) date, ref(float) value ) {
    int year;
    int month;
    int day;
    float val;
    
    int n = 0;
    int res = sscanf(line.c_str(), "%d-%d-%d | %f%n", &year, &month, &day, &val, &n);
    if (res != 4)
        return (1);
    
    if (n != (int)line.length())
        return (1);

    dateFormat = to_string(year);
    dateFormat += '-';
    if (month < 10)
        dateFormat += '0';
    dateFormat += to_string(month);
    dateFormat += '-';
    if (day < 10)
        dateFormat += '0';
    dateFormat += to_string(day);
    if (year < 0 || month > 12 || day > 31)
        return (1);
    if (year % 4 == 0 && month == 2 && day > 29)
        return (1);
    if (year % 4 != 0 && month == 2 && day > 28)
        return (1);
    if ((month <= 7 && month % 2 == 0 && day > 30) || (month > 7 && month % 2 == 1 && day > 30))
        return (1);
    
    std::tm tm;
    std::memset(&tm, 0, sizeof(tm));
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0;
    tm.tm_isdst = -1;

    date = std::mktime(&tm);
    if (date == -1)
        return (1);

    value = val;
    if (value < 0)
        return (2);
    if (value > 1000)
        return (3);
    return (0);
}

float   BitcoinExchange::searchPrice( std::time_t date ) {
    std::map<std::time_t, float>::const_iterator it = this->_bitcoinValue.lower_bound(date);
    if (it == this->_bitcoinValue.end())
        --it;
    else if (it->first > date) {
        if (it == this->_bitcoinValue.begin())
            throw std::invalid_argument("No date found");
        --it;
    }
              
    return (it->second);

}

void    BitcoinExchange::run( char *data ){
    std::ifstream input(data);
    if (!input.is_open())
		throw (std::invalid_argument("Can't open your input"));
    input.seekg(0, std::ios::end);
    if (input.tellg() == 0) {
        input.close();
        throw (std::invalid_argument("Your input is empty"));
    }
    input.seekg(0, std::ios::beg);
    str line;
    std::getline(input, line);
    if (line != "date | value") {
        input.close();
        throw (std::invalid_argument("Miss header in your input"));
    }

    while (std::getline(input, line)) {
        str         dateFormat;
        std::time_t date;
        float       value;
        int         ret = this->parseInput(line, dateFormat, date, value);

        switch (ret) {
            case 0: {
                try {
                    float price = this->searchPrice(date);
                    PRINT CYAN AND dateFormat AND " => " AND value AND " = " AND BLUE AND value * price CENDL; 
                    break;
                } catch (const std::exception& e) {
		            ERROR MAGENTA AND e.what() CENDL;
		            break;
	            }
            }
            case 1: {
                PRINT MAGENTA "Error: Bad input => " AND line CENDL;
                break;
            }
            case 2: {
                PRINT MAGENTA "Error: Not a positive number" CENDL;
                break;
            }
            case 3: {
                PRINT MAGENTA "Error: Too large Number" CENDL;
                break;
            }
            default:
                ;
        }
    }
    input.close();
}

template<typename T>
str to_string(const T & value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}
