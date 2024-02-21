/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:46:15 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/21 15:48:05 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Location.hpp"

Location::Location(){}
Location::~Location(){}

const string	&Location::getPath(void)
{
	return (_path);
}

ServerConfig	&Location::getConfig(void)
{
	return (_config);
}

void	Location::setPath(const string &path)
{
	_path = path;
}

vector<string>	&Location::getAllowedMethods(void)
{
	return (_allowedMethods);
}

void	Location::setAllowedMethods(const string &method)
{
	_allowedMethods.push_back(method);
}