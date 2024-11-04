#include "ShortStory.h"

template<class T, class R>
Story ConstructStory(T& Item, VariadicArguments& Arg, R(*F)(T&, VariadicArguments&)) {
	Story S;
	S.Item = Item;
	S.Arg = Arg;
	S.F = F;
	//S.T = T;
	//S.R = R;

	return S;
}
bool Free(Story& In) {
	Free(In.Item);
	Free(In.Arg);

	return true;
}

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