/* Vid-comic (unnamed) (level 30): baserom/levels/30_vidcomic_unnamed.elf (tools/levels.py dump), built by tools/build.py
   --target level_30. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/30_vidcomic_unnamed/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/30_vidcomic_unnamed/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/30_vidcomic_unnamed/asm/levels/30_vidcomic_unnamed/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/30_vidcomic_unnamed/asm/levels/30_vidcomic_unnamed/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A3D00 : AT(0xCF680)
    {
        build/levels/30_vidcomic_unnamed/asm/levels/30_vidcomic_unnamed/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F5180 : AT(0x120B00)
    {
        build/levels/30_vidcomic_unnamed/asm/levels/30_vidcomic_unnamed/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F5B80 : AT(0x121500)
    {
        build/levels/30_vidcomic_unnamed/asm/levels/30_vidcomic_unnamed/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F5C80 : AT(0x121600)
    {
        build/levels/30_vidcomic_unnamed/asm/levels/30_vidcomic_unnamed/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/30_vidcomic_unnamed/src/ (tools/levels.py tree). */
    .text 0x2F5D00 : AT(0x121680)
    {
        build/levels/30_vidcomic_unnamed/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x3201C0)
    {
        build/levels/30_vidcomic_unnamed/asm/levels/30_vidcomic_unnamed/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
