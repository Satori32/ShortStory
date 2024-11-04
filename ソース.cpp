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
	R(*F)(T&, VariadicArguments&)=NULL;
};

template<class T,class R>
Story ConstructStory(T& Item, VariadicArguments& Arg, R(*F)(T&, VariadicArguments&)) {
	Story S;
	S.Item = Item;
	S.Arg = Arg;
	S.F = F;

	return S;
}
bool Free(Story& In) {
	Free(In.Item);
	Free(In.Arg);

	return true;
}

struct ShortStory {
	Vector<Story> Storys;
	VariadicArguments Arg;
};

ShortStory ConstructShortStory(Vector<Story>& V, VariadicArguments& Arg) {
	ShortStory S;
	S.Storys = V;
	S.Arg = Arg;

	return S;
}
bool Free(ShortStory& In) {
	Free(In.Storys);
	Free(In.Arg);

	return true;
}