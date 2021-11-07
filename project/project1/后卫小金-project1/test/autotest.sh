#!/bin/bash

int=$3
while(( $int<=$4 ))
do
    result="$(./$1 ${2}${int}.txt  $5 | tail -n 1)"
    #echo ${result}
    answer="$(tail -n 1 ${2}${int}.txt | tr -d "\r")"
    #echo ${answer}

    if [ "${answer}" == "${result}" ];then
	echo "case ${int} ok"
    else
	echo "case ${int} fail"
	echo "	You program out : ${result}"
	#echo ${#result}
	echo "	Standard answer : ${answer}"
	#echo ${#answer}
    fi
    let "int++"
done

