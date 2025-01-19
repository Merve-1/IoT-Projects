
/*
 * interface.h
 *
 * Created: 5/6/2024 11:17:11 PM
 *  Author: NotFound
 */ 



#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define KPD_NOT_PRESSED		0xff	//255 

/************************************************************************/
/*							APIS PROTO TYPES                            */
/************************************************************************/

void KPD_voidInit		(void);
void KPD_GetValue		(u8* copy_pu8ReturnedValue);




#endif /* KPD_INTERFACE_H_ */