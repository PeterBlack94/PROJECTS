#pragma once
#include <ctime>
#include "CCinema_Room.h"
class CProjection
{
protected:
	tm tm_projection_time;
	unsigned short int usi_movie_number;
	unsigned short int usi_cinema_room_number;
	CCinema_Room cinema_room;
	
public:
	CProjection();
	CProjection(tm,unsigned short int,unsigned short int, CCinema_Room);
	virtual ~CProjection();

	void set_tm_projection_time(tm);
	void set_usi_movie_number(unsigned short int);
	void set_usi_cinema_room_number(unsigned short int);
	void set_cinema_room(CCinema_Room);

	tm get_tm_projection_time();
	unsigned short int get_usi_movie_number();
	unsigned short int get_usi_cinema_room_number();
	CCinema_Room get_cinema_room();

	CProjection& operator=(CProjection const&);
};

