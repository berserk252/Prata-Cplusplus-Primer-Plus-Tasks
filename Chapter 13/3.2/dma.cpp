// dma.cpp --dma class methods

#include "dma.h"
#include <cstring>
//AbsDMA methods
AbsDMA::AbsDMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

AbsDMA::AbsDMA(const AbsDMA & rs)
{
	label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

AbsDMA::~AbsDMA()
{
    delete [] label;
}

AbsDMA & AbsDMA::operator=(const AbsDMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const AbsDMA & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

void AbsDMA::View() const {
	std::cout << "\nLabel: " << label << ", Rating: " << rating << std::endl;
}

// baseDMA methods
baseDMA::baseDMA(const char * l, int r, int sc) : AbsDMA(l, r)
{
    score = sc;
}

baseDMA::baseDMA(const baseDMA & rs) : AbsDMA(rs)
{
    score = rs.score;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
   	AbsDMA::operator=(rs);
   	score = rs.score;
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << (const AbsDMA &) rs << std::endl;
    os << "Score: " << rs.score << std::endl;
    return os;
}


void baseDMA::View() const {
	AbsDMA::View();
	std::cout << "\nScore: " << score << std::endl;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : AbsDMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const AbsDMA & rs)
    : AbsDMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    os << (const AbsDMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

void lacksDMA::View() const {
	AbsDMA::View();
	std::cout << "\nColor: " << color << std::endl;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
         : AbsDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const AbsDMA & rs)
         : AbsDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
         : AbsDMA(hs)  // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    AbsDMA::operator=(hs);  // copy base portion
    delete [] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
    
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << (const AbsDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}

void hasDMA::View() const {
	AbsDMA::View();
	std::cout << "\nStyle: " << style << std::endl;
}
