#pragma once
class UserAction
{
public:
	UserAction();
	~UserAction();
	bool m_keypress;
	bool m_upPress;
	bool m_DownPress;
	bool m_playing;
	bool m_options;
	bool m_quit;
};

