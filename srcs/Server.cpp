/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:30:04 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/21 16:17:57 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"
#include "../includes/webserver.hpp"

Server::Server(void)
{
	_port = DEFAULT_PORT;
	_host = DEFAULT_HOST;
	_config.setRoot(DEFAULT_ROOT);
	_config.setMaxClientBodySize(DEFAULT_MAX_CLIENT_BODY_SIZE);
	_config.setIndex(DEFAULT_INDEX);
	_config.setAutoIndex(string(DEFAULT_AUTOINDEX) == "off" ? false : true);
}

Server::~Server(void){}

void	Server::setHost(const string &host)
{
	_host = host;
}
void	Server::setPort(const int &port)
{
	_port = port;
}
void	Server::setServerName(const string &server_name)
{
	_serverName.push_back(server_name);
}

const int	&Server::getPort(void)
{
	return (_port);
}

const string	&Server::getHost(void)
{
	return (_host);
}

const vector<string>	&Server::getServerName(void)
{
	return (_serverName);
}

ServerConfig	&Server::getConfig(void)
{
	return (_config);
}

vector<Location>	&Server::getLocations(void)
{
	return (_locations);
}