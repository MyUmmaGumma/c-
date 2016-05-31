#include <iostream>
using namespace std;

enum Direction {
		NORTH,
		SOUTH,
		EAST,
		WEST
} _e;

class Coordinates 
{
	int _x;
	int _y;
		public:
		Coordinates(int x, int y, char dir)
		{
			_x = x;
			_y = y;
			if (dir == 'N') {
				_e = NORTH;
			} else if (dir == 'S') {
				_e = SOUTH;
			} else if (dir == 'E') {
				_e = EAST;
			} else {
				_e = WEST;
			}
		}
		
		Direction getDirection()
		{
			return _e;
		}

		void setDirection(Direction d)
		{
			_e = d;
		}

		void moveRight(Coordinates *c) {
			if (c->getDirection() == NORTH) {
				c->setDirection(EAST);
			} else if (c->getDirection() == SOUTH) {
				c->setDirection(WEST);
			} 
			if (c->getDirection() == EAST) {
				c->setDirection(SOUTH);
			} 
			if (c->getDirection() == WEST) {
				c->setDirection(NORTH);
			} 
		} 

		void moveLeft(Coordinates *c) {
			if (c->getDirection() == NORTH) {
				c->setDirection(WEST);
			} else if (c->getDirection() == SOUTH) {
				c->setDirection(EAST);
			} 
			if (c->getDirection() == EAST) {
				c->setDirection(NORTH);
			} 
			if (c->getDirection() == WEST) {
				c->setDirection(SOUTH);
			} 
		}
	
		void moveForward(Coordinates *c) {
			if (c->getDirection() == NORTH) {
			}
		}
};

class Robot {
	public:
		Coordinates *c;
		Robot(int x, int y, char d) {
			c = new Coordinates(x, y, d);
		}

		void move(const char *seq)
		{
			const char *tmp = seq;
			while (*tmp) {
				switch(*tmp) {
					case 'L':
						c->moveLeft();		
						break;
					case 'R':
						c->moveLeft();		
						break;
					case 'F':
								
						break;
				}			
				tmp++;
			}
		}
};

class World
{
	private:
		//Is the position scented or not
		bool **scented;
		int maxX;
		int maxY;
	public:
		World(int x, int y) : maxX(x), maxY(y)
		{
			*scented = new bool[x];
			for (int i = 0; i < y; i++) {
				scented[i] =  new bool;
			}
		}

		bool hasFallenOff(int x, int y)
		{
			if (x < 0 || x > maxX) {
				return true;
			}
			
			if (y < 0 || y > maxY) {
				return true;
			}

			return false;
		}

		void setScent(int x, int y) 
		{
			scented[x][y] = true;
		}
};

