/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 05:07:25 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/17 17:41:44 by tchartie         ###   ########.fr       */
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
    if (line.find_first_of(',') == str::npos || (line.find_first_of(',') != line.find_last_of(',')))
        return (false);
    if (line.size() < 12)
        return (false);

    if (line[4] != '-' || line[7] != '-' || line[10] != ',')
        return (false);

    str yearStr = line.substr(0, 4);
    str monthStr = line.substr(5, 2);
    str dayStr = line.substr(8, 2);
    if (yearStr.find_first_not_of("0123456789") != str::npos || monthStr.find_first_not_of("0123456789") != str::npos || dayStr.find_first_not_of("0123456789") != str::npos)
        return (false);
    int year = std::atof(yearStr.c_str());
    int month = std::atof(monthStr.c_str());
    int day = std::atof(dayStr.c_str());
    str val = line.substr(line.find(',') + 1);

    for (size_t i = 0; i < val.length(); ++i)
        if (!std::isdigit(val[i]) && val[i] != '.')
            return (false);
    
    std::tm tm;
    std::memset(&tm, 0, sizeof(tm));
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0;
    tm.tm_isdst = -1;;

    std::tm tm_tmp = tm;
    date = std::mktime(&tm);
    if (date == -1 || (tm.tm_year != tm_tmp.tm_year || tm.tm_mon != tm_tmp.tm_mon || tm.tm_mday != tm_tmp.tm_mday))
        return (1);

    value = std::atof(val.c_str());
    return (true);
}

int BitcoinExchange::parseInput( cref(str) line, ref(str) dateFormat, ref(std::time_t) date, ref(float) value ) {
    if (line.find_first_of('|') == str::npos)
        return (1);
    if (line.size() < 14)
        return (1);

    if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        return (1);

    str yearStr = line.substr(0, 4);
    str monthStr = line.substr(5, 2);
    str dayStr = line.substr(8, 2);
    if (yearStr.find_first_not_of("0123456789") != str::npos || monthStr.find_first_not_of("0123456789") != str::npos || dayStr.find_first_not_of("0123456789") != str::npos)
        return (1);
    int year = std::atof(yearStr.c_str());
    int month = std::atof(monthStr.c_str());
    int day = std::atof(dayStr.c_str());
    str val = line.substr(line.find('|') + 2);

    value = std::atof(val.c_str());
    if (value < 0)
        return (2);
    if (value > 1000)
        return (3);

    bool    hasFloat = false;
    for (size_t i = 0; i < val.length(); ++i) {
        if (val[i] == '.' && !hasFloat) {
            hasFloat = true;
            continue;
        }
        if (val[i] == '.' && hasFloat)
            return 1;
        if (!std::isdigit(val[i]))
            return (1);
    }
    

    dateFormat = to_string(year);
    dateFormat += '-';
    if (month < 10)
        dateFormat += '0';
    dateFormat += to_string(month);
    dateFormat += '-';
    if (day < 10)
        dateFormat += '0';
    dateFormat += to_string(day);
    
    std::tm tm;
    std::memset(&tm, 0, sizeof(tm));
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 0; tm.tm_min = 0; tm.tm_sec = 0;
    tm.tm_isdst = -1;

    std::tm tm_tmp = tm;
    date = std::mktime(&tm);
    if (date == -1 || (tm.tm_year != tm_tmp.tm_year || tm.tm_mon != tm_tmp.tm_mon || tm.tm_mday != tm_tmp.tm_mday))
        return (1);
    return (0);
}

float   BitcoinExchange::searchPrice( std::time_t date ) {
    std::map<std::time_t, float>::const_iterator it = this->_bitcoinValue.lower_bound(date);
    if (it == this->_bitcoinValue.end())
        --it;
    else if (it->first > date) {
        if (!(it == this->_bitcoinValue.begin()))
            --it;
    }
              
    return (it->second);

}

void    BitcoinExchange::run( char *data ){
    std::ifstream input(data);
    if (!input.is_open())
		throw (std::invalid_argument("Can't open your input"));
    str line;
    std::getline(input, line);
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

