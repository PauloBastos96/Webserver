/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:01:35 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/21 13:00:23 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERCONFIG_HPP
# define SERVERCONFIG_HPP

#include "ConfigException.hpp"
#include <vector>
#include <map>

using std::vector;
using std::map;

typedef unsigned int uint;

class ServerConfig
{
	private:
		string				_root;
		vector<string>		_index;
		map<uint, string>	_error_page;
		string				_max_client_body_size;
	public:
		ServerConfig();
		~ServerConfig();

		const string				&getRoot(void);
		const vector<string>		&getIndex(void);
		map<uint, string>			&getErrorPage(void);
		const string				&getMaxClientBodySize(void);

		void	setRoot(const string &root);
		void	setIndex(const string &index);
		void	setErrorPage(const uint &error_code, const string &error_page);
		void	setMaxClientBodySize(const string &max_client_body_size);
};

#endif
