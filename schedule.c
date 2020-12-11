#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

#define MAX_TYPE		7

//strings for printing the name of each enum element
//enum type's name
char type_string[MAX_TYPE][20] = 
{
	"drama",
	"movie",
	"advertisement",
	"entertainment",
	"meeting",
	"fitness",
	"privacy"
};

//month's name
char month_string[13][4] = 
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

//enum definitions
typedef enum scheduleType {
	drama=0, 		//드라마 
	movie, 			//영화 
	advertisement, 	//광고 
	entertainment, 	//예능 
	meeting,		//회의 
	fitness,		//운동 
	privacy			//개인사 
} scheduleType_e;



//structure definition for a schedule info.
typedef struct schedInfo
{
	char name[200];			//schedule name
	scheduleType_e type;	//schedule type
	int month;				//when : month
	int day;				//when : day
	char place[100];		//where
} schedInfo_t;


void sched_printTypes(void) 
{
	int i;
	
	for (i=0;i<MAX_TYPE;i++) {
		printf("- %s\n", i, type_string[i]);
	}
}

void sched_print(void* obj) 
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	printf("Schedule Name : %s (%s)\n", schedPtr->name, type_string[schedPtr->type]);
	printf("When : %s. %i\n", month_string[schedPtr->month], schedPtr->day);
	printf("Where : %s\n", schedPtr->place);
	
	return;
}



//generating a structure of scheduling information
void* sched_genSchedInfo(char* name, char* place, int type, int month, int day)
{
	schedInfo_t *schedPtr;
	schedPtr = (schedInfo_t*)malloc(5*sizeof(schedInfo_t));					//allocate memory						

	if(schedPtr == NULL)																	//error handler
	{
		printf("memory allocation error!\n");
		return	-1;
	}
	
	strcpy(schedPtr->name, name)	;																//and set the member variables
	strcpy(schedPtr->place, place)	;
	schedPtr->type = type 	;
	schedPtr->month = month	;
	schedPtr->day = day 	;
//	printf("it's running!!\n\n\n'");
	return (void*)schedPtr;
}



//get month information from the scheduler info structure
float sched_getMonth(void* obj)
{
	float get_month;																					
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if(schedPtr == NULL)														//error handler
	{
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	get_month = schedPtr->month	;												//get month information																				
	
	return get_month;															//for comparing in main.c ; return the value of get_month

}


//get type information from the scheduler info structure
int sched_getType(void* obj)
{
	int get_type;																					
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if(schedPtr == NULL)														//error handler
	{
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	get_type = schedPtr->type;													//get type information																				
	
	return get_type;															//for comparing in main.c ; return the value of get_type
}



//get place string information from the scheduler info structure
char* sched_getPlace(void* obj)
{
	char* get_place;																					
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if(schedPtr == NULL)															//error handler
	{
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	get_place = schedPtr->place;													//get place information																				
	
	return get_place;																//for comparing in main.c ; return the value of get_place
}


//convert the name of the type into the enum(integer) value
int sched_convertType(char* typeName)
{	
		
	int integer;							//convertied value	

	if(typeName == "drama")	
		integer = 0;
	else if(typeName == "movie")
		integer = 1;
	else if(typeName == "advertisement")
		integer = 2;
	else if(typeName == "entertainment")
		integer = 3;
	else if(typeName == "meeting")
		integer = 4;
	else if(typeName == "fitness")
		integer = 5;
	else if(typeName == "privacy")
		integer = 6;
			
	return integer;
}

