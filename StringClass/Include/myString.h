#pragma once

class myString
{
public:
	myString(const char*); // The ability to set the string to an input C-style string
	myString(const myString& other);
	~myString();
	int Length() const; // Query string length
	char Index(unsigned int) const; // Access char at certain index
	bool operator==(const myString&); // Compare string to another string
	myString& operator+(const myString&); // Append string to another string & prepend
	const char* Basic() const; // Return the string as basic constant C-style
	myString ToLower() const;
	myString ToUpper() const;
	int Find(const myString&, const unsigned int = 0) const;
	myString& Replace(const myString&, const myString&);

private:
	char* m_data;

};