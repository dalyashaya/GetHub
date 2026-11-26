
#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;


class File {
		
	public:
		//constructor
		File(const string& name, const string& content, const Date& date);
		
		//copy constructor
		File( File&);
		bool lessThan(const File& e) const;
		bool equals(const File& e) const;

		const string& getName() const{
			return name;
		}
		
		//other
		void print() const;
		void printContents() const;
	
	private:
		Date lastModified;
		string name;
		string content;
	
};
#endif
