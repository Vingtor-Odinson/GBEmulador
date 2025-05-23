#include <ROM/ROMLoader.hpp>
#include <CPU/CPU.hpp>
#include <Memoria/Memory.hpp>
#include <Memoria/MemoryParts.hpp>
#include "fstream"

ROMLoader::ROMLoader( CPU* cpuRef )
{
    cpu = cpuRef;
}

void ROMLoader::SetROM( std::string Path)
{
    ROMPath = Path;
}

void ROMLoader::LoadROM()
{
    std::ifstream ROM( ROMPath, std::ios::binary | std::ios::ate );

    if(!ROM.is_open())
    {
        throw std::runtime_error("Não foi posśivel carregar a ROM");
    }

    std::streamsize size = ROM.tellg();
    ROM.seekg(0, std::ios::beg);

    ROMData = new std::vector<uint8_t>(size);

    ROM.read(reinterpret_cast<char*>(ROMData->data()), size);
}

uint8_t ROMLoader::ReadROM( uint16_t add )
{
    return (*ROMData)[add];
}