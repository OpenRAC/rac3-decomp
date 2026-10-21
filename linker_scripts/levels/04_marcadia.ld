/* Marcadia (level 4): baserom/levels/04_marcadia.elf (tools/levels.py dump), built by tools/build.py
   --target level_04. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/04_marcadia/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/04_marcadia/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/04_marcadia/asm/levels/04_marcadia/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/04_marcadia/asm/levels/04_marcadia/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A4B80 : AT(0xD0500)
    {
        build/levels/04_marcadia/asm/levels/04_marcadia/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F7080 : AT(0x122A00)
    {
        build/levels/04_marcadia/asm/levels/04_marcadia/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F8100 : AT(0x123A80)
    {
        build/levels/04_marcadia/asm/levels/04_marcadia/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F8200 : AT(0x123B80)
    {
        build/levels/04_marcadia/asm/levels/04_marcadia/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/04_marcadia/src/ (tools/levels.py tree). */
    .text 0x2F8280 : AT(0x123C00)
    {
        build/levels/04_marcadia/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x357EC0)
    {
        build/levels/04_marcadia/asm/levels/04_marcadia/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
