#ifndef WIDGET_H__
#define WIDGET_H__

class Widget
{
public:

   Widget(void);

   ~Widget(void);

	void setSize(int w, int h);
	void setPosition(int x, int y);
	
	void FrameOnFrame(void * frameBuff, FrameData data);
	void config(void); //TODO some kind of dictionnary

protected:
private:
};


#endif  // _WIDGET_H__
