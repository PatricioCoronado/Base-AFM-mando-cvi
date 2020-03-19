#include <cvirte.h>		
#include <userint.h>
#include "mando.h"

static int mando;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((mando = LoadPanel (0, "mando.uir", MANDO)) < 0)
		return -1;
	DisplayPanel (mando);
	RunUserInterface ();
	DiscardPanel (mando);
	return 0;
}
