#include "Account.hpp"
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static	int	get_index(void){
	static int	index = -1;

	index++;
	return (index);
}

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
	this->_displayTimestamp();
	this->_accountIndex = get_index();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void ) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t	timer;
	tm		*timeinfo;
	int		year, month, day;
	std::string	month_str;
	std::ostringstream	stream;

	time(&timer);
	timeinfo = localtime(&timer);
	year = timeinfo->tm_year + 1900;
	month = timeinfo->tm_mon + 1;
	stream << month;
	month_str = stream.str();
	day = timeinfo->tm_mday;

	month_str.resize(2, '0');
	std::cout << "[";
	std::cout << year ;
	std::cout << month_str << std::setfill('0') << std::setw(2);
	std::cout << day;
	std::cout << "_";
	std::cout << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec << "] ";
}

int		Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int		Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

int		Account::getTotalAmount( void ) {
	return (Account	::_totalAmount);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;	
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;	
}

void	Account::makeDeposit( int deposit ) {
	int	p_amount;

	Account::_displayTimestamp();
	p_amount = this->_amount;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	if (this->checkAmount() < withdrawal) {
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	int	p_amount = this->_amount;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	this->_totalAmount -= withdrawal;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount<< ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
