/* Tyhrranosis (level 9): baserom/levels/09_tyhrranosis.elf (tools/levels.py dump), built by tools/build.py
   --target level_09. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/09_tyhrranosis/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/09_tyhrranosis/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/09_tyhrranosis/asm/levels/09_tyhrranosis/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/09_tyhrranosis/asm/levels/09_tyhrranosis/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A4700 : AT(0xD0080)
    {
        build/levels/09_tyhrranosis/asm/levels/09_tyhrranosis/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F7080 : AT(0x122A00)
    {
        build/levels/09_tyhrranosis/asm/levels/09_tyhrranosis/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F8000 : AT(0x123980)
    {
        build/levels/09_tyhrranosis/asm/levels/09_tyhrranosis/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F8100 : AT(0x123A80)
    {
        build/levels/09_tyhrranosis/asm/levels/09_tyhrranosis/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/09_tyhrranosis/src/ (tools/levels.py tree). */
    .text 0x2F8180 : AT(0x123B00)
    {
        build/levels/09_tyhrranosis/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x360738)
    {
        build/levels/09_tyhrranosis/asm/levels/09_tyhrranosis/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
