#pragma once

#include <string>

class Product final
{
public:
	Product();
	Product(const std::string&& name, double price);

	std::string GetName() const noexcept;
	double GetPrice() const noexcept;

	bool IsValid() const noexcept;
	bool operator==(const Product& other) const noexcept;

private:
	std::string m_Name{};
	double		m_Price{ 0.0 };
};
