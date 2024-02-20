/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:30:04 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/20 16:34:32 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

Server::Server(void){}
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
	_server_name.push_back(server_name);
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
	return (_server_name);
}