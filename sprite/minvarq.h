#ifndef MINVARQ_H
#define MINVARQ_H

#include "quant.h"

class MinimalVarianceQuant : public ColorQuant
{
    struct ColorRect
    {
        dword redFrequency[256];
        dword greenFrequency[256];
        dword blueFrequency[256];

        dword variance;
        dword totalWeight;
        dword weightedDistance;
        dword weightedRed;
        dword weightedGreen;
        dword weightedBlue;

        byte redMin, greenMin, blueMin;
        byte redMax, greenMax, blueMax;
    };

    ColorRect  originalColorRect;
    ColorRect* pColorRects;
    int        totalHistogramWeight;
    int        colorsUsed;
    int*       pColorList;
    word*      pHistogram;

    const int  HISTSIZE = 0x40000;
    static int HistIndex( byte r, byte g, byte b )
    {
        return ( ( r & 0xFC ) << 10 ) | ( ( g & 0xFC ) << 4 ) | ( ( b & 0xFC ) >> 2 );
    }

  public:
    MinimalVarianceQuant( );
    ~MinimalVarianceQuant( );

    virtual bool AddImage( const Image* pImage );
    void         AdjustRect( int rectIndex );
    void         SplitColorRect( int oldIndex, int newIndex );
    RGBQUAD      GetRGBColor( int rectIndex ); // NOTE: implementation stolen from varcut.cpp
    virtual bool CreatePalette( RGBQUAD* pPalette, int* palSize );

    //  I don't really want to make these public, but the system qsort
    //  routine seems to have problems with class members, and these are
    //  needed by the compare routines for the sort, so here they are...
    static byte RGB18Red( dword rgb18 ) { return (byte)( ( rgb18 >> 10 ) & 0xFC ); }
    static byte RGB18Green( dword rgb18 ) { return (byte)( ( rgb18 >> 4 ) & 0xFC ); }
    static byte RGB18Blue( dword rgb18 ) { return (byte)( ( rgb18 << 2 ) & 0xFC ); }
};

#endif
