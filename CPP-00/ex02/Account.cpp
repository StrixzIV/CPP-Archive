/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikaewsi <jikaewsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:34:21 by jikaewsi          #+#    #+#             */
/*   Updated: 2025/01/04 13:41:22 by jikaewsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iomanip>
#include <iostream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount() const {
	return (this->_amount);
}

void Account::_displayTimestamp() {
	
	std::time_t	now = std::time(0);
	std::tm*	local_time = std::localtime(&now);

	std::cout << "["
		<< (local_time->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << (local_time->tm_mon + 1)
		<< std::setw(2) << std::setfill('0') << local_time->tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << local_time->tm_hour
		<< std::setw(2) << std::setfill('0') << local_time->tm_min
		<< std::setw(2) << std::setfill('0') << local_time->tm_sec
		<< "] ";

}

void Account::displayAccountsInfos() {

	Account::_displayTimestamp();

	std::cout << "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;

}

void Account::displayStatus() const {

	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;

}

void Account::makeDeposit(int deposit_amount) {

	this->_nbDeposits++;

	Account::_displayTimestamp();
	
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit_amount
		<< ";amount:" << this->_amount + deposit_amount
		<<  ";nb_deposits:" << this->_nbDeposits << std::endl;

	this->_amount += deposit_amount;
	
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit_amount;
	
}

bool Account::makeWithdrawal(int withdraw_amount) {

	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:";
	
	if (withdraw_amount > this->checkAmount()) {
		std::cout << "refused" << std::endl;
		return (false);
	}

	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;

	std::cout << withdraw_amount
		<< ";amount:" << this->checkAmount() - withdraw_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	
	this->_amount -= withdraw_amount;
	Account::_totalAmount -= withdraw_amount;
	
	return (true);

}

Account::Account(int initial_value) {

	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_value;

	this->_accountIndex = this->getNbAccounts();

	Account::_totalAmount += initial_value;
	Account::_displayTimestamp();

	std::cout 
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";created" << std::endl;
	
	Account::_nbAccounts++;

}

Account::~Account() {

	Account::_displayTimestamp();

	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";closed" << std::endl;

	Account::_nbAccounts--;

}
