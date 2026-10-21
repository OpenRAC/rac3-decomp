/* Blackwater Docks (level 47): baserom/levels/47_blackwater_docks.elf (tools/levels.py dump), built by tools/build.py
   --target level_47. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/47_blackwater_docks/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/47_blackwater_docks/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/47_blackwater_docks/asm/levels/47_blackwater_docks/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x241A00 : AT(0x1000)
    {
        build/levels/47_blackwater_docks/asm/levels/47_blackwater_docks/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x3A8000 : AT(0x167600)
    {
        build/levels/47_blackwater_docks/asm/levels/47_blackwater_docks/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x3CBB80 : AT(0x18B180)
    {
        build/levels/47_blackwater_docks/asm/levels/47_blackwater_docks/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x3CC900 : AT(0x18BF00)
    {
        build/levels/47_blackwater_docks/asm/levels/47_blackwater_docks/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x3CCA00 : AT(0x18C000)
    {
        build/levels/47_blackwater_docks/asm/levels/47_blackwater_docks/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/47_blackwater_docks/src/ (tools/levels.py tree). */
    .text 0x3CCA80 : AT(0x18C080)
    {
        build/levels/47_blackwater_docks/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x3012E8)
    {
        build/levels/47_blackwater_docks/asm/levels/47_blackwater_docks/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
