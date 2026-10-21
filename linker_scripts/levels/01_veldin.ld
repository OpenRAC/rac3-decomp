/* Veldin (level 1): baserom/levels/01_veldin.elf (tools/levels.py dump), built by tools/build.py
   --target level_01. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/01_veldin/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/01_veldin/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/01_veldin/asm/levels/01_veldin/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/01_veldin/asm/levels/01_veldin/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A4400 : AT(0xCFD80)
    {
        build/levels/01_veldin/asm/levels/01_veldin/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F6800 : AT(0x122180)
    {
        build/levels/01_veldin/asm/levels/01_veldin/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F7680 : AT(0x123000)
    {
        build/levels/01_veldin/asm/levels/01_veldin/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F7780 : AT(0x123100)
    {
        build/levels/01_veldin/asm/levels/01_veldin/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/01_veldin/src/ (tools/levels.py tree). */
    .text 0x2F7800 : AT(0x123180)
    {
        build/levels/01_veldin/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x34D648)
    {
        build/levels/01_veldin/asm/levels/01_veldin/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
