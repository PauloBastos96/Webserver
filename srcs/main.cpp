/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:28:49 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/21 16:19:49 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/webserver.hpp"
#include <fstream>

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
		if (line.find("server") != string::npos && line.end()[-1] == '{')
		{
			Server server;
			while (std::getline(file, line) && !file.eof() && line.find("}") == string::npos)
			{
				line_number++;
				if (line.find("listen") != string::npos)
				{
					AParserFunctions::parseHost(line, server);
					AParserFunctions::parsePort(line, server);
				}
				if (line.find("server_name") != string::npos)
					AParserFunctions::parseServerName(line, server);
				if (line.find("root") != string::npos)
					server.getConfig().setRoot(line.substr(line.find_first_of(" ") + 1));
				if (line.find("index") != string::npos)
					AParserFunctions::parseIndex(line, server);
				if (line.find("error_page") != string::npos)
				{
					if (AParserFunctions::parseErrorPage(line, server))
						throw ConfigException("Error: Invalid error page directive", line_number);
				}
				if (line.find("max_client_body_size") != string::npos)
					server.getConfig().setMaxClientBodySize(line.substr(line.find_first_of(" ") + 1));
				if (line.find("location") != string::npos && line.end()[-1] == '{')
					AParserFunctions::parseLocation(line, server, line_number, file);
				if (line.find("autoindex") != string::npos)
				{
					string autoindex = line.substr(line.find_first_of(" ") + 1);
					server.getConfig().setAutoIndex(autoindex == "off" ? false : true);
				}
			}
			if (line.find("}") == string::npos)
			{
				throw ConfigException("Error: Missing closing bracket", line_number);
			}
			servers.push_back(server);
		}
	}
	file.close();
}

void	debugDisplayServerConfigs(vector<Server> &servers)
{
	for (size_t i = 0; i < servers.size(); i++)
	{
		cout << BLUE << "Host " << servers[i].getHost() << ":" << servers[i].getPort() << RESET << endl;
		cout << "Server name: ";
		for (size_t j = 0; j < servers[i].getServerName().size() ; j++)
		{
			cout << servers[i].getServerName()[j] << " ";
		}
		cout << endl;
		cout << "Root: " << servers[i].getConfig().getRoot() << endl;
		cout << "Index: ";
		for (size_t j = 0; j < servers[i].getConfig().getIndex().size(); j++)
		{
			cout << servers[i].getConfig().getIndex()[j] << " ";
		}
		cout << endl;
		cout << "Error pages: ";
		for (std::map<uint, string>::iterator it = servers[i].getConfig().getErrorPage().begin(); it != servers[i].getConfig().getErrorPage().end(); it++)
		{
			cout << it->first << "=>" << it->second << " ";
		}
		cout << endl;
		cout << "Max client body size: " << servers[i].getConfig().getMaxClientBodySize() << endl;
		cout << "Autoindex: " << (servers[i].getConfig().getAutoIndex() ? "on" : "off") << endl;
		cout << "Locations: " << endl;
		for (size_t j = 0; j < servers[i].getLocations().size(); j++)
		{
			cout << "	" << servers[i].getLocations()[j].getPath() << endl;
			cout << "	" << "Root: " << servers[i].getLocations()[j].getConfig().getRoot() << endl;
			cout << "	" << "Index: ";
			for (size_t k = 0; k < servers[i].getLocations()[j].getConfig().getIndex().size(); k++)
			{
				cout << servers[i].getLocations()[j].getConfig().getIndex()[k];
			}
			cout << endl;
			cout << "	" << "Error pages: ";
			for (std::map<uint, string>::iterator it = servers[i].getLocations()[j].getConfig().getErrorPage().begin(); it != servers[i].getLocations()[j].getConfig().getErrorPage().end(); it++)
			{
				cout << "	" << it->first << " " << it->second << " ";
			}
			cout << endl;
			cout << "	" << "Max client body size: " << servers[i].getLocations()[j].getConfig().getMaxClientBodySize() << endl;
			cout << "	" << "Allowed methods: ";
			for (size_t k = 0; k < servers[i].getLocations()[j].getAllowedMethods().size(); k++)
			{
				cout << servers[i].getLocations()[j].getAllowedMethods()[k] << " ";
			}
			cout << endl;
			cout << "	" << "Autoindex: " << (servers[i].getLocations()[j].getConfig().getAutoIndex() ? "on" : "off") << endl;
			cout << endl;
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
		debugDisplayServerConfigs(servers);
	}
	catch(const std::exception& e)
	{
		cerr << RED << e.what() << RESET << endl;
		return (1);
	}
	return (0);
}