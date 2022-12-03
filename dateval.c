/**************************************************
    dateval.c
    Chanon Khanijoh
    63070503408
	
	This program test the function dateValidation 
	which is to be put in main program later on.
***************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1//TRUE will always equal to 1
#define FALSE 0// FALSE will always equal to 0

char stringInput[128];

void dateValidation(char stringToCheck[])
{
	char datestring[3];
	char monthstring[4];
	char yearstring[5];
	int idate;
	int iyear;
	
	if(strlen(stringToCheck) == 11)
	{
		if(isdigit(stringToCheck[0]) && isdigit(stringToCheck[1]))
		{	
			datestring[0]=stringToCheck[0];
			datestring[1]=stringToCheck[1];
			datestring[2]=0;
			yearstring[0]=stringToCheck[7];
			yearstring[1]=stringToCheck[8];
			yearstring[2]=stringToCheck[9];
			yearstring[3]=stringToCheck[10];
			yearstring[4]=0;

			iyear=atoi(yearstring);
			idate=atoi(datestring);
			
			if(stringToCheck[2] == 32 && stringToCheck[6] == 32)
			{
				monthstring[0]=stringToCheck[3];
				monthstring[1]=stringToCheck[4];
				monthstring[2]=stringToCheck[5];
				monthstring[3]=0;
				
				if(strcmp(monthstring,"JAN") == 0 || strcmp(monthstring,"FEB") == 0 || strcmp(monthstring,"MAR") == 0 || strcmp(monthstring,"APR") == 0 
				   || strcmp(monthstring,"MAY") == 0 || strcmp(monthstring,"JUN") == 0 || strcmp(monthstring,"JUL") == 0 || strcmp(monthstring,"AUG") == 0 
				   || strcmp(monthstring,"SEP") == 0 || strcmp(monthstring,"OCT") == 0 || strcmp(monthstring,"NOV") == 0 || strcmp(monthstring,"DEC") == 0)
				{
					if(isdigit(stringToCheck[7]) && isdigit(stringToCheck[8]) && isdigit(stringToCheck[9]) && isdigit(stringToCheck[10]))
					{
						if(iyear >= 1920 && iyear <= 2120)
						{			
							if(iyear%4 == 0 && strcmp(monthstring,"FEB") == 0 )
							{
								if(idate >=1 && idate <=29)
								{
									printf("The date you enter is valid\n");
								}
								else
								{
									printf("There are only 29 days in FEB this year\n");
								}
							}
							else if(strcmp(monthstring,"JAN") == 0 || strcmp(monthstring,"MAR") == 0 || strcmp(monthstring,"MAY") == 0 || strcmp(monthstring,"JUL") == 0 
									|| strcmp(monthstring,"AUG") == 0 || strcmp(monthstring,"OCT") == 0 || strcmp(monthstring,"DEC") == 0)
							{
								if(idate >=1 && idate <=31)
								{
									printf("The date you enter is valid\n");
								}
								else
								{
									printf("There are only 31 days in the month you entered\n");
								}
							}
							else if(strcmp(monthstring,"APR") == 0 || strcmp(monthstring,"JUN") == 0 
									|| strcmp(monthstring,"SEP") == 0 || strcmp(monthstring,"NOV") == 0)
							{
								if(idate >=1 && idate <=30)
								{
									printf("The date you enter is valid\n");
								}
								else
								{
									printf("There are only 30 days in the month you entered\n");
								}
							}
							else if(strcmp(monthstring,"FEB") == 0)
							{
								if(idate >=1 && idate <=28)
								{
									printf("The date you enter is valid\n");
								}
								else
								{
									printf("There are only 28 days in FEB this year\n");
								}
							}
						}
						else
						{
							printf("Year should be 100 years before and after today year\n");
						}
					}
					else
					{
						printf("Year should be 4 digits number\n");
					}
				}
				else
				{
					printf("Incorrect Month input(MMM only)\n");
				}
			}
			else
			{
				printf("Space in between DD and MMM and YYYY\n");
			}
		}
		else
		{
			printf("Date should be 2 digits\n");
		}
	}
	else
	{
		printf("Should be in DD MMM YYYY format\n");
	}
}

int main()
{
	char date_input[128];
	
	while(-1)
	{
		memset(date_input, 0, sizeof(date_input));
		
		printf("please input date(DD MMM YYYY):");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%[^\n]", date_input);
		
		if(strcmp(date_input, "") == 0)
		{
			exit(0);
		}
		
		dateValidation(date_input);
		
	}
}