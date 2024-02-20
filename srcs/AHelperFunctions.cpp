/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AHelperFunctions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:17:05 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/20 16:56:44 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AHelperFunctions.hpp"
#include <sstream>
#include <cstdlib>

AHelperFunctions::AHelperFunctions(void){}
AHelperFunctions::~AHelperFunctions(void){}

/// @brief Parse the IP address from the line from the config file and set it to the server object
/// @param line The line from the config file
/// @param server The server object
void	AHelperFunctions::parseHost(const string line, Server &server)
{
	string		host;
	if (line.find_first_of(".") != string::npos)
	{
		if (line.find_first_of(":") != string::npos)
			host = line.substr(line.find_first_of(" ") + 1, line.find_first_of(":") - line.find_first_of(" ") - 1);
		else
			host = line.substr(line.find_first_of(" ") + 1);
	}
	else
	{
		if (line.find_first_of(":") != string::npos)
			host = line.substr(line.find_first_of(" ") + 1, line.find_first_of(":") - line.find_first_of(" ") - 1);
		else
			host = line.substr(line.find_first_of(" ") + 1);
	}
	server.setHost(host);
}

/// @brief Parse the port from the line from the config file and set it to the server object
/// @param line The line from the config file
/// @param server The server object
void	AHelperFunctions::parsePort(const string line, Server &server)
{
	int	port = 80;
	
	if (line.find_first_of(":") != string::npos)
		port = std::atoi(line.substr(line.find_first_of(":") + 1).c_str());
	server.setPort(port);
}

void	AHelperFunctions::parseServerName(const string line, Server &server)
{
	std::stringstream ss(line);
	string word;
	while (ss >> word)
	{
		if (word != "server_name")
			server.setServerName(word);
	}
}