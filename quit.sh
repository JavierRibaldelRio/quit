#! /bin/bash

if [ -z "$1" ]
then
    read -rep $'Insert:\n1 to shutdown\n2 to timed shutdown\n3 to reboot\n4 to timed reboot\n5 to suspend\n: ' ord
    
else
  
    ord=$1

fi

# https://askubuntu.com/questions/454039/what-command-is-executed-when-shutdown-from-the-graphical-menu-in-14-04

case $ord in
    # Shutdown
    1)
        dbus-send --system --print-reply --dest=org.freedesktop.login1 /org/freedesktop/login1 "org.freedesktop.login1.Manager.PowerOff" boolean:true
        ;;
    # Timed Shutdown
    2)
        read -rep  $'How long do you want the timer? (in minutes)\n: ' time

        echo The countdown has started, to cancel it close the terminal.
        
        sleep $((time*60))

        dbus-send --system --print-reply --dest=org.freedesktop.login1 /org/freedesktop/login1 "org.freedesktop.login1.Manager.PowerOff" boolean:true

        ;;
    # Reboot
    3)
        dbus-send --system --print-reply --dest=org.freedesktop.login1 /org/freedesktop/login1 "org.freedesktop.login1.Manager.Reboot" boolean:true
        ;;
    # Timed Reboot
    4)
        read -rep  $'How long do you want the timer? (in minutes)\n: ' time
        
        echo The countdown has started, to cancel it close the terminal.

        sleep $((time*60))
        
        dbus-send --system --print-reply --dest=org.freedesktop.login1 /org/freedesktop/login1 "org.freedesktop.login1.Manager.Reboot" boolean:true

        ;;
    # Suspend
    5)
        dbus-send --system --print-reply --dest=org.freedesktop.login1 /org/freedesktop/login1 "org.freedesktop.login1.Manager.Suspend" boolean:true
        ;;

esac

exit 0