#pragma once
#include <ctime>
#include "CCinema_Room.h"

class CProjection
{
protected:
	tm tm_projection_time;
	unsigned short int usi_cinema_room_number;
	CCinema_Room cinema_room;
	
public:
	CProjection();
	CProjection(tm,unsigned short int, CCinema_Room);
	~CProjection();
};

