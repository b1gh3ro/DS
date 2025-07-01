#!/bin/bash 
# Input variable 
echo "Enter a number (1-3):" 
read choice 
 
# Switch-like behavior using case statement 
case $choice in 
    1) 
        echo "You chose Option 1." 
        ;; 
    2) 
        echo "You chose Option 2." 
        ;; 
    3) 
        echo "You chose Option 3." 
        ;; 
    *) 
        echo "Invalid choice. Please enter a number between 1 and 3." 
        ;; 
esac 