#include "main.hpp"

int		cmd_nick(Message &message)
{
	User &user = *message.get_user();
	std::string line;

	line = user.get_nick() + " has change his NICK to: " + message.get_params()[0] + "\n";

	message.set_lineToSend(line);
	user.set_nick(message.get_params().front());
	
	user.updateMask();

	if (!user.isRegistered() && user.get_username() != "unknown" && user.get_nick() != "*")
		send_all(user.get_fd(), "PING :irc-serv\n");
	return 0;
}