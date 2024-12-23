#include "ProductData.h"
#include <stdexcept>

void Database::AddProduct(const Product&& product)
{
	if (!product.IsValid())
	{
		throw std::invalid_argument("Invalid product");
	}

	const auto hash = Hash(product.GetName());
	if (m_Products.contains(hash))
	{
		throw std::runtime_error("product already exist");
	}

	m_Products[hash] = product;
}

void Database::EditProduct(const Product&& product)
{
	if (!product.IsValid())
	{
		throw std::invalid_argument("Invalid product");
	}

	const auto hash = Hash(product.GetName());
	if (!m_Products.contains(hash))
	{
		throw std::runtime_error("product doesn't exist");
	}

	m_Products[hash] = product;
}

void Database::RemoveProduct(const std::string&& name)
{
	if (name.empty())
	{
		throw std::invalid_argument("Invalid product");
	}

	m_Products.erase(Hash(std::forward<const std::string&&>(name)));
}

Product Database::GetProduct(const std::string&& name)
{
	if (name.empty())
	{
		throw std::invalid_argument("Invalid name");
	}

	const auto hash = Hash(std::forward<const std::string&&>(name));
	if (!m_Products.contains(hash))
	{
		throw std::runtime_error("product doesn't exist");
	}

	return m_Products[hash];
}

size_t Database::Hash(const std::string&& name) const noexcept
{
	return std::hash<std::string>{}(std::forward<const std::string&&>(name));
}
