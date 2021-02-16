// zgxq.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//#include"chess.h"
#include"chessboard.h"
#include<time.h>
#include<opencv2/opencv.hpp>

#define CVUI_IMPLEMENTATION
#include "cvui.h"

#define WINDOW_NAME "AT中国象棋"

using namespace cv;

Chessboard CB;
Mat red_chess[7];
Mat black_chess[7];
Mat scrj;
cv::Mat frame;

int width, height;
int cur_x=0, cur_y=0;
int to_x=0, to_y=0;
bool cur_sig=false, to_sig=false;

void reset_option()//重开
{
    cout << "reset" << endl;
    CB.reset_all_points();
    Mat draw_res = CB.draw(red_chess, black_chess, scrj);
    Rect roi_rect = cv::Rect(0, 0, width, height);
    draw_res.copyTo(frame(roi_rect));//
    cvui::window(frame, width, 0, 200, height, "Setting");
    cur_x = cur_y = 0;
    to_x = to_y = 0;
    cvui::update();
    cvui::imshow(WINDOW_NAME, frame);
}

void withdraw_option()//悔棋
{
    cout << "withdraw" << endl;
    CB_change(vec2(cur_x, cur_y),vec2(to_x, to_y), CB,1);
    Mat draw_res = CB.draw(red_chess, black_chess, scrj);
    Rect roi_rect = cv::Rect(0, 0, width, height);
    draw_res.copyTo(frame(roi_rect));//
    cvui::window(frame, width, 0, 200, height, "Setting");
    cur_x = cur_y = 0;
    to_x = to_y = 0;
    cvui::update();
    cvui::imshow(WINDOW_NAME, frame);
}

void draw_all(Mat draw_res)
{
    Rect roi_rect = cv::Rect(0, 0, width, height);//设定整幅图中棋盘位置
    draw_res.copyTo(frame(roi_rect));//

    cvui::window(frame, width, 0, 200, height, "Setting");//设置窗口位置
    
    
    if (cvui::button(frame, width + 40, 40, "new game"))
    {
        reset_option();
        return;
    }
    if (cvui::button(frame, width + 40, 80, "retract a move"))
    {
        withdraw_option();
        return;
    }

    if (cvui::mouse(cvui::LEFT_BUTTON, cvui::CLICK)) {
        cv::Point cursor = cvui::mouse();
        int x = cursor.x;
        int y = cursor.y;
        if (x > 500 || y > 557)
        {
            return;
        }
        cur_x = (x - 3) / 54;
        cur_y = 9 - ((y - 9) / 54);
        cur_sig = true;
        
    }
    if (cvui::mouse(cvui::RIGHT_BUTTON, cvui::CLICK)) {
        cv::Point cursor = cvui::mouse();
        int x = cursor.x;
        int y = cursor.y;
        if (x > 500 || y > 557)
        {
            return;
        }
        to_x = (x - 3) / 54;
        to_y = 9 - ((y - 9) / 54);
        to_sig = true;

    }
    
    // Show window content
    cvui::update();
    cvui::imshow(WINDOW_NAME, frame);
    //waitKey(0);
    
}

//void on_mouse(int event, int x, int y, int flags, void* ustc)
//{
//    if ((event == CV_EVENT_LBUTTONDOWN)&& (flags)  )//鼠标左键按下事件发生 
//    {
//        if ((x>500 && y < 40 && y>60) || (x>500 && x<520) || x>580)
//        {
//            return;
//        }
//        else if ((x > 520 && x < 580) && (y > 40 && y < 60))
//        {
//            cout << "reset" << endl;
//            CB.reset_all_points();
//            Mat draw_res = CB.draw(red_chess, black_chess, scrj);
//            cur_x =  cur_y = 0;
//            to_x =  to_y = 0;
//            draw_all(draw_res);
//        }
//        else
//        {
//            CvPoint pt = cvPoint(x, y);//获取当前点的横纵坐标值  
//            char temp[16];
//            sprintf(temp, "(%d,%d)", pt.x, pt.y);//打印当前坐标值  
//            cout << temp << endl;
//            cur_x = (x - 3) / 54;
//            cur_y = 9 - ((y - 9) / 54);
//        }
//        
// 
//        
//    }
//    else if ((event == CV_EVENT_RBUTTONDOWN) && (flags))
//    {
//        if (x > 500 || y > 557)
//        {
//            return;
//        }
//        CvPoint pt = cvPoint(x, y);//获取当前点的横纵坐标值  
//        char temp[16];
//        sprintf(temp, "(%d,%d)", pt.x, pt.y);//打印当前坐标值  
//        cout << temp << endl;
//        
//        to_x = (x - 3) / 54;
//        to_y = 9 - ((y - 9) / 54);
//        
//    }
//
//
//}

void read_pic()
{
    red_chess[0] = imread("C:\\Users\\JWTQL\\Desktop\\oche.jpg");
    red_chess[1] = imread("C:\\Users\\JWTQL\\Desktop\\oma.jpg");
    red_chess[2] = imread("C:\\Users\\JWTQL\\Desktop\\opao.jpg");
    red_chess[3] = imread("C:\\Users\\JWTQL\\Desktop\\oxiang.jpg");
    red_chess[4] = imread("C:\\Users\\JWTQL\\Desktop\\oshi.jpg");
    red_chess[5] = imread("C:\\Users\\JWTQL\\Desktop\\bing.jpg");
    red_chess[6] = imread("C:\\Users\\JWTQL\\Desktop\\shuai.jpg");

    black_chess[0] = imread("C:\\Users\\JWTQL\\Desktop\\hche.jpg");
    black_chess[1] = imread("C:\\Users\\JWTQL\\Desktop\\hma.jpg");
    black_chess[2] = imread("C:\\Users\\JWTQL\\Desktop\\hpao.jpg");
    black_chess[3] = imread("C:\\Users\\JWTQL\\Desktop\\hxiang.jpg");
    black_chess[4] = imread("C:\\Users\\JWTQL\\Desktop\\hshi.jpg");
    black_chess[5] = imread("C:\\Users\\JWTQL\\Desktop\\zu.jpg");
    black_chess[6] = imread("C:\\Users\\JWTQL\\Desktop\\jiang.jpg");

    scrj = imread("C:\\Users\\JWTQL\\Desktop\\xq.jpg"); //此为你电脑上图片的路径
}


int main()
{
    read_pic();//读入素材图片

    

    // Create a frame
    width = scrj.cols, height = scrj.rows;
    //cout << width << height;
    frame = cv::Mat(cv::Size(width + 200, height), CV_8UC3);//真正的合成窗口(注意通道数！！！
    //
    cv::namedWindow(WINDOW_NAME, 0);
    cvui::init(WINDOW_NAME);//与回调函数冲突,只用这个cvui就好
    //cvSetMouseCallback(WINDOW_NAME, on_mouse, 0);  //注册鼠标相应回调函数     
    
    while (waitKey(30) != 27)
    {
        if (cur_sig && to_sig)//要选定了从哪到哪才更改，不然耗时
        {
            CB_change(vec2(cur_x,cur_y),vec2(to_x,to_y),CB,0);
            cur_sig = to_sig = false;
        } 
        Mat draw_res=CB.draw(red_chess, black_chess, scrj); 
        draw_all(draw_res);

        if (CB.jiang.alive == false)
        {
            cout << "红方获胜！" << endl;
            reset_option();
        }
        else if (CB.shuai.alive == false)
        {
            cout << "蓝方获胜！" << endl;
            reset_option();
        }
                
    }
    destroyAllWindows();
    return 0;
}

