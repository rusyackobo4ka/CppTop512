#pragma once
#include <string>

class Guide
{
public:
	Guide(std::string name, std::string user, std::string phone, std::string adress, std::string activity) : _name(name), _user(user), _phone(phone), _adress(adress), _activity(activity) {}
	~Guide() = default;

	std::string getName() { return _name; };
	std::string getUser() { return _user; };
	std::string getPhone() { return _phone; };
	std::string getAdress() { return _adress; };
	std::string getActivity() { return _activity; };

	void show();

private:
	std::string _name;
	std::string _user;
	std::string _phone;
	std::string _adress;
	std::string _activity;
};

