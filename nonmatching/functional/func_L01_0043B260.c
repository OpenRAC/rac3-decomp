/* functional: high. Same loop, comparisons, stores and calls; the vsub.xyz (lqc2/sqc2 through VU0) is plain float math, keeping the destination w lane as retail does (w of the minuend). */
typedef struct { f32 x, y, z, w; } V4_0043B260;
extern s32 D_L01_001E00B4;
extern u8 *D_L01_001E00C0;
extern s32 D_001D6694;
extern u8 D_L01_001DF9E4;
extern u8 D_L01_001DF9E5;
extern u8 D_L01_001DF9E6;
extern f32 D_L01_001DF9E8;
extern f32 D_L01_001DF9EC;
extern f32 D_L01_001DF9F0;
extern f32 D_L01_001DF9F4;
extern u8 D_001A30B0[];
extern f32 func_L01_0040E4C0(void *);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_003A1930(s32, s32, s32);
extern void func_003864C0(s32);

void func_L01_0043B260(u8 *obj) {
    s32 i;
    s32 best = -1;
    f32 bestd = 1000000.0f;
    V4_0043B260 v;
    V4_0043B260 d;
    f32 *p;
    u8 *rec;
    s32 off;

    for (i = 0; i < D_L01_001E00B4; i++) {
        rec = D_L01_001E00C0 + i * 32;
        v.x = *(u16 *)(rec + 4) * 0.25f;
        v.y = *(u16 *)(rec + 6) * 0.25f;
        v.z = *(u16 *)(rec + 8) * 0.25f;
        p = (f32 *)(obj + 0x10);
        d.x = p[0] - v.x;
        d.y = p[1] - v.y;
        d.z = p[2] - v.z;
        d.w = p[3];
        {
            f32 dist = func_L01_0040E4C0(&d);
            if (dist < bestd) {
                bestd = dist;
                best = i;
            }
        }
    }
    if (best == -1) {
        return;
    }
    if (400.0f < bestd) {
        return;
    }
    off = best * 32;
    rec = D_L01_001E00C0 + off;
    func_003C6F90(obj, (rec[0x12] << 16) + (rec[0x11] << 8) + rec[0x10], 0, 0, 0);
    *(s32 *)(obj + 0x38) = *(s32 *)(D_L01_001E00C0 + off);
    if (D_001D6694 != 2) {
        rec = D_L01_001E00C0 + off;
        if (rec[0x16] != 0) {
            *(s32 *)(D_001A30B0 + 0xB4) = *(s16 *)(rec + 0xA);
            D_001A30B0[0x40] = rec[0x13];
            D_001A30B0[0x41] = rec[0x14];
            D_001A30B0[0x42] = rec[0x15];
            D_001A30B0[0x43] |= 7;
        }
        if (D_001D6694 != 2) {
            func_003A1930(*(s16 *)(D_L01_001E00C0 + off + 0xC), 1, 0x400);
        }
    }
    rec = D_L01_001E00C0 + off;
    if (*(s16 *)(rec + 0x1A) < *(s16 *)(rec + 0x1C)) {
        D_L01_001DF9E4 = rec[0x17];
        D_L01_001DF9E5 = rec[0x18];
        D_L01_001DF9E6 = rec[0x19];
        D_L01_001DF9E8 = *(s16 *)(rec + 0x1A) * 1024.0f;
        D_L01_001DF9EC = *(s16 *)(rec + 0x1C) * 1024.0f;
        D_L01_001DF9F0 = rec[0xE];
        D_L01_001DF9F4 = rec[0xF];
        func_003864C0(0);
    }
}
