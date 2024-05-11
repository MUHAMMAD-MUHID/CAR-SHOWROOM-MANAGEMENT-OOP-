#ifndef SHOWROOM_H
#define SHOWROOM_H
class Showroom {
private:
	int id;string name, location;
public:
	Showroom();
	Showroom(int id, string name, string location);
	Showroom(Showroom& obj);
	void set_id(int id);
	void set_name(string name);
	void set_location(string location);
	int get_id();
	string get_name();
	string get_location();
	string toStringShowroom();
	void store_to_file();
	static void view_from_file();
	void search();
	void update();
	void del();
	void menu();
};
#endif // !SHOWROOM_H
