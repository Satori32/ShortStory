#pragma once
#include <stdio.h>

#include "Vector.h"
#include "Type.h"

struct Story {
	//type T = NULL;
	typedef int T;
	T Item;
	VariadicArguments Arg;
	//type R = NULL;
	typedef int R;
	R(*F)(T&, VariadicArguments&) = NULL;
};

struct ShortStory {
	Vector<Story> Storys;
	VariadicArguments Arg;
};

template<class T, class R> Story ConstructStory(T& Item, VariadicArguments& Arg, R(*F)(T&, VariadicArguments&));
bool Free(Story& In);
ShortStory ConstructShortStory(Vector<Story>& V, VariadicArguments& Arg);
bool Free(ShortStory& In);