# C-validation

<h2><b>Validation of address</b></h2>

Your function should check an address as follows:<br>
• Begins with a number (the house number). The number can include a single slash, e.g. “34/12”, but must have at least one digit before and one digit after the slash.<br>
• Next a street name which can include numbers as well as letters.<br>
• Next an optional label “Road”, “Street” or “Lane”.<br>
• Finally, a postal code, which must be five digits, and which must begin with “10”.<br>

<h2><b>Validation of date</b></h2>

‘MMM’ is first 3 chars of month, capital letters. As above, you must make sure that the date is both formatted correctly and a legal date. Years cannot be more than 100 years in the past or the future.<br>

<h2><b>Validation of name</b></h2>

The user must enter exactly three strings separated by spaces: title, first name, last name. No special characters are allowed except a period after the title. Upper or lower case are both accepted for any part of the name and title. First and last names must be at least 2 characters long and no longer than 30 characters (each). Title must be one of: Mr., Ms., Miss, Mrs., Dr. or Ajarn Except for the titles “Miss” and “Ajarn”, the terminating period is required.<br>

<h2><b>Validation of password</b></h2>

Write a function that will correctly determine whether a password string follow these rules:<br>
• At least 8 characters long and no longer than 12 characters<br>
• Must contain at least one upper case letter<br>
• Must contain at least one lower case letter<br>
• Must contain at least two digits<br>
• Must contain at least one of the following special characters: ? @ % $ #<br>
• Must not contain any other special characters not in the list<br>
