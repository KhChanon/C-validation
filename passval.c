/**************************************************
    passval.c
    Chanon Khanijoh
    63070503408
	
	This program test the function passwordValidation 
	which is to be put in main program later on.
***************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1//TRUE will always equal to 1
#define FALSE 0// FALSE will always equal to 0

char stringInput[128];
int valupper = FALSE;
int vallower = FALSE;
int valalpha = FALSE;
int valdigit = FALSE;
int valspace = TRUE;
int valnospc = TRUE;

void passwordValidation(char stringToCheck[])
{
	int countdigit = 0;
	
	if(strlen(stringToCheck) >= 8 && strlen(stringToCheck) <= 12)
	{
		for(int i = 0; i < strlen(stringToCheck); i++)
		{
			if(isupper(stringToCheck[i]))
			{
				valupper = TRUE;
			}
			
			if(islower(stringToCheck[i]))
			{
				vallower = TRUE;
			}
			
			if(stringToCheck[i] == '?' || stringToCheck[i] == '@' || stringToCheck[i] == '%' || stringToCheck[i] == '$' || stringToCheck[i] == '#' )
			{
				valalpha = TRUE;
			}
			
			if(isdigit(stringToCheck[i]))
			{
				countdigit++;
			}
			
			if(stringToCheck[i] == 32)
			{
				valspace = FALSE;
			}
			
			if(stringToCheck[i] == '~' || stringToCheck[i] == '`' || stringToCheck[i] == '!' || stringToCheck[i] == '^' || stringToCheck[i] == '&' || stringToCheck[i] == '*' 
			   || stringToCheck[i] == '(' || stringToCheck[i] == ')' || stringToCheck[i] == '-' || stringToCheck[i] == '_' || stringToCheck[i] == '+' || stringToCheck[i] == '=' 
			   || stringToCheck[i] == '{' || stringToCheck[i] == '}' || stringToCheck[i] == '[' || stringToCheck[i] == ']' || stringToCheck[i] == '|' || stringToCheck[i] == 92 
			   || stringToCheck[i] == 47 || stringToCheck[i] == ':' || stringToCheck[i] == ';' || stringToCheck[i] == 34 || stringToCheck[i] == 39 || stringToCheck[i] == '<' 
			   || stringToCheck[i] == '>' || stringToCheck[i] == ',' || stringToCheck[i] == '.' || stringToCheck[i] == '?')
			{
				valnospc = FALSE;
			}
		}
		
		if(countdigit >= 2)
		{
			valdigit = TRUE;
		}
		else
		{
			printf("Password should countain at least 2 digits\n");
		}
		
		if(valalpha == TRUE && valupper == TRUE && vallower == TRUE && valdigit == TRUE && valspace == TRUE && valnospc == TRUE)
		{
			printf("Password is valid\n");
		}
	}
	else
	{
		printf("Password should be between 8 to 12 character long\n");
	}
	
}

int main()
{
	char pass_input[128];
	
	while(-1)
	{
		memset(pass_input, 0, sizeof(pass_input));
		
		printf("please input password:");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%[^\n]", pass_input);
		
		if(strcmp(pass_input, "") == 0)
		{
			exit(0);
		}
		
		passwordValidation(pass_input);
		
		if(strlen(pass_input) == 8 || strlen(pass_input) == 9 || strlen(pass_input) == 10 || strlen(pass_input) == 11 || strlen(pass_input) == 12)
		{
			if(valupper == FALSE)
			{
				printf("No uppercase entered\n");
			}
			
			if(vallower == FALSE)
			{
				printf("No lowercase entered\n");
			}
			
			if(valalpha == FALSE)
			{
				printf("No special character entered\n");
			}
			
			if(valspace == FALSE)
			{
				printf("No space allowed\n");
			}
			
			if(valnospc == FALSE)
			{
				printf("Invalid special character entered\n");
			}
		}
		
		valupper = FALSE;
		vallower = FALSE;
		valalpha = FALSE;
		valdigit = FALSE;
		valspace = TRUE;
		valnospc = TRUE;
	}
}