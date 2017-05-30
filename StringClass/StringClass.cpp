// StringClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Include/myString.h"
#include <iostream>


int main()
{
	myString data("The quick brown fox.");
	myString find("quick");
	myString replace("slow");
	int test = data.Find(find);

	std::cout << test << std::endl;

	
	myString data2("The quick brown fox.");
	myString find2("quick");
	myString replace2("slow");
	myString test2 = data.Replace(find2, replace2);

	std::cout << test2.Basic() << std::endl;

    return 0;
}

