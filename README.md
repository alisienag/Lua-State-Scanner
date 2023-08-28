# Lua-State-Scanner

The code is designed in a way to only work for internal cheats. (via injecting as a DLL).

Scans for Roblox Lua State by hooking a function the Lua function "index2adr".

I haven't confirmed this yet but it seems you need to call the print_to_console function, as it may or may not call the index2adr function and hence allows us to grab the lua state.

Use this as you please, just don't forget to give credits.

Ignore poor quality of coding, I needed a fast and decently reliable way to grab the Lua State.


How to use:

DLLmain shows how to use this. The variable "LUA_STATE" will be the hooked Lua_State. Just don't forget to update the address for the index2adr and the print function, which both are fairly easy to reverse engineer. Any issues or questions, feel free to ask and I will attempt to fix/aid you.

Notice: This is tailored for the UWP client.
