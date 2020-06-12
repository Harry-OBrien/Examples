#!/bin/bash

#Check if script is running as root
if [ "$EUID" -ne 0 ] 
  then echo "Please run as root"
  exit 1
fi

echo "Running as root!"
