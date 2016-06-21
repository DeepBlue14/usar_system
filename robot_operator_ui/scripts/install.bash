#!/bin/bash


echo "WARNING.  Before continuing, be aware that this program was written by an undergraduate, and will be mucking around in the very bowels of your system.  Oh yeah, and it will require superuser permissions.  Thus--theoretically--it could cause serious damange to your computer.  Procede at your own risk.  Are you sure that you wish to preceed? (Y/n)"
read procead

if [ procead == 'n' || procead == 'N' ] then
    exit
fi


