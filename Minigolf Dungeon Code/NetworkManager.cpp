#include "NetworkManager.h"


// Check to see if there can be a connection made

void NetworkManager::CheckConnection()
{ // Start of the CheckConnection function 

	// try the connection
	try
	{
		Connect(); // Calling the TCP Connection for the CLIENT (Game) to Server (Database)
	}
	catch (exception error)
	{
		// display error
	}

} // End of the CheckCollision function


// The client connecting the server connection
void NetworkManager::Connect()
{ // Start of the Connect function
	ip.getLocalAddress();

	socket.connect(ip, 3030);

	cout << "Connecting";

} // End of the Connect function

// Displays the type of Error message in the command line
void NetworkManager::SQLError(unsigned int handletype, const SQLHANDLE& handle)
{ // Start of the SQLError function
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];

	if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, SQLState, NULL, message, 1024, NULL))
	{ // Start of the if statement

		// printing out the error to the command line
		cout << "SQL Error Message: " << message << "+\nSQLState: " << SQLState << "." << endl;

	} // End of the if statement

	

} // End of the SQLError function


//The server that runs until application or connection is broken 
/*
void Engine::TCPConnection()
{ // Start of the TCPConnection function

	// TCPListener to listen for a connection
	TcpListener listener;

	// continous loop of the server connection
	while (true)
	{
		listener.listen(10000); //listen for the connection from the client

		listener.accept(socket); // Accepting the found TCP socket connection, if found


	}
	*/
	

//} // End of the TCPConnection function