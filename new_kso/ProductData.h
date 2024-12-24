#pragma once

#include "product.h"
#include <unordered_map>

class Database final
{
public:
	void AddProduct(const Product&& product);
	void EditProduct(const Product&& product);

	void RemoveProduct(const std::string&& name);
	Product GetProduct(const std::string&& name);

	size_t Hash(const std::string&& name) const noexcept;

private:
	std::unordered_map<size_t, Product> m_Products{};
};
