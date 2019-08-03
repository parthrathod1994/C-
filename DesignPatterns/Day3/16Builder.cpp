#include<iostream>
#include<string>
using namespace std;

namespace nm16
{
	class Vehicle
	{
	public:
		string Manufacturer;
		string Wheels;
		string Steering;
		string Body;
		string Engine;
		string WindShield;
		virtual void Display() = 0;
		operator Vehicle*()
		{
			return this;
		}
	};

	class Manufacturer
	{
	protected:
		string name;
		Vehicle *vehicle;
		Manufacturer(string name) :name(name)
		{

		}
	public:
		void Set_vehicle(Vehicle *vehicle)
		{
			this->vehicle = vehicle;
			vehicle->Manufacturer = name;
		}
		virtual void Set_Wheels() = 0;
		virtual void Set_Steering() = 0;
		virtual void Set_Body() = 0;
		virtual void Set_Engine() = 0;
		virtual void Set_WindShield() = 0;
		operator Manufacturer*()
		{
			return this;
		}
	};

	class Car :public Vehicle
	{
	public:
		void Display()
		{
			cout << "Car manufactured by ___" << Manufacturer << "__________" << endl;
			cout << "Wheels --> " << Wheels << endl;
			cout << "Steering --> " << Steering << endl;
			cout << "Body --> " << Body << endl;
			cout << "engine --> " << Engine << endl;
			cout << "WindShield --> " << WindShield << endl;
			cout << "__________________________________________" << endl;
		}
	};

	class Truck :public Vehicle
	{
	public:
		void Display()
		{
			cout << "Truck manufactured by ___" << Manufacturer << "__________" << endl;
			cout << "Wheels --> " << Wheels << endl;
			cout << "Steering --> " << Steering << endl;
			cout << "Body --> " << Body << endl;
			cout << "engine --> " << Engine << endl;
			cout << "WindShield --> " << WindShield << endl;
			cout << "__________________________________________" << endl;
		}
	};



	class MercedezCar :public Manufacturer
	{
	public:
		MercedezCar() :Manufacturer("MercedezCars")
		{
		}
		virtual void Set_Wheels()
		{
			vehicle->Wheels = "Alloy Of Steel and Iron";
		}
		virtual void Set_Steering()
		{
			vehicle->Steering = "Plastics of WI";
		}
		virtual void Set_Body()
		{
			vehicle->Body = "Steel and plastic blend";
		}
		virtual void Set_Engine()
		{
			vehicle->Engine = "4Stroke with turbo jet";
		}
		virtual void Set_WindShield()
		{
			vehicle->WindShield = "Glass from Belgium";
		}
	};



	class TataCar :public Manufacturer
	{
	public:
		TataCar() :Manufacturer("TataCars")
		{
		}
		virtual void Set_Wheels()
		{
			vehicle->Wheels = "Iron Wheels";
		}
		virtual void Set_Steering()
		{
			vehicle->Steering = "Plastics Recycled";
		}
		virtual void Set_Body()
		{
			vehicle->Body = "Plastic ";
		}
		virtual void Set_Engine()
		{
			vehicle->Engine = "4Stroke without turbo jet";
		}
		virtual void Set_WindShield()
		{
			vehicle->WindShield = "Glass from Bengal";
		}
	};


	class TataTruck :public Manufacturer
	{
	public:
		TataTruck() :Manufacturer("TataTrucks")
		{
		}
		virtual void Set_Wheels()
		{
			vehicle->Wheels = "Steel Truck Wheels with MRF Tyres";
		}
		virtual void Set_Steering()
		{
			vehicle->Steering = "Iron Steering with plastic grip";
		}
		virtual void Set_Body()
		{
			vehicle->Body = "Iron Body ";
		}
		virtual void Set_Engine()
		{
			vehicle->Engine = "Truck Engine from italy ";
		}
		virtual void Set_WindShield()
		{
			vehicle->WindShield = "Glass form local";
		}
	};


	//mercedez
	//tata
	//hyundai

	class Director
	{
	public:
		static void ConstructionFlow(Vehicle * vehicle, Manufacturer *manufacturer)
		{
			manufacturer->Set_vehicle(vehicle);
			manufacturer->Set_Wheels();
			manufacturer->Set_Body();
			manufacturer->Set_Engine();
			manufacturer->Set_Steering();
			manufacturer->Set_WindShield();
		}
	};


	void main()
	{
		Car car;
		Truck truck;
		MercedezCar mercCarBuilder;
		TataTruck tataTruckBuilder;
		TataCar tatCarBuilder;

		Director::ConstructionFlow(truck, tataTruckBuilder);

		truck.Display();
	}
}