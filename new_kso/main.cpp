#include <iostream>
#include "KSO.h"

int main() noexcept
{
	KSO kso{};
	int command{ 0 };
	for(;;)
	{
		std::cout << "Enter command: 1 - Add product, 2 - Remove product, 3 - Show product_cart, 4 - Pay: ";
		std::cin >> command;
		if (command == 1)
		{
			std::string product{};
			std::cout << "Input name of product to append: ";
			std::cin >> product;
			try
			{
				kso.AddProduct(std::forward<const std::string&&>(product));
			}
			catch (const std::invalid_argument& ex)
			{
				std::cout << ex.what() << std::endl;
				continue;
			}
			std::cout << "product append in cart" << std::endl;
		}
		else if (command == 2)
		{
			std::string product{};
			std::cout << "Input name of product to remove: ";
			std::cin >> product;
			try
			{
				kso.RemoveProduct(std::forward<const std::string&&>(product));
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
				continue;
			}
			std::cout << "product is successfully removed!" << std::endl;
		}
		else if (command == 3)
		{
			auto product_cart{ kso.GetCart() };
			std::cout << "Name\tPrice" << std::endl;
			for (auto el : product_cart)
			{
				std::cout << el.GetName() << "\t" << el.GetPrice()<< "\t" << std::endl;
			}
			std::cout << std::endl << "Total price: " << kso.GetPrice() << std::endl;

		}
		else if (command == 4)
		{
			std::string ask{};
			std::cout << "Do you want to pay? ";
			std::cin >> ask;
			if (ask == "Yes" || ask == "yes")
			{
				std::cout << "Success!";
				break;
			}
			else if (ask == "No" || ask == "no")
			{
				continue;
			}
		}
		else
		{
			std::cout << "Invalid command!!!" << std::endl;
			continue;
		}
	}
	std::cout << "Thank you! Bye :)" << std::endl;
	return 0;
}