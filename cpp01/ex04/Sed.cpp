/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:45:12 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 00:37:30 by tchartie         ###   ########.fr       */
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
    if (_seek.empty() || _replace.empty())
        throw std::runtime_error("Nothing to replace");
}

// Destructor
Sed::~Sed() {
    if (this->_infile.is_open())
        this->_infile.close();
    if (this->_outfile.is_open())
        this->_outfile.close();
}

void    Sed::_readLine() {
    std::getline(_infile, _content);
    if (_content.empty())
        _content = "";
}

void    Sed::_modifyContent(size_t index) {
    size_t      match = _content.find(_seek, index);
    std::string newContent;

    if (_seek == _replace)
        return ;
    if (match == std::string::npos)
		return ;
	newContent = _content.substr(0, match);
    newContent += _replace;
    newContent += _content.substr(match + _seek.length());
    _content = newContent;
    _modifyContent(match + _replace.length());
}

void    Sed::_writeLine() {
    _outfile << _content;
    if (!_infile.eof())
        _outfile << std::endl;
}

void    Sed::startSed() {
    while (!_infile.eof())
    {
        _readLine();
        _modifyContent();
        _writeLine();
    }
}
