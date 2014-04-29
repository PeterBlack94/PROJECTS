#include "stdafx.h"
#include "CMovie.h"


CMovie::CMovie()
{
	s_title = "Title...";
	s_production = "Production...";
	s_director = "Director...";
	s_scenario = "Scenario...";
	s_description = "Description...";
	s_cast = "Cast...";
	b_if_3d = 0;
	b_if_dubbing = 0;
	b_if_premiere = 0;
	ui_minimal_age = 18;
	ui_duration = 0;
}

CMovie::CMovie(string s_title, string s_production,string s_director, string s_scenario, string s_description, string s_cast, bool b_if_3d,bool b_if_dubbing,bool b_if_premiere,unsigned int ui_minimal_age,unsigned int ui_duration)
{
	this->s_title = s_title;
	this->s_production = s_production;
	this->s_director = s_director;
	this->s_scenario = s_scenario;
	this->s_description = s_description;
	this->s_cast = s_cast;
	this->b_if_3d = b_if_3d;
	this->b_if_dubbing = b_if_dubbing;
	this->b_if_premiere = b_if_premiere;
	this->ui_minimal_age = ui_minimal_age;
	this->ui_duration = ui_duration;
}

CMovie::~CMovie()
{
}

void CMovie::set_s_title(string s_title){ this->s_title = s_title; }
void CMovie::set_s_production(string s_production){ this->s_production = s_production; }
void CMovie::set_s_director(string s_director){ this->s_director = s_director; }
void CMovie::set_s_scenario(string s_scenario){ this->s_scenario = s_scenario; }
void CMovie::set_s_description(string s_description){ this->s_description = s_description; }
void CMovie::set_s_cast(string s_cast){ this->s_cast = s_cast; }
void CMovie::set_b_if_3d(bool b_if_3d){ this->b_if_3d = b_if_3d; }
void CMovie::set_b_if_dubbing(bool b_if_dubbing){ this->b_if_dubbing = b_if_dubbing; }
void CMovie::set_b_if_premiere(bool b_if_premiere){ this->b_if_premiere = b_if_premiere; }
void CMovie::set_ui_minimal_age(unsigned int i_minimal_age){ this->ui_minimal_age = i_minimal_age; }
void CMovie::set_ui_duration(unsigned int i_duration){ this->ui_duration = i_duration; }

string CMovie::get_s_title(){ return s_title; }
string CMovie::get_s_production(){ return s_production; }
string CMovie::get_s_director(){ return s_director; }
string CMovie::get_s_scenario(){ return s_scenario; }
string CMovie::get_s_description(){ return s_description; }
string CMovie::get_s_cast(){ return s_cast; }
bool CMovie::get_b_if_3d(){ return b_if_3d; }
bool CMovie::get_b_if_dubbing(){ return b_if_dubbing; }
bool CMovie::get_b_if_premiere(){ return b_if_premiere; }
unsigned CMovie::get_ui_minimal_age(){ return ui_minimal_age; }
unsigned CMovie::get_ui_duration(){ return ui_duration; }