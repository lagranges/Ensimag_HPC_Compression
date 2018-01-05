#!/bin/bash

EXE=(../hpcompressor)

if [ $# = 0 ] ; then
	echo "usage: hpcompressor <file name to compress then decompress>"
else
	echo "[ Test $1 ]"
	$EXE -c $1 $1.comp
	$EXE -d $1.comp $1.comp.txt || echo "Try: cd .. ; make"
	ok=$(diff $1 $1.comp.txt)
	echo ""
	if [ "$ok" = "" ] ; then
		echo "[ Result OK : $1 and $1.comp.txt are IDENTICAL  ]"
	else
		echo "[ Result KO : $1 and $1.comp.txt are DIFFERENTS ]"
        echo $ok
	fi
fi ;

