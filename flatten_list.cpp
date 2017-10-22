#include <list>  // to use list objects
#include <boost/any.hpp>  // for anylist object
#include <iostream>  // for cout printing
#include "flatten_list.h"
#include <cctype> // for isspace 
#include <vector>

flatten_list::flatten_list()
{
}

flatten_list::~flatten_list()
{
}
void flatten_list::skipwhite(char const** s)
{
	while (**s && std::isspace((unsigned char)**s))
	{
		++*s;
	}
}
flatten_list::anylist flatten_list::flatten(const std::list<boost::any>& list )
{
	typedef anylist::iterator iterator;
	anylist list_ = list;
	iterator current = list_.begin();
	while (current != list_.end())
	{
		if (current->type() == typeid(anylist))
		{
			iterator next = current;
			++next;
			list_.splice(next, boost::any_cast<anylist&>(*current));
			current = list_.erase(current);
		}
		else
			++current;
	}
	return list_;
}
flatten_list::anylist flatten_list::create_anylist(char const* i)
{
	return create_anylist_i(&i);
}
flatten_list::anylist flatten_list::create_anylist_i(char const** s)
{
	anylist result;
	skipwhite(s);
	if (**s != '[')
		throw "Not a list";
	++*s;
	while (true)
	{
		skipwhite(s);
		if (!**s)
			throw "Error";
		else if (**s == ']')
		{
			++*s;
			return result;
		}
		else if (**s == '[')
			result.push_back(create_anylist_i(s));
		else if (std::isdigit((unsigned char)**s))
		{
			int i = 0;
			while (std::isdigit((unsigned char)**s))
			{
				i = 10 * i + (**s - '0');
				++*s;
			}
			result.push_back(i);
		}
		else
			throw "Error";

		skipwhite(s);
		if (**s != ',' && **s != ']')
			throw "Error";
		if (**s == ',')
			++*s;
	}
}


void flatten_list::print_list(flatten_list::anylist const& list) {
	
	std::cout << '[';
	int count = 0;
	for (auto elem: list)
	{
		
		print_item(elem);
		count++;
		if (count < list.size())
		{
			std::cout << ", ";
		}
		
	
	}
	std::cout << ']' ;
}

void flatten_list::print_item(boost::any const& a)
{
	if (a.type() == typeid(int))
		std::cout << boost::any_cast<int>(a);
	else if (a.type() == typeid(anylist))
		print_list(boost::any_cast<anylist const&>(a));
	else
		std::cout << "???";
}


