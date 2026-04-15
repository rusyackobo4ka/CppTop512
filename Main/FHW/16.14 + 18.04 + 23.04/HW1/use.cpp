#include "use.h"
#include <iostream>

void use::addInfo(Guide info)
{
    list.push_back(info);
}

Guide use::searchName(std::string name)
{
    for (int i = 1; i < list.size(); ++i)
    {
        if (list[i].getName() == name)
        {
            return list[i];
        }
    }
    std::cout << "no";
    std::cout << "\t";
    return list[0];
}

Guide use::searchUser(std::string user)
{
    for (int i = 1; i < list.size(); ++i)
    {
        if (list[i].getUser() == user)
        {
            return list[i];
        }
    }
    std::cout << "no";
    std::cout << "\t";
    return list[0];
}

Guide use::searchPhone(std::string phone)
{
    for (int i = 1; i < list.size(); ++i)
    {
        if (list[i].getPhone() == phone)
        {
            return list[i];
        }

    }
    std::cout << "no";
    std::cout << "\t";
    return list[0];
}

Guide use::searchActivity(std::string activity)
{
    for (int i = 1; i < list.size(); ++i)
    {
        if (list[i].getActivity() == activity)
        {
            return list[i];
        }
    }
    std::cout << "no";
    std::cout << "\t";
    return list[0];
}

void use::showAll()
{
    for (int i = 1; i < list.size(); ++i)
    {
        list[i].show();
        std::cout << "\t";
    }
}
