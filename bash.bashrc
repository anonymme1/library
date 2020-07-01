if [ -x /data/data/com.termux/files/usr/libexec/termux/command-not-found ]; then
	command_not_found_handle() {
		/data/data/com.termux/files/usr/libexec/termux/command-not-found "$1"
	}
fi

PS1='\e[1;91m╔▬▬[\e[1;93m<<differentUser>>\e[1;91m]▬▬[\e[1;97m\W\e[1;91m]▬▬[\e[1;90m\t||\e[1;90m\d\e[1;91m]▬▬▬▬▬▬[\e[1;92m\#\e[1;91m]\n\e[1;91m|\n\e[1;91m╚▬▬>>\e[1;92m'
