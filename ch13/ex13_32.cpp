#include "ex13_32.h"

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}