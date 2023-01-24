#include<stdio.h>
#include<stdbool.h>
#include"SDL2\SDL.h"
#include "SDL2\SDL_main.h"
#include"SDL2\SDL_ttf.h"
#include"SDL2\SDL_mixer.h"
#include"SDL2\SDL_image.h"
int main(int argc,char *argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    
    int x=0;
    int WindowWidth = 150;
    int WindowHeight = 300;

    SDL_Window *Window=SDL_CreateWindow("hello!",x,SDL_WINDOWPOS_CENTERED,WindowWidth,WindowHeight,SDL_WINDOW_SHOWN);
    
    SDL_Renderer *Renderer=SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(Renderer,0,0,0,255);
    // RGBA ~ Red Green Blue Alpha 
    
    
    bool IsQuit = false;

    
    
    SDL_Event event;

    SDL_Rect ScreenRect;
    SDL_GetDisplayBounds(0,&ScreenRect);//得到屏幕的尺寸


    int direction = 1;
    // SDL_SetWindowBordered(Window,false);//不显示边框
    // SDL_SetWindowMouseGrab(Window,true);//控制使鼠标在窗口内
    // SDL_Rect rect={100,100,10,10};
    // SDL_SetWindowMouseRect(Window,&rect);//进一步压缩鼠标的活动空间


    
    // SDL_FlashWindow(Window,SDL_FLASH_BRIEFLY);//小窗闪烁(注意焦点)

    SDL_SetRenderDrawBlendMode(Renderer,SDL_BLENDMODE_BLEND);//允许绘制透明色
    
    while(!IsQuit){
        while(SDL_PollEvent(&event)){
            if(event.type ==  SDL_QUIT){
                IsQuit = true;
            }
        }



        if(x+WindowWidth>=ScreenRect.w){
            direction=-1;
        }
        else if(x<0){
            direction=1;
        }
        x+=10*direction;
        
        SDL_SetRenderDrawColor(Renderer,0,0,0,255);
        SDL_RenderClear(Renderer);//使用绘图颜色清除当前呈现目标

        SDL_SetRenderDrawColor(Renderer,255,0,255,100);
        SDL_Rect rect1={50,50,25,25};
        SDL_RenderFillRect(Renderer,&rect1);
        SDL_SetRenderDrawColor(Renderer,0,255,0,255);
        SDL_RenderDrawRect(Renderer,&rect1);

        SDL_SetRenderDrawColor(Renderer,0,255,255,100);
        SDL_Rect rect2={60,60,25,25};
        SDL_RenderFillRect(Renderer,&rect2);
        SDL_SetRenderDrawColor(Renderer,0,255,0,255);
        SDL_RenderDrawRect(Renderer,&rect2);



        //SDL_SetWindowPosition(Window,x,SDL_WINDOWPOS_CENTERED);


        SDL_RenderPresent(Renderer);





        SDL_Delay(3000);
    }




    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
    return 0;
}