/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:04:14 by fredchar          #+#    #+#             */
/*   Updated: 2025/08/18 15:34:58 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contact_count(0), oldest_index(0) {}

static bool is_str_alpha(const std::string &s) {
	for (char c : s) {
		if (!std::isalpha(static_cast<char>(c))) {
			return (false);
		}
	}
	return (true);
}

// static bool is_str_num(const std::string &s) {
// 	for (char c : s) {
// 		if (!std::isalpha(static_cast<char>(c))) {
// 			return (false);
// 		}
// 	}
// 	return (true);
// }

static std::string prompt_field(const std::string &field_name) // const promises I won't change it and &is speed+++ because we avoid copying!
{
	std::string input;
	while (true)
	{
		std::cout << field_name << ": ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nAborted ADD due to EOF\n";
			return "";
		}
		if (input.empty())
		{
			std::cout << "Field cannot be empty. Try again.\n";
			continue;
		}
		if (!is_str_alpha(input) && (field_name == "First Name" || field_name == "Last Name"))
		{
			std::cout << "Field must be strictly alphabetic characters. Try again\n";
			continue ;
		}
		return (input);
	}
}

void PhoneBook::add_contact()
{
	std::string fn, ln, nn, pn, ds;

	fn = prompt_field("First Name");
	if (fn.empty()) return;
	ln = prompt_field("Last Name");
	if (ln.empty()) return;
	nn = prompt_field("Nickname");
	if (nn.empty()) return;
	pn = prompt_field("Phone Number");
	if (pn.empty()) return;
	ds = prompt_field("Darkest Secret");
	if (ds.empty()) return;

	if (contact_count < 8)
	{
		contacts[contact_count].set_contact(fn, ln, nn, pn, ds);
		contact_count++;
	}
	else
	{
		contacts[oldest_index].set_contact(fn, ln, nn, pn, ds);
		oldest_index = (oldest_index + 1) % 8;
	}
	std::cout << "Contact saved!\n";
}

void PhoneBook::search_contacts() const {
	if (contact_count == 0) {
		std::cout << "PhoneBook is empty. \n";
		return ;
	}
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "\n";

	for (int i = 0; i < contact_count; i++)
		contacts[i].display_short(i);
	
	std::cout << "Enter index: ";
	std::string input;
	if (!std::getline(std::cin, input)) {
		std::cout << "\nAborted SEARCH due to EOF\n";
		return ;
	}

	if (input.size() != 1 || !isdigit(input[0])) {
		std::cout << "Invalid index format.\n";
		return ;
	}

	int idx = input[0] - '0';
	if (idx >= contact_count) {
		std::cout << "Index out of range.\n";
		return ;
	}

	contacts[idx].display_contact();

}
