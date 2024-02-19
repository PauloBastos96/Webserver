/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigException.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:57:59 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:40 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGEXCEPTION_HPP
# define CONFIGEXCEPTION_HPP

#include <string>

using std::string;

class ConfigException : public std::exception
{
	private:
		string	_finalMessage;
		string 	_message;
		int		_line;
	public:
		virtual const char *what() const throw();
		const int &getLine() const;
		ConfigException(const string &message, const int &line = 0);
		~ConfigException() throw();
};

#endif