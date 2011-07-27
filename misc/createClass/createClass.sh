#!/bin/sh

templatePath=`echo $0 | sed 's@\(.*\)/.*@\1@'`

templateH=$templatePath/template.h
templateCPP=$templatePath/template.cpp

UPERCASE_PATTERN=XXX
FIRSTUPERCASE_PATTERN=Xxx
LOWERCASE_PATTERN=xxx

FIRSTUPERCASE_REPLACE=`echo $1 | sed -e 's/\([a-zA-Z]\)/\U\1/'`
LOWERCASE_REPLACE=`echo $1 | sed -e 's/\([a-zA-Z]\)/\L\1/'`
UPERCASE_REPLACE=`echo $FIRSTUPERCASE_REPLACE | sed -e 's/\([A-Z]\)/\_\1/g' -e 's/\_//' | tr '[:lower:]' '[:upper:]'`


echo "Creating $FIRSTUPERCASE_REPLACE class header in $LOWERCASE_REPLACE.h"

cat $templateH | sed -e 's@'$UPERCASE_PATTERN'@'$UPERCASE_REPLACE@'g' -e 's@'$FIRSTUPERCASE_PATTERN'@'$FIRSTUPERCASE_REPLACE'@g' -e 's@'$LOWERCASE_PATTERN'@'$LOWERCASE_REPLACE'@g' > $LOWERCASE_REPLACE.h


echo "Creating $FIRSTUPERCASE_REPLACE class implementation in $LOWERCASE_REPLACE.cpp"

cat $templateCPP | sed -e 's@'$UPERCASE_PATTERN'@'$UPERCASE_REPLACE@'g' -e 's@'$FIRSTUPERCASE_PATTERN'@'$FIRSTUPERCASE_REPLACE'@g' -e 's@'$LOWERCASE_PATTERN'@'$LOWERCASE_REPLACE'@g' > $LOWERCASE_REPLACE.cpp

