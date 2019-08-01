#include<iostream>
using namespace std;
class Video
{
public:
	virtual void MakeVideo() = 0;
	virtual void AttachVideo() = 0;
};
class Audio
{
public:
	virtual void MakeAudio() = 0;
	virtual void AttachAudio() = 0;
};
class Mag
{
public:
	virtual void MakeMag() = 0;
	virtual void AttachMag() = 0;
};

class Factory
{
public:
	virtual Video* CreateVideo() = 0;
	virtual Audio* CreateAudio() = 0;
	virtual Mag* CreateMag() = 0;
};

class ExpVideo:public Video
{
public:
	void MakeVideo()
	{
		cout << "Exp Video Made\n";
	}
	void AttachVideo()
	{
		cout << "Exp Video Attached\n";
	}
};
class ExpAudio :public Audio
{
public:
	void MakeAudio()
	{
		cout << "Exp Audio Made\n";
	}
	void AttachAudio()
	{
		cout << "Exp Audio Attached\n";
	}
};
class ExpMag:public Mag
{
public:
	void MakeMag()
	{
		cout << "Exp Mag Made\n";
	}
	void AttachMag()
	{
		cout << "Exp Mag Attached\n";
	}
};

class ExpFactory:public Factory
{
public:
	Video* CreateVideo()
	{
		return new ExpVideo();
	}
	Audio* CreateAudio()
	{
		return new ExpAudio();
	}
	Mag* CreateMag()
	{
		return new ExpMag();
	}
};

class ChromeVideo :public Video
{
public:
	void MakeVideo()
	{
		cout << "Chrome Video Made\n";
	}
	void AttachVideo()
	{
		cout << "Chrome Video Attached\n";
	}
};
class ChromeAudio :public Audio
{
public:
	void MakeAudio()
	{
		cout << "Chrome Audio Made\n";
	}
	void AttachAudio()
	{
		cout << "Chrome Audio Attached\n";
	}
};
class ChromeMag :public Mag
{
public:
	void MakeMag()
	{
		cout << "Chrome Mag Made\n";
	}
	void AttachMag()
	{
		cout << "Chrome Mag Attached\n";
	}
};

class ChromeFactory :public Factory
{
public:
	Video* CreateVideo()
	{
		return new ChromeVideo();
	}
	Audio* CreateAudio()
	{
		return new ChromeAudio();
	}
	Mag* CreateMag()
	{
		return new ChromeMag();
	}
};


Factory* CreateFactory(int par)
{
	//Reflection code
	if (10 == par)
		return new ExpFactory();
	return new ChromeFactory();
}


void main()
{
	Factory *factory = CreateFactory(20);
	Video *vid = factory->CreateVideo();
	vid->MakeVideo();
	vid->AttachVideo();
	Audio * aud = factory->CreateAudio();
	aud->MakeAudio();
	aud->AttachAudio();
	Mag *mag = factory->CreateMag();
	mag->MakeMag();
	mag->AttachMag();
}