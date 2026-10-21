/* Bakisi Isles (level 40): baserom/levels/40_bakisi_isles.elf (tools/levels.py dump), built by tools/build.py
   --target level_40. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/40_bakisi_isles/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/40_bakisi_isles/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/40_bakisi_isles/asm/levels/40_bakisi_isles/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x241A00 : AT(0x1000)
    {
        build/levels/40_bakisi_isles/asm/levels/40_bakisi_isles/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x3A0280 : AT(0x15F880)
    {
        build/levels/40_bakisi_isles/asm/levels/40_bakisi_isles/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x3C3F00 : AT(0x183500)
    {
        build/levels/40_bakisi_isles/asm/levels/40_bakisi_isles/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x3C5000 : AT(0x184600)
    {
        build/levels/40_bakisi_isles/asm/levels/40_bakisi_isles/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x3C5100 : AT(0x184700)
    {
        build/levels/40_bakisi_isles/asm/levels/40_bakisi_isles/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/40_bakisi_isles/src/ (tools/levels.py tree). */
    .text 0x3C5180 : AT(0x184780)
    {
        build/levels/40_bakisi_isles/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x30D4A0)
    {
        build/levels/40_bakisi_isles/asm/levels/40_bakisi_isles/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
