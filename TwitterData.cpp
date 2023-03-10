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
	mpUserName = new std::string(*other.mpUserName);
	mpActualName = new std::string(*other.mpActualName);
	mpEmail = new std::string(*other.mpEmail);
	mpCategory = new std::string(*other.mpCategory);
	mpNumTweets = new int(*other.mpNumTweets);
}

//Move constructor
TwitterData::TwitterData(TwitterData&& other)
{
	mpUserName = other.mpUserName;
	mpActualName = other.mpActualName;
	mpEmail = other.mpEmail;
	mpCategory = other.mpCategory;
	mpNumTweets = other.mpNumTweets;

	other.mpUserName = nullptr;
	other.mpActualName = nullptr;
	other.mpEmail = nullptr;
	other.mpCategory = nullptr;
	other.mpNumTweets = nullptr;
}

//Copy assignment operator
TwitterData& TwitterData::operator=(TwitterData& other)
{
	if (this != &other) {
		setUserName(other.getUserName());
		setActualName(other.getActualName());
		setEmail(other.getEmail());
		setCategory(other.getCategory());
		setNumTweets(other.getNumTweets());
	}

	return *this;
}

//Move assignment operator
TwitterData& TwitterData::operator=(TwitterData&& other)
{
	if (this != &other) {
		this->~TwitterData();

		this->mpUserName = other.mpUserName;
		this->mpActualName = other.mpActualName;
		this->mpEmail = other.mpEmail;
		this->mpCategory = other.mpCategory;
		this->mpNumTweets = other.mpNumTweets;

		other.mpUserName = nullptr;
		other.mpActualName = nullptr;
		other.mpEmail = nullptr;
		other.mpCategory = nullptr;
		other.mpNumTweets = nullptr;
	}

	return *this;
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