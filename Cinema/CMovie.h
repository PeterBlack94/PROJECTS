#pragma once
#include <string>

using namespace std;

class CMovie
{
private:
	string s_title;
	string s_production;
	string s_director;
	string s_scenario;
	string s_cast;
	string s_description;
	bool b_if_dubbing;
	bool b_if_3d;
	bool b_if_premiere;
	unsigned int ui_minimal_age;
	unsigned int ui_duration;

public:
	CMovie();
	CMovie(string,string,string,string,string,string,bool,bool, bool,unsigned int,unsigned int);
	virtual ~CMovie();

	void set_s_title(string);
	void set_s_production(string);
	void set_s_director(string);
	void set_s_scenario(string);
	void set_s_cast(string);
	void set_s_description(string);
	void set_b_if_dubbing(bool);
	void set_b_if_3d(bool);
	void set_b_if_premiere(bool);
	void set_ui_minimal_age(unsigned int);
	void set_ui_duration(unsigned int);

	string get_s_title();
	string get_s_production();
	string get_s_director();
	string get_s_scenario();
	string get_s_cast();
	string get_s_description();
	bool get_b_if_dubbing();
	bool get_b_if_3d();
	bool get_b_if_premiere();
	unsigned int get_ui_minimal_age();
	unsigned int get_ui_duration();
};

