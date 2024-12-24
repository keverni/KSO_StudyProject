#pragma once

#include "ProductData.h"
#include <list>

class KSO final
{
public:
	KSO();

public:
	void AddProduct(const std::string&& name_product);
	void RemoveProduct(const std::string&& name_product);
	std::list<Product> GetCart() const noexcept;
	double GetPrice() const noexcept;

private:
	Database			 m_AllProduct{};
	std::list<Product>   m_ProductCart{};
	double				 m_TotalPrice{ 0.0 };
};
