#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

void	test_types(std::string const &n, std::string const &tittle) {
	std::cout << std::endl;
	std::cout << tittle << " test with literal: " << n << std::endl;
	std::string	isTypesNames[4] = {"is_char", "is_int", "is_float", "is_double"};
	bool	(*istypes[4])(std::string const &) = {&ScalarConverter::is_char, &ScalarConverter::is_int, &ScalarConverter::is_float, &ScalarConverter::is_double};
	for (int i = 0; i < 4; i++) {
		std::cout << isTypesNames[i] << " result: " << istypes[i](n) << std::endl;
	}
	std::cout << std::endl;
}

int main(void) {
	test_types("42", "is_int");
	test_types("-42", "is_int");
	test_types("0", "is_int");
	test_types("56", "is_int");
	test_types("312321423423232", "is_int");
	test_types("-5423432345345", "is_int");
	test_types("+42342342342313", "is_int");
	test_types("++42342342342313", "is_int");
	test_types("+-42342342342313", "is_int");
	
	test_types("adasd", "is_char");
	test_types("42342", "is_char");
	test_types("a", "is_char");
	test_types("$", "is_char");
	test_types("@", "is_char");
	test_types(" ", "is_char");
	test_types("\t", "is_char");
	test_types("aa", "is_char");
	test_types("0", "is_char");
	
	test_types("1.0f", "is_float");
	test_types(".0f", "is_float");
	test_types(".3f", "is_float");
	test_types("5.5f", "is_float");
	test_types("-43423.423423423423f", "is_float");
	test_types("5.5", "is_float");
	test_types("42f", "is_float");
	test_types("-.42f", "is_float");
	test_types("-.42", "is_float");
	test_types("-43423.423423423423f", "is_float");
	test_types("42342.f", "is_float");
	test_types("0.0f", "is_float");
	test_types("0.434.43f", "is_float");
	test_types("0.0.f", "is_float");
	test_types("", "is_float");
	test_types("", "is_float");
	
		test_types("1.0", "is_double");
	test_types(".0", "is_double");
	test_types(".3", "is_double");
	test_types("5.5", "is_double");
	test_types("-43423.423423423423", "is_double");
	test_types("5.5", "is_double");
	test_types("42", "is_double");
	test_types("-.42", "is_double");
	test_types("-.42", "is_double");
	test_types("-43423.423423423423", "is_double");
	test_types("42342.", "is_double");
	test_types("0.0", "is_double");
	test_types("0.434.43", "is_double");
	test_types("0.0.", "is_double");
	test_types("", "is_double");
	test_types("", "is_double");
	
	
	return (0);
}