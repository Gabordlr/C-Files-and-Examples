//Game of snake and ladder with classes
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class snake
{
	int s;
	int e;
	public:
		snake()
		{
			s=0;
			e=0;
		}
		void set_snake(int s1,int e1)
		{
			s=s1;
			e=e1;
		}
		int get_snake_start()
		{
			return s;
		}
		int get_snake_end()
		{
			return e;
		}
};

class ladder
{
	int s;
	int e;
	public:
		ladder()
		{
			s=0;
			e=0;
		}
		void set_ladder(int s1,int e1)
		{
			s=s1;
			e=e1;
		}
		int get_ladder_start()
		{
			return s;
		}
		int get_ladder_end()
		{
			return e;
		}
};

class player
{
	int pos;
	public:
		player()
		{
			pos=0;
		}
		void set_pos(int p)
		{
			pos=p;
		}
		int get_pos()
		{
			return pos;
		}
};

class dice
{
	int d;
	public:
		dice()
		{
			d=0;
		}
		void set_dice(int d1)
		{
			d=d1;
		}
		int get_dice()
		{
			return d;
        }
};

