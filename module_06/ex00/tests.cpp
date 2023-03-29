#include <iostream>
#include <string>
#include "Test.hpp"

int main(void) {
	Test::testTypes("42", "is_int");
	Test::testTypes("-42", "is_int");
	Test::testTypes("0", "is_int");
	Test::testTypes("56", "is_int");
	Test::testTypes("312321423423232", "is_int");
	Test::testTypes("-5423432345345", "is_int");
	Test::testTypes("+42342342342313", "is_int");
	Test::testTypes("++42342342342313", "is_int");
	Test::testTypes("+-42342342342313", "is_int");
	
	Test::testTypes("adasd", "is_char");
	Test::testTypes("42342", "is_char");
	Test::testTypes("a", "is_char");
	Test::testTypes("$", "is_char");
	Test::testTypes("@", "is_char");
	Test::testTypes(" ", "is_char");
	Test::testTypes("\t", "is_char");
	Test::testTypes("aa", "is_char");
	Test::testTypes("0", "is_char");
	
	Test::testTypes("1.0f", "is_float");
	Test::testTypes(".0f", "is_float");
	Test::testTypes(".3f", "is_float");
	Test::testTypes("5.5f", "is_float");
	Test::testTypes("-43423.423423423423f", "is_float");
	Test::testTypes("5.5", "is_float");
	Test::testTypes("42f", "is_float");
	Test::testTypes("-.42f", "is_float");
	Test::testTypes("-.42", "is_float");
	Test::testTypes("-43423.423423423423f", "is_float");
	Test::testTypes("42342.f", "is_float");
	Test::testTypes("0.0f", "is_float");
	Test::testTypes("0.434.43f", "is_float");
	Test::testTypes("0.0.f", "is_float");
	Test::testTypes("", "is_float");
	Test::testTypes("", "is_float");
	
	Test::testTypes("1.0", "is_double");
	Test::testTypes(".0", "is_double");
	Test::testTypes(".3", "is_double");
	Test::testTypes("5.5", "is_double");
	Test::testTypes("-43423.423423423423", "is_double");
	Test::testTypes("5.5", "is_double");
	Test::testTypes("42", "is_double");
	Test::testTypes("-.42", "is_double");
	Test::testTypes("-.42", "is_double");
	Test::testTypes("-43423.423423423423", "is_double");
	Test::testTypes("42342.", "is_double");
	Test::testTypes("0.0", "is_double");
	Test::testTypes("0.434.43", "is_double");
	Test::testTypes("0.0.", "is_double");
	Test::testTypes("", "is_double");
	Test::testTypes("", "is_double");
	
	
	return (0);
}