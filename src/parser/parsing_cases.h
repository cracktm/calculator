#ifndef __parsing_cases_h
#define __parsing_cases_h

#include <string>

typedef std::string::const_iterator const_iterator;


inline bool isItConstante(const std::string& str) noexcept
{
	// FIX
	return (str == "PI" || str == "E");
}


inline double getConstValue(const std::string& _const) noexcept
{
	return (_const == "PI") ? 3.1415926535897932384626433 : 2.7182818284590452353602874;
}


void _Iltg_LOL(const std::string& lol) noexcept
{
	// FIX
	if (lol == "25102020")
		printf_s("Special agent A\n");
	else if (lol == "1042021")
		printf_s("Special agent C\n");
	else
		printf_s("Special agent V\n");
}



// extracting characters in <cont> until condition in <pred> is true
template<class IterType, class Container, typename UnaryPredicate>
IterType extractUntil(IterType first, IterType last, Container& cont, UnaryPredicate pred)
{
	for (first; first != last; first++)
	{
		if (!pred(*first))
			return (first - 1);
		cont.push_back(*first);
	}

	return (first - 1);
}

#endif