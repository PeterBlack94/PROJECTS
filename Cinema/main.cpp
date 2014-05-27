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

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Polish");
	srand(time(NULL));
	using namespace std;

	CCinema::Cinema();
	CCinema::Initialization();
	CCinema::ClearProjections();

	CCinema::ShowMenu();

	CCinema::ClearProjections();
	CCinema::Finish();
	delete CCinema::Cinema();
	return 0;
}

