/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:01:35 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/19 15:58:48 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERCONFIG_HPP
# define SERVERCONFIG_HPP

#include "ConfigException.hpp"

class ServerConfig
{
	private:
		string 	_listen;
		string	_server_name;
		string	_error_page;
		string	_max_client_body_size;
		string	_root;
		string	_index;
	public:
		ServerConfig();
		~ServerConfig();
};

#endif
