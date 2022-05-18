#pragma once
#include <vector>

template <class entity>
class repository
{
public:
	void add(entity* ent)
	{
		entities.push_back(ent);
	}
	void remove(entity* ent)
	{
		for (auto index = entities.begin(); index != entities.end(); index++)
			if (*index == ent)
			{
				entities.erase(index);
				break;
			}
	}
	int size()
	{
		return entities.size();
	}
	
protected:
	std::vector <entity*> entities;
};