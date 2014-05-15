#pragma once

struct room_array
{
	unsigned int ui_line;
	unsigned int ui_column;
};

enum place {NO_SEAT='-', BUSY = 'X', FREE = 'O', SOFA_LEFT = 'L', SOFA_RIGHT = 'R', ERROR ='E'};

class CCinema_Room
{
protected:
	::room_array room_array;
	bool b_if_3d;
	place** ppP_room;

public:
	CCinema_Room();
	CCinema_Room(::room_array, bool);
	CCinema_Room(::room_array, bool, place** ppP_room);
	~CCinema_Room();

	void set_room_array(::room_array);
	void set_b_if_3d(bool);
	void set_ppP_room(place**);
	bool set_place(unsigned int, unsigned int,place);

	::room_array get_room_array();
	bool get_b_if_3d();
	place** get_ppP_room();
	place get_place(unsigned int,unsigned int);

	CCinema_Room& operator= (CCinema_Room&);
};

