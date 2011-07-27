#ifndef BUFF_TO_BMP_H__
#define BUFF_TO_BMP_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ImgStruct {
	unsigned int width;
	unsigned int height;
	unsigned char * pixels;
}ImgStruct;

// MACRO to get the adress of a pixel of the image buffer.
// Offset 0 for red, 1 for green and 2 for blue
#define IMG_STRUCT_PIXEL_PTR(img, x, y)		(img->pixels + 3*(x + y*img->width))

int buffToBMP(char * filePath, ImgStruct * img);

ImgStruct * makeImg(int width, int height);
void destroyImg(ImgStruct * img);

void drawVLine(ImgStruct * img, int startX, int constY, int endX, int color);
void drawHLine(ImgStruct * img, int constX, int startY, int endY, int color);
void drawRectangle(ImgStruct * img, int leftX, int topY, int rightX, int bottomY, int color);

#ifdef __cplusplus
}
#endif


#endif // BUFF_TO_BMP_H__
