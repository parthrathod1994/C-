#include<iostream>
using namespace std;
namespace nm12
{
	class IOutput
	{
	public:
		virtual void Click() = 0;
		virtual void Drag() = 0;
		virtual void DoubleClick() = 0;
		operator IOutput*()
		{
			return this;
		}
	};

	class Screen :public IOutput
	{
	public:
		virtual void Click()
		{
			cout << "Screen is selected " << endl;
		}
		virtual void Drag()
		{
			cout << "Screen is Moved " << endl;
		}
		virtual void DoubleClick()
		{
			cout << "Screen is minimized " << endl;
		}
	};
	class Audio :public IOutput
	{
	public:
		virtual void Click()
		{
			cout << "Audio Oink " << endl;
		}
		virtual void Drag()
		{
			cout << "Audio Screetch " << endl;
		}
		virtual void DoubleClick()
		{
			cout << "Audio Doubled" << endl;
		}
	};

	class InputDevice
	{
	protected:
		IOutput *output = NULL;
	public:
		/*InputDevice& operator=(IOutput *output)
		{
			this->output = output;
			return *this;
		}*/
		void SetOutput(IOutput *output)
		{
			this->output = output;
		}
	};

	class Mouse :public InputDevice
	{
	public:
		void Click()
		{
			output->Click();
		}
		void Drag()
		{
			output->Drag();
		}
		void DoubleClick()
		{
			output->DoubleClick();
		}
	};

	class Gestures :public InputDevice
	{
	public:
		void Tap()
		{
			output->Click();
		}
		void Pinch()
		{
			output->DoubleClick();
		}
		void Pan()
		{
			output->Drag();
		}
	};



	void main()
	{
		Screen scr;
		Audio aud;

		Gestures ges;
		Mouse mouse;

		//ges = scr;
		ges.SetOutput(scr);

		ges.Tap();
		ges.Pan();
		ges.Pinch();
		cout << "______________________" << endl;
		mouse.SetOutput(aud);
		mouse.Click();
		mouse.DoubleClick();
		mouse.Drag();
		cout << "______________________" << endl;
		mouse.SetOutput(scr);
		mouse.Click();
		mouse.DoubleClick();
		mouse.Drag();
		cout << "______________________" << endl;
		ges.SetOutput(aud);

		ges.Tap();
		ges.Pan();
		ges.Pinch();
	}
}