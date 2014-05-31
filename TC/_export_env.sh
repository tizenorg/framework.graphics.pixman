#!/bin/sh

. ./config
export TET_INSTALL_PATH=$TET_INSTALL_HOST_PATH # tetware root path
export TET_TARGET_PATH=$TET_INSTALL_PATH/tetware-target # tetware target path
export PATH=$TET_TARGET_PATH/bin:$PATH
export LD_LIBRARY_PATH=$TET_TARGET_PATH/lib/tet3:$LD_LIBRARY_PATH
export TET_ROOT=$TET_TARGET_PATH
export PIXMAN_TC_ROOT_PATH=/home/seongwon/workspace/00_cairo_pixman/00_private/pixman/TC/testcase
