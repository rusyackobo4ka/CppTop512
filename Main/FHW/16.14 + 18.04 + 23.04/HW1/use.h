#pragma once
#include <vector>
#include "Guide.h"

class use
{
public:
	use() {}
	~use() {}

	void addInfo(Guide info);

	Guide searchName(std::string name);
	Guide searchUser(std::string user);
	Guide searchPhone(std::string phone);
	Guide searchActivity(std::string activity);

	void showAll();

private:
	std::vector<Guide> list = {Guide("0", "0", "0", "0", "0")};
};

