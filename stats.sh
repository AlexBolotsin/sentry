#!/bin/bash

LINES=$(find . -name "*.[ch]pp" | xargs wc -l | grep total)
LINES=${LINES% *}
PREV=$(tail -n1 stats)
echo `date +%d/%m/%y`$LINES >> stats
echo "From last time there are "$(($LINES - ${PREV#* })) "new lines"
echo "Current info" $LINES "lines"