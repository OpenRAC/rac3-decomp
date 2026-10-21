/* Hoven Gorge (level 41): baserom/levels/41_hoven_gorge.elf (tools/levels.py dump), built by tools/build.py
   --target level_41. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/41_hoven_gorge/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/41_hoven_gorge/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/41_hoven_gorge/asm/levels/41_hoven_gorge/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x241A00 : AT(0x1000)
    {
        build/levels/41_hoven_gorge/asm/levels/41_hoven_gorge/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x39F800 : AT(0x15EE00)
    {
        build/levels/41_hoven_gorge/asm/levels/41_hoven_gorge/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x3C3580 : AT(0x182B80)
    {
        build/levels/41_hoven_gorge/asm/levels/41_hoven_gorge/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x3C4700 : AT(0x183D00)
    {
        build/levels/41_hoven_gorge/asm/levels/41_hoven_gorge/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x3C4800 : AT(0x183E00)
    {
        build/levels/41_hoven_gorge/asm/levels/41_hoven_gorge/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/41_hoven_gorge/src/ (tools/levels.py tree). */
    .text 0x3C4880 : AT(0x183E80)
    {
        build/levels/41_hoven_gorge/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x30F668)
    {
        build/levels/41_hoven_gorge/asm/levels/41_hoven_gorge/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
