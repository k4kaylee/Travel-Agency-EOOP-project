#pragma once
class Tour{
private:
	char* name;
	float price;
	char* route;
	char* startDate;
	char* finishDate;
	char* description;
public:
	Tour(const char* nm, float prc, const char* rt, const char* strtDt, const char* fnshDt, const char* dscrptn);
	~Tour(void);

	void setName(const char* nm);
	void setPrice(float prc);
	void setRoute(const char* rt);
	void setDescription(const char* dscrptn);
	void setStartDate(const char* strtDt);
	void setFinishDate(const char* fnshDt);

	char* getName(void) { return name; };
	float getPrice(void) { return price; };
	char* getRoute(void) { return route; };
	char* getStartDate(void) { return startDate; };
	char* getFinishDate(void) { return finishDate; };
	char* getDuration(void) { return finishDate; };
	char* getDescription(void) { return description; };
	
	void print();
};

		