/* functional: high. Display/GS init for the current video mode: picks the framebuffer layout (3 variants keyed on D_00143950/D_001D5520), derives the GS display/scissor values from the 16-bit width/height fields of D_001CFEC0, writes them to the GS packet/register shadows, and (when clear!=0) clears the screen buffers in a loop; ends with func_003D96F0(). Written from the asm; D_00142120/D_001D5330 slot values checked word by word. Unrun branches not known. */
typedef struct { u8 p0[0x150]; s16 h150; s16 h152; u8 p154[4]; s16 h158; s16 h15A; } V_387EF8;
typedef struct { u8 p0[0x240]; s32 f240, f244, f248, f24C; } G_387EF8;
extern s32 D_00143950;
extern s32 D_001D5520;
extern s32 D_001A1ED0[];
extern V_387EF8 D_001CFEC0;
extern G_387EF8 D_00225900;
extern u8 D_00142120[];
extern long D_001D5330[];
extern long D_00142360;
extern long D_001422F0;
extern s32 D_001D4BB0, D_001D4BB4;
extern s32 D_001D4BC0, D_001D4BC4, D_001D4BC8, D_001D4BCC;
extern s32 D_001D4BD0, D_001D4BD4, D_001D4BD8, D_001D4BDC;
extern u8 D_002276C0[];
extern void func_0011F0A0(s32);
extern void func_0012A9F0(s32, s32);
extern void func_00391A58(s32, s32, s32, s32, s32, s32);
extern void func_00392698(void);
extern void func_00392730(s32);
extern void func_00392670(void);
extern void func_0038CF58(void *, s32, s32);
extern void func_0012C9A0(void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0012CCC8(void *, void *);
extern void func_003D96F0(void);

void func_00387EF8(s32 clear)
{
    s32 buf[24];
    s32 w2, h2, w, h, i, n, base;
    long a, b, c;

    func_0011F0A0(0);
    if (D_00143950 != 0) {
        D_001A1ED0[2] = 0x100000;
        D_001A1ED0[1] = 0x1E0000;
        D_001A1ED0[3] = 0x2C0000;
        D_001A1ED0[0] = 0;
        func_00391A58(0x200, 0x1C0, 0x200, 0x200, 4, 0);
    } else if (D_001D5520 != 0) {
        D_001A1ED0[3] = 0x2C0000;
        D_001A1ED0[1] = 0x1E8000;
        D_001A1ED0[2] = 0x118000;
        D_001A1ED0[0] = 0;
        func_00391A58(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        D_001A1ED0[1] = 0x1E8000;
        D_001A1ED0[3] = 0x2C0000;
        D_001A1ED0[2] = 0x118000;
        D_001A1ED0[0] = 0;
        func_00391A58(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }

    h2 = D_001CFEC0.h152 >> 1;
    w2 = D_001CFEC0.h150 >> 1;
    w = D_001CFEC0.h150;
    h = D_001CFEC0.h152;
    base = D_001A1ED0[3];
    D_001D4BD4 = (0x800 - h2) << 4;
    D_001D4BD0 = (0x800 - w2) << 4;
    D_00225900.f244 = w - 1;
    D_00225900.f24C = h - 1;
    *(long *)(D_00142120 + 0x60) = (long)D_001D4BD0 | ((long)D_001D4BD4 << 32);
    D_001A1ED0[5] = base + 0x1000;
    D_001A1ED0[6] = base + 0x1400;
    D_001A1ED0[7] = base + 0x1800;
    D_001A1ED0[8] = base + 0x1C00;
    b = ((long)D_001A1ED0[1] >> 13) | ((long)(w >> 6) << 16);
    a = (long)(D_001A1ED0[2] >> 13) | 0x1000000;
    D_001D4BD8 = (w2 + 0x800) << 4;
    D_001D4BDC = (h2 + 0x800) << 4;
    *(long *)(D_00142120 + 0x20) = b;
    *(long *)(D_00142120 + 0x50) = (long)D_001D4BD0 | ((long)D_001D4BD4 << 32);
    D_001A1ED0[4] = base;
    D_001D4BC0 = w;
    D_001D4BC4 = h;
    D_001D4BC8 = w2;
    D_001D4BCC = h2;
    D_00142360 = a | 0x100000000L;
    D_00225900.f240 = 0;
    D_00225900.f248 = 0;
    *(long *)(D_00142120 + 0x10) = b;
    *(long *)(D_00142120 + 0x30) = a;
    *(long *)(D_00142120 + 0x40) = a;
    D_001D5330[2] = (long)(w - 1 << 16) | ((long)D_00225900.f24C << 48);
    D_001D5330[4] = ((long)D_00225900.f244 << 16) | ((long)D_00225900.f24C << 48);
    D_001422F0 = a;

    if (clear != 0) {
        D_001D4BB4 = base;
        D_001D4BB0 = base;
        func_0011F0A0(0);
        func_0012A9F0(0, 0);
        func_0011F0A0(0);
        func_00392698();
        func_00392730(0);
        func_0011F0A0(0);
        func_0012A9F0(0, 0);
        func_00392670();
        func_0038CF58(D_002276C0, 0, 0x1000);
        n = (D_001CFEC0.h158 * D_001CFEC0.h15A) >> 10;
        for (i = 0; i < n; ) {
            func_0012C9A0(buf, (s32)(i << 20) >> 16, 1, 0, 0, 0, 0x20, 0x20);
            i++;
            func_0011F0A0(0);
            func_0012CCC8(buf, D_002276C0);
            func_0012A9F0(0, 0);
        }
    }
    func_003D96F0();
}
