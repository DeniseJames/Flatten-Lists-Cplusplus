#ifndef FLATTEN_LIST_INCLUDED
#define FLATTEN_LIST_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once  // if using microsoft
#endif

#pragma once
#include <list>
#include <boost/any.hpp>

class flatten_list
{
public:
	typedef std::list<boost::any> anylist;
	void skipwhite(char const** s);
	flatten_list();
	~flatten_list();
	flatten_list::anylist flatten(const std::list<boost::any>& list);
	anylist create_anylist_i(char const** s);
	anylist create_anylist(char const* i);
	void print_list(anylist const& list);
	void print_item(boost::any const& a);
private:

};



#endif // end of FLATTEN_LIST_INCLUDED