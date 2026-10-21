/* Daxx (level 5): baserom/levels/05_daxx.elf (tools/levels.py dump), built by tools/build.py
   --target level_05. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/05_daxx/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/05_daxx/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/05_daxx/asm/levels/05_daxx/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/05_daxx/asm/levels/05_daxx/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A7B80 : AT(0xD3500)
    {
        build/levels/05_daxx/asm/levels/05_daxx/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F9200 : AT(0x124B80)
    {
        build/levels/05_daxx/asm/levels/05_daxx/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2FA080 : AT(0x125A00)
    {
        build/levels/05_daxx/asm/levels/05_daxx/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2FA180 : AT(0x125B00)
    {
        build/levels/05_daxx/asm/levels/05_daxx/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/05_daxx/src/ (tools/levels.py tree). */
    .text 0x2FA200 : AT(0x125B80)
    {
        build/levels/05_daxx/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x346A98)
    {
        build/levels/05_daxx/asm/levels/05_daxx/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
