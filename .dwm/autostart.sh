#! /bin/zsh

/home/makorino/.dwm/locker &
/home/makorino/dwm-bar/dwm_bar.sh &
feh --bg-fill ~/Downloads/RckWffc.jpg
xrandr --output DVI-D-0 --auto --right-of DisplayPort-0

#compositor
picom --experimental-backends
