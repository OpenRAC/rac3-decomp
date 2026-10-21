/* Multiplayer Menu (level 39): baserom/levels/39_multiplayer_menu.elf (tools/levels.py dump), built by tools/build.py
   --target level_39. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/39_multiplayer_menu/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/39_multiplayer_menu/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/39_multiplayer_menu/asm/levels/39_multiplayer_menu/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x241A00 : AT(0x1000)
    {
        build/levels/39_multiplayer_menu/asm/levels/39_multiplayer_menu/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x453F80 : AT(0x213580)
    {
        build/levels/39_multiplayer_menu/asm/levels/39_multiplayer_menu/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x4B2500 : AT(0x271B00)
    {
        build/levels/39_multiplayer_menu/asm/levels/39_multiplayer_menu/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x4B2F80 : AT(0x272580)
    {
        build/levels/39_multiplayer_menu/asm/levels/39_multiplayer_menu/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x4B3080 : AT(0x272680)
    {
        build/levels/39_multiplayer_menu/asm/levels/39_multiplayer_menu/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/39_multiplayer_menu/src/ (tools/levels.py tree). */
    .text 0x4B3100 : AT(0x272700)
    {
        build/levels/39_multiplayer_menu/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x4A0D18)
    {
        build/levels/39_multiplayer_menu/asm/levels/39_multiplayer_menu/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
