/* US draft of func_0038ABC0 (rac3-uya-decomp func_00386488, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0038ABC0 */
typedef struct { s32 f0; u32 f4; unsigned long f8; s32 f10; u32 f14; unsigned long f18; s32 f20; u32 f24; unsigned long f28; } P_00386488;
__asm__(".extern D_001D58B8_0038ABC0, 4");
extern P_00386488 *D_001D58B8_0038ABC0;
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
typedef struct { u8 p0[0x150]; s16 f150, f152; } C_00386488;
extern C_00386488 D_001CFEC0_0038ABC0;
void func_0038ABC0(void) {
    s32 i = 0;
    s32 h = D_001CFEC0_0038ABC0.f152;
    s32 y;
    if (D_001D58B8_0038ABC0->f8) {
        func_003A9440(0x42, D_001D58B8_0038ABC0->f8 & 0xFF000000FFUL);
    }
    if (D_001D58B8_0038ABC0->f4 & 0xFF000000) {
        func_0038AF30(0, h, 0, D_001CFEC0_0038ABC0.f150, D_001D58B8_0038ABC0->f4);
    }
    if (h > 0) {
        do {
            if (D_001D58B8_0038ABC0->f18) {
                func_003A9440(0x42, D_001D58B8_0038ABC0->f18 & 0xFF000000FFUL);
            }
            if (D_001D58B8_0038ABC0->f14 & 0xFF000000) {
                y = (i + D_001D58B8_0038ABC0->f10 >= h - 1) ? h - 1 : i + D_001D58B8_0038ABC0->f10;
                func_0038AF30(i, y, 0, D_001CFEC0_0038ABC0.f150, D_001D58B8_0038ABC0->f14);
            }
            i += D_001D58B8_0038ABC0->f10;
            if (D_001D58B8_0038ABC0->f28) {
                func_003A9440(0x42, D_001D58B8_0038ABC0->f28 & 0xFF000000FFUL);
            }
            if (D_001D58B8_0038ABC0->f24 & 0xFF000000) {
                y = (i + D_001D58B8_0038ABC0->f20 >= h - 1) ? h - 1 : i + D_001D58B8_0038ABC0->f20;
                func_0038AF30(i, y, 0, D_001CFEC0_0038ABC0.f150, D_001D58B8_0038ABC0->f24);
            }
            i += D_001D58B8_0038ABC0->f20;
        } while (i < h);
    }
}
/* localdecomp:end func_0038ABC0 */
