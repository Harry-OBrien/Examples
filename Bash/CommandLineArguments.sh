#!/bin/bash

usage()
{
	echo "Invalid args!"
}

# If wrong no. of params given
if [[ $# != 4 ]]
then
	echo "Incorrect no. of params. Expected 4, got $#."
	usage
	exit 1
fi

# Get params
while [ "$1" != "" ]; do
        case $1 in
                -a )           		shift
                                        paramA=$1
                                        ;;
                -b )           		shift
                                        paramB=$1
					;;
                -h )	           	usage
                                        exit
                                        ;;
                * )                     usage
                                        exit 1
        esac
        shift
done

echo "Param A is: ${paramA}"
echo "Param B is: ${paramB}"
