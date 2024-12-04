#include "Product.h"

Product::Product() :
	m_Price(0.0)
{
}

Product::Product(std::string&& name, double price) :
	m_Name(std::move(name)),
	m_Price(price)
{
}

bool Product::operator==(const Product& other) const noexcept
{
	return m_Name == other.m_Name;
}

std::string Product::GetName() const noexcept
{
	return m_Name;
}

double Product::GetPrice() const noexcept
{
	return m_Price;
}

bool Product::IsValid() const noexcept
{
	return !m_Name.empty() && m_Price > 0.0;
}

