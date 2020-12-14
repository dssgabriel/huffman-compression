#!/bin/sh

echo "IN505 C++ Project: Part 2 - Huffman build script\n"

./.check_dependencies.sh
ret=$?

if [ $ret -eq 0 ]
then
  echo "\nGenerating Makefile with cmake..."
  cmake CMakeLists.txt

  echo "\nBuilding C++ project..."
  make

  echo "\nBUILD SUCCESSFUL!"
  echo "\nYou can run the project with './partie_2'"
  echo "ADVICE: Keep the terminal open as output will be printed to it during execution!"
else
echo "\nWARNING: Dependencies are not met."
while true
  do
    read -r -p "Do you want to proceed to the build anyway? [Y/n] " input
    case $input in
    [yY]|[yY][eE][sS])
      echo "Proceeding to build..."

      echo "\nGenerating Makefile with cmake..."
      cmake CMakeLists.txt

      echo "\nBuilding C++ project..."
      make

      echo "\nBUILD SUCCESSFUL!"
      echo "\nYou can run the project with './partie_2'"
      echo "ADVICE: Keep the terminal open as output will be printed to it during execution!"
      break
      ;;

    [nN]|[nN][oO])
      echo "\nTry installing the necessary packages and re-run this script."
      break
      ;;

    *)
      echo "ERROR: Invalid input"
      ;;
    esac
  done
fi
