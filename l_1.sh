
//1 CALCULATOR CODE 


#!/bin/bash

while true
do
 
  echo "ENTER THE CHOICE "
  echo "1. ADDITION "
  echo "2. SUBTRACTION"
  echo "3. MULTIPLICATION "
  echo "4. DIVISION "
  echo "5. EXIT"
  read ch
  
  
  case $ch in
    1|2|3|4)
      echo "ENTER THE FIRST NUMBER:"
      read a
      echo "ENTER THE SECOND NUMBER:"
      read b

  case $ch in
   1)result=$((a+b))
     echo "RESULT:$result"
     ;;
  2)result=$((a-b))
     echo "RESULT:$result"
     ;;
  3)result=$((a*b))
     echo "RESULT:$result"
     ;;
  4)if [ "$b" -eq 0 ]
    then 
    echo "ERROR: DENOM CANT BE 0"  
    else
     result=$(echo "scale=2; $a / $b" | bc)
     echo "RESULT:$result"
     fi
     ;;
     esac 
     ;;
     
   5) echo "EXIT"
      break
      ;;
   *) echo "INVALID CHOICE "
      ;;
      esac
      
      echo ""
 done
