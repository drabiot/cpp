/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:45:12 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/25 23:49:37 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

// Constructor
Sed::Sed(const std::string &filename, const std::string &s1, const std::string &s2){
    if (filename.empty())
        throw std::runtime_error("Your file need a name");
    this->_infile.open(filename.c_str());
    if (!_infile.is_open())
        throw std::runtime_error("Unable to read infile");
    this->_outfile.open(std::string(filename + ".replace").c_str());
    if (!_outfile.is_open())
        throw std::runtime_error("Unable to create outfile");
    this->_seek = s1;
    this->_replace = s2;
    if (_seek.empty())
        throw std::runtime_error("Nothing to replace");
}

// Destructor
Sed::~Sed() {
    if (this->_infile)
        this->_infile.close();
    if (this->_outfile)
    this->_outfile.close();
}

void    Sed::readLine() {
    std::getline(_infile, _content);
}

void    Sed::modifyContent() {
    
}

void    Sed::writeLine() {
    _outfile << _content;
    if (!_infile.eof())
        _outfile << std::endl;
}

void    Sed::startSed() {
    while (!_infile.eof())
    {
        readLine();
        modifyContent();
        writeLine();
    }
}
