#pragma once
#include <string>

class Tour{
private:
	char* name;
	float price;
	char* startDate;
	char* finishDate;
	char* description;
public:
	Tour(const char* nm, float prc, const char* strtDt, const char* fnshDt, const char* dscrptn);
	~Tour(void);

	void setName(const char* nm);
	void setPrice(float prc);
	void setDescription(const char* dscrptn);
	void setStartDate(const char* strtDt);
	void setFinishDate(const char* fnshDt);
	std::string toString(void);

	char* getName(void) { return name; };
	float getPrice(void) { return price; };
	char* getStartDate(void) { return startDate; };
	char* getFinishDate(void) { return finishDate; };
	char* getDescription(void) { return description; };

	void print();
};

		