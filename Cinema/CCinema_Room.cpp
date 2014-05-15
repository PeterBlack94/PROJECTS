#include "stdafx.h"
#include "CCinema_Room.h"

CCinema_Room::CCinema_Room()
{
	room_array = { 1, 1 };
	bool b_if_3d = 0;
	ppP_room = new place*[room_array.ui_line];
	for (unsigned int i = 0; i < room_array.ui_line; ++i)
		ppP_room[i] = new place[room_array.ui_column];

	for (unsigned int i = 0; i < room_array.ui_line; ++i)
		for (unsigned int j = 0; j < room_array.ui_column; ++j)
			ppP_room[i][j] = BUSY;
}


CCinema_Room::CCinema_Room(::room_array room_array, bool b_if_3d)
{
	this->room_array = room_array;
	this->b_if_3d = b_if_3d;
	ppP_room = new place*[room_array.ui_line];
	for (unsigned int i = 0; i < room_array.ui_line; ++i)
		ppP_room[i] = new place[room_array.ui_column];

	for (unsigned int i = 0; i < room_array.ui_line;++i)
	for (unsigned int j = 0; j < room_array.ui_column; ++j)
		ppP_room[i][j] =FREE;
}

CCinema_Room::CCinema_Room(::room_array room_array, bool b_if_3d, place** ppP_room)
{
	this->room_array = room_array;
	this->b_if_3d = b_if_3d;
	this->ppP_room = ppP_room;
}

CCinema_Room::~CCinema_Room()
{
	for (unsigned int i = 0; i < room_array.ui_line; ++i)
		delete[] ppP_room[i];
		
	delete[] ppP_room;
}

void CCinema_Room::set_room_array(::room_array room_array) { this->room_array = room_array; }
void CCinema_Room::set_b_if_3d(bool b_if_3d) { this->b_if_3d = b_if_3d; }
void CCinema_Room::set_ppP_room(place** ppP_room){ this->ppP_room = ppP_room; }
bool CCinema_Room::set_place(unsigned int ui_line, unsigned int ui_column, place P_place)
{
	if (ui_line >= (this->room_array.ui_line) && ui_column >= (this->room_array.ui_column)) return false;
	else
	{
		ppP_room[ui_line][ui_column] = P_place;
		return true;
	}
}

::room_array CCinema_Room::get_room_array() { return room_array; }
bool CCinema_Room::get_b_if_3d() { return b_if_3d; }
place** CCinema_Room::get_ppP_room() { return ppP_room; }
place CCinema_Room::get_place(unsigned int ui_line, unsigned int ui_column) 
{
	if (ui_line < (this->room_array.ui_line) && ui_column < (this->room_array.ui_column)) return ppP_room[ui_line][ui_column];
	else return ERROR;
}

CCinema_Room& CCinema_Room::operator=(CCinema_Room& cinema_room)
{
	if (this != &cinema_room)
	{
		for (unsigned int i = 0; i < room_array.ui_line; ++i)
			delete[] ppP_room[i];
		delete[] ppP_room;
		ppP_room = NULL;
	}
	
	room_array = cinema_room.room_array;
	b_if_3d = cinema_room.b_if_3d;
	
	ppP_room = new place*[room_array.ui_line];
	for (unsigned int i = 0; i < room_array.ui_line; ++i)
		ppP_room[i] = new place[room_array.ui_column];

	for (unsigned int i = 0; i < room_array.ui_line;++i)
	for (unsigned int j = 0; j < room_array.ui_column; ++j)
		ppP_room[i][j] = cinema_room.get_place(i, j);
	
	return *this;
}