#include "Include/myString.h"
#include <string.h>
#include <iostream>

myString::myString(const char* c)
{
	int length = strlen(c) + 1;
		
	m_data = new char[length];

	strcpy(m_data, c);
}

myString::myString(const myString& other)
{
	m_data = new char[strlen(other.m_data) + 1];

	strcpy(m_data, other.m_data);
}


myString::~myString()
{
	delete[] m_data;

}

int myString::Length() const
{
	int i = 0;

	while (m_data[i] != '\0') {
		i++;
	}

	return i;
}

char myString::Index(unsigned int) const
{

	return 0;
}

bool myString::operator==(const myString &compare)
{
	if (Length() != compare.Length())
	{
		return false;
	}
	for (int i = 0; i < Length(); i++)
	{
		if (m_data[i] != compare.m_data[i]) {
			return false;
		}
	}
	return true;
}

myString & myString::operator+(const myString &other)
{
	char* newstring = new char[Length() + other.Length() + 1];

	int i = 0;
	int j = 0;
	while (i < Length())
	{
		newstring[i] = m_data[i];
		i++;
	}
	while (j <= other.Length())
	{
		newstring[i] = other.m_data[j];
		i++;
		j++;
	}

	delete[] m_data;

	m_data = newstring;

	return *this;
}

const char * myString::Basic() const
{
	return m_data;
}

myString myString::ToLower() const
{
	for (int i = 0; i < Length(); i++)
	{
		// Check if the data is within the decimal range of capital chars.
		if ((int)m_data[i] >= 65 && (int)m_data[i] <= 90) {
			// If yes, then add 32.
			m_data[i] = m_data[i] + 32;
		}
	}
	return *this;
}

myString myString::ToUpper() const
{
	for (int i = 0; i < Length(); i++)
	{
		// Check if the data is within the decimal range of capital chars.
		if ((int)m_data[i] >= 97 && (int)m_data[i] <= 122) {
			// If yes, then remove 32.
			m_data[i] = m_data[i] - 32;
		}
	}
	return *this;
}

int myString::Find(const myString &other, const unsigned int index) const
{
	if (other.Length() > Length()) // If the second string is longer than the first, no point looking.
		return -1;

	for (int i = index; i < Length(); i++) { // TODO: Fix if at length?
		int j = 0;
		if (m_data[i] == other.m_data[j]) {
			while (m_data[i] == other.m_data[j] && j < other.Length()) {
				j++;
				i++;
			}

			if (j == other.Length())
				return i - other.Length()+1;
		}
	}

	return -1;
}

myString & myString::Replace(const myString &find, const myString &replace)
{
	// TODO: Fix
	int found = Find(find.m_data) -1;
	if (found >= 0)
	{
		std::cout << "I found it" << std::endl;
		int j = 0;
		for (int i = found; i < found + replace.Length(); i++)
		{
			std::cout << "Replacing " << m_data[i] << " with " << replace.m_data[j] << "" << std::endl;
			m_data[i] = replace.m_data[j];
			j++;
		}

	}
	return *this;
}

