/* US draft of func_003A8450 (rac3-uya-decomp func_003A3028, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A8450 */
__asm__(".extern D_001D6EEC_003A8450, 4");
__asm__(".extern D_001D6EF0, 4");
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028;
extern E_3A3028 *D_001D6EEC_003A8450;
extern f32 D_001D6EF0;
extern void func_003D3FA0(E_3A3028 *, s32, s32, s32, f32, f32, f32);
void func_003A8450(void) {
    s32 i;
    s32 off;
    if (D_001D6EEC_003A8450) {
        off = 0;
        for (i = 0x1FF; i >= 0; i--) {
            E_3A3028 *e = (E_3A3028 *)((u8 *)D_001D6EEC_003A8450 + off);
            if (e->f48) {
                s32 s = e->f3C >> 1;
                s32 flag = 1;
                if (s) { s = s ^ 1; flag = s != 0; }
                func_003D3FA0(e, e->f4C, e->f30 | ((s32)((f32)e->f38 * D_001D6EF0) << 24), flag, e->f28, 0.001f, e->f24);
            }
            off += 0x50;
        }
    }
}
/* localdecomp:end func_003A8450 */
