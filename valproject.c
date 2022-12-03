/**************************************************
    valproject.c
    Chanon Khanijoh
    63070503408
	
	4. Validate date in form dd MMM yyyy ­ Western year
	   ‘MMM’ is first 3 chars of month, capital letters. As above, you must make sure that the date is both 
	   formatted correctly and a legal date. Years cannot be more than 100 years in the past or the future. 
	
	13. Validate street address in Bangkok (simplified)
		Your function should check an address as follows:
		• Begins with a number (the house number). The number can include a single slash, e.g. “34/12”,
		  but must have at least one digit before and one digit after the slash.
		• Next a street name which can include numbers as well as letters;
		• Next an optional label “Road”, “Street” or “Lane”;
		• Finally, a postal code, which must be five digits and which must begin with “10”.
	
	17. Validate password against a set of rules
		Write a function that will correctly determine whether a password string follows these rules:
		• At least 8 characters long and no longer than 12 characters
		• Must contain at least one upper case letter
		• Must contain at least one lower case letter
		• Must contain at least two digits
		• Must contain at least one of the following special characters: ? @ % $ #
		• Must not contain any other special characters not in the list above
		
	8. Validate first and last name with title
	   The user must enter exactly three strings separated by spaces: title, first name, last name. No special 
	   characters are allowed except a period after the title. Upper or lower case are both accepted for any 
	   part of the name and title. First and last names must be at least 2 characters long and no longer than 
	   30 characters (each). Title must be one of: Mr., Ms., Miss, Mrs., Dr. or Ajarn  Except for the titles 
	   “Miss” and “Ajarn”, the terminating period is required.
***************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1//TRUE will always equal to 1
#define FALSE 0// FALSE will always equal to 0

char stringInput[128];// for inputing
int streetnumval = FALSE;//validating street number
int streetval = TRUE;//validating street name
int rlsval = FALSE;//check if its road lane or street or not
int numval = TRUE;//check if its number or not
int slashval = FALSE;//check if there is slash or not
int postnumval = TRUE;//check if postcode is all number
int startpostval = FALSE;//check if post number start with 10 or not
int postcodeval = FALSE;//validating postcode
int slashcount = 0;//check number of slash
int slashnumval = FALSE;//check if there is only 1 number of slash
int titleval = FALSE;//validating title
int fNameval = FALSE;//validating first name
int lNameval = FALSE;//validating last name
int fpunct = TRUE;//check for punctuation in first name
int lpunct = TRUE;//check for punctuation in last name
int valupper = FALSE;//check for uppercase
int vallower = FALSE;//check for lowercase
int valalpha = FALSE;//check if its alphabet
int valdigit = FALSE;//check if its digit
int valspace = TRUE;//check for space
int valnospc = TRUE;//check for invalid special
int val1 = 0;//counter for validation1
int val2 = 0;//counter for validation2
int val3 = 0;//counter for validation3
int val4 = 0;//counter for validation4

int main();

void streetnumValidation(char stringToCheck[])//validate street number
{
	for(int i = 0; i < strlen(stringToCheck); i++)//count number of slash
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
		printf("There can be only 1 slash\n");//if more than 1 slash give error
	}
	
	for(int i = 0; i < strlen(stringToCheck); i++)
	{
		if(isdigit(stringToCheck[i]) == 0 && stringToCheck[i] != '/')//check if street num is only number and slashes
		{
			numval = FALSE;
		}
		
		if(stringToCheck[i] == '/')
		{
			if(isdigit(stringToCheck[i-1]) && isdigit(stringToCheck[i+1]))//check if before and after slash are numbers
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

void streetValidation(char stringToCheck[])//validate street name
{
	for(int i = 0; i < strlen(stringToCheck); i++)
	{
		if(ispunct(stringToCheck[i]))
		{
			streetval = FALSE;//check if streetname have punctuation or not
		}
	}
	
	if(streetval == FALSE)
	{
		printf("Street name can't have special characters\n");
	}
}

void rlsValidation(char stringToCheck[])//check for road, lane or street
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

void postcodeValidation(char stringToCheck[])//validating postcode
{
	if(strlen(stringToCheck) == 5)//make sure postcode is 5 digit long
	{
		if(stringToCheck[0] == '1' && stringToCheck[1] == '0') //check if it start with 10
		{
			startpostval = TRUE;
		}
		
		for(int i = 0; i < strlen(stringToCheck); i++) // check if postcode is all digit
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

void address3Validation(char stringToCheck[])//if there are 4 input include road, street and lane and check all of them
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

void address2Validation(char stringToCheck[])//if only 3 input check for street num, street name and postcode only
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

int validation13()
{
	char address_input[128];
	int spacecount = 0;
	
	while(-1)
	{
		memset(address_input, 0, sizeof(address_input));//clear string
		
		printf("Enter street address:");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%[^\n]", address_input);
		
		if(strcmp(address_input, "") == 0)//enter to go back to menu
		{
			main();
		}
		
		for(int i = 0; i < strlen(address_input); i++)//check if there is 3 input or 4 input
		{
			if(isspace(address_input[i]))
			{
				spacecount++;
			}
		}
		
		if(spacecount == 3)//4 input
		{
			address3Validation(address_input);
		}
		else if(spacecount == 2)//3 input
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
		spacecount = 0;
		slashcount = 0;
		slashnumval = FALSE;
		
		val2++;
	}
}

void nameValidation(char stringToCheck[])// validating name
{
	char title[128];
	char fName[128];
	char lName[128];
	
	sscanf(stringToCheck,"%s %s %s",title,fName,lName); //seperate input into 3 string seperated by space
	
	for(int i = 0; i < strlen(stringToCheck); i++)
	{
		title[i] = tolower(title[i]);
	}

	
	if(strcmp(title,"mr.") == 0 || strcmp(title,"ms.") == 0 || strcmp(title,"miss") == 0 
	   || strcmp(title,"mrs.") == 0 || strcmp(title,"dr.") == 0 || strcmp(title,"ajarn") == 0)//check title
	{
	   titleval = TRUE;
	}
	else
	{
		printf("Invalid Title\n");
	}
	
	if(strlen(fName) >= 2 && strlen(fName) <= 30)//check first name length
	{
		for(int i = 0; i < strlen(fName); i++)
		{
			if(ispunct(fName[i])) // check for punctuation in first name
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
	
	if(strlen(lName) >= 2 && strlen(lName) <= 30)// check last name length
	{
		for(int i = 0; i < strlen(lName); i++)
		{
			if(ispunct(lName[i])) // check for punctuation in last name
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

int validation8()
{
	char name_input[128];
	
	while(-1)
	{
		memset(name_input, 0, sizeof(name_input));//clear string
		
		printf("Enter name:");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%[^\n]", name_input);
		
		if(strcmp(name_input, "") == 0)//enter to go back to menu
		{
			main();
		}
		
		nameValidation(name_input);
		
		titleval = FALSE;
		fNameval = FALSE;
		lNameval = FALSE;
		fpunct = TRUE;
		lpunct = TRUE;
		
		val4++; // counter to check how many time its done
	}
}

void passwordValidation(char stringToCheck[])
{
	int countdigit = 0;//check number of digit enter
	
	if(strlen(stringToCheck) >= 8 && strlen(stringToCheck) <= 12)
	{
		for(int i = 0; i < strlen(stringToCheck); i++)
		{
			if(isupper(stringToCheck[i]))//check if there is uppercase enter
			{
				valupper = TRUE;
			}
			
			if(islower(stringToCheck[i]))//check if there is lowercase enter
			{
				vallower = TRUE;
			}
			
			if(stringToCheck[i] == '?' || stringToCheck[i] == '@' || stringToCheck[i] == '%' || stringToCheck[i] == '$' || stringToCheck[i] == '#' )//check if there is these sign enter
			{
				valalpha = TRUE;
			}
			
			if(isdigit(stringToCheck[i]))//count number of digit enter
			{
				countdigit++;
			}
			
			if(stringToCheck[i] == 32)//check if there is space enter
			{
				valspace = FALSE;
			}
			
			if(stringToCheck[i] == '~' || stringToCheck[i] == '`' || stringToCheck[i] == '!' || stringToCheck[i] == '^' || stringToCheck[i] == '&' || stringToCheck[i] == '*' 
			   || stringToCheck[i] == '(' || stringToCheck[i] == ')' || stringToCheck[i] == '-' || stringToCheck[i] == '_' || stringToCheck[i] == '+' || stringToCheck[i] == '=' 
			   || stringToCheck[i] == '{' || stringToCheck[i] == '}' || stringToCheck[i] == '[' || stringToCheck[i] == ']' || stringToCheck[i] == '|' || stringToCheck[i] == 92 
			   || stringToCheck[i] == 47 || stringToCheck[i] == ':' || stringToCheck[i] == ';' || stringToCheck[i] == 34 || stringToCheck[i] == 39 || stringToCheck[i] == '<' 
			   || stringToCheck[i] == '>' || stringToCheck[i] == ',' || stringToCheck[i] == '.' || stringToCheck[i] == '?')//check invalid special characters
			{
				valnospc = FALSE;
			}
		}
		
		if(countdigit >= 2)//check if digits enter is more than 2 digits
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

int validation17()
{
	char pass_input[128];
	
	while(-1)
	{
		memset(pass_input, 0, sizeof(pass_input));//clear string
		
		printf("please input password:");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%[^\n]", pass_input);
		
		if(strcmp(pass_input, "") == 0)//enter to return to menu
		{
			main();
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
		
		val3++;
	}
}

void dateValidation(char stringToCheck[])
{
	char datestring[3];
	char monthstring[4];
	char yearstring[5];
	int idate;
	int iyear;
	
	if(strlen(stringToCheck) == 11)//check date length
	{
		if(isdigit(stringToCheck[0]) && isdigit(stringToCheck[1]))//check if date is number
		{	
			datestring[0]=stringToCheck[0];
			datestring[1]=stringToCheck[1];
			datestring[2]=0;
			
			idate=atoi(datestring);//convert date string to int
			
			if(stringToCheck[2] == 32 && stringToCheck[6] == 32)//check for spaces between date month and year
			{
				monthstring[0]=stringToCheck[3];
				monthstring[1]=stringToCheck[4];
				monthstring[2]=stringToCheck[5];
				monthstring[3]=0;
				
				if(strcmp(monthstring,"JAN") == 0 || strcmp(monthstring,"FEB") == 0 || strcmp(monthstring,"MAR") == 0 || strcmp(monthstring,"APR") == 0 
				   || strcmp(monthstring,"MAY") == 0 || strcmp(monthstring,"JUN") == 0 || strcmp(monthstring,"JUL") == 0 || strcmp(monthstring,"AUG") == 0 
				   || strcmp(monthstring,"SEP") == 0 || strcmp(monthstring,"OCT") == 0 || strcmp(monthstring,"NOV") == 0 || strcmp(monthstring,"DEC") == 0)//check if month is correct form
				{
					if(isdigit(stringToCheck[7]) && isdigit(stringToCheck[8]) && isdigit(stringToCheck[9]) && isdigit(stringToCheck[10]))//check if year is number
					{
						yearstring[0]=stringToCheck[7];
						yearstring[1]=stringToCheck[8];
						yearstring[2]=stringToCheck[9];
						yearstring[3]=stringToCheck[10];
						yearstring[4]=0;
						
						iyear=atoi(yearstring);//convert year string to int
			
						if(iyear >= 1920 && iyear <= 2120)//check if year is between 100 year from present
						{			
							if(iyear%4 == 0 && strcmp(monthstring,"FEB") == 0 )//leap year
							{
								if(idate >=1 && idate <=29)//29 days in FEB in leap year
								{
									printf("The date you enter is valid\n");
								}
								else
								{
									printf("There are only 29 days in FEB this year\n");
								}
							}
							else if(strcmp(monthstring,"JAN") == 0 || strcmp(monthstring,"MAR") == 0 || strcmp(monthstring,"MAY") == 0 || strcmp(monthstring,"JUL") == 0 
									|| strcmp(monthstring,"AUG") == 0 || strcmp(monthstring,"OCT") == 0 || strcmp(monthstring,"DEC") == 0)//31 days in these month
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
									|| strcmp(monthstring,"SEP") == 0 || strcmp(monthstring,"NOV") == 0)//30 days in these month
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

int validation4()
{
	char date_input[128];
	
	while(-1)
	{
		memset(date_input, 0, sizeof(date_input));//clear string
		
		printf("please input date(DD MMM YYYY):");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%[^\n]", date_input);
		
		if(strcmp(date_input, "") == 0)//enter to go back to main menu
		{
			main();
		}
		
		dateValidation(date_input);
		
		val1++;//counter to increase number of validation done 
	}
}

int main()
{
	int mainval = 0;//menu selection
	
	while(-1)
	{
		printf("Validation options:\n");
		printf("\t1 – Validate date in form dd MMM yyyy ­ Western year\n");
		printf("\t2 – Validate street address in Bangkok (simplified)\n");
		printf("\t3 – Validate password against a set of rules\n");
		printf("\t4 – Validate first and last name with title\n");
		printf("\t5 – Exit the program\n");
		printf("What do you want to do?\n");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput, "%d", &mainval);//input to select validation type
		
		if(mainval == 1)//pressing 1 does date validation
		{
			validation4();
		}
		else if(mainval == 2)//pressing 2 does address validation
		{
			validation13();
		}
		else if(mainval == 3)//pressing 3 does password validation
		{
			validation17();
		}
		else if(mainval == 4)//pressing 4 does name validation
		{
			validation8();
		}
		else if(mainval == 5)//pressing 5 give number of validation on each type and exit program
		{
			printf("Program run summary:\n");
			printf("\tValidation type 1: %d\n", val1);
			printf("\tValidation type 2: %d\n", val2);
			printf("\tValidation type 3: %d\n", val3);
			printf("\tValidation type 4: %d\n", val4);
			printf("Goodbye!\n");
			exit(0);
		}
	}
}