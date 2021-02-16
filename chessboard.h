#pragma once
#include<iostream>
#include"vec2.h"
#include<string>
#include "windows.h"
#include <stdlib.h>
#include<time.h>
#include<opencv2/opencv.hpp>
#define WINDOW_NAME "CVUI Test"
using namespace cv;

using namespace std;

int mymin(int s1, int s2)
{
	return (s1 > s2) ? s2 : s1;
}
int mymax(int s1, int s2)
{
	return (s1 > s2) ? s1 : s2;
}

//


//

string C_name[8] = { "车","马","炮","象","士","兵","帅","将" };

class Chess;
class Che;
class Chessboard;

struct myPoint
{
	bool isempty;
	Chess* ConB;

	myPoint()
	{
		isempty = true;
		ConB = NULL;
	}

	void clear_points()
	{
		isempty = true;
	}

	void setPoint(Chess* t)
	{
		isempty = false;
		ConB = t;
	}
};

///
class Chess {
public:
	int chessname;
	vec2 position;
	bool alive;
	int fang;//0 hong;1 hei 
	Chess() {}
	/*Chess(int c, vec2 po, bool al, int f)
	{
		chessname = c;
		position = po;
		alive = al;
		fang = f;
	}*/

	virtual bool move(vec2 desitination, Chessboard* CB) = 0;

};



class Che :public Chess {
public:
	Che() :Chess() {}
	void set_Che(int f, vec2 po) 
	{
		position = po;
		chessname = 0;
		alive = true;
		fang = f;
	}
	virtual bool move(vec2 desitination, Chessboard* CB);
};

class Ma :public Chess {
public:
	Ma() :Chess() {}
	void set_Ma(int f, vec2 po)
	{
		position = po;
		chessname = 1;
		alive = true;
		fang = f;
	}
	virtual bool move(vec2 desitination, Chessboard* CB);
};

class Pao :public Chess {
public:
	Pao() :Chess() {}
	void set_Pao(int f, vec2 po)
	{
		position = po;
		chessname = 2;
		alive = true;
		fang = f;
	}
	virtual bool move(vec2 desitination, Chessboard* CB);
};

class Xiang :public Chess {
public:
	Xiang() :Chess() {}
	void set_Xiang(int f, vec2 po)
	{
		position = po;
		chessname = 3;
		alive = true;
		fang = f;
	}
	virtual bool move(vec2 desitination, Chessboard* CB);
};

class Shi :public Chess {
public:
	Shi() :Chess() {}
	void set_Shi(int f, vec2 po)
	{
		position = po;
		chessname = 4;
		alive = true;
		fang = f;
	}
	virtual bool move(vec2 desitination, Chessboard* CB);
};

class Bing :public Chess {
public:
	Bing() :Chess() {}
	void set_Bing(int f, vec2 po)
	{
		position = po;
		chessname = 5;
		alive = true;
		fang = f;
	}
	virtual bool move(vec2 desitination, Chessboard* CB);
};

class Shuai :public Chess {
public:
	Shuai() :Chess() {}
	void set_Shuai(int f, vec2 po)
	{
		position = po;
		chessname = 6;
		alive = true;
		fang = f;
	}
	virtual bool move(vec2 desitination, Chessboard* CB);
};

class Jiang :public Chess {
public:
	Jiang() :Chess() {}
	void set_Jiang(int f, vec2 po)
	{
		position = po;
		chessname = 7;
		alive = true;
		fang = f;
	}
	virtual bool move(vec2 desitination, Chessboard* CB);
};


///
void Mix_pic(Mat qizi,Mat &qipan,int px,int py)
{
	Mat dst = Mat::zeros(40, 40, CV_8UC3); //棋子图像缩放
	//cout << dst.size();
	resize(qizi, dst, dst.size());

	Rect roi_rect1 = cv::Rect(px, py, dst.cols, dst.rows);

	Mat mix_res = Mat::zeros(40, 40, CV_8UC3);
	addWeighted(qipan(roi_rect1), 0.4, dst, 0.6, 0, mix_res);

	mix_res.copyTo(qipan(roi_rect1));


}
Chess* beichi=NULL;
Chess* chi = NULL;

