/* Koros (level 14): baserom/levels/14_koros.elf (tools/levels.py dump), built by tools/build.py
   --target level_14. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/14_koros/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/14_koros/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/14_koros/asm/levels/14_koros/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/14_koros/asm/levels/14_koros/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A6C80 : AT(0xD2600)
    {
        build/levels/14_koros/asm/levels/14_koros/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F8500 : AT(0x123E80)
    {
        build/levels/14_koros/asm/levels/14_koros/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F9200 : AT(0x124B80)
    {
        build/levels/14_koros/asm/levels/14_koros/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F9300 : AT(0x124C80)
    {
        build/levels/14_koros/asm/levels/14_koros/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/14_koros/src/ (tools/levels.py tree). */
    .text 0x2F9380 : AT(0x124D00)
    {
        build/levels/14_koros/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x337FD0)
    {
        build/levels/14_koros/asm/levels/14_koros/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
