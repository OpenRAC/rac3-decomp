/* Holostar Studios (Ratchet) (level 13): baserom/levels/13_holostar_studios_ratchet.elf (tools/levels.py dump), built by tools/build.py
   --target level_13. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/13_holostar_studios_ratchet/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/13_holostar_studios_ratchet/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/13_holostar_studios_ratchet/asm/levels/13_holostar_studios_ratchet/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/levels/13_holostar_studios_ratchet/asm/levels/13_holostar_studios_ratchet/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x2A3B80 : AT(0xCF500)
    {
        build/levels/13_holostar_studios_ratchet/asm/levels/13_holostar_studios_ratchet/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F5000 : AT(0x120980)
    {
        build/levels/13_holostar_studios_ratchet/asm/levels/13_holostar_studios_ratchet/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F5D00 : AT(0x121680)
    {
        build/levels/13_holostar_studios_ratchet/asm/levels/13_holostar_studios_ratchet/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F5E00 : AT(0x121780)
    {
        build/levels/13_holostar_studios_ratchet/asm/levels/13_holostar_studios_ratchet/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/13_holostar_studios_ratchet/src/ (tools/levels.py tree). */
    .text 0x2F5E80 : AT(0x121800)
    {
        build/levels/13_holostar_studios_ratchet/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x32D598)
    {
        build/levels/13_holostar_studios_ratchet/asm/levels/13_holostar_studios_ratchet/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
