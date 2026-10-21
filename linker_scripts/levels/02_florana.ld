/* Florana (level 2): baserom/levels/02_florana.elf (tools/levels.py dump), built by tools/build.py
   --target level_02. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/02_florana/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/02_florana/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/02_florana/asm/levels/02_florana/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/02_florana/asm/levels/02_florana/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A3100 : AT(0xCEA80)
    {
        build/levels/02_florana/asm/levels/02_florana/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F4280 : AT(0x11FC00)
    {
        build/levels/02_florana/asm/levels/02_florana/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F4E00 : AT(0x120780)
    {
        build/levels/02_florana/asm/levels/02_florana/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F4F00 : AT(0x120880)
    {
        build/levels/02_florana/asm/levels/02_florana/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/02_florana/src/ (tools/levels.py tree). */
    .text 0x2F4F80 : AT(0x120900)
    {
        build/levels/02_florana/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x31DC80)
    {
        build/levels/02_florana/asm/levels/02_florana/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
