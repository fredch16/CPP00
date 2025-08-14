/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:04:14 by fredchar          #+#    #+#             */
/*   Updated: 2025/08/12 23:57:48 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : contact_count(0), oldest_index(0) {}

void PhoneBook::add_contact() {
	std::cout << "[DEBUG] addContact() called\n";
	contact_count++; // Increment contact count to use the field
	if (contact_count > 8) { // Assuming a maximum of 8 contacts
		contact_count = 8;
		oldest_index = (oldest_index + 1) % 8; // Update oldest index
	}
}

void PhoneBook::search_contacts() const {
	std::cout << "[DEBUG] searchContacts() called\n";
	std::cout << "Total contacts: " << contact_count << "\n"; // Use contact_count
}
