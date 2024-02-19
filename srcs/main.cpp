/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulorod <paulorod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:28:49 by paulorod          #+#    #+#             */
/*   Updated: 2024/02/19 16:23:13 by paulorod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/webserver.hpp"

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		cerr << RED << "Error: Too many arguments" << RESET << endl;
		return (1);
	}
	try
	{
		
	}
	catch(const std::exception& e)
	{
		cerr << RED << e.what() << RESET << endl;
		return (1);
	}
	(void)argv;
	return (0);
}