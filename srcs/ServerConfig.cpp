/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:14:43 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/21 15:41:35 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ServerConfig.hpp"

ServerConfig::ServerConfig(){}
ServerConfig::~ServerConfig() {}

void	ServerConfig::setRoot(const string &root)
{
	_root = root;
}
void	ServerConfig::setIndex(const string &index)
{
	_index.push_back(index);
}
void	ServerConfig::setErrorPage(const uint &error_code, const string &error_page)
{
	_errorPage.insert(std::pair<uint, string>(error_code, error_page));
}
void	ServerConfig::setMaxClientBodySize(const string &max_client_body_size)
{
	_maxClientBodySize = max_client_body_size;
}

const string	&ServerConfig::getRoot(void)
{
	return (_root);
}
vector<string>	&ServerConfig::getIndex(void)
{
	return (_index);
}
map<uint, string>	&ServerConfig::getErrorPage(void)
{
	return (_errorPage);
}
const string	&ServerConfig::getMaxClientBodySize(void)
{
	return (_maxClientBodySize);
}

