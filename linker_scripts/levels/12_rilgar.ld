/* Rilgar (level 12): baserom/levels/12_rilgar.elf (tools/levels.py dump), built by tools/build.py
   --target level_12. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/12_rilgar/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/12_rilgar/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/12_rilgar/asm/levels/12_rilgar/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/12_rilgar/asm/levels/12_rilgar/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A4300 : AT(0xCFC80)
    {
        build/levels/12_rilgar/asm/levels/12_rilgar/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F6800 : AT(0x122180)
    {
        build/levels/12_rilgar/asm/levels/12_rilgar/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F7700 : AT(0x123080)
    {
        build/levels/12_rilgar/asm/levels/12_rilgar/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F7800 : AT(0x123180)
    {
        build/levels/12_rilgar/asm/levels/12_rilgar/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/12_rilgar/src/ (tools/levels.py tree). */
    .text 0x2F7880 : AT(0x123200)
    {
        build/levels/12_rilgar/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x34ED90)
    {
        build/levels/12_rilgar/asm/levels/12_rilgar/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
