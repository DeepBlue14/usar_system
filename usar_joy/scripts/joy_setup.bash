#!/bin/bash

sudo chmod a+rw /dev/input/js1
rosparam set joy_node/dev "/dev/input/js1"

echo "Finished"
