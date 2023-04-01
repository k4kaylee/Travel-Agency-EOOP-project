#pragma once
class Tour{
private:
	char* name;
	char* duration;
	float price;
	char* route;
	char* description;
public:
	Tour(char* nm, char* drtn, float prc, char* rt, char* dscrptn);
	~Tour();

	void setName(char* nm);
	void setDuration(char* drtn);
	void setPrice(float prc);
	void setRoute(char* rt);
	void setDescription(char* dscrptn);

	char* getName() { return name; };
	char* getDuration() { return duration; };
	float getPrice() { return price; };
	char* getRoute() { return route; };
	char* getDescriprion() { return description; };
	
};

	