class Chessboard {
public:
	myPoint BoardMap[9][10];
	Che che1, che2, che3, che4;
	Ma ma1, ma2, ma3, ma4;
	Pao pao1, pao2, pao3, pao4;
	Xiang xiang1, xiang2, xiang3, xiang4;
	Shi shi1, shi2, shi3, shi4;
	Bing bing[10];
	Shuai shuai;
	Jiang jiang;

	Chessboard()
	{
		che1.set_Che(0, vec2(0, 0));BoardMap[0][0].setPoint(&che1);
		che2.set_Che(0, vec2(8, 0));BoardMap[8][0].setPoint(&che2);
		che3.set_Che(1, vec2(0, 9));BoardMap[0][9].setPoint(&che3);
		che4.set_Che(1, vec2(8, 9));BoardMap[8][9].setPoint(&che4);

		ma1.set_Ma(0, vec2(1, 0)); BoardMap[1][0].setPoint(&ma1);
		ma2.set_Ma(0, vec2(7, 0)); BoardMap[7][0].setPoint(&ma2);
		ma3.set_Ma(1, vec2(1, 9)); BoardMap[1][9].setPoint(&ma3);
		ma4.set_Ma(1, vec2(7, 9)); BoardMap[7][9].setPoint(&ma4);

		pao1.set_Pao(0, vec2(1, 2)); BoardMap[1][2].setPoint(&pao1);
		pao2.set_Pao(0, vec2(7, 2)); BoardMap[7][2].setPoint(&pao2);
		pao3.set_Pao(1, vec2(1, 7)); BoardMap[1][7].setPoint(&pao3);
		pao4.set_Pao(1, vec2(7, 7)); BoardMap[7][7].setPoint(&pao4);

		xiang1.set_Xiang(0, vec2(2,0)); BoardMap[2][0].setPoint(&xiang1);
		xiang2.set_Xiang(0, vec2(6,0)); BoardMap[6][0].setPoint(&xiang2);
		xiang3.set_Xiang(1, vec2(2,9)); BoardMap[2][9].setPoint(&xiang3);
		xiang4.set_Xiang(1, vec2(6,9)); BoardMap[6][9].setPoint(&xiang4);

		shi1.set_Shi(0, vec2(3, 0)); BoardMap[3][0].setPoint(&shi1);
		shi2.set_Shi(0, vec2(5, 0)); BoardMap[5][0].setPoint(&shi2);
		shi3.set_Shi(1, vec2(3, 9)); BoardMap[3][9].setPoint(&shi3);
		shi4.set_Shi(1, vec2(5, 9)); BoardMap[5][9].setPoint(&shi4);

		bing[0].set_Bing(0, vec2(0, 3)); BoardMap[0][3].setPoint(&bing[0]);
		bing[1].set_Bing(0, vec2(2, 3)); BoardMap[2][3].setPoint(&bing[1]);
		bing[2].set_Bing(0, vec2(4, 3)); BoardMap[4][3].setPoint(&bing[2]);
		bing[3].set_Bing(0, vec2(6, 3)); BoardMap[6][3].setPoint(&bing[3]);
		bing[4].set_Bing(0, vec2(8, 3)); BoardMap[8][3].setPoint(&bing[4]);
		bing[5].set_Bing(1, vec2(0, 6)); BoardMap[0][6].setPoint(&bing[5]);
		bing[6].set_Bing(1, vec2(2, 6)); BoardMap[2][6].setPoint(&bing[6]);
		bing[7].set_Bing(1, vec2(4, 6)); BoardMap[4][6].setPoint(&bing[7]);
		bing[8].set_Bing(1, vec2(6, 6)); BoardMap[6][6].setPoint(&bing[8]);
		bing[9].set_Bing(1, vec2(8, 6)); BoardMap[8][6].setPoint(&bing[9]);

		shuai.set_Shuai(0, vec2(4, 0)); BoardMap[4][0].setPoint(&shuai);
		jiang.set_Jiang(1, vec2(4, 9)); BoardMap[4][9].setPoint(&jiang);

	}

	
	void reset_all_points()
	{
		for (int i = 0; i <9 ; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				BoardMap[i][j].clear_points();
			}
		}

		che1.set_Che(0, vec2(0, 0)); BoardMap[0][0].setPoint(&che1);
		che2.set_Che(0, vec2(8, 0)); BoardMap[8][0].setPoint(&che2);
		che3.set_Che(1, vec2(0, 9)); BoardMap[0][9].setPoint(&che3);
		che4.set_Che(1, vec2(8, 9)); BoardMap[8][9].setPoint(&che4);

