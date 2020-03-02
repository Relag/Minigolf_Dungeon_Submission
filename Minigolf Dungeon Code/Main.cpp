#include "Engine.h"
#include "NetworkManager.h"

int main()
{ // Start of the main method 
	
	//Create the Game
	Engine engine;

	NetworkManager net;

	//Run the Game
	engine.run();

	net.Connect();
	
} // End of the main method