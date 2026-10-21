/* Kerwan (level 16): baserom/levels/16_kerwan.elf (tools/levels.py dump), built by tools/build.py
   --target level_16. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/16_kerwan/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/16_kerwan/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/16_kerwan/asm/levels/16_kerwan/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/16_kerwan/asm/levels/16_kerwan/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2AFE00 : AT(0xDB780)
    {
        build/levels/16_kerwan/asm/levels/16_kerwan/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x302200 : AT(0x12DB80)
    {
        build/levels/16_kerwan/asm/levels/16_kerwan/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x303180 : AT(0x12EB00)
    {
        build/levels/16_kerwan/asm/levels/16_kerwan/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x303280 : AT(0x12EC00)
    {
        build/levels/16_kerwan/asm/levels/16_kerwan/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/16_kerwan/src/ (tools/levels.py tree). */
    .text 0x303300 : AT(0x12EC80)
    {
        build/levels/16_kerwan/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x35EDD8)
    {
        build/levels/16_kerwan/asm/levels/16_kerwan/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
