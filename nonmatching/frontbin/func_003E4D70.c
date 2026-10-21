/* US draft of func_003E4D70 (rac3-uya-decomp func_003DF820, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003E4D70 */
__asm__(".extern D_001D955D, 1");
__asm__(".extern D_001D955C, 1");
extern u8 D_001D955D;
extern u8 D_001D955C;
extern s32 func_00392A18(void);
extern s32 func_003E8100(s32, s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
void func_003E4D70(s32 arg0) {
    F_3DE8F0 *g = D_142CA0;
    s32 a, b;
    D_001D955C = (g->x20 != D_001D955D);
    if (D_001D955C) {
        a = g->x20 ? 0x8E : 0x8C;
        b = g->x20 ? 0x8F : 0x8D;
        D_001D955D = g->x20 != 0;
        func_003E8100(0x90002, func_00392A18(), a);
        func_003E8100(0x90001, func_00392A18(), b);
        func_003E73B8(0x9000C, g->x20 ? 0.4025f : 0.4285f, 0.1315f);
        func_003E81F0(0x9000C, 0.6f, 0.6f);
        func_003E73B8(0x90007, g->x20 ? 0.4394f : 0.464136f, 0.1335f);
    }
}
/* localdecomp:end func_003E4D70 */
