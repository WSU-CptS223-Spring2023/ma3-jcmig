#include "TwitterData.hpp"

TwitterData::TwitterData () 
{
	mpUserName =  mpActualName = mpEmail = mpCategory = nullptr;
	mpNumTweets = nullptr;
}

// destructor
TwitterData::~TwitterData()
{
	// Task 1(b) - you need to implement
}

//Copy constructor - deep copy
TwitterData::TwitterData(const TwitterData& other) 
{
	// Task 1(b) - you need to implement
}

//Move constructor
TwitterData::TwitterData(TwitterData&& other)
{
	// Task 1(b) - you need to implement
}

//Copy assignment operator
TwitterData& TwitterData::operator=(TwitterData& other)
{
	// Task 1(b) - you need to implement
}

//Move assignment operator
TwitterData& TwitterData::operator=(TwitterData&& other)
{
	// Task 1(b) - you need to implement
}

std::string TwitterData::getUserName() const
{
	return *(this->mpUserName);
}

std::string TwitterData::getActualName() const
{
	return *(this->mpActualName);
}

std::string TwitterData::getEmail() const
{
	return *(this->mpEmail);
}

std::string TwitterData::getCategory() const
{
	return *(this->mpCategory);
}

int TwitterData::getNumTweets() const
{
	return *(this->mpNumTweets);
}

void TwitterData::setUserName(const std::string& newUserName)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
}
// assume actualname = last,first;
void TwitterData::setActualName(const std::string& newActualName)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
}

void TwitterData::setEmail(const std::string& newEmail)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
}

void TwitterData::setCategory(const std::string& newCategory)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
}

void TwitterData::setNumTweets(const int& newNumTweets)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for an int here?
}