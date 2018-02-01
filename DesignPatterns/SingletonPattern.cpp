// singleton pattern
#include <iostream>

using namespace std;

class Server
{
	static bool isServerCaptured;
	Server() { isServerCaptured = true; }
	public:
	    static Server& captureServer()
		{
			if(isServerCaptured == true)
				return nullptr;
			else
				return new Server();
		}
		~Server()
		{
			isServerCaptured = false;
			cout<<"server has been released successfully"<<endl;
		}
};

bool Server::isServerCaptured = false;

int main()
{
	Server& server = Server::captureServer();
	if(server != nullptr)
	{
		cout<<"server has been captured successfully"<<endl;
	}
	return 0;
}