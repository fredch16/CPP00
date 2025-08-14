/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:03:53 by fredchar          #+#    #+#             */
/*   Updated: 2025/08/13 00:32:26 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook pb;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nExiting\n";
			break ;
		}

		if (command == "ADD")
			pb.add_contact();
		else if (command == "SEARCH")
			pb.search_contacts();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Unknown command\n";
	}
	return (0);
}