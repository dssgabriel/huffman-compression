#!/bin/sh

echo "This script will make sure that you have the necessary packages to build the project."
echo "It may try to install programs if needed."

while true
do
  read -r -p "Continue anyway? [Y/n] " input
  case $input in
  [yY]|[yY][eE][sS])
    echo "\nStarting checks..."
    for package in g++ cmake qt5-default
    do
      echo -n "Checking $package... "
      if [ $(dpkg -s $package >/dev/null 2>&1) ];
      then
        echo "not found"
        while true
        do
          read -r -p "Do you want to install it? [Y/n] " answer
          case $answer in
          [yY]|[yY][eE][sS])
            sudo apt install $package
            found=0
            break
            ;;

          [nN]|[nN][oO])
            echo "Not installing $package"
            found=1
            break
            ;;

          *)
            echo "ERROR: Invalid input"
            ;;
          esac
        done
      else
        echo "ok"
        found=0
      fi
    done
    if [ $found -eq 0 ];
    then
      echo "\nYou already have all the necessary dependencies."
      ret=0
    else
      echo "\nYou may have unmet dependencies."
      ret=1
    fi
    break
    ;;

  [nN]|[nN][oO])
    echo "\nSkipping checks..."
    ret=1
    break
    ;;

  *)
    echo "ERROR: Invalid input"
    ;;
  esac
done

if [ $ret -eq 0 ]
then
  exit 0
else
  exit 1
fi
