#!/bin/bash

function UpdateServer() {
  ./ftpput.sh 
}

function RenameFile() {
  wget -q -4 --spider www.t1b1.nl/rename.php
}

function GetFile() {
  ./ftpget.sh 
}


climbers="climbers.xml"
if [ -f "$climbers" ]
then
	rm "$climbers"
fi

oldclimbers="oldclimbers.xml"
if [ -f "$oldclimbers" ]
then
	rm "$oldclimbers"
fi

resultfile="index.xml"

while true; do
echo "Querying T1B1 database" 
./t1b1dataprocessor

if [ -f "$oldclimbers" ]; then
  if diff "$oldclimbers" "$climbers"; then
    echo "No changes detected"
  else
    echo "Changes detected, going to update"
    UpdateServer
    RenameFile
    GetFile
    if diff "$climbers" "$resultfile"; then
      echo "Server contains new update"
      cp "$climbers" "$oldclimbers"
    else
      echo "Failed to update server"
    fi
  fi
else
  echo "Initial update"
  UpdateServer
  RenameFile
  GetFile
  if diff "$climbers" "$resultfile"; then
    echo "Server contains new update"
    cp "$climbers" "$oldclimbers"
  else
    echo "Failed to update server"
  fi
fi
sleep 1
done
