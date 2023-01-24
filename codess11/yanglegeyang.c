#include<stdio.h>
#include<easyx.h>
#include<windows.h>//播放音乐 的头文件
#pragma comment(lib,"Winmm.lib")//播放音乐 的库文件

//导入图片前先定义图片
IMAGE img_bk;//背景图片
IMAGE img_item[3];//三维数组

//定义宽高
const int WIDTH  = 400;
const int HEIGHT = 760;
const int INTERVAL = 48;


void loadImg(){
	//加载
	loadimage(&img_bk,"images/bk.jpg", WIDTH, HEIGHT);
	loadimage(img_item + 0,"images/cao.png", 48, 48);//48是图片的大小 
	loadimage(img_item + 1,"images/lingdang.png", 48, 48);
	loadimage(img_item + 2,"images/shu.png", 48, 48);
}


int main(){
	
	//创建窗口
	initgraph(WIDTH,HEIGHT);
	//加载图片函数
	loadImg();

	//播放音乐
	mciSendString(_T("open micc/yang.mp3"), 0, 0, 0);
	mciSendString(_T("play micc/yang.mp3"), 0, 0, 0);
	
	//创建头数组
	// 初始化
	int map [3][3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			map[i][j] = i + 1;
		}
	}

	//打乱数组，创造随机的图片分布
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//数组当中的行和列随机打乱
			int i1 = rand() % 3;
			int j2 = rand() % 3;
			//打乱行和列 交换打乱
			int temp = map[i1][j2];
			map[i1][j2] = map[i][j];
			map[i][j] = temp;
		}
	}
	//算一下数组的位置在哪里
	//找到图片x
	int offsetX = (WIDTH - (2 * INTERVAL + 3 * 48)) / 2;
	//找到y的位置
	int offsetY = (HEIGHT - (2 * INTERVAL + 3 * 48)) / 2;

	//定义逻辑部分的下面的数组:7个卡槽
	int store[7] = { 0 };

	//绘制地图 定义，加载，绘制
	while (1)
	{
		//缓存机制
		BeginBatchDraw();
		//绘制背景地图
		putimage(0,0,&img_bk);
		//渲染 绘制
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//开始渲染
				if (map[i][j])//判断一下，如果map里有值就开始渲染
					//渲染需要萨格参数x，y，图片
					putimage(offsetX + j * (48 + INTERVAL), offsetY + i * (48 + INTERVAL),img_item + (map[i][j]));

			}
		}


		//绘制下面的图片
		for (int i = 0; i < 7; i++)
		{
			if (store[i])
			{
				putimage((i * 50) + 26, 620, img_item + (store[i] - 1));
			}
		}


		EndBatchDraw();
		//点击了创建下面的数组，图片往下掉，进入卡槽
		ExMessage msg = {0};//鼠标点击的消息
		//点击鼠标后是否有消息，消息是WM_LBUTTONDOWN 左键
		if (peekmessage(&msg)&&msg.message == WM_LBUTTONDOWN){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					//鼠标坐标得X
					int x = offsetX + j * (48 + INTERVAL);
					//鼠标坐标Y
					int y = offsetY + i * (48 + INTERVAL);
					//判断鼠标是否点击了图片
					if (msg.x > x && msg.x< x + 48 && msg.y > y && msg.y < y + 48)
					{
						//求出图片对应的数组的位置
						int col = (msg.x - offsetX) / (48 + INTERVAL);
						int row = (msg.y - offsetX) / (48 + INTERVAL);

						//点击到图片渲染得到下面的数组
						for (int  i = 0; i < 7; i++)
						{
							//下面的数组没有
							if (store[i] == 0)
							{
								//上面的数组给下面的数组图片
								store[i] = map[row][col];
								break;
							}

						}
						//记录一下给的次数
						int cnt = 0;
						for (int i = 0; i < 7; i++)
						{
							if (store[i] == map[row][col]) {
								cnt++;
							}

						}
						if (cnt == 3) {
							//消除操作
							for (int i = 0; i < 7; i++)
							{
								
								if (store[i] == map[row][col]) {
									store[i] = 0;
								}
							}
						}
						map[row][col] = 0;
					}

				}
			}
		}

	}



	//创建尾数组

	return 0;
}
