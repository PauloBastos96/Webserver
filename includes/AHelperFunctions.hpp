/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AHelperFunctions.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:11:49 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/20 16:53:55 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERFUNCTIONS_HPP
# define HELPERFUNCTIONS_HPP

#include "Server.hpp"

using std::string;

class AHelperFunctions
{
	private:
		AHelperFunctions(void);
		virtual ~AHelperFunctions(void) = 0;
	public:
		static void	parseHost(const string line, Server &server);
		static void	parsePort(const string line, Server &server);
		static void	parseServerName(const string line, Server &server);
};

#endif