/* Near miss of func_003B0F70 with its file's own flags: tools/check.py reports 71 diff
   (the US draft it started from: 77).
   What differs: 64-bit constants, one global load and one `addu` operand order are still
   split-address-mode code; register allocation follows from those.
*/

/* Candidate for func_003B0F70 (boot_elf, PAL).
   D_001DA0C0 is reached through an unsized alias (same address as
   D_001DA0C0_003B0F70): an unsized array is never small data, so the file's
   -mno-split-addresses flags still give retail's lui %hi / addiu %lo form
   instead of a $gp-relative address. */

/* localdecomp:start func_003B0F70 */
extern s32 D_001A1ED4[];
extern s32 D_001DA0C0[];
extern void func_003A1428_003B0F70(s32, s32);
void func_003B0F70(unsigned long *p, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 i, j;
    s32 h = a3 >> 4;
    s32 w = a4 >> 4;
    p[0] = 0x10000003;
    p[1] = 0;
    p[2] = 0x1000000000000002L;
    p[3] = 0xE;
    p[4] = (((long)D_001A1ED4[0] >> 8) << 32) | 0x8000000000000L;
    p[5] = 0x50;
    p[6] = 0x1000000010L;
    p[7] = 0x52;
    p += 8;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            p[0] = 0x10000004;
            p[1] = 0;
            p[2] = 0x1000000000000002L;
            p[3] = 0xE;
            p[4] = ((unsigned long)(j << 4) << 32) | ((unsigned long)(i << 4) << 48);
            p[5] = 0x51;
            p[6] = 0;
            p[7] = 0x53;
            p[8] = 0x800000000000040L;
            p[9] = 0;
            ((u32 *)p)[20] = 0x30000040;
            ((u32 *)p)[21] = a1 & 0xFFFFFFF;
            p[11] = 0;
            a1 += 0x400;
            p += 12;
        }
    }
    {
    s32 *q = (s32 *)(a2 * 4 + (u32)D_001DA0C0);
    ((u32 *)p)[0] = 0x20000000;
    ((u32 *)p)[1] = *q;
    ((u32 *)p)[2] = 0;
    ((u32 *)p)[3] = 0;
    func_003A1428_003B0F70((*q & 0xFFFFFFF) | 0x20000000, 1);
    }
}
/* localdecomp:end func_003B0F70 */
