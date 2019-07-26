#include<iostream>
using std::cout;
using std::endl;


class Circle
{
public:
	virtual void DrawCircle()
	{
		cout << "Circle Drawn" << endl;
	}
	virtual void CircleArea()
	{
		cout << "Circle Area" << endl;
	}
};


class Rect
{
public:
	virtual void DrawRect()
	{
		cout << "Rect Drawn" << endl;
	}
	virtual void RectArea()
	{
		cout << "Rect Area" << endl;
	}
};

class Shape:public Circle,public Rect
{

};

void main1()
{
	Shape shape;
	Circle *circle = &shape;
	circle->DrawCircle();
	circle->CircleArea();
	cout << "_______________________________\n";
	Rect *rect =(Rect*) circle;
	rect->DrawRect();
	rect->RectArea();
}

void main2()
{
	Shape shape;
	Circle *circle = &shape;
	circle->DrawCircle();
	circle->CircleArea();
	cout << "_______________________________\n";
	Rect *rect = (Rect*)circle;
	rect++;
	rect->DrawRect();
	rect->RectArea();
}

void main3()
{
	Shape shape;
	Circle *circle = &shape;
	circle->DrawCircle();
	circle->CircleArea();
	cout << "_______________________________\n";
	Rect *rect = (Rect*)(Shape*)circle;
	rect->DrawRect();
	rect->RectArea();
}

void main4()
{
	Shape shape;
	Circle *circle = &shape;
	circle->DrawCircle();
	circle->CircleArea();
	cout << "_______________________________\n";
	Rect *rect = (Shape*)circle;
	rect->DrawRect();
	rect->RectArea();
}
Circle* CreateShape()//factory
{
	static Shape sp;
	return &sp;
}
void main()
{

	Circle *circle = CreateShape();
	circle->DrawCircle();
	circle->CircleArea();
	cout << "_______________________________\n";
	//use polymorphic cast
	//Rect *rect = dynamic_cast<Rect*>(circle);
	Rect *rect = dynamic_cast<Rect*>(circle);
	rect->DrawRect();
	rect->RectArea();
}