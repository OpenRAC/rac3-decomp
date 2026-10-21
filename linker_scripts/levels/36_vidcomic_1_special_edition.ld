/* Vid-comic 1 Special Edition (level 36): baserom/levels/36_vidcomic_1_special_edition.elf (tools/levels.py dump), built by tools/build.py
   --target level_36. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/36_vidcomic_1_special_edition/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/36_vidcomic_1_special_edition/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/36_vidcomic_1_special_edition/asm/levels/36_vidcomic_1_special_edition/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/36_vidcomic_1_special_edition/asm/levels/36_vidcomic_1_special_edition/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A5400 : AT(0xD0D80)
    {
        build/levels/36_vidcomic_1_special_edition/asm/levels/36_vidcomic_1_special_edition/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F7080 : AT(0x122A00)
    {
        build/levels/36_vidcomic_1_special_edition/asm/levels/36_vidcomic_1_special_edition/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F7B00 : AT(0x123480)
    {
        build/levels/36_vidcomic_1_special_edition/asm/levels/36_vidcomic_1_special_edition/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F7C00 : AT(0x123580)
    {
        build/levels/36_vidcomic_1_special_edition/asm/levels/36_vidcomic_1_special_edition/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/36_vidcomic_1_special_edition/src/ (tools/levels.py tree). */
    .text 0x2F7C80 : AT(0x123600)
    {
        build/levels/36_vidcomic_1_special_edition/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x326420)
    {
        build/levels/36_vidcomic_1_special_edition/asm/levels/36_vidcomic_1_special_edition/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
