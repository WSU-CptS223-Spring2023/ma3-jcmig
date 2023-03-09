#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

#include <map>
#include "TwitterData.hpp"

std::ostream& operator<<(std::ostream& out, const std::map<std::string, TwitterData>& map) {
	for (const auto& pair : map) {
		int i = 1;

		out << i << " - Key: " << pair.first << std::endl;
		out << "    Value : { Name: " << pair.second.getActualName() << ";  Username: " << pair.second.getUserName() << ";  ";
		out << "Email: " << pair.second.getEmail() << ":  Category: " << pair.second.getCategory() << ";  Tweet count: " << pair.second.getNumTweets() << " }" << std::endl;

		i++;
	}

	return out;
}

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

		std::string actualName = lastName + "," + firstName;

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

		i++;
	}

	// Task 1(e) - remove the key-value pair matching key “ken2005”
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Removing item with key \"ken2005\"." << std::endl;
	
	twitterDataMap.erase("ken2005");

	std::cout << "Erased 1 element(s)." << std::endl;
	std::cout << "--------------------------------" << std::endl;

	// Task 1(g) - 2nd print - iterate through the std::map and print the key-value pairs; print using a for loop using iterators
	for (auto iterator = twitterDataMap.begin(); iterator != twitterDataMap.end(); ++iterator){
		int i = 1;
		
		std::cout << i << " - Key: " << iterator->first << std::endl;
		std::cout << "    Value : { Name: " << iterator->second.getActualName() << ";  Username: " << iterator->second.getUserName() << ";  ";
		std::cout << "Email: " << iterator->second.getEmail() << ":  Category: " << iterator->second.getCategory() << ";  Tweet count: " << iterator->second.getNumTweets() << " }" << std::endl;

		i++;
	}

	// Task 1(f) - remove the key-value pair matching last and first name “Ay,Arslan”
	
	/*	Possible method: using std::find_if(); Chose to use a for-loop instead as it is something I'm more confident in, and I just learnt about std::find_if()
		
		auto iter = std::find_if(twitterDataMap.begin(), twitterDataMap.end(), [](const std::pair<std::string, TwitterData>&p) {
			return p.second.getActualName() == "Ay,Arslan";
		});

		if (iter != twitterDataMap.end()) {
			twitterDataMap.erase(iter);
		}
	*/

	for (auto iter = twitterDataMap.begin(); iter != twitterDataMap.end(); ++iter) {
		if (iter->second.getActualName() == "Ay,Arslan") {
			twitterDataMap.erase(iter);
			break;
		}
	}

	// Task 1(g) - 3rd print - print using a “<< operator for map” . You need to define the operator function in main.cpp
	std::cout << twitterDataMap << std::endl;

	//Task 1(h) reorganize the data and store it in a map object where the keys are categories and values are vectors of TwitterData
	std::map<std::string, std::vector<TwitterData>> categoryTwitterDataMap;
	for (const auto& pair : twitterDataMap) {
		const std::string& category = pair.second.getCategory();
		categoryTwitterDataMap[category].push_back(pair.second);
	}

	// Task 1(i) - print (MostViewedCategory, vector of TwitterData) pairs.
	for (const auto& pair : categoryTwitterDataMap) {
		const std::string& category = pair.first;
		const std::vector<TwitterData>& dataVector = pair.second;
		int i = 1;

		std::cout << i << " - Key: " << category << std::endl;
		std::cout << "    Value : [" << std::endl;

		for (const auto& data : dataVector) {
			std::cout << "* { Name: " << data.getActualName() << ";  Username: " << data.getUserName() << ";  ";
			std::cout << "Email: " << data.getEmail() << ":  Category: " << data.getCategory() << ";  Tweet count: " << data.getNumTweets() << " }" << std::endl;
		}

		std::cout << " ]" << std::endl;
	
	}
	return 0;
}