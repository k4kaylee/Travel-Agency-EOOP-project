#pragma once
class Tour{
private:
	char* name;
	char* duration;
	float price;
	char* route;
	char* description;
public:
	Tour(const char* nm, const char* drtn, float prc, const char* rt, const char* dscrptn);
	~Tour();

	void setName(const char* nm);
	void setDuration(const char* drtn);
	void setPrice(float prc);
	void setRoute(const char* rt);
	void setDescription(const char* dscrptn);

	char* getName() { return name; };
	char* getDuration() { return duration; };
	float getPrice() { return price; };
	char* getRoute() { return route; };
	char* getDescrition() { return description; };
	
	void print();
};

		