		ma1.set_Ma(0, vec2(1, 0)); BoardMap[1][0].setPoint(&ma1);
		ma2.set_Ma(0, vec2(7, 0)); BoardMap[7][0].setPoint(&ma2);
		ma3.set_Ma(1, vec2(1, 9)); BoardMap[1][9].setPoint(&ma3);
		ma4.set_Ma(1, vec2(7, 9)); BoardMap[7][9].setPoint(&ma4);

		pao1.set_Pao(0, vec2(1, 2)); BoardMap[1][2].setPoint(&pao1);
		pao2.set_Pao(0, vec2(7, 2)); BoardMap[7][2].setPoint(&pao2);
		pao3.set_Pao(1, vec2(1, 7)); BoardMap[1][7].setPoint(&pao3);
		pao4.set_Pao(1, vec2(7, 7)); BoardMap[7][7].setPoint(&pao4);

		xiang1.set_Xiang(0, vec2(2, 0)); BoardMap[2][0].setPoint(&xiang1);
		xiang2.set_Xiang(0, vec2(6, 0)); BoardMap[6][0].setPoint(&xiang2);
		xiang3.set_Xiang(1, vec2(2, 9)); BoardMap[2][9].setPoint(&xiang3);
		xiang4.set_Xiang(1, vec2(6, 9)); BoardMap[6][9].setPoint(&xiang4);

		shi1.set_Shi(0, vec2(3, 0)); BoardMap[3][0].setPoint(&shi1);
		shi2.set_Shi(0, vec2(5, 0)); BoardMap[5][0].setPoint(&shi2);
		shi3.set_Shi(1, vec2(3, 9)); BoardMap[3][9].setPoint(&shi3);
		shi4.set_Shi(1, vec2(5, 9)); BoardMap[5][9].setPoint(&shi4);

		bing[0].set_Bing(0, vec2(0, 3)); BoardMap[0][3].setPoint(&bing[0]);
		bing[1].set_Bing(0, vec2(2, 3)); BoardMap[2][3].setPoint(&bing[1]);
		bing[2].set_Bing(0, vec2(4, 3)); BoardMap[4][3].setPoint(&bing[2]);
		bing[3].set_Bing(0, vec2(6, 3)); BoardMap[6][3].setPoint(&bing[3]);
		bing[4].set_Bing(0, vec2(8, 3)); BoardMap[8][3].setPoint(&bing[4]);
		bing[5].set_Bing(1, vec2(0, 6)); BoardMap[0][6].setPoint(&bing[5]);
		bing[6].set_Bing(1, vec2(2, 6)); BoardMap[2][6].setPoint(&bing[6]);
		bing[7].set_Bing(1, vec2(4, 6)); BoardMap[4][6].setPoint(&bing[7]);
		bing[8].set_Bing(1, vec2(6, 6)); BoardMap[6][6].setPoint(&bing[8]);
		bing[9].set_Bing(1, vec2(8, 6)); BoardMap[8][6].setPoint(&bing[9]);

		shuai.set_Shuai(0, vec2(4, 0)); BoardMap[4][0].setPoint(&shuai);
		jiang.set_Jiang(1, vec2(4, 9)); BoardMap[4][9].setPoint(&jiang);

	}

	Mat draw(Mat *red,Mat* black,Mat in)
	{
		
		Mat in_qp=in.clone();//才是深拷贝！！
		
		for (int i = 9; i >= 0; i--)
		{
			for (int j = 0; j < 9; j++)
			{
				if (BoardMap[j][i].isempty)
				{
					//printf("   ");
				}
				else
				{
					if (BoardMap[j][i].ConB->fang == 1)
					{
						//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
						//设置蓝色
						//int po_x, po_y;
						
						if (BoardMap[j][i].ConB->chessname == 7)
						{
							Mix_pic(black[6], in_qp, 10 + j * 54, 16 + (9 - i) * 54);
						}
						else {
							Mix_pic(black[BoardMap[j][i].ConB->chessname],in_qp,10+j*54,16+(9-i)*54);
						}
						
						
					}
					else
					{
						//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						//设置红色
						Mix_pic(red[BoardMap[j][i].ConB->chessname], in_qp, 10 + j * 54, 16 + (9 - i) * 54);

					}
					//cout << C_name[temp->chessname] << " ";
				}
			}
			
		}

		//imshow(WINDOW_NAME, in_qp);
		return in_qp;
		//destroyAllWindows();
		

		//int temp;
		//temp = rand() % 11;
		//Sleep(temp*1000);
		//system("cls");
		//for (int i = 9; i >= 0; i--)
		//{
		//	for (int j = 0; j < 9; j++)
		//	{
		//		Chess* temp = BoardMap[j][i].ConB;
		//		if (BoardMap[j][i].isempty)
		//		{
		//			printf("   ");
		//		}
		//		else
		//		{
		//			if (BoardMap[j][i].ConB->fang==1)
		//			{
		//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		//				//设置蓝色
		//			}
		//			else
		//			{
		//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		//				//设置红色
		//			}
		//			cout<<C_name[temp->chessname]<<" ";
		//		}
		//	}
		//	printf("\n");
		//}
		//printf("\n\n");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
	}
};

