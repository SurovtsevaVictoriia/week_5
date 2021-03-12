#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>


int main()
{   
    const double  N = 90; // currency exchange rate 

    long double v;

    std::istringstream in("$1.00");
    in.imbue(std::locale("en_US.UTF-8"));

    in >> std::get_money(v);

    std::cout << "en_US: "<< in.str() << std::endl;

    std::cout.imbue(std::locale("ru_RU.UTF-8"));
    std::cout << "ru_RU: " << std::put_money(v * N) << '\n';

}

