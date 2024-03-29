/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigException.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:01:12 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/19 16:21:53 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ConfigException.hpp"
#include <sstream>

ConfigException::ConfigException(const string &message, const int &line): _message(message), _line(line) 
{
	std::stringstream ss;
	ss << this->_message << " at line " << this->_line;
	this->_finalMessage = ss.str();
}
ConfigException::~ConfigException() throw() {}

const char *ConfigException::what() const throw()
{
	return (this->_finalMessage.c_str());
}