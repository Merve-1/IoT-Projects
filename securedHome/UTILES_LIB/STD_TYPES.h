/* Documentation
 * Software component : STD_TYPES.h
 * Created: 4/8/2024 7:48:21 PM
 * Author: NotFound
 * Version : 1.0
 * VersionDescription: no description yet 
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// Boolean type definition
/*typedef unsigned char bool;
#define true  1
#define false 0
*/
typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;


typedef unsigned long int u32;
typedef signed long int s32;

typedef float f32;
typedef double f64;

// for unit testing part 
typedef enum {
	false, true
	}BOOL;
	
//address to zero 
#define NULL (void*)0
#endif /* STD_TYPES_H_ */