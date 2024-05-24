#!/usr/bin/sh 


if test -d build; then 
  echo "Recreating Meson Project"
  meson setup --reconfigure build
else 
  echo "Making meson build dir"
  meson build
fi
