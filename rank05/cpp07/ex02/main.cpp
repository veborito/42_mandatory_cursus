#include "Array.hpp"
#define MAX_VAL 750

template<typename T>
void print_tab(Array<T> &tab){
	for (int i = 0; i < static_cast<int>(tab.size()); i++)
		std::cout << tab[i] << ' ';
	std::cout << '\n';
}

int main(void) {
    Array<int> *tab = new Array<int>(3);
	std::cout << "tab ";
	print_tab(*tab);
    Array<int> tab2(*tab);
	delete tab;
	std::cout << "tab2 ";
	print_tab(tab2);
	Array<char> char_tab;
	Array<char> char_tabcpy(char_tab);
	Array<char> *char_tab2 = new Array<char>(5);
	try {
		(*char_tab2)[0] = 'a';
		(*char_tab2)[1] = 'b';
		(*char_tab2)[2] = 'c';
		(*char_tab2)[3] = 'd';
		(*char_tab2)[4] = 'e';
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	} 
	try {
		char_tab[0] = 'i';
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	} 
	try {
		(*char_tab2)[-2] = 'i';
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	} 
	try {
		(*char_tab2)[20] = 'i';
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	char_tab = *char_tab2;
	std::cout << "tab after = operator ";
	print_tab(char_tab);
	delete char_tab2;
	char_tab[0] = '1';
	char_tab[3] = '4';
	print_tab(char_tab);
	//------------------------------------------------------------------------------
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}