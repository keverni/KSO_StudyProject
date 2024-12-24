#include "KSO.h"

#include <algorithm>

KSO::KSO() :
	m_TotalPrice{ 0.0 }
{
	m_AllProduct.AddProduct({ "Juice", 10.0 });
	m_AllProduct.AddProduct({ "Chips", 120.0 });
	m_AllProduct.AddProduct({ "Bread", 35.0 });
	m_AllProduct.AddProduct({ "Milk", 89.99 });
}

void KSO::AddProduct(const std::string&& name_product)
{
	auto find_product = m_AllProduct.GetProduct(std::forward<const std::string&&>(name_product));
	m_ProductCart.emplace_back(find_product);
	m_TotalPrice += find_product.GetPrice();
}

void KSO::RemoveProduct(const std::string&& name_product)
{
	auto find_product = m_AllProduct.GetProduct(std::forward<const std::string&&>(name_product));
	auto product_to_remove = std::find(std::cbegin(m_ProductCart), std::cend(m_ProductCart), find_product);
	m_ProductCart.erase(product_to_remove);
	m_TotalPrice -= find_product.GetPrice();
}

std::list<Product> KSO::GetCart() const noexcept
{
	return m_ProductCart;
}

double KSO::GetPrice() const noexcept
{
	return m_TotalPrice;
}

