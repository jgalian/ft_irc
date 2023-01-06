#ifndef USER_HPP
# define USER_HPP

# include "main.hpp"

class User
{
	public:
		User(int fd, Server& server);
		~User();

		int				get_fd() const { return this->_fd; };
		std::string &			get_bufferLine() { return this->_bufferLine; };
		void					clear_bufferLine() { this->_bufferLine.clear(); };
		const std::string		get_nick() const { return this->_nick; };
		void					set_nick(std::string newNick) {	this->_nick = newNick; };
		const std::string		get_username() const { return this->_username; };
		void					set_username(std::string newUsername) { this->_username = newUsername; };
		const std::string		get_host() const { return this->_host; };
		time_t					get_registTime() const { return this->_registTime; };
		time_t					get_time() const { return this->_time; };
		void					reset_time() { this->_time = time(NULL); };
		time_t					get_timeout() const { return this->_timeout; };
		void					set_timeout(time_t timeout) { this->_timeout = timeout; };
		bool					isRegistered() const { return this->_registered; };
		void					set_registered(bool val) { this->_registered = val;};

		void				updateMask(void);
		const std::string&	get_mask(void) const { return this->_mask; };

		void	setHost(const std::string& value);

		int		recv_line();

	private:
		User(void);
		User(const User& src);
		User&	operator=(const User& rhs);

		int				_fd;
		Server &		_server;
		std::string		_mask;
		std::string		_nick;
		std::string		_username;
		std::string		_host;
		std::string		_bufferLine;

		bool			_registered;
		bool			_password;
		time_t			_registTime;
		time_t			_time;
		time_t			_timeout;
};

std::ostream	&operator<<(std::ostream &out, User &rhs);

#endif