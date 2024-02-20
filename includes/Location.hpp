/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:17 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/20 14:00:58 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION_HPP
# define LOCATION_HPP

#include "ServerConfig.hpp"

class Location
{
	private:
		string			_path;
		ServerConfig	_config;
	public:
		Location();
		~Location();
};

#endif