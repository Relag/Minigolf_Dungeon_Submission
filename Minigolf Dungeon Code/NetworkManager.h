#pragma once
#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H
#include "Engine.h"
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqlucode.h>
#include <sqltypes.h>
#include <sql.h>

using namespace std;
using namespace sf;


class NetworkManager
{
public:
	void CheckConnection();
	void Connect();
	void SQLError(unsigned int handletype, const SQLHANDLE& handle);

protected:
	
	// Our TCP Socket
	TcpSocket socket;

	// Our IP Address for the Server Connection
	IpAddress ip;
};

#endif // !NETWORKMANAGER.H
