/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:28:49 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/20 16:59:01 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/webserver.hpp"
#include <fstream>
#include <cstdlib>

void	parseConfigFile(const string &path, vector<Server> &servers)
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
	{
		throw ConfigException("Error: Could not open file " + path);
	}
	string line;
	int	line_number = 0;
	while (std::getline(file, line) && !file.eof())
	{
		line_number++;
		if (line.find("server{") != string::npos)
		{
			Server server;
			while (std::getline(file, line) && !file.eof() && line.find("}") == string::npos)
			{
				line_number++;
				if (line.find("listen") != string::npos)
				{
					AHelperFunctions::parseHost(line, server);
					AHelperFunctions::parsePort(line, server);
				}
				if (line.find("server_name") != string::npos)
				{
					AHelperFunctions::parseServerName(line, server);
				}
			}
			if (line.find("}") == string::npos)
			{
				throw ConfigException("Error: Missing closing bracket", line_number);
			}
			servers.push_back(server);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		cerr << RED << "Error: Too many arguments" << RESET << endl;
		return (1);
	}
	try
	{
		vector<Server> servers;
		if (argc == 2)
		{
			parseConfigFile(argv[1], servers);
		}
		else
		{
			parseConfigFile(DEFAULT_CONFIG_PATH, servers);
		}
	}
	catch(const std::exception& e)
	{
		cerr << RED << e.what() << RESET << endl;
		return (1);
	}
	return (0);
}