#include "TravelAgency.h"
#include "List.h"
#include "Console.hpp"

int main() {
	Client* client1 = new Client("Nikolai", "Borutko", "+124134674122", "10256381@wxample.com");
	Client* client2 = new Client("Pavel", "Fuggy", "+612567487291", "012412495@example.com");
	Client* client3 = new Client("Eugene", "Smith", "+039528736481", "18258924@wxample.com");
	Client* client4 = new Client("Jakub", "Kowalski", "+347902478299", "1958195145@example.com");
	Client* client5 = new Client("Maria", "Garcia", "+44123456789", "1524742325@example.com");

	List<Client>* listOfClients = new List<Client>;
	listOfClients->add(client1);
	listOfClients->add(client2);
	listOfClients->add(client3);
	listOfClients->add(client4);


	Tour* tour1 = new Tour( "Hawaii Paradise",
						    "7 days",
						    2500.0,
						    "Honolulu to Maui",
							"21.05.2023",
						    "Experience the best of Hawaii with this 7-day tour that takes you\
\nfrom Honolulu to Maui. Enjoy stunning beaches, tropical rainforests,\
\nsand breathtaking landscapes.\n" );

	Tour* tour2 = new Tour( "European Adventure",
							"14 days",
							4500.0,
							"Paris to Barcelona",
							"15.02.2021",
							"Embark on a 14-day adventure through Europe, starting in Paris and\
\nending in Barcelona. Discover the beauty of the continent with this\
\nexciting tour that covers 6 different countries.\n" );

	Tour* tour3 = new Tour( "African Safari",
							"10 days",
							3500.0,
							"Kenya to Tanzania",
							"21.02.2024",
							"Experience the ultimate adventure with this 10-day safari tour\
\nthat takes you through the heart of Kenya and Tanzania. Get up close\
\nand personal with some of Africa's most majestic wildlife.\n" );

	Tour* tour4 = new Tour( "Paris Tour",
							"4 days",
							1200.0,
							"Eiffel Tower, Notre-Dame Cathedral, The Louvre",
							"01.07.2023",
							"Experience the culture and beauty of Paris in this four-day tour.\n" );

	Tour* tour5 = new Tour( "Australia Tour", 
							"10 days", 
							3500.0, 
							"Sydney Opera House, Great Barrier Reef, Uluru", 
							"30.08.2023",
							"Explore the stunning natural wonders and iconic landmarks\
\nof Australia in this ten-day tour.\n");

	List<Tour>* listOfTours = new List<Tour>;
	listOfTours->add(tour1);
	listOfTours->add(tour2);
	listOfTours->add(tour3);
	listOfTours->add(tour4);

	TravelAgency* agency = new TravelAgency(listOfTours, listOfClients);

	//agency->getTourList()->print();
	client5->book(tour1);
	client4->book(tour2);
	agency->getClientList()->add(client5);
	//agency->getClientList()->print();

	Engine terminal;
	terminal.run();

	return 0;
}