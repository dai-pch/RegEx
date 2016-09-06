#ifndef REGEX_CHAR_SET_H
#define REGEX_CHAR_SET_H

#include "Macro.h"

class CharSet{
public:
	wchar_t begin, end;
	CharSet(wchar_t Begin, wchar_t End) :begin(Begin), end(End) {}
	bool isEqual(CharSet &Set2)
	{
		if (begin == Set2.begin && end == Set2.end)
			return true;
		else
			return false;
	}
	bool isSubSetOf(CharSet &Set2)
	{
		if (begin >= Set2.begin && end <= Set2.end)
			return true;
		else
			return false;
	}
	bool isIntersect(CharSet &Set2)
	{
		if (begin > Set2.end || end < Set2.begin)
			return false;
		else
			return true;
	}
};





#endif