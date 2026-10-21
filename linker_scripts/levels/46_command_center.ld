/* Command Center (level 46): baserom/levels/46_command_center.elf (tools/levels.py dump), built by tools/build.py
   --target level_46. Made by tools/levels.py config; regenerate it rather than editing it.

   frontbin's layout at the level's addresses: one PT_LOAD from file offset 0x1000. Every
   section sits at its retail file offset (AT(...)); the gaps between them are zeros. */

INPUT(build/levels/46_command_center/symbol_addrs_resolved.txt)
/* the names the level's C uses (tools/level_symbols.py) */
INPUT(build/levels/46_command_center/symbol_addrs_derived.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/levels/46_command_center/asm/levels/46_command_center/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x241A00 : AT(0x1000)
    {
        build/levels/46_command_center/asm/levels/46_command_center/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data. */
    .data 0x3A7C80 : AT(0x167280)
    {
        build/levels/46_command_center/asm/levels/46_command_center/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x3CB780 : AT(0x18AD80)
    {
        build/levels/46_command_center/asm/levels/46_command_center/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x3CC500 : AT(0x18BB00)
    {
        build/levels/46_command_center/asm/levels/46_command_center/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x3CC600 : AT(0x18BC00)
    {
        build/levels/46_command_center/asm/levels/46_command_center/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/levels/ through build/levels/46_command_center/src/ (tools/levels.py tree). */
    .text 0x3CC680 : AT(0x18BC80)
    {
        build/levels/46_command_center/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table, raw bytes. Its address is arbitrary;
       objcopy places it by file offset. */
    .trailer 0x8000000 : AT(0x2FEA68)
    {
        build/levels/46_command_center/asm/levels/46_command_center/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
