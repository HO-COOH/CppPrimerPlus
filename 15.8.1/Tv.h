#pragma once
class Remote;	//forward declaration
class Tv
{
	friend class Remote;
private:
	enum _state{ON, OFF} state;
	enum {MaxVal=20};
	unsigned int volume;
	unsigned int maxchannel;
	unsigned int channel;
	enum _mode{ANTENNA, CABLE} mode;
	enum _input{TV, DVD}input;
public:
	Tv(_state st= OFF, unsigned int mc = 125) :state(st), volume(5), maxchannel(mc), channel(2), mode(CABLE), input(TV) {}
	void onoff() { state = (state == ON) ? OFF : ON; }
	bool ison() const { return state == ON; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == ANTENNA) ? CABLE : ANTENNA; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
	void switch_remote(Remote& r);
};

class Remote
{
	friend class Tv;
private:
	enum _state { INTERACTIVE, STANDARD } state;
	void switch_state() { state = (state == INTERACTIVE ? STANDARD : INTERACTIVE); }
public:
	Remote(_state s = STANDARD) :state(s) {}
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	bool set_chan(Tv& t, unsigned int c);
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
	void show() const;
};