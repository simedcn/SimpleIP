//
//  Board.hpp
//  ai_hw
//
//  Created by neroyang on 2017/10/10.
//  Copyright © 2017年 neroyang. All rights reserved.
//

#ifndef OpenIP_Board_hpp
#define OpenIP_Board_hpp

#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "StateBase.hpp"
#include "PixelMap.h"
#include "PNGLoader.h"
#include "Font.h"
#include "FpsLimter.h"
#include <vector>


namespace OpenIP {

    enum STATE{
        RENDERING,STOP
    };
    class Board : public StateBase {
    private:

        char *title;
        int width;
        int height;
        ColorRGB *backGround;

        float _fps;

        PNGLoader* pngLoader = new PNGLoader();
        std::vector<std::vector<ColorRGB *>> colorVector = pngLoader->loadPNG("yz.png");

        STATE state;
        FpsLimter* _fpsLimter = new FpsLimter();

        Font* fps = new Font("default.otf", FONT_MODE::TRANSPARENT,new ColorRGB(0,0,255), new ColorRGB(0,255,0), 100, 100,10, 450);
        Font* fpsNum = new Font("default.otf", FONT_MODE::TRANSPARENT,new ColorRGB(0,0,255), new ColorRGB(0,255,0), 100, 100,60, 450);

        std::vector<std::vector<Pixel *>> pixels;
        std::vector<std::vector<Pixel *>> pixels_zhong;
        std::vector<std::vector<Pixel *>> pixels_zuida;
        std::vector<std::vector<Pixel *>> pixels_zuixiao;

        std::vector<std::vector<Pixel *>> pixels_suanshu;
        std::vector<std::vector<Pixel *>> pixels_jihe;
        std::vector<std::vector<Pixel *>> pixels_xie;
        std::vector<std::vector<Pixel *>> pixels_niexie;


        PixelMap *yuantu;       //原图
        PixelMap *zhongzhi;     //中值滤波
        PixelMap *zuidazhi;     //最大值
        PixelMap *zuixiaozhi;   //最小值

        PixelMap *suanshu;      //算数均值
        PixelMap *jihe;         //几何均值
        PixelMap *xie;          //谐波
        PixelMap *nixie;        //逆谐波


        Font* Open = new Font("default.otf", FONT_MODE::TRANSPARENT,new ColorRGB(255,255,255), new ColorRGB(0,255,0), 500, 500,100, 200);
        Font* IP = new Font("ip2.TTF", FONT_MODE::TRANSPARENT,new ColorRGB(0,255,0), new ColorRGB(0,255,0), 500, 500,400, 200);
    public:
        Board(char *title, int width, int height, ColorRGB *backGround);


        void update();


        void renderFPS();

        virtual void keycallback(
                GLFWwindow *window,
                int key,
                int scancode,
                int action,
                int mods);

        virtual void framebuffer_size_callback(GLFWwindow *window, int w, int h);

        void Render(void);

        int run();
    };
}
#endif /* Board_hpp */
