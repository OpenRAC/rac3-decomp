/* Zeldrin Starport (level 10): baserom/levels/10_zeldrin_starport.elf (tools/levels.py dump), built by tools/build.py
   --target level_10. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/10_zeldrin_starport/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/10_zeldrin_starport/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/10_zeldrin_starport/asm/levels/10_zeldrin_starport/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/10_zeldrin_starport/asm/levels/10_zeldrin_starport/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A3580 : AT(0xCEF00)
    {
        build/levels/10_zeldrin_starport/asm/levels/10_zeldrin_starport/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F4900 : AT(0x120280)
    {
        build/levels/10_zeldrin_starport/asm/levels/10_zeldrin_starport/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F5500 : AT(0x120E80)
    {
        build/levels/10_zeldrin_starport/asm/levels/10_zeldrin_starport/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F5600 : AT(0x120F80)
    {
        build/levels/10_zeldrin_starport/asm/levels/10_zeldrin_starport/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/10_zeldrin_starport/src/ (tools/levels.py tree). */
    .text 0x2F5680 : AT(0x121000)
    {
        build/levels/10_zeldrin_starport/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x330840)
    {
        build/levels/10_zeldrin_starport/asm/levels/10_zeldrin_starport/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
