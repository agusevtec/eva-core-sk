#ifndef EVACONSTANS_H_
#define EVACONSTANS_H_
#pragma once
namespace eva
{
    static const unsigned char ON_UNCLASSIFIED = 0x00;
    static const unsigned char ON_PRESS = 0x01;
    static const unsigned char ON_RELEASE = 0x02;
    static const unsigned char ON_SHORTCLICK = 0x04;
    static const unsigned char ON_LONGCLICK = 0x08;
    static const unsigned char ON_ELAPSED = 0x10;
    static const unsigned char ON_DATA = 0x40;
    static const unsigned char ON_CHANGED = 0x80;

    static const unsigned char ON_ACTIVE = ON_PRESS;
    static const unsigned char ON_INACTIVE = ON_RELEASE;
}

#endif
