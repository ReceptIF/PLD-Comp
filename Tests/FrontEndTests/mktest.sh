#!/usr/bin/env bash
echo "Test ID;Return code validation;Out result;StdErr result;File creation result;Global result" > ./Tests/FrontEndTests/results.csv
nOk=0
nKo=0
nTotal=0
nMis=0

for j in "./Tests/FrontEndTests/Tests/*"
do
    for i in ./$j/*
    do
      ./Tests/FrontEndTests/test.sh "$i" ./Tests/FrontEndTests/results.csv
      result=$?
      if [ $result -eq 0 ]
      then
        let "nKo=$nKo+1"
      elif [ $result -eq 1 ]
      then
        let "nOk=$nOk+1"
      else
        let "nMis=$nMis+1"
      fi
      let "nTotal=$nTotal+1"
    done
done

echo "Passed tests     : $nOk"
echo "Failed tests     : $nKo"
echo "Misformed tests  : $nMis"
echo "-----------------------"
echo "Total            : $nTotal"
