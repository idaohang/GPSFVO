#include "buffToBMP.h"


#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

int buffToBMP(char * filePath, ImgStruct * img)
{
	FILE * bmpFile;
	int x,y;
	char *writeBuff=NULL;
	
	if(!img)
	{
		printf("No images passed\n");
		return -1;
	}
	
	// Create file
	bmpFile = fopen(filePath, "wb");
	if(bmpFile<=0)
	{
		printf("Open failed (%d)\n", errno);
		return -1;
	}

	writeBuff = (char *) malloc(9*sizeof(char));
	if(!writeBuff)
	{
		printf("Malloc writting buffer failed\n");
		return -1;
	}

	//Write a BMP header that works with most viewers
	*(writeBuff+0) = 0x42;
	*(writeBuff+1) = 0x4D;
	*(writeBuff+2) = 0xF6;
	*(writeBuff+3) = 0xC5;
	*(writeBuff+4) = 0x01;
	*(writeBuff+5) = 0x00;
	*(writeBuff+6) = 0x00;
	*(writeBuff+7) = 0x00;
	fwrite(writeBuff, sizeof(char), 8, bmpFile);

	*(writeBuff+0) = 0x00;
	*(writeBuff+1) = 0x00;
	*(writeBuff+2) = 0x36;
	*(writeBuff+3) = 0x00;
	*(writeBuff+4) = 0x00;
	*(writeBuff+5) = 0x00;
	*(writeBuff+6) = 0x28;
	*(writeBuff+7) = 0x00;
	fwrite(writeBuff, sizeof(char), 8, bmpFile);
	
	*(writeBuff+0) = 0x00;
	*(writeBuff+1) = 0x00;
	*(writeBuff+2) = img->width % 256;			//WIDTH LSB
	*(writeBuff+3) = (img->width/256); 	//WIDTH HSB
	*(writeBuff+4) = 0x00;
	*(writeBuff+5) = 0x00;
	*(writeBuff+6) = img->height % 256;		//HEIGHT LSB
	*(writeBuff+7) = (img->height/256);	//HEIGHT HSB
	fwrite(writeBuff, sizeof(char), 8, bmpFile);

	*(writeBuff+0) = 0x00;
	*(writeBuff+1) = 0x00;
	*(writeBuff+2) = 0x01;
	*(writeBuff+3) = 0x00;
	*(writeBuff+4) = 0x18;
	*(writeBuff+5) = 0x00;
	*(writeBuff+6) = 0x00;
	*(writeBuff+7) = 0x00;
	fwrite(writeBuff, sizeof(char), 8, bmpFile);

	*(writeBuff+0) = 0x00;
	*(writeBuff+1) = 0x00;
	*(writeBuff+2) = 0xC0;
	*(writeBuff+3) = 0xC5;
	*(writeBuff+4) = 0x01;
	*(writeBuff+5) = 0x00;
	*(writeBuff+6) = 0x12;
	*(writeBuff+7) = 0x0B;
	fwrite(writeBuff, sizeof(char), 8, bmpFile);

	*(writeBuff+0) = 0x00;
	*(writeBuff+1) = 0x00;
	*(writeBuff+2) = 0x12;
	*(writeBuff+3) = 0x0B;
	*(writeBuff+4) = 0x00;
	*(writeBuff+5) = 0x00;
	*(writeBuff+6) = 0x00;
	*(writeBuff+7) = 0x00;
	fwrite(writeBuff, sizeof(char), 8, bmpFile);

	*(writeBuff+0) = 0x00;
	*(writeBuff+1) = 0x00;
	*(writeBuff+2) = 0x00;
	*(writeBuff+3) = 0x00;
	*(writeBuff+4) = 0x00;
	*(writeBuff+5) = 0x00;
	fwrite(writeBuff, sizeof(char), 6, bmpFile);

	//Write pixels (BGR and line by line from left bottom to top rigth)
	for(y=img->height-1; y>=0; y--)
	{
		unsigned char * currentPixel = IMG_STRUCT_PIXEL_PTR(img, 0, y);
		for(x=0; x<img->width; x++)
		{
			*(writeBuff+0) = *(currentPixel+2);
			*(writeBuff+1) = *(currentPixel+1);
			*(writeBuff+2) = *(currentPixel);
			fwrite(writeBuff, sizeof(char), 3, bmpFile);
			currentPixel+=3;
		}
		//Fill line alignment (4 bytes) with zeros
		//(writeBuff+3) and later are set to 0 during last header 8 bytes write
		fwrite((writeBuff+3), sizeof(char), (4-((img->width*3)%4))%4, bmpFile);
	}


	//Close everything
	free(writeBuff);
	fclose(bmpFile);
	
	return 0;
}

ImgStruct * makeImg(int width, int height)
{
	ImgStruct * returnedImg = NULL;
	returnedImg = (ImgStruct *) malloc(sizeof(ImgStruct));
	if(!returnedImg)	return NULL;
	returnedImg->width=width;
	returnedImg->height=height;
	returnedImg->pixels= (unsigned char *) malloc((3*sizeof(unsigned char))*width*height);
	if(!returnedImg->pixels)
	{
		free(returnedImg);
		return NULL;
	}
	
	return returnedImg;
}

void destroyImg(ImgStruct * img)
{
	if(!img)	return;
	if(img->pixels)	free(img->pixels);
	free(img);
}

void drawHLine(ImgStruct * img, int startX, int constY, int endX, int color)
{
	int x;
	if(startX>endX)
	{
		int tmp=startX;
		startX=endX;
		endX=tmp;
	}
	
	for(x=startX; x<=endX; x++)
	{
		unsigned char *pixel = IMG_STRUCT_PIXEL_PTR(img, x, constY);
		*(pixel+0) = (char) ((color&0xff0000)>>16);
		*(pixel+1) = (char) ((color&0x00ff00)>>8);
		*(pixel+2) = (char) ((color&0x0000ff)>>0);
	}
}

void drawVLine(ImgStruct * img, int constX, int startY, int endY, int color)
{
	int y;
	if(startY>endY)
	{
		int tmp=startY;
		startY=endY;
		endY=tmp;
	}
	
	for(y=startY; y<=endY; y++)
	{
		unsigned char *pixel = IMG_STRUCT_PIXEL_PTR(img, constX, y);
		*(pixel+0) = (char) ((color&0xff0000)>>16);
		*(pixel+1) = (char) ((color&0x00ff00)>>8);
		*(pixel+2) = (char) ((color&0x0000ff)>>0);
	}
}

void drawRectangle(ImgStruct * img, int leftX, int topY, int rightX, int bottomY, int color)
{
	drawVLine(img, leftX, topY, bottomY, color);
	drawHLine(img, leftX, bottomY, rightX, color);
	drawVLine(img, rightX, topY, bottomY, color);
	drawHLine(img, leftX, topY, rightX, color);
}

