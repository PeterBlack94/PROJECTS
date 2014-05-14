#include "stdafx.h"
#include "CProjection.h"


CProjection::CProjection()
{
	__time32_t long_time;
	_time32(&long_time);
	errno_t err;
	err = _localtime32_s(&tm_projection_time, &long_time);

	usi_movie_number = 0;
	usi_cinema_room_number = 0;
	//POBRANIE ROZK£ADU SALI NR .... ! ! ! !
}

CProjection::CProjection(tm tm_projection_time, unsigned short int usi_movie_number, unsigned short int usi_cinema_room_number)
{
	this->tm_projection_time = tm_projection_time;
	this->usi_movie_number = usi_movie_number;
	this->usi_cinema_room_number = usi_cinema_room_number;
	//POBRANIE ROZK£ADU SALI NR .... ! ! ! !
}


CProjection::~CProjection() {}

void CProjection::set_tm_projection_time(tm tm_projection_time){ this->tm_projection_time = tm_projection_time; }
void CProjection::set_usi_movie_number(unsigned short int usi_movie_number){ this->usi_movie_number = usi_movie_number; }
void CProjection::set_usi_cinema_room_number(unsigned short int usi_cinema_room_number){ this->usi_cinema_room_number = usi_cinema_room_number; }
void CProjection::set_cinema_room(CCinema_Room cinema_room){ this->cinema_room = cinema_room; }

tm CProjection::get_tm_projection_time(){ return tm_projection_time; }
unsigned short int CProjection::get_usi_movie_number(){ return usi_movie_number; }
unsigned short int CProjection::get_usi_cinema_room_nuber(){ return usi_cinema_room_number; }
CCinema_Room CProjection::get_cinema_room(){ return cinema_room; }