#!/bin/bash

arg1=$1
arg2=$2
arg3=$3

fileName=${arg1##*/}
fileType=${fileName#*.}
filePath=${arg1%%/*}

outfilename=${fileName%%.*}".out"

echo "The algrithm is compile now ..."

type="c"

if [ "$fileType" = "$type" ]; then
    gcc $arg1 -o ./out/${outfilename}
else
    g++ -std=c++11 $arg1 -o ./out/${outfilename}
fi

if [ $? -eq 0 ]; then
  echo "The ${fileName} is compiled sucessful!"
  echo "The program is ready to run."
  echo "-----------------running ${outfilename}------------------"
  
  tmp=""

  if [ "$arg2" = "$tmp" ]; then
      ./out/${outfilename}
  else
      if [ "$arg3" = "$tmp" ]; then
        ./out/${outfilename} ${arg2}
    else
        ./out/${outfilename} ${arg2} ${arg3}
    fi
  fi

  echo "-----------------${outfilename} exited-------------------"

  gedit ${arg3} &

  rm ./out/${outfilename}

else
  echo "Some error occur..."
fi
