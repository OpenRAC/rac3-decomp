/* US draft of func_003BF2B8 (rac3-uya-decomp func_003BF1C8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003BF2B8 */
__asm__(".extern D_001DA2D0, 4");
__asm__(".extern D_001D8D28, 4");
__asm__(".extern D_001D8D40, 4");
__asm__(".extern D_001DA300_003BF2B8, 16");
__asm__(".extern D_001DA2D4_003BF2B8, 16");
extern u8 D_001DA2D4_003BF2B8;
extern volatile u8 D_001DA300_003BF2B8;
extern s32 D_001DA2D0;
extern s32 D_001D8D28;
extern s32 D_001D8D40;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_00225700_003BF2B8;
extern void func_003BCB20();
extern s32 func_003BE2C8();
extern s32 func_003BE2D0();
extern void func_003BE520();
extern void func_003BBD20();
extern s32 func_003BE0F0();
extern void func_003BE218();
extern void func_003BE6C0();
extern void func_003BE2F8();
extern void func_003882D0();
extern void func_003BE8E0();
extern void func_003BE318();
void func_003BF2B8(s32 a0) {
    s32 v;
    if (D_001DA2D4_003BF2B8 != 0) {
        func_003BCB20();
        if (func_003BE2C8() == 1) {
            func_003BE520();
        }
        if (func_003BE2C8() > 0 && func_003BE2D0() != 0) {
            func_003BBD20();
        }
        if (D_001DA300_003BF2B8 == 0) {
            v = 0;
            if (func_003BE2C8() > 0 && a0 != 0) {
                switch (D_001DA2D0) {
                case 0:
                    v = D_001D8D28;
                    break;
                case 1:
                    v = D_001D8D40;
                    break;
                }
                D_001DA300_003BF2B8 = 1;
            } else {
                v = func_003BE0F0();
            }
            func_003BE218(v);
            func_003BE6C0(func_003BE8E0);
            func_003BE2F8();
            func_003882D0();
        }
    }
    {
        S_3B9A08 *g = &D_00225700_003BF2B8;
        func_003BE318(g->f34, g->h40, 0xF, 0xF);
    }
}
/* localdecomp:end func_003BF2B8 */
