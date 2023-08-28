#pragma once

#include "rlua.h"

BYTE list[6] = {
	0, 0, 0, 0, 0, 0
};

char* __fastcall lua_pseudo_index2adr(uintptr_t a1, int a2) {

	DWORD protection;
	VirtualProtect((void*)(HOOKADDRESS), 5, PAGE_EXECUTE_READWRITE, &protection);

	for (int i = 0; i < 5; i++) {
		*((BYTE*)(HOOKADDRESS + i)) = list[i];
	}

	DWORD temp;
	VirtualProtect((void*)(HOOKADDRESS), 5, protection, &temp);

	LUA_STATE = a1;

	return pseudo_index2adr_func(a1, a2);

}

void HookLuaState() {
	uintptr_t new_jump = (DWORD)((void*)(lua_pseudo_index2adr)) - (HOOKADDRESS)-5;


	print_func(1, std::to_string(new_jump).c_str());

	DWORD protection;
	VirtualProtect((void*)(HOOKADDRESS), 5, PAGE_EXECUTE_READWRITE, &protection);

	for (int i = 0; i < 5; i++) {
		list[i] = *((BYTE*)(HOOKADDRESS + i));
	}


	memset((void*)(HOOKADDRESS), 0x90, 5);

	*(BYTE*)HOOKADDRESS = 0xE9;
	*(uintptr_t*)((uintptr_t)HOOKADDRESS + 1) = new_jump;

	DWORD temp;
	VirtualProtect((void*)(HOOKADDRESS), 5, protection, &temp);

	Sleep(50);

	print_func(1, "EVERYTHINIG SET BACK TO NORMAL");
}
