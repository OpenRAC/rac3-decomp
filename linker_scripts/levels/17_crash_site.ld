/* Crash Site (level 17): baserom/levels/17_crash_site.elf (tools/levels.py dump), built by tools/build.py
   --target level_17. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/17_crash_site/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/17_crash_site/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/17_crash_site/asm/levels/17_crash_site/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/17_crash_site/asm/levels/17_crash_site/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2AD200 : AT(0xD8B80)
    {
        build/levels/17_crash_site/asm/levels/17_crash_site/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2FE100 : AT(0x129A80)
    {
        build/levels/17_crash_site/asm/levels/17_crash_site/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2FEC00 : AT(0x12A580)
    {
        build/levels/17_crash_site/asm/levels/17_crash_site/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2FED00 : AT(0x12A680)
    {
        build/levels/17_crash_site/asm/levels/17_crash_site/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/17_crash_site/src/ (tools/levels.py tree). */
    .text 0x2FED80 : AT(0x12A700)
    {
        build/levels/17_crash_site/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x3266B0)
    {
        build/levels/17_crash_site/asm/levels/17_crash_site/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
