#pragma once
#include <string>

using namespace std;

class CMovie
{
protected:
	string s_title;
	string s_production;
	bool b_if_dubbing;
	bool b_if_3d;
	bool b_if_premiere;
	unsigned int ui_minimal_age;
	unsigned int ui_duration;

public:
	CMovie();
	CMovie(string,string,bool,bool, bool,unsigned int,unsigned int);
	virtual ~CMovie();

	void set_s_title(string);
	void set_s_production(string);
	void set_b_if_dubbing(bool);
	void set_b_if_3d(bool);
	void set_b_if_premiere(bool);
	void set_ui_minimal_age(unsigned int);
	void set_ui_duration(unsigned int);

	string get_s_title();
	string get_s_production();
	bool get_b_if_dubbing();
	bool get_b_if_3d();
	bool get_b_if_premiere();
	unsigned int get_ui_minimal_age();
	unsigned int get_ui_duration();
};

