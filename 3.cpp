#include <iostream>
#include <regex>
#include <string>

int main() {
	std::regex mail_adress("([0-9A-Za-z]{1}[-0-9A-z\.]{1,}[0-9A-Za-z]{1}@(([-A-Za-z]{1,})\.[a-z]{2,}))");
	std::string line = "=-=-=-=-=adress1@domen1.com-=-=-=-=-=-adress2@dom-en2.ru=-=-=-=-=-=-=-=adreess-3@domen3.com=-=-=";
	std::smatch matches;
	//выражение работает на regex101 а тут нет и я не знаю почему
	if (std::regex_search(line, matches, mail_adress))
	{
		for (std::size_t i = 0; i < matches.size(); ++i)
		{
			std::cout << matches[i] << " | ";

			if (i % 3 == 0) std::cout << "\n";

		}

		std::cout << std::endl;
	}
}



