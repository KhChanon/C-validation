/**************************************************
    addressval.c
    Chanon Khanijoh
    63070503408
	
	This program test the function addressValidation 
	which is to be put in main program later on.
***************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1//TRUE will always equal to 1
#define FALSE 0// FALSE will always equal to 0

char stringInput[128];
int streetnumval = FALSE;
int streetval = TRUE;
int rlsval = FALSE;
int numval = TRUE;
int slashval = FALSE;
int postnumval = TRUE;
int startpostval = FALSE;
int postcodeval = FALSE;
int slashcount = 0;
int slashnumval = FALSE;

void streetnumValidation(char stringToCheck[])
{
	for(int i = 0; i < strlen(stringToCheck); i++)
	{
		if(stringToCheck[i] == '/')
		{
			slashcount++;
		}
	}
	
	if(slashcount == 0)
	{
		slashnumval = TRUE;
		slashval = TRUE;
	}
	else if(slashcount == 1)
	{
		slashnumval = TRUE;
	}
	else
	{
		printf("There can be only 1 slash\n");
	}
	
	for(int i = 0; i < strlen(stringToCheck); i++)
	{
		if(isdigit(stringToCheck[i]) == 0 && stringToCheck[i] != '/')
		{
			numval = FALSE;
		}
		
		if(stringToCheck[i] == '/')
		{
			if(isdigit(stringToCheck[i-1]) && isdigit(stringToCheck[i+1]))
			{
				slashval = TRUE;
			}
		}
	}
	
	if(numval == FALSE)
	{
		printf("street number can only contain / and digits\n");
	}
	else if(slashval == FALSE)
	{
		printf("There should be digit before and after /\n");
	}
	else if(numval == TRUE && slashval == TRUE && slashnumval == TRUE)
	{
		streetnumval = TRUE;
	}
}

void streetValidation(char stringToCheck[])
{
	for(int i = 0; i < strlen(stringToCheck); i++)
	{
		if(ispunct(stringToCheck[i]))
		{
			streetval = FALSE;
		}
	}
	
	if(streetval == FALSE)
	{
		printf("Street name can't have special characters\n");
	}
}

void rlsValidation(char stringToCheck[])
{
	if(strcmp(stringToCheck,"Road") == 0 || strcmp(stringToCheck,"Street") == 0 || strcmp(stringToCheck,"Lane") == 0)
	{
		rlsval = TRUE;
	}
	else
	{
		printf("Either Road, Street, Lane or nothing at all\n");
	}
}	

void postcodeValidation(char stringToCheck[])
{
	if(strlen(stringToCheck) == 5)
	{
		if(stringToCheck[0] == '1' && stringToCheck[1] == '0')
		{
			startpostval = TRUE;
		}
		
		for(int i = 0; i < strlen(stringToCheck); i++)
		{
			if(isdigit(stringToCheck[i]) == 0)
			{
				postnumval = FALSE;
			}
		}
		
		if(startpostval == FALSE)
		{
			printf("Postcode should start with 10 only\n");
		}
		else if(postnumval == FALSE)
		{
			printf("Postcode can only be in numbers\n");
		}
		else if(startpostval == TRUE && postnumval == TRUE)
		{
			postcodeval = TRUE;
		}
	}
	else
	{
		printf("Postal code should be 5 digits long\n");
	}
}

void address3Validation(char stringToCheck[])
{
	char streetnum[128];
	char street[128];
	char rls[128];
	char postcode[128];
	
	sscanf(stringToCheck,"%s %s %s %s", streetnum, street, rls , postcode);
	
	streetnumValidation(streetnum);
	streetValidation(street);
	rlsValidation(rls);
	postcodeValidation(postcode);
	
	
	if(streetnumval == TRUE && streetval == TRUE && rlsval == TRUE && postcodeval == TRUE)
	{
		printf("address is valid\n");
	}
}

void address2Validation(char stringToCheck[])
{
	char streetnum[128];
	char street[128];
	char rls[128];
	char postcode[128];
	
	sscanf(stringToCheck,"%s %s %s", streetnum, street, postcode);
	
	streetnumValidation(streetnum);
	streetValidation(street);
	postcodeValidation(postcode);
	
	if(streetnumval == TRUE && streetval == TRUE && postcodeval == TRUE)
	{
		printf("address is valid\n");
	}
}

int main()
{
	char address_input[128];
	int spacecount = 0;
	
	while(-1)
	{
		memset(address_input, 0, sizeof(address_input));
		
		printf("Enter street address:");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%[^\n]", address_input);
		
		if(strcmp(address_input, "") == 0)
		{
			exit(0);
		}
		
		for(int i = 0; i < strlen(address_input); i++)
		{
			if(isspace(address_input[i]))
			{
				spacecount++;
			}
		}
		
		if(spacecount == 3)
		{
			address3Validation(address_input);
		}
		else if(spacecount == 2)
		{
			address2Validation(address_input);
		}
		else
		{
			printf("Wrong address format\n");
		}
		
		streetnumval = FALSE;
		streetval = TRUE;
		rlsval = FALSE;
		numval = TRUE;
		slashval = FALSE;
		postnumval = TRUE;
		startpostval = FALSE;
		postcodeval = FALSE;
		slashcount = 0;
		slashnumval = FALSE;
		spacecount = 0;
	}
}