#pragma once
class Tour{
private:
	char* name;
	char* duration;
	float price;
	char* route;
	char* startDate;
	char* description;
public:
	Tour(const char* nm, const char* drtn, float prc, const char* rt, const char* strtDt, const char* dscrptn);
	~Tour(void);

	void setName(const char* nm);
	void setDuration(const char* drtn);
	void setPrice(float prc);
	void setRoute(const char* rt);
	void setDescription(const char* dscrptn);
	void setStartDate(const char* strtDt);

	char* getName(void) { return name; };
	char* getDuration(void) { return duration; };
	float getPrice(void) { return price; };
	char* getRoute(void) { return route; };
	char* getDescription(void) { return description; };
	char* getStartDate(void) { return startDate; };
	
	void print();
};

		