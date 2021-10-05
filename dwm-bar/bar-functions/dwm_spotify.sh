#!/bin/sh

# A dwm_bar function that shows the current artist, track, duration, and status from Spotify using playerctl
# Joe Standring <git@joestandring.com>
# GNU GPLv3

# Dependencies: spotify/spotifyd, playerctl

# NOTE: The official spotify client does not provide the track position or shuffle status through playerctl. This does work through spotifyd however.

dwm_spotify () {
    if ps -C spotify > /dev/null; then
        PLAYER="spotify"
    elif ps -C spotifyd > /dev/null; then
        PLAYER="spotifyd"
    fi

    if [ "$PLAYER" = "spotify" ] || [ "$PLAYER" = "spotifyd" ]; then
        ARTIST=$(playerctl -p spotify metadata artist)
        TRACK=$(playerctl -p spotify metadata title)
        POSITION=$(playerctl position | sed 's/..\{6\}$//')
        DURATION=$(playerctl metadata mpris:length | sed 's/.\{6\}$//')
        STATUS=$(playerctl status)
        SHUFFLE=$(playerctl shuffle)
        
        if [ "$PLAYER" = "spotify" ]; then
            printf "%s %s" "$SEP1" "$TRACK"
            printf "%s\n" "$SEP2"
        #else
        #    printf "%s%s %s - %s " "$SEP1" "$STATUS" "$ARTIST" "$TRACK"
        #    printf "%0d:%02d/" $((POSITION%3600/60)) $((POSITION%60))
        #    printf "%0d:%02d" $((DURATION%3600/60)) $((DURATION%60))
        #    printf "%s%s\n" "$SHUFFLE" "$SEP2"
        fi
    fi
}

dwm_spotify
