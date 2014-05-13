#pragma once
#include "CCinema_Room.h"
#include "CMovie.h"
#include "CProjection.h"
#include "CReservation.h"
#include "CTicket.h"
#include "CWorker.h"
#include <fstream>
class CCinema
{
private:
	static CCinema* p_Cinema;
	static CCinema_Room* p_Cinema_Room;
	static CTicket* p_Ticket;
	static CMovie* p_Movie;
	static CWorker* p_Worker;
	static CProjection* p_Projection;
	static CReservation* p_Reservation;

	CCinema();

public:
	~CCinema();
	static CCinema* Cinema();

};

