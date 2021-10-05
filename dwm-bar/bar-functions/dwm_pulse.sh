#!/bin/sh

# A dwm_bar function to show the master volume of PulseAudio
# Joe Standring <git@joestandring.com>
# GNU GPLv3

# Dependencies: pamixer

dwm_pulse () {
    VOL=$(pamixer --get-volume)
    OUT=$(pacmd list-sinks | grep -e '*' | cut -c12-12)

    #if [ "$OUT" = "0" ]; then
    #    OUT_STR="Headphones"
    #elif [ "$OUT" = "1" ]; then
    #    OUT_STR="Speaker"
    #fi
    
    printf "%s" "$SEP1"
    if [ "$IDENTIFIER" = "unicode" ]; then

        if [ "$OUT" = "0" ]; then
            printf " %s%%" "$VOL"
        elif [ "$OUT" = "1" ]; then
            printf " %s%%" "$VOL"
        fi

        #if [ "$VOL" = "muted" ] || [ "$VOL" -eq 0 ]; then
         #   printf "🔇"
        #elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 33 ]; then
        #    printf "🔈 %s%% - %s" "$VOL" "$OUT_STR"
        #elif [ "$VOL" -gt 33 ] && [ "$VOL" -le 66 ]; then
        #    printf "🔉 %s%% - %s" "$VOL" "$OUT_STR"
        #else
        #    printf "🔊 %s%% - %s" "$VOL" "$OUT_STR"
        #fi
    #else
        #if [ "$VOL" = "muted" ] || [ "$VOL" -eq 0 ]; then
        #    printf "MUTE"
        #elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 33 ]; then
        #    printf "VOL %s%%" "$VOL"
        #elif [ "$VOL" -gt 33 ] && [ "$VOL" -le 66 ]; then
        #    printf "VOL %s%%" "$VOL"
        #else
        #    printf "VOL %s%%" "$VOL"
        #fi
    fi
    printf "%s\n" "$SEP2"
}

dwm_pulse
