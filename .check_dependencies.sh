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
      if [ $($package -v 2>/dev/null) ]
      then
        echo "Not found"
        while true
        do
          read -r -p "Do you want to install it? [Y/n] " answer
          case $answer in
          [yY]|[yY][eE][sS])
            sudo apt install $package
            break
            ;;

          [nN]|[nN][oO])
            echo "Not installing $package"
            ret=1
            break
            ;;

          *)
            echo "ERROR: Invalid input"
            ;;
          esac
        done
      else
        echo "Ok"
        ret=0
      fi
    done
    if [ $ret -eq 0 ]
    then
      echo "\nYou already have all the necessary dependencies."
      deps=0
    else
      echo "\nYou may have unmet dependencies."
      deps=1
    fi
    break
    ;;

  [nN]|[nN][oO])
    echo "\nSkipping checks..."
    deps=1
    break
    ;;

  *)
    echo "ERROR: Invalid input"
    ;;
  esac
done

if [ $deps -eq 0 ]
then
  exit 0
else
  exit 1
fi
