#!/bin/bash 
# Initialize the variable 
number=0 
 
# Start of do-while loop 
while true; do 
    # Display prompt 
    echo "Enter a positive number:" 
     # Read user input 
    read number 
     
    # Check if the input is a positive number 
    if [ $number -gt 0 ]; then 
        break  # Exit the loop if a positive number is entered 
    else 
        echo "Invalid input. Please enter a positive number." 
    fi 
done 
# End of do-while loop 
 
echo "You entered a positive number: $number" 