/**************************************************
    nameval.c
    Chanon Khanijoh
    63070503408
	
	This program test the function nameValidation 
	which is to be put in main program later on.
***************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1//TRUE will always equal to 1
#define FALSE 0// FALSE will always equal to 0

char stringInput[128];
int titleval = FALSE;
int fNameval = FALSE;
int lNameval = FALSE;
int fpunct = TRUE;
int lpunct = TRUE;

void nameValidation(char stringToCheck[])
{
	char title[128];
	char fName[128];
	char lName[128];
	
	sscanf(stringToCheck,"%s %s %s",title,fName,lName);
	
	for(int i = 0; i < strlen(stringToCheck); i++)
	{
		title[i] = tolower(title[i]);
	}

	if(strcmp(title,"mr.") == 0 || strcmp(title,"ms.") == 0 || strcmp(title,"miss") == 0 
	   || strcmp(title,"mrs.") == 0 || strcmp(title,"dr.") == 0 || strcmp(title,"ajarn") == 0)
	{
	   titleval = TRUE;
	}
	else
	{
		printf("Invalid Title\n");
	}
	
	if(strlen(fName) >= 2 && strlen(fName) <= 30)
	{
		for(int i = 0; i < strlen(fName); i++)
		{
			if(ispunct(fName[i]))
			{
				fpunct = FALSE;
			}
		}
		
		if(fpunct == TRUE)
		{
			fNameval = TRUE;
		}
		else
		{
			printf("First name can not have any special characters\n");
		}
	}
	else
	{
		printf("First name should be 2 to 30 characters long\n");
	}
	
	if(strlen(lName) >= 2 && strlen(lName) <= 30)
	{
		for(int i = 0; i < strlen(lName); i++)
		{
			if(ispunct(lName[i]))
			{
				lpunct = FALSE;
			}
		}
		
		if(lpunct == TRUE)
		{
			lNameval = TRUE;
		}
		else if(lpunct == FALSE)
		{
			printf("Last name can not have any special characters\n");
		}
	}
	else
	{
		printf("Last name should be 2 to 30 characters long\n");
	}
	
	if(titleval == TRUE && fNameval == TRUE && lNameval == TRUE)
	{
		printf("Name is valid\n");
	}
}

int main()
{
	char name_input[128];
	
	while(-1)
	{
		memset(name_input, 0, sizeof(name_input));
		
		printf("Enter name:");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%[^\n]", name_input);
		
		
		
		if(strcmp(name_input, "") == 0)
		{
			exit(0);
		}
		
		nameValidation(name_input);
		
		titleval = FALSE;
		fNameval = FALSE;
		lNameval = FALSE;
		fpunct = TRUE;
		lpunct = TRUE;
	}
}