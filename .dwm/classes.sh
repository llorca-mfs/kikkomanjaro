#!/bin/sh

day=$(date "+%A")

class=$(echo -e "csarch2\ngeethic\nlbyarch\nstadvdb\nsthciux\nstsweng" | dmenu -i -l 6 -p "ᜐᜀᜈ᜔ ᜋᜓᜅ᜔ ᜈᜁᜐ᜔ ᜉᜓᜋᜐᜓᜃ᜔?")

if [[ $class = "sthciux" ]]; then
	if [[ $day = "Monday" ]]; then
        xdg-open https://zoom.us/j/99949676281?pwd=MTJyN1Y1b0NXVDRwUWxSM2E1Y3d1UT09
    elif [[ $day = "Wednesday" ]]; then
        xdg-open https://zoom.us/j/99636280753?pwd=MDQrcWlKc1YwU1pPZGdndDJQZXZhZz09
    fi 
elif [[ $class = "lbyarch" ]]; then
	xdg-open https://zoom.us/j/93362732225?pwd=UUhsMWhNTTd2RkYvbE5TdlNGV1ZwQT09
elif [[ $class = "stsweng" ]]; then
	xdg-open https://zoom.us/j/95369861649?pwd=d1VYTzQ5WExmTm1RdFY4em1qZTVCUT09
elif [[ $class = "csarch2" ]]; then
	xdg-open https://zoom.us/j/98107439289?pwd=R0taVEw5L3VhYTQyS0ZSUHFLOWd2Zz09
elif [[ $class = "geethic" ]]; then
	chromium https://dlsu.instructure.com/courses/78340/external_tools/6457
elif [[ $class = "stadvdb" ]]; then
	xdg-open https://zoom.us/j/95567412327?pwd=TFN5YzVsWXdVQTJIS3kxTXJjN0syZz09
fi