bool CB_change(vec2 cha_point, vec2 dest, Chessboard& CB,int do_or_redo)//do 0
{
	if (do_or_redo == 1)//悔棋
	{
		if (cha_point == dest)return false;
		if (beichi != NULL)
		{
			beichi->alive = true;
			beichi->position = dest;
			CB.BoardMap[dest.x][dest.y].setPoint(beichi);
		}
		else
		{
			CB.BoardMap[dest.x][dest.y].isempty = true;
			CB.BoardMap[dest.x][dest.y].ConB = NULL;
		}
		if (chi != NULL)
		{
			chi->position = cha_point;
			CB.BoardMap[cha_point.x][cha_point.y].setPoint(chi);
		}

		beichi = NULL;
		chi = NULL;

		return true;
	}

	if (CB.BoardMap[cha_point.x][cha_point.y].isempty)
	{
		//cout << "no chess in it\n";
		return false;
	}
	else
	{
		Chess* t = CB.BoardMap[cha_point.x][cha_point.y].ConB;
		bool res = t->move(dest, &CB);
		if (res)
		{
			beichi = CB.BoardMap[dest.x][dest.y].ConB;
			chi=CB.BoardMap[cha_point.x][cha_point.y].ConB;
			CB.BoardMap[cha_point.x][cha_point.y].isempty = true;
			CB.BoardMap[dest.x][dest.y].ConB = CB.BoardMap[cha_point.x][cha_point.y].ConB;
			CB.BoardMap[dest.x][dest.y].isempty = false;
			CB.BoardMap[cha_point.x][cha_point.y].ConB = NULL;
			
			return true;
		}
		else return false;
	}

}

bool Che::move(vec2 desitination, Chessboard* CB)
{
	if (desitination.x != position.x && desitination.y != position.y)
	{
		return false;
	}
	if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
	{
		if ((CB->BoardMap[desitination.x][desitination.y].ConB->fang) == this->fang)return false;
		else
		{
			if (desitination.x == position.x)
			{
				int beg = mymin(desitination.y, position.y);
				int end = mymax(desitination.y, position.y);
				for (int i = beg + 1; i < end; i++)
				{
					if (CB->BoardMap[position.x][i].isempty == false)
					{
						return false;
					}
				}

				position = desitination;
				CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				return true;
			}
			else
			{
				int beg = mymin(desitination.x, position.x);
				int end = mymax(desitination.x, position.x);
				for (int i = beg + 1; i < end; i++)
				{
					if (CB->BoardMap[i][position.y].isempty == false)
					{
						return false;
					}
				}
			}
			CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
			position = desitination;
			return true;
		}
	}
	if (desitination.x == position.x)
	{
		int beg = mymin(desitination.y, position.y);
		int end = mymax(desitination.y, position.y);
		for (int i = beg + 1; i < end; i++)
		{
			if (CB->BoardMap[position.x][i].isempty == false)
			{
				return false;
			}
		}

		position = desitination;
		return true;
	}
	else
	{
		int beg = mymin(desitination.x, position.x);
		int end = mymax(desitination.x, position.x);
		for (int i = beg + 1; i < end; i++)
		{
			if (CB->BoardMap[i][position.y].isempty == false)
			{
				return false;
			}
		}

		position = desitination;
		return true;
	}

}

bool Ma::move(vec2 desitination, Chessboard* CB)
{
	int mx = desitination.x;
	int my = desitination.y;
	int nx = position.x;
	int ny = position.y;
//(mx == nx - 2 && (my == ny + 1 || my == ny - 1)) || (mx == nx - 1 && (my == ny + 2 || my == ny - 2)) || (mx == nx + 1 && (my == ny + 2 || my == ny - 2)) || (mx == nx + 2 && (my == ny + 1 || my == ny - 1))
	if (mx == nx - 2)
	{
		if (my == ny + 1)
		{
			if (nx < 2 || ny>8 || CB->BoardMap[nx-1][ny].isempty==false || (CB->BoardMap[desitination.x][desitination.y].isempty==false && CB->BoardMap[desitination.x][desitination.y].ConB->fang==this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty==false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}
			
		}
		else if (my == ny - 1)
		{
			if (nx < 2 || ny<1 || CB->BoardMap[nx - 1][ny].isempty == false || (CB->BoardMap[desitination.x][desitination.y].isempty == false && CB->BoardMap[desitination.x][desitination.y].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}

		}
		else return false;


	}
	else if (mx == nx - 1)
	{
		if (my == ny + 2)
		{
			if (nx < 1 || ny>7 || CB->BoardMap[nx][ny+1].isempty == false || (CB->BoardMap[desitination.x][desitination.y].isempty == false && CB->BoardMap[desitination.x][desitination.y].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}

		}
		else if (my == ny - 2)
		{
			if (nx < 1 || ny < 2 || CB->BoardMap[nx][ny - 1].isempty == false || (CB->BoardMap[desitination.x][desitination.y].isempty == false && CB->BoardMap[desitination.x][desitination.y].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}

		}
		else return false;

	}
	else if (mx == nx + 1)
	{
		if (my == ny + 2)
		{
			if (nx >7 || ny>7 || CB->BoardMap[nx][ny + 1].isempty == false || (CB->BoardMap[desitination.x][desitination.y].isempty == false && CB->BoardMap[desitination.x][desitination.y].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}

		}
		else if (my == ny - 2)
		{
			if (nx >7 || ny < 2 || CB->BoardMap[nx][ny - 1].isempty == false || (CB->BoardMap[desitination.x][desitination.y].isempty == false && CB->BoardMap[desitination.x][desitination.y].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}

		}
		else return false;

	}
	else if (mx == nx + 2)
	{
		if (my == ny + 1)
		{
			if (nx >6 || ny>8 || CB->BoardMap[nx + 1][ny].isempty == false || (CB->BoardMap[desitination.x][desitination.y].isempty == false && CB->BoardMap[desitination.x][desitination.y].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}

		}
		else if (my == ny - 1)
		{
			if (nx >6 || ny < 1 || CB->BoardMap[nx + 1][ny].isempty == false || (CB->BoardMap[desitination.x][desitination.y].isempty == false && CB->BoardMap[desitination.x][desitination.y].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}

		}
		else return false;


	}
	else return false;
	
}

bool Pao::move(vec2 desitination, Chessboard* CB)
{
	if (desitination.x != position.x && desitination.y != position.y)
	{
		return false;
	}
	int count=0;
	if (desitination.x == position.x)//
	{
		int beg = mymin(desitination.y, position.y);
		int end = mymax(desitination.y, position.y);
		for (int i = beg + 1; i < end; i++)
		{
			if (CB->BoardMap[position.x][i].isempty == false)
			{
				count++;
				if (count > 1)return false;
			}
		}

	}
	else
	{
		int beg = mymin(desitination.x, position.x);
		int end = mymax(desitination.x, position.x);
		for (int i = beg + 1; i < end; i++)
		{
			if (CB->BoardMap[i][position.y].isempty == false)
			{
				count++;
				if (count > 1)return false;
			}
		}

	}

	if (count == 0)
	{
		if (CB->BoardMap[desitination.x][desitination.y].isempty == false)return false;
		else
		{
			position = desitination;
			return true;
		}

	}
	else {
		if (CB->BoardMap[desitination.x][desitination.y].isempty == true || (CB->BoardMap[desitination.x][desitination.y].isempty == false && CB->BoardMap[desitination.x][desitination.y].ConB->fang == this->fang))return false;
		else
		{
			position = desitination;
			if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
			{
				CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
			}
			return true;
		}

	}
	return true;
}

bool Xiang::move(vec2 desitination, Chessboard* CB)
{
	int mx = desitination.x;
	int my = desitination.y;
	int nx = position.x;
	int ny = position.y;
	if (mx == (nx-2))
	{
		if (nx < 2)return false;
		else if (my == (ny + 2))
		{
			if ((ny > 7) || (this->fang == 0 && my > 4) || (CB->BoardMap[nx - 1][ny + 1].isempty == false) || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}
		}
		else if (my == ny - 2)
		{
			if ((ny < 2 ) || (this->fang == 1 && my < 5 ) || (CB->BoardMap[nx - 1][ny - 1].isempty == false) || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}
		}
		else return false;

	}
	else if (mx == (nx + 2))
	{
		if (nx > 7)return false;
		else if (my == (ny + 2))
		{
			if ((ny > 7) || (this->fang == 0 && my > 4) || (CB->BoardMap[nx + 1][ny + 1].isempty == false) || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}
		}
		else if (my == ny - 2)
		{
			if ((ny < 2) || (this->fang == 1 && my < 5) || (CB->BoardMap[nx + 1][ny - 1].isempty == false) || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))
			{
				return false;
			}
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}
		}
		else return false;

	}
	else return false;
}

bool Shi::move(vec2 desitination, Chessboard* CB)
{
	int mx = desitination.x;
	int my = desitination.y;
	int nx = position.x;
	int ny = position.y;

	if (mx < 3 || mx>5 || (this->fang == 0 && (my > 2 || my < 0)) || (this->fang == 1 && (my > 9 || my < 7)) || (nx==mx) || (my==ny) || abs(nx-mx)!=1 || abs(ny-my)!=1 || (CB->BoardMap[mx][my].isempty==false && CB->BoardMap[mx][my].ConB->fang==this->fang))return false;
	else
	{
		position = desitination;
		if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
		{
			CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
		}
		return true;
	}

}

bool Bing::move(vec2 desitination, Chessboard* CB)
{
	int f = this->fang;
	int mx = desitination.x;
	int my = desitination.y;
	int nx = position.x;
	int ny = position.y;
	
	if (f == 0)//红方
	{
		if (ny <= 4)//没过河
		{
			if (my != ny + 1 || (abs(nx - mx) + abs(ny - my) != 1) || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))return false;
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}
		}
		else//过河了
		{
			if (my<ny ||(abs(nx - mx) + abs(ny - my) != 1) || my < 0 || my>9 || mx < 0 || mx>8 || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))return false;
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}
		}

	}
	else//蓝方
	{
		if (ny >= 5)//没过河
		{
			if (my != ny - 1 || (abs(nx - mx) + abs(ny - my) != 1) || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))return false;
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}
		}
		else//过河了
		{
			if (my>ny ||(abs(nx - mx) + abs(ny - my) != 1) || my < 0 || my>9 || mx < 0 || mx>8 || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))return false;
			else
			{
				position = desitination;
				if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
				{
					CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
				}
				return true;
			}
		}

	}

}

bool Shuai::move(vec2 desitination, Chessboard* CB)
{
	int mx = desitination.x;
	int my = desitination.y;
	int nx = position.x;
	int ny = position.y;

	if (mx < 3 || mx>5 || my > 2 || my < 0 ||  (abs(nx - mx)+abs(ny - my)!= 1)  || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))return false;
	else
	{
		position = desitination;
		if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
		{
			CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
		}
		return true;
	}

}

bool Jiang::move(vec2 desitination, Chessboard* CB)
{
	int mx = desitination.x;
	int my = desitination.y;
	int nx = position.x;
	int ny = position.y;

	if (mx < 3 || mx>5 || my > 9 || my < 7 || (abs(nx - mx) + abs(ny - my) != 1) || (CB->BoardMap[mx][my].isempty == false && CB->BoardMap[mx][my].ConB->fang == this->fang))return false;
	else
	{
		position = desitination;
		if (CB->BoardMap[desitination.x][desitination.y].isempty == false)
		{
			CB->BoardMap[desitination.x][desitination.y].ConB->alive = false;
		}
		return true;
	}

}