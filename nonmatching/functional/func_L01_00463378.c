/* functional: high. 53 diff at default flags (0xD0 frame with 16-byte sq/lq saves vs the file's fixed -fopt-stack frame; flags are fixed); every field offset re-verified against PAL asm */
/* localdecomp:start func_L01_00463378 */
extern u8 *D_L01_002210F4[];
extern u8 *D_L01_00221098[];
u8 *func_L01_00463378(Q_463218 *pos, f32 *a, f32 *b, s32 color0, s32 color1, s32 life0, s32 life1, s32 duration, s32 texture) {
    extern u8 *func_L01_004618E0(s32);
    extern f32 func_003824E0(f32 low, f32 high);
    extern void func_003C4E80(void *, void *);
    extern void func_L01_0044E130(void *, void *);
    f32 v0[4], v1[4];
    u8 *p = func_L01_004618E0(2);
    u8 *vars;
    if (p) {
        *(Q_463218 *)(p+0x10) = *pos;
        *(f32 *)(p+0xC) = 0.0f;
        *(s32 *)(p+4) = color0;
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x44;
        p[8] = (s32)func_003824E0(*(f32 *)(p+0xC),255.0f);
        if (texture == -1) {
            p[2] = D_L01_002210F4[0][0];
        } else {
            p[2] = D_L01_00221098[texture & 0xFFFF][0];
            if (texture & 0x10000) p[3] = 0x48;
        }
        *(s16 *)(p+0xA) = life0;
        vars = p+0x20;
        *(s16 *)(vars+0x16) = (s32)(a[3] * 210000.0f / 1000.0f);
        *(s16 *)(vars+0x18) = (s32)(b[3] * 210000.0f / 1000.0f);
        func_003C4E80(a, vars);
        func_003C4E80(b, vars+4);
        func_L01_0044E130(v0, vars);
        func_L01_0044E130(v1, vars+4);
        *(s32 *)(vars+8) = color0;
        *(s32 *)(vars+0xC) = color1;
        *(s16 *)(vars+0x10) = life0;
        *(s16 *)(vars+0x12) = life1;
        *(s16 *)(vars+0x14) = duration;
    }
    return p;
}
/* localdecomp:end func_L01_00463378 */
