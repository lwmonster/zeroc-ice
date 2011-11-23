// **********************************************************************
//
// Copyright (c) 2003-2010 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#ifndef TEST_ICE
#define TEST_ICE

[["java:package:test.Ice.stream"]]
module Test
{

enum MyEnum
{
    enum1,
    enum2,
    enum3
};

class MyClass;

["java:serializable:test.Ice.stream.Serialize.Small"] sequence<byte> SerialSmall;

struct SmallStruct
{
    bool bo;
    byte by;
    short sh;
    int i;
    long l;
    float f;
    double d;
    string str;
    MyEnum e;
    MyClass* p;
    SerialSmall ss;
};

sequence<bool> BoolS;
sequence<byte> ByteS;
sequence<short> ShortS;
sequence<int> IntS;
sequence<long> LongS;
sequence<float> FloatS;
sequence<double> DoubleS;
sequence<string> StringS;
sequence<MyEnum> MyEnumS;
sequence<MyClass> MyClassS;

sequence<BoolS> BoolSS;
sequence<ByteS> ByteSS;
sequence<ShortS> ShortSS;
sequence<IntS> IntSS;
sequence<LongS> LongSS;
sequence<FloatS> FloatSS;
sequence<DoubleS> DoubleSS;
sequence<StringS> StringSS;
sequence<MyEnumS> MyEnumSS;
sequence<MyClassS> MyClassSS;

dictionary<byte, bool> ByteBoolD;
dictionary<short, int> ShortIntD;
dictionary<long, float> LongFloatD;
dictionary<string, string> StringStringD;
dictionary<string, MyClass> StringMyClassD;

class MyClass
{
    MyClass c;
    Object o;
    SmallStruct s;
    BoolS seq1;
    ByteS seq2;
    ShortS seq3;
    IntS seq4;
    LongS seq5;
    FloatS seq6;
    DoubleS seq7;
    StringS seq8;
    MyEnumS seq9;
    MyClassS seq10;
    StringMyClassD d;
};

interface MyInterface
{
};

exception MyException
{
    MyClass c;
};

};

#endif