// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class AbsDMA{
	private:
		char * label;
    	int rating;
    public:
    	AbsDMA(const char * l = "null", int r = 0);
    	AbsDMA(const AbsDMA & rs);
    	virtual ~AbsDMA();
   		AbsDMA & operator=(const AbsDMA & rs);
    	friend std::ostream & operator<<(std::ostream & os, 
                                     const AbsDMA & rs);
        virtual void View()const = 0;
};

//  Base Class Using DMA
class baseDMA : public AbsDMA
{
private:
   int score;
public:
    baseDMA(const char * l = "null", int r = 0, int sc = 0);
    baseDMA(const baseDMA & rs);
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, 
                                     const baseDMA & rs);
	void View()const;
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public AbsDMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const AbsDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, 
                                     const lacksDMA & rs);
	void View()const;
};

// derived class with DMA
class hasDMA : public AbsDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const AbsDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);  
    friend std::ostream & operator<<(std::ostream & os, 
                                     const hasDMA & rs);
	void View()const;
};

#endif
