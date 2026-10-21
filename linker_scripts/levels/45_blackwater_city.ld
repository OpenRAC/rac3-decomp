/* Blackwater City (level 45): baserom/levels/45_blackwater_city.elf (tools/levels.py dump), built by tools/build.py
   --target level_45. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/45_blackwater_city/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/45_blackwater_city/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/45_blackwater_city/asm/levels/45_blackwater_city/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x241A00 : AT(0x1000)
    {
        build/levels/45_blackwater_city/asm/levels/45_blackwater_city/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x397580 : AT(0x156B80)
    {
        build/levels/45_blackwater_city/asm/levels/45_blackwater_city/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x3BB200 : AT(0x17A800)
    {
        build/levels/45_blackwater_city/asm/levels/45_blackwater_city/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x3BC300 : AT(0x17B900)
    {
        build/levels/45_blackwater_city/asm/levels/45_blackwater_city/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x3BC400 : AT(0x17BA00)
    {
        build/levels/45_blackwater_city/asm/levels/45_blackwater_city/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/45_blackwater_city/src/ (tools/levels.py tree). */
    .text 0x3BC480 : AT(0x17BA80)
    {
        build/levels/45_blackwater_city/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x2FF210)
    {
        build/levels/45_blackwater_city/asm/levels/45_blackwater_city/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
