chosen=$(echo -e "Lock\nLogout\nShutdown\nReboot\nSuspend\nHibernate" | dmenu -i -l 6 -p "ᜀᜈᜓᜅ᜔ ᜈᜁᜐ᜔ ᜋᜓᜅ᜔ ᜄᜏᜒᜈ᜔?")

if [[ $chosen = "Lock" ]]; then
	/home/makorino/.dwm/lock
elif [[ $chosen = "Logout" ]]; then
	pkill dwm
elif [[ $chosen = "Shutdown" ]]; then
	systemctl poweroff
elif [[ $chosen = "Reboot" ]]; then
	systemctl reboot
elif [[ $chosen = "Suspend" ]]; then
	systemctl suspend
elif [[ $chosen = "Hibernate" ]]; then
	systemctl hibernate
fi
