#include <Cosmos.h>

class Antares : public Cosmos::Application
{
public:
	Antares()
	{

	}

	~Antares()
	{

	}

	
};

Cosmos::Application* Cosmos::CreateCosmosApplication()
{
	return new Antares();
}