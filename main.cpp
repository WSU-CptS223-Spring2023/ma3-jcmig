#include <fstream>
#include <sstream>
#include <vector>

#include <map>
#include "TwitterData.hpp"

int main(int argc, char* argv[])
{
	// we need a map to store our key-value pairs
	// std::map<keyType, ValueType>; What should the key be? What about the value?
	std::map<std::string, TwitterData> twitterDataMap;

	// Tasks 1(c) and (d) - Read the CSV file and insert the data into the std::map object
	std::ifstream infile("TwitterAccounts.csv");
	if (!infile) {
		std::cerr << "Unable to open TwitterAccounts.csv" << std::endl;
		return 1;
	}

	std::string line;
	char quotationChar = '\"';
	int lineNum = 0;
	while (std::getline(infile, line)) {
		++lineNum;
		
		std::stringstream linestream(line);
		std::string userName, lastName, firstName, email, numTweetsStr, category;

		std::getline(linestream, userName, ',');
		std::getline(linestream, lastName, ',');
		std::getline(linestream, firstName, ',');
		std::getline(linestream, email, ',');
		std::getline(linestream, numTweetsStr, ',');
		std::getline(linestream, category, ',');

		std::string actualName = lastName + ", " + firstName;

		actualName.erase(0, 1); // Removes the first character, which is a quotation symbol
		category.erase(category.size() - 1, 1); // Removes the last character, which is a quotation symbol

		int numTweets;
		try {
			numTweets = std::stoi(numTweetsStr);
		} catch (std::invalid_argument& e) {
			numTweets = 0;
		}

		TwitterData twitterData;
		twitterData.setUserName(userName);
		twitterData.setActualName(actualName);
		twitterData.setEmail(email);
		twitterData.setCategory(category);
		twitterData.setNumTweets(numTweets);
		twitterDataMap[userName] = twitterData;
	}

	// Task 1(g) - 1st print - iterate through the std::map and print the key-value pairs; print using a range loop
	for (const auto& pair : twitterDataMap) {
		int i = 1;
		std::string key = pair.first;
		TwitterData value = pair.second;

		std::cout << i << " - Key: " << key << std::endl;
		std::cout << "    Value : { Name: " << value.getActualName() << ";  Username: " << value.getUserName() << ";  ";
		std::cout << "Email: " << value.getEmail() << ":  Category: " << value.getCategory() << ";  Tweet count: " << value.getNumTweets() << " }" << std::endl;
	}


	// Task 1(e) - remove the key-value pair matching key “ken2005”

	// Task 1(g) - 2nd print - iterate through the std::map and print the key-value pairs; print using a for loop using iterators

	// Task 1(f) - remove the key-value pair matching last and first name “Ay,Arslan”

	// Task 1(g) - 3rd print - print using a “<< operator for map” . You need to define the operator function in main.cpp

	//Task 1(h) reorganize the data and store it in a map object where the keys are categories and values are vectors of TwitterData

	// Task 1(i) - print (MostViewedCategory, vector of TwitterData) pairs.

	return 0;
}