/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:46:15 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/21 15:20:35 by paulorod         ###   ########.fr       */
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