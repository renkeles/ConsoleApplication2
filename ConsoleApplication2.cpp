#include <iostream>

int main() {

    setlocale(0,"");

    std::cout << "Кол-во байт в         int = " << sizeof(int) << std::endl;
    std::cout << "Кол-во байт в   short int = " << sizeof(short int) << std::endl;
    std::cout << "Кол-во байт в    long int = " << sizeof(long int) << std::endl;
    std::cout << "Кол-во байт в       float = " << sizeof(float) << std::endl;
    std::cout << "Кол-во байт в      double = " << sizeof(double) << std::endl;
    std::cout << "Кол-во байт в long double = " << sizeof(long double) << std::endl;
    std::cout << "Кол-во байт в        char = " << sizeof(char) << std::endl;
    std::cout << "Кол-во байт в        bool = " << sizeof(bool) << std::endl;

	{
		int value = 3; // Значение числа
		unsigned int order = 32; // Количество разрядов
		unsigned int mask = 1 << order - 1; // Маска побитового сравнения 2 147 483 648     1000 0000 0000 0000 0000 0000 0000 0000
		for (int i = 1; i <= order; ++i)
		{
			putchar(value & mask ? '1' : '0');
			value <<= 1; // Побитовый сдвиг числа
			if (i % 8 == 0)
			{
				putchar(' ');
			}
			if (i % order - 1 == 0)
			{
				putchar(' ');
			}
		}
	}

	std::cout << std::endl;

	{
		union MyUnion {
			int tool;
			float value;
		};

		MyUnion floatUnion;
		floatUnion.value = 3.14;

		unsigned int order = 32; // Количество разрядов
		unsigned int mask = 1 << order - 1; // Маска побитового сравнения 2 147 483 648     1000 0000 0000 0000 0000 0000 0000 0000
		for (int i = 1; i <= order; ++i)
		{
			putchar(floatUnion.tool & mask ? '1' : '0');
			floatUnion.tool <<= 1; // Побитовый сдвиг числа
			if (i == 9)
			{
				putchar(' ');
			}

			if (i > 9 && (i - 9) % 4 == 0)
			{
				putchar(' ');
			}

			if (i % order - 1 == 0)
			{
				putchar(' ');
			}
		}
	}
	
	std::cout << std::endl;

	{
		union MyUnion {
			int tool[2];
			double value;
		};

		MyUnion doubleUnion;
		doubleUnion.value = 3.14;

		unsigned int order = 64;
		unsigned int mask = 1 << order - 1;
		for (int i = 1; i <= order; ++i) {
			if (i <= 32) {
				putchar(doubleUnion.tool[1] & mask ? '1' : '0');
				doubleUnion.tool[1] <<= 1;
			}
			else
			{
				putchar(doubleUnion.tool[0] & mask ? '1' : '0');
				doubleUnion.tool[0] <<= 1;
			}

			if (i % order - 1 == 0)
			{
				putchar(' ');
			}

			if (i == 12)
			{
				putchar(' ');
			}

			if (i > 12 && (i - 12) % 4 == 0)
			{
				putchar(' ');
			}

		}
	}




    return 0;
}
