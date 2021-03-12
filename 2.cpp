#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#ifndef _HAS_AUTO_PTR_ETC
#define _HAS_AUTO_PTR_ETC 1
#endif




#include <iostream>
#include <locale>
#include <string>
#include <boost/locale.hpp>

#include <Windows.h>

#include <unordered_map>


std::unordered_map<wchar_t, std::string> u = {
	{'а', "a"},
	{'б',"b"},
	{'в',"v"},
	{'г',"g"},
	{'д',"d"},
	{'е',"ye"},
	{'ё',"yo"},
	{'ж',"dj"},
	{'з',"z"},
	{'и',"i"},
	{'й',"y"},
	{'к',"k"},
	{'л',"l"},
	{'м',"m"},
	{'н',"n"},
	{'о',"o"},
	{'п',"p"},
	{'р',"r"},
	{'с',"s"},
	{'т',"t"},
	{'у',"u"},
	{'ф',"f"},
	{'х',"h"},
	{'ц',"ts"},
	{'ч',"tch"},
	{'ш',"tsh"},
	{'щ',"tsch"},
	{'ъ',"'"},
	{'ы',"y"},
	{'ь',"'"},
	{'э',"e"},
	{'ю',"yu"},
	{'я',"ya"}

};

std::string locale_to_utf_8(const std::string& string)
{
	boost::locale::generator generator;
	generator.locale_cache_enabled(true);

	std::locale locale =
		generator(boost::locale::util::get_system_locale());

	return boost::locale::conv::to_utf < char >(string, locale);
}

std::string utf_8_to_locale(const std::string& string)
{
	boost::locale::generator generator;
	generator.locale_cache_enabled(true);

	std::locale locale =
		generator(boost::locale::util::get_system_locale());

	return boost::locale::conv::from_utf < char >(string, locale);
}


std::string utf_8_to_utf_16(const std::string& string) {
	return boost::locale::conv::between(string, std::string("UTF-16"), std::string("UTF-8"));
}

std::string utf_16_to_utf_8(const std::string& string) {
	return boost::locale::conv::between(string, std::string("UTF-8"), std::string("UTF-16"));
}

int main() {

	const std::string initial_text = "добрый вечер ";

	std::string text_8 = locale_to_utf_8(initial_text);
	std::string text_16 = utf_8_to_utf_16(text_8);

	std::string lit;

	for (auto c : text_16) {
		if (c == ' ') { lit += ' '; }
		else
			lit += u[c];
	}

	std::cout << lit;

	std::cout << "after reverse converting::"<< utf_8_to_locale(lit);

	

}