#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int exit_flag = 0;
	FILE *fp;
	
	char name[200];
	char place[100], typeName[100];	
	size_t size;
	int month;
	int day;
	int type;
	void *list;
	void *ndPtr;
	void *schedInfo;
	int option;
	int line;											//for
	int	i;												//for문을 위한 변수 
	
	//1. FILE pointer open & error handling
	//fill code here ----
	
	//FILE *fp = fopen("schedule.txt", "r");				//open the file pointer for read mode
	if ((fp = fopen("schedule.txt", "r")) == NULL)										//error handling code
   {
   		printf("FILE OPEN ERROR!\n");
    	return -1;										
	}
	
	//initializing the list
	printf("Reading the data files... \n");
	list = (void*)list_genList();
	
	
	//2. read from the file
	while (fscanf(fp, "%c %i %i %i %c\n", name, &type, &month, &day, place)!=EOF)	/* fill code here -- read from the file*/		//reading the file until there's no blank
	{																						
		schedInfo = sched_genSchedInfo(name, place, type, month, day);								//fill code here -- generate genSchedInfo structure by genSchedInfo function
		line++;																						//the number of schedule 
		//put the scheduling info instance generated by genSchedInfo function
		list_addTail(schedInfo, list);
	}
	
	
	fclose(fp);											//fill code here ---- close the file pointer
	printf("Read done! %i schedules are read\n", list_len(list));
	
	
	//program starts
	while(exit_flag == 0) 
	{
		//3. menu printing
		printf("1.Print all the schedules\n");			//fill code here ---- 
		printf("2.Search for schedules in the month\n");
		printf("3.Search for schedules in the place\n");
		printf("4.search for specific type schedule\n");
		printf("5.exit\n");
		
		//4. get option from keyboard
		printf("\nSELECT AN OPTION :");					//fill code here ----
		scanf("%i", &option);
		
		
		switch(option)
		{
			case 1: //print all the schedules
				printf("printing all the schedules in the scheduler.....\n\n\n");
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0)
				{
					for(i = 1; i<line ;i++)										//count the schedule number????????????????????????????????
																	//file code here -- print count and each scheduling info element
					
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					//fill code this part - end
					
					//print the schedule in blank= object ?????????????
				}
				
				break;
				
			case 2:
				printf("which month ? : ");
				scanf("%i", &month);
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0)
				{
					//file code here -- print scheduling info elements matching to the month
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					//fill code this part - end
				}
				
				break;
				
			case 3:
				printf("which place ? : ");
				scanf("%s", place);
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0)
				{
					//file code here -- print scheduling info elements matching to the place
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					for(i=0;i<line;i++)							//fill code this part - end
					{
						if(strcmp(place, schedInfo[i]->place)==0)		//입력값이랑 스케줄 내용이 같은동안에 
							printf("&i.	", i); 
							sched_print(/**/);						//스케줄을출력한다 
						 
					}
				}
				
				break;
				
			case 4:
				printf("which type ?\n");
				sched_printTypes();
				printf("your choice : ");
				scanf("%s", typeName);
				
				if (/* fill code here -- convert the type and check if the type is valid */)
				{
					ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)
					{
						//file code here -- print scheduling info elements matching to the place
						ndPtr = list_getNextNd(ndPtr); //get the next node from the list
						schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
						
						//fill code this part - end
					}
				}
				else
				{
					printf("wrong type name!\n");
				}
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
		
	}
	
	return 0;
}
