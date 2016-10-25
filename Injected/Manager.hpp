#pragma once
#include <map>
#include <string>
#include <d3d9.h>
#include "Timer.hpp"
#include "D3dx9core.h"
#include "Detour.hpp"
#include "Lua.hpp"
#include "Graphics.hpp"
#include "WowFuncs.hpp"
#include "Spell.hpp"
#include "Helpers.hpp"
#include "PaladinLeveling.hpp"

bool shouldRemoveEndSceneInjection = false;
bool endSceneUnhooked = false;
std::map<std::string, Detour*> g_Detours;

int frameCount = 0;
Graphics* graph = nullptr;
timer afkTimer;

void mrint(std::string name, std::string value)
{
	if (graph == nullptr)
		return;

	std::string line = name + " = " + value;
	graph->AddTextLine(line);
}

//---------------- END SCENE DETOUR ------------------
int __stdcall EndSceneDetour(LPDIRECT3DDEVICE9 device)
{
	auto det = g_Detours["EndScene"];

	OM_Pulse();

	if (frameCount % 30 == 0)
	{
		//printf("%d ", frameCount);
		printf(".");
	}
	if (frameCount == 0)
		chat("CppBot started.");

	if (graph == nullptr && device)
		graph = new Graphics();

	if (afkTimer.elapsedTime() > 150)
	{
		afkTimer.start();
		*(int*)0x00B499A4 = PerformanceCount();
	}

	graph->Pulse(device);

	if (me && me->Class() == CLASS_PALADIN)
		PaladinLeveling();

	frameCount++;

	det->Restore();
	int res = ((int(__stdcall*)(LPDIRECT3DDEVICE9))det->GetOrig())(device);
	if (shouldRemoveEndSceneInjection)
	{
		chat("Removing EndScene injection");
		auto it = g_Detours.find("EndScene");
		delete it->second;
		g_Detours.erase(it);

		if (graph != nullptr)
			delete graph;

		endSceneUnhooked = true;
	}
	else
	{
		det->Apply();
	}
	return res;
}

int __stdcall ResetDetour(LPDIRECT3DDEVICE9 device, int pp)
{
	printf("\nResetDetour\n");
	chat("ResetDetour");

	if (graph != nullptr)
		graph->ReleaseFont();

	auto det = g_Detours["Reset"];
	det->Restore();
	int res = ((int(__stdcall*)(LPDIRECT3DDEVICE9, int))det->GetOrig())(device, pp);
	det->Apply();
	return res;
}