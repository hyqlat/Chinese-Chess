#pragma once

class vec2 {
public:
	int x;
	int y;
	vec2() {
		x = 0;
		y = 0;
	}
	vec2(int po1, int po2)
	{
		x = po1;
		y = po2;
	}

	void operator=(const vec2 t)
	{
		this->x = t.x;
		this->y = t.y;
	}

	bool operator==(const vec2 t)
	{
		if (this->x == t.x && this->y == t.y)return true;
		else return false;
	}

};
