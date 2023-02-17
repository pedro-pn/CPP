#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string input;
	std::string megaphone;

	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
	}
	for (int y = 1; argv[y] != NULL; y++){
		input = argv[y];
		for (int i = 0; i < (int) input.length(); i++){
			megaphone += (char) std::toupper(input[i]);
		}
	}

	std::cout << megaphone << std::endl;
	return (0);
}
