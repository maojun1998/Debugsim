#ifndef __CMDTRANS_H__  //__CMDTRANS_H__
#define __CMDTRANS_H__

/*
 *      Conts Var define.
 */

#define BLANK   ((char)' ')

/*
 *	Status const var.
 */

typedef char Status;

#define STATUS_OK		((Status)0 )	// execl ok.
#define STATUS_FL		((Status)-1)	// execl fail.

/*
 *	Interface for cmdtrans.
 */

void cmdtrans(char *buffer);

#endif  //__CMDTRANS_H__