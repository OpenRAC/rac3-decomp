/* Aquatos Base (level 27): baserom/levels/27_aquatos_base.elf (tools/levels.py dump), built by tools/build.py
   --target level_27. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/27_aquatos_base/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/27_aquatos_base/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/27_aquatos_base/asm/levels/27_aquatos_base/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/27_aquatos_base/asm/levels/27_aquatos_base/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A4680 : AT(0xD0000)
    {
        build/levels/27_aquatos_base/asm/levels/27_aquatos_base/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F8F80 : AT(0x124900)
    {
        build/levels/27_aquatos_base/asm/levels/27_aquatos_base/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F9A00 : AT(0x125380)
    {
        build/levels/27_aquatos_base/asm/levels/27_aquatos_base/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F9B00 : AT(0x125480)
    {
        build/levels/27_aquatos_base/asm/levels/27_aquatos_base/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/27_aquatos_base/src/ (tools/levels.py tree). */
    .text 0x2F9B80 : AT(0x125500)
    {
        build/levels/27_aquatos_base/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x31BE90)
    {
        build/levels/27_aquatos_base/asm/levels/27_aquatos_base/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
