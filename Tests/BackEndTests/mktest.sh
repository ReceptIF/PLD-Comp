#!/usr/bin/env bash
echo "Test ID;Return code validation;Out result;StdErr result;File creation result;Global result" > ./Tests/BackEndTests/results.csv
nOk=0
nKo=0
nTotal=0
nMis=0

for i in ./Tests/BackEndTests/Tests/*
do
  ./Tests/BackEndTests/test.sh "$i" ./Tests/BackEndTests/results.csv
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

echo "Passed tests     : $nOk"
echo "Failed tests     : $nKo"
echo "Misformed tests  : $nMis"
echo "-----------------------"
echo "Total            : $nTotal"
