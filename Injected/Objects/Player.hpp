#pragma once
#include "Unit.hpp"

extern std::vector<Unit*> units;

class Player : public Unit
{
public:

	Player(int pointer) : Unit(pointer) { }

	uint64 PetGuid()
	{
		for (auto& u : units)
		{
			if (u->Guid() == Guid())
				return Guid();
		}
	}

	int PlayerFlags()
	{
		return addr && GetDescriptor<int>(PLAYER_FLAGS);
	}

	uint64 Coinage()
	{
		return GetDescriptor<uint64>(PLAYER_FIELD_COINAGE);
	}
};