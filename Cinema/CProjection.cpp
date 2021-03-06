#include "stdafx.h"
#include "CProjection.h"
#include "CCinema.h"

CProjection::CProjection()
{
	__time32_t long_time;
	_time32(&long_time);
	errno_t err;
	err = _localtime32_s(&tm_projection_time, &long_time);

	usi_movie_number = 0;
	usi_cinema_room_number = 0;
	cinema_room = CCinema::Cinema()->get_p_Cinema_Room(0);
}

CProjection::CProjection(tm tm_projection_time, unsigned short int usi_movie_number, unsigned short int usi_cinema_room_number, CCinema_Room* cinema_room)
{
	this->tm_projection_time = tm_projection_time;
	this->usi_movie_number = usi_movie_number;
	this->usi_cinema_room_number = usi_cinema_room_number;
	this->cinema_room = cinema_room;
}

CProjection::~CProjection() {}

void CProjection::set_tm_projection_time(tm tm_projection_time){ this->tm_projection_time = tm_projection_time; }
void CProjection::set_usi_movie_number(unsigned short int usi_movie_number){ this->usi_movie_number = usi_movie_number; }
void CProjection::set_usi_cinema_room_number(unsigned short int usi_cinema_room_number){ this->usi_cinema_room_number = usi_cinema_room_number; }
void CProjection::set_cinema_room(CCinema_Room* cinema_room){ this->cinema_room = cinema_room; }

tm CProjection::get_tm_projection_time(){ return tm_projection_time; }
unsigned short int CProjection::get_usi_movie_number(){ return usi_movie_number; }
unsigned short int CProjection::get_usi_cinema_room_number(){ return usi_cinema_room_number; }
CCinema_Room* CProjection::get_cinema_room(){ return cinema_room; }

CProjection& CProjection::operator=(CProjection& projection)
{
	tm_projection_time = projection.tm_projection_time;
	usi_movie_number = projection.usi_movie_number;
	usi_cinema_room_number = projection.usi_cinema_room_number;
	cinema_room = projection.cinema_room;
	return *this;
}

bool operator>(tm& tm_time_left, tm& tm_time_right)
{
	if (tm_time_left.tm_year > tm_time_right.tm_year) return true;
	else if (tm_time_left.tm_year < tm_time_right.tm_year) return false;
		else if (tm_time_left.tm_mon > tm_time_right.tm_mon) return true;
			else if (tm_time_left.tm_mon < tm_time_right.tm_mon) return false;
				else if (tm_time_left.tm_mday > tm_time_right.tm_mday) return true;
					else if (tm_time_left.tm_mday < tm_time_right.tm_mday) return false;
						else if (tm_time_left.tm_hour > tm_time_right.tm_hour) return true;
							else if (tm_time_left.tm_hour < tm_time_right.tm_hour) return false;
								else if (tm_time_left.tm_min > tm_time_right.tm_min) return true;
									else return false;
}

bool operator<(tm& tm_time_left, tm& tm_time_right)
{
	if (tm_time_left.tm_year < tm_time_right.tm_year) return true;
	else if (tm_time_left.tm_year > tm_time_right.tm_year) return false;
		else if (tm_time_left.tm_mon < tm_time_right.tm_mon) return true;
			else if (tm_time_left.tm_mon > tm_time_right.tm_mon) return false;
				else if (tm_time_left.tm_mday < tm_time_right.tm_mday) return true;
					else if (tm_time_left.tm_mday > tm_time_right.tm_mday) return false;
						else if (tm_time_left.tm_hour < tm_time_right.tm_hour) return true;
							else if (tm_time_left.tm_hour > tm_time_right.tm_hour) return false;
								else if (tm_time_left.tm_min < tm_time_right.tm_min) return true;
									else return false;
}

bool CProjection::Free_places(unsigned short int usi_tickets_number)
{
	unsigned int ui_counter = 0;
	for (unsigned int i = 0; i < get_cinema_room()->get_room_array().ui_line;++i)
	for (unsigned int j = 0; j < get_cinema_room()->get_room_array().ui_column; ++j)
	{
		if (get_cinema_room()->get_place(i, j) == FREE)
			++ui_counter;
	}
	if (ui_counter >= usi_tickets_number) return true;
	else
	{
		cout << "BRAK WOLNYCH MIEJSC !" << endl;
		cout << "Ilo�� wolnych miejsc: " << ui_counter;
		return false;
	}
}	