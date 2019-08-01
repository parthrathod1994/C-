#include<iostream>
#include<map>
#include<string>
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


class ExpVideo :public Video
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
class ExpMag :public Mag
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

map<string, map<string, void*>> repo;

void Register(string key1, string key2, void* pf)
{
	repo[key1][key2] = pf;
}

Video* CreateExpVideo()
{
	return new ExpVideo();
}
Audio* CreateExpAudio()
{
	return new ExpAudio();
}
Mag* CreateExpMag()
{
	return new ExpMag();
}

Video* CreateChromeVideo()
{
	return new ChromeVideo();
}
Audio* CreateChromeAudio()
{
	return new ChromeAudio();
}
Mag* CreateChromeMag()
{
	return new ChromeMag();
}

class Dummy
{
public:
	Dummy()
	{
		Register("exp", "vid", CreateExpVideo);
		Register("exp", "aud", CreateExpAudio);
		Register("exp", "mag", CreateExpMag);
		Register("crm", "vid", CreateChromeVideo);
		Register("crm", "aud", CreateChromeAudio);
		Register("crm", "mag", CreateChromeMag);
	}
}dummy;

map<string,void*> CreateFactory(string par)
{
	return repo[par];
}



void main()
{
	map<string, void*> lRep=CreateFactory("crm");
	Video *vid = ((Video*(*)())lRep["vid"])();
	vid->MakeVideo();
	vid->AttachVideo();
	Audio * aud =  ((Audio*(*)())lRep["aud"])();
	aud->MakeAudio();
	aud->AttachAudio();
	Mag *mag = ((Mag*(*)())lRep["mag"])();
	mag->MakeMag();
	mag->AttachMag();
}