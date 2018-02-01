// abstract factory
#include <iostream>
#include <string>

class Vehicle
{
	public:
		void displayVehicleInfo() = 0;
};

class Cycle : public Vehicle
{
	
	public:
		void displayVehicleInfo()
		{
			std::cout<<"Cycle"<<endl;
		}
};

class MotorBike : public Vehicle
{
	
	public:
		void displayVehicleInfo()
		{
			std::cout<<"MotorBike"<<endl;
		}
};

class VehicleFactory
{
	public:
		virtual Vehicle* manufactureVehicle() = 0;
};

class CycleFactoryUnit
{
	public:
		Vehicle* vehicleType() override
		{
			return new Cycle();
		}
};

class MotorBikeFactoryUnit
{
	public:
		Vehicle* vehicleType() override
		{
			return new MotorBike();
		}
};


class Rider
{
	VehicleFactory& vehicleFactory;
	public:
		Rider(VehicleFactory& factory) : vehicleFactory(factory)
		{}
		void IRide()
		{
			cout<< (vehicleFactory.vehicleType() -> displayVehicleInfo() );
		}
};


int main()
{
	VehicleFactory *vehicleFactory;
	vehicleFactory = new CycleFactoryUnit();
	
	Rider rider1(vehicleFactory);
	cout<<"Rider1: I ride "<<rider1.IRide();
	
	vehicleFactory = new MotorBikeFactoryUnit();
	
	Rider rider2(vehicleFactory);
	cout<<"Rider2: I ride "<<rider2.IRide();	
	
	// don't forget to delete the allocated heap objects or better use RAII
	return 0;
}