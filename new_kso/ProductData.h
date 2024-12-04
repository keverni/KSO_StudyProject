#pragma once

#include "Product.h"
#include <unordered_map>

class Database
{
public:
	void AddProduct(Product&& product);
	void EditProduct(Product&& product);

	void RemoveProduct(std::string&& name);
	Product GetProduct(std::string&& name);

	size_t Hash(std::string&& name) const noexcept;

private:
	std::unordered_map<size_t, Product> m_Products;

};
