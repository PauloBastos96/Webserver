/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserver.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:35:21 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/21 16:13:33 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP

/************** DEFAULT VALUES *****************/
# define DEFAULT_CONFIG_PATH "../default.conf"
# define DEFAULT_MAX_CLIENT_BODY_SIZE "1m"
# define DEFAULT_PORT 80
# define DEFAULT_HOST "0.0.0.0"
# define DEFAULT_ROOT "/var/www/html"
# define DEFAULT_INDEX "index.html"
# define DEFAULT_AUTOINDEX "off"
/**********************************************/

# include <iostream>
# include <string>
# include "Colors.hpp"
# include "Server.hpp"
# include "AParserFunctions.hpp"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

#endif