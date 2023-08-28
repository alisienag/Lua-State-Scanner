#include "memory.h"


int main() {
    print_func(1, "PRINT WORKS: ");
    HookLuaState();

    while (!GetAsyncKeyState(VK_ESCAPE)) {

        if (LUA_STATE == 0) {
            print_func(1, "No Lua State");
        }
        else {
            print_func(1, "Lua State");
            break;
        }

        Sleep(100);
    }

    return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)main, NULL, NULL, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

