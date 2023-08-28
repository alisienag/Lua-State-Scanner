#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream> 
#include <winuser.h>
#include <string>

#define aslr(x) (x - 0x400000 + (DWORD)GetModuleHandleA(0))

uintptr_t HOOKADDRESS = aslr(0x01BEBC80); //PSEUDO INDEX2ADR

uintptr_t LUA_STATE = 0;

//HOOK REGISTER AT STARTUP, STEAL ARGS AND THEN GET LUA STATE HAHAH

using print = int32_t(__cdecl*)(int32_t type, const char* message);
const auto print_func = reinterpret_cast<print>(aslr(0x011686E0)); //Function which pr

using pseudo_index2adr = char*(__fastcall*)(uintptr_t state, int idx);
const auto pseudo_index2adr_func = reinterpret_cast<pseudo_index2adr>(aslr(0x01BEBC80)); //the function we are hooking
