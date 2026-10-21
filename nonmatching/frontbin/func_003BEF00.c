/* US draft of func_003BEF00 (rac3-uya-decomp func_003B9A08, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003BEF00 */
__asm__(".extern D_001DA2D0, 4");
__asm__(".extern D_001D8D28, 4");
__asm__(".extern D_001D8D40, 4");
__asm__(".extern D_001DA300_003BEF00, 16");
__asm__(".extern D_001DA2D4_003BEF00, 16");
extern u8 D_001DA2D4_003BEF00;
extern volatile u8 D_001DA300_003BEF00;
extern s32 D_001DA2D0;
extern s32 D_001D8D28;
extern s32 D_001D8D40;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_00225700_003BEF00;
extern void func_003BC768();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
extern void func_003BE168();
extern void func_003BB968();
extern s32 func_003BDD38();
extern void func_003BDE60();
extern void func_003BE308();
extern void func_003BDF40();
extern void func_00387EF0();
extern void func_003BE528();
extern void func_003BDF60();
void func_003BEF00(s32 a0) {
    s32 v;
    if (D_001DA2D4_003BEF00 != 0) {
        func_003BC768();
        if (func_003BDF10() == 1) {
            func_003BE168();
        }
        if (func_003BDF10() > 0 && func_003BDF18() != 0) {
            func_003BB968();
        }
        if (D_001DA300_003BEF00 == 0) {
            v = 0;
            if (func_003BDF10() > 0 && a0 != 0) {
                switch (D_001DA2D0) {
                case 0:
                    v = D_001D8D28;
                    break;
                case 1:
                    v = D_001D8D40;
                    break;
                }
                D_001DA300_003BEF00 = 1;
            } else {
                v = func_003BDD38();
            }
            func_003BDE60(v);
            func_003BE308(func_003BE528);
            func_003BDF40();
            func_00387EF0();
        }
    }
    {
        S_3B9A08 *g = &D_00225700_003BEF00;
        func_003BDF60(g->f34, g->h40, 0xF, 0xF);
    }
}
/* localdecomp:end func_003BEF00 */
