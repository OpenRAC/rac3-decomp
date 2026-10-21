/* Korgon Outpost (level 43): baserom/levels/43_korgon_outpost.elf (tools/levels.py dump), built by tools/build.py
   --target level_43. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/43_korgon_outpost/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/43_korgon_outpost/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/43_korgon_outpost/asm/levels/43_korgon_outpost/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x241A00 : AT(0x1000)
    {
        build/levels/43_korgon_outpost/asm/levels/43_korgon_outpost/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x397580 : AT(0x156B80)
    {
        build/levels/43_korgon_outpost/asm/levels/43_korgon_outpost/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x3BB200 : AT(0x17A800)
    {
        build/levels/43_korgon_outpost/asm/levels/43_korgon_outpost/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x3BC280 : AT(0x17B880)
    {
        build/levels/43_korgon_outpost/asm/levels/43_korgon_outpost/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x3BC380 : AT(0x17B980)
    {
        build/levels/43_korgon_outpost/asm/levels/43_korgon_outpost/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/43_korgon_outpost/src/ (tools/levels.py tree). */
    .text 0x3BC400 : AT(0x17BA00)
    {
        build/levels/43_korgon_outpost/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x302628)
    {
        build/levels/43_korgon_outpost/asm/levels/43_korgon_outpost/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
