#!/bin/sh

if [ -z "$1" ]
then
    read -rep $'Insert:\n1 to shutdown\n2 to timed shutdown\n3 to reboot\n4 to timed reboot\n5 to suspend\n: ' ord
    
    echo $ord

    echo "hi"

else
  
    ord=$1

fi

case $ord in

    1)
        shutdown now
        ;;

    2)
        read -rep  $'How long do you want the timer? (in minutes)\n: ' time

        shutdown $time
        ;;

    3)
        shutdown -r now
        ;;

    4)
        read -rep  $'How long do you want the timer? (in minutes)\n: ' time

        shutdown -r $time
        ;;

    5)
        systemctl suspend -i
        ;;

esac

exit 0