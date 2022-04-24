#include <iostream>

int main(int argc, char *argv[])
{
	int j = 0;

	if (argc < 2) std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		for (int i = 1; i < argc; i++) {
			while (argv[i][j]) {
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
					std::cout << char(argv[i][j] - 32);
				else std::cout << argv[i][j];
				j++;
			}
		}
	}
	std::cout << "\n";
}
