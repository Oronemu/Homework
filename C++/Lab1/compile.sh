#!/bin/bash

for file in *.cpp 
do
    obj=$(echo $file | sed 's/.cpp/.o/g')
    g++ -c $file -o Build/${obj}
done

cd ./Build
g++ *.o -o program


