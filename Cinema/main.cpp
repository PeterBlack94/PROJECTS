// Cinema.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CCinema.h"
#include "CCinema_Room.h"
#include "CHuman.h"
#include "CMovie.h"
#include "CProjection.h"
#include "CTicket.h"
#include "CWorker.h"
#include "CReservation.h"
#include <locale.h>
#include <cstdlib>

// CProjection - zaczête...

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Polish");
	CCinema::Cinema();
	CCinema::Initialization();
	for (unsigned short int i = 0; i < 7;++i)
	cout <<CCinema::Cinema()->get_p_Ticket(0)->get_b_validity(i) << " ";
	cout << endl;
	CCinema::Finish();
	delete CCinema::Cinema();
	return 0;
}

