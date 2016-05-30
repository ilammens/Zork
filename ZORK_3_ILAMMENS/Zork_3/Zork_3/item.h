#ifndef __ITEM_H__
#define __ITEM_H__

#include "entity.h"

class Item : public Entity
{
public:

	Item();
	Item(const char* name, const char* description, e_type type) : Entity(name, description, type){};
	~Item();

};

#endif //item