#include "TwitterData.hpp"

TwitterData::TwitterData () 
{
	mpUserName =  mpActualName = mpEmail = mpCategory = nullptr;
	mpNumTweets = nullptr;
}

// destructor
TwitterData::~TwitterData()
{
	delete mpUserName;
	delete mpActualName;
	delete mpEmail;
	delete mpCategory;
	delete mpNumTweets;
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
	delete mpUserName;
	mpUserName = new std::string(newUserName);
}
// assume actualname = last,first;
void TwitterData::setActualName(const std::string& newActualName)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
	delete mpActualName;
	mpActualName = new std::string(newActualName);
}

void TwitterData::setEmail(const std::string& newEmail)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
	delete mpEmail;
	mpEmail = new std::string(newEmail);
}

void TwitterData::setCategory(const std::string& newCategory)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for a std::string here?
	delete mpCategory;
	mpCategory = new std::string(newCategory);
}

void TwitterData::setNumTweets(const int& newNumTweets)
{
	// Task 1(a) - you need to implement
	// do we need to allocate space for an int here?
	delete mpNumTweets;
	mpNumTweets = new int(newNumTweets);
}