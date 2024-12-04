#pragma once

#include "ProductData.h"

#include <list>

class KSO
{
public:
	KSO();

public:
	void AddProduct(std::string&& NameProduct);
	void RemoveProduct(std::string&& NameProduct);
	std::list<Product> GetCart() const noexcept;
	double GetPrice() const noexcept;

private:
	Database			 m_AllProduct;
	std::list<Product>   m_ProductCart;
	double				 m_TotalPrice;
};
