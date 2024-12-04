#include "KSO.h"

#include <algorithm>

KSO::KSO() :
	m_TotalPrice(0.0)
{
	m_AllProduct.AddProduct({ "Juice", 10.0 });
	m_AllProduct.AddProduct({ "Chips", 120.0 });
	m_AllProduct.AddProduct({ "Bread", 35.0 });
	m_AllProduct.AddProduct({ "Milk", 89.99 });
}

void KSO::AddProduct(std::string&& NameProduct)
{
	auto Find_Product = m_AllProduct.GetProduct(std::move(NameProduct));
	m_ProductCart.emplace_back(Find_Product);
	m_TotalPrice += Find_Product.GetPrice();
}

void KSO::RemoveProduct(std::string&& NameProduct)
{
	auto Find_Product = m_AllProduct.GetProduct(std::move(NameProduct));
	auto Product_to_remove = std::find(std::cbegin(m_ProductCart), std::cend(m_ProductCart), Find_Product);
	m_ProductCart.erase(Product_to_remove);
	m_TotalPrice -= Find_Product.GetPrice();
}

std::list<Product> KSO::GetCart() const noexcept
{
	return m_ProductCart;
}

double KSO::GetPrice() const noexcept
{
	return m_TotalPrice;
}

