#include "ex13_32.h"

void Message::save(Folder &f)
{
	folders.insert(&f);
	//f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	//f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
	{
		//f->addMsg(this);
	}
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
	{
		//f->remMsg(this);
	}
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	this->contents = rhs.contents;
	this->folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}