#include "pch.h"
#include <iostream>

const uintptr_t discordBase = (uintptr_t)GetModuleHandleA("discord.dll");

void bypass() {

    std::string* authLink = (std::string*)(discordBase + 0x94E80);

    while (true) {
        *authLink = "http://yourlink";
    }

}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)bypass, 0, 0, 0);

    return TRUE;
}
