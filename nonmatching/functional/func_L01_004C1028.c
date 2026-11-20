/* functional: medium. Rewritten from PAL asm; switch case order confirmed through the L04 copy's jump table; func_L01_00517BF8 takes six arguments (a0, 1, 1, 1, 0, 0 in retail). */
/* localdecomp:start func_L01_004C1028 */
extern void func_L01_00518D40(s32);
extern void func_L01_00518590(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E7F20(s32, s32);
extern void func_003E8898(s32, f32, f32);
extern void func_003E8630(s32, s32);
extern char *func_00381FF0(s32);
extern void func_L01_00518010(s32, s32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00516728(s32, f32, f32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00518670(s32, s32, s32);
extern void func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8(s32, s32, s32, f32);
extern void func_L01_00516B90(s32, s32, s32);

void func_L01_004C1028(u8 *tbl) {
    s32 i;
    u8 *r;
    s32 f20, a, b;
    s32 s;
    for (i = 0; *(s32 *)(tbl + i * 0x30) != 0; i++) {
        r = tbl + i * 0x30;
        switch (*(s32 *)(r + 8)) {
        case 0:
            func_L01_00518D40(*(s32 *)(r + 0));
            if (*(s32 *)(r + 0x2C) & 1) {
                func_L01_00518590(*(s32 *)(r + 0), 1, 1);
                func_L01_00516470(*(s32 *)(r + 0), *(f32 *)(r + 0x10), *(f32 *)(r + 0x14));
                func_L01_00517538(*(s32 *)(r + 0), *(f32 *)(r + 0x18), *(f32 *)(r + 0x1C));
            }
            break;
        case 1:
            func_003E8EF0(*(s32 *)(r + 0), *(s32 *)(r + 0x24), *(s32 *)(r + 0xC), *(f32 *)(r + 0x10), *(f32 *)(r + 0x14), *(f32 *)(r + 0x18), *(f32 *)(r + 0x1C), 0.0f);
            break;
        case 2:
            func_003E9138(*(s32 *)(r + 0), *(s32 *)(r + 0xC), *(s32 *)(r + 0x24), *(f32 *)(r + 0x10), *(f32 *)(r + 0x14), *(f32 *)(r + 0x18), *(f32 *)(r + 0x1C));
            break;
        case 3:
            func_003E9270(*(s32 *)(r + 0), *(s32 *)(r + 0xC), *(f32 *)(r + 0x10), *(f32 *)(r + 0x14), *(f32 *)(r + 0x18), *(f32 *)(r + 0x1C), *(f32 *)(r + 0x28), *(f32 *)(r + 0x28));
            break;
        case 4:
            if (*(s32 *)(r + 0x2C) & 4) s = (s32)func_00381FF0(*(s32 *)(r + 0x24));
            else s = *(s32 *)(r + 0x24);
            func_003E90B8(*(s32 *)(r + 0), s, *(s32 *)(r + 0xC), *(f32 *)(r + 0x10), *(f32 *)(r + 0x14), *(f32 *)(r + 0x18), *(f32 *)(r + 0x1C), 0.005f, 0.005f);
            func_003E7F20(*(s32 *)(r + 0), (*(s32 *)(r + 0x2C) & 0x10) ? 1 : 2);
            if (*(f32 *)(r + 0x28) != 0.0f) {
                func_L01_00518010(*(s32 *)(r + 0), 1);
                func_003E8898(*(s32 *)(r + 0), *(f32 *)(r + 0x28), 0.0f);
            }
            break;
        case 5:
            if (*(s32 *)(r + 0x2C) & 4) s = (s32)func_00381FF0(*(s32 *)(r + 0x24));
            else s = *(s32 *)(r + 0x24);
            func_003E9358(*(s32 *)(r + 0), s, *(s32 *)(r + 0xC), *(f32 *)(r + 0x10), *(f32 *)(r + 0x14), *(f32 *)(r + 0x18), *(f32 *)(r + 0x1C), 1.0f);
            func_L01_00516818(*(s32 *)(r + 0), *(f32 *)(r + 0x28));
            func_L01_00516728(*(s32 *)(r + 0), *(f32 *)(r + 0x28) * 0.005f, *(f32 *)(r + 0x28) * 0.005f);
            func_L01_00516AA0(*(s32 *)(r + 0), 0x40, 1);
            if (*(s32 *)(r + 0x2C) & 8) func_L01_00518670(*(s32 *)(r + 0), 1, 1);
            func_003E7F20(*(s32 *)(r + 0), (*(s32 *)(r + 0x2C) & 0x10) ? 1 : 2);
            if (*(s32 *)(r + 0x2C) & 0x60) {
                func_L01_00517BF8(*(s32 *)(r + 0), 1, 1, 1, 0, 0);
                func_L01_00517DB8(*(s32 *)(r + 0), 0xF0, 0, 0.0005f);
            }
            break;
        }
        f20 = *(s32 *)(r + 0x20);
        if (f20 != 0) {
            a = (f20 & 1) ? 1 : ((f20 & 2) ? 2 : 3);
            b = (f20 & 8) ? 1 : ((f20 & 0x10) ? 2 : 3);
            func_L01_00516B90(*(s32 *)(r + 0), a, b);
        }
        if (*(s32 *)(r + 0x2C) & 2) func_L01_00516AA0(*(s32 *)(r + 0), 1, 0);
        if (*(s32 *)(r + 4) != 0) func_003E8630(*(s32 *)(r + 4), *(s32 *)(r + 0));
    }
}
/* localdecomp:end func_L01_004C1028 */
