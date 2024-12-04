#include "ProductData.h"
#include <stdexcept>

void Database::AddProduct(Product&& product)
{
	if (!product.IsValid())
	{
		throw std::invalid_argument("Invalid product");
	}

	const auto hash = Hash(product.GetName());
	if (m_Products.contains(hash))
	{
		throw std::runtime_error("Product already exist");
	}

	m_Products[hash] = product;
}

void Database::EditProduct(Product&& product)
{
	if (!product.IsValid())
	{
		throw std::invalid_argument("Invalid product");
	}

	const auto hash = Hash(product.GetName());
	if (!m_Products.contains(hash))
	{
		throw std::runtime_error("Product doesn't exist");
	}

	m_Products[hash] = product;
}

void Database::RemoveProduct(std::string&& name)
{
	if (name.empty())
	{
		throw std::invalid_argument("Invalid product");
	}

	m_Products.erase(Hash(std::move(name)));
}

Product Database::GetProduct(std::string&& name)
{
	if (name.empty())
	{
		throw std::invalid_argument("Invalid name");
	}

	const auto hash = Hash(std::move(name));
	if (!m_Products.contains(hash))
	{
		throw std::runtime_error("Product doesn't exist");
	}

	return m_Products[hash];
}

size_t Database::Hash(std::string&& name) const noexcept
{
	return std::hash<std::string>{}(std::move(name));
}
