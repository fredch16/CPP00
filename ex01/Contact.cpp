/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:12:08 by fredchar          #+#    #+#             */
/*   Updated: 2025/08/15 00:46:16 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{

}

static std::string truncate_field(const std::string &str) {
	if (str.length() > 10)
		return (str.substr(0,9) + ".");
	return (str);
}

void Contact::display_short(int index) const {
	std::cout	<< std::setw(10) << index << "|"
				<< std::setw(10) << truncate_field(first_name) << "|"
				<< std::setw(10) << truncate_field(last_name) << "|"
				<< std::setw(10) << truncate_field(nickname) << "\n";
}

void	Contact::set_contact(const std::string &fn, const std::string &ln, const std::string &nn, const std::string &pn, const std::string &ds)
{
	first_name = fn;
	last_name = ln;
	nickname = nn;
	phone_number = pn;
	darkest_secret = ds;
}

void Contact::display_contact() const {
	std::cout << "First Name: " << first_name << "\n";
	std::cout << "Last Name: " << last_name << "\n";
	std::cout << "Nickname: " << nickname << "\n";
	std::cout << "Phone Number: " << phone_number << "\n";
	std::cout << "Darkest Secret: " << darkest_secret << "\n";
}
