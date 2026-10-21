/* Holostar Studios (Clank) (level 23): baserom/levels/23_holostar_studios_clank.elf (tools/levels.py dump), built by tools/build.py
   --target level_23. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/23_holostar_studios_clank/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/23_holostar_studios_clank/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/23_holostar_studios_clank/asm/levels/23_holostar_studios_clank/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/23_holostar_studios_clank/asm/levels/23_holostar_studios_clank/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A5300 : AT(0xD0C80)
    {
        build/levels/23_holostar_studios_clank/asm/levels/23_holostar_studios_clank/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F7800 : AT(0x123180)
    {
        build/levels/23_holostar_studios_clank/asm/levels/23_holostar_studios_clank/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F8380 : AT(0x123D00)
    {
        build/levels/23_holostar_studios_clank/asm/levels/23_holostar_studios_clank/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F8480 : AT(0x123E00)
    {
        build/levels/23_holostar_studios_clank/asm/levels/23_holostar_studios_clank/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/23_holostar_studios_clank/src/ (tools/levels.py tree). */
    .text 0x2F8500 : AT(0x123E80)
    {
        build/levels/23_holostar_studios_clank/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x3313F8)
    {
        build/levels/23_holostar_studios_clank/asm/levels/23_holostar_studios_clank/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
