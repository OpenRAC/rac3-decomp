/* functional: high. 178 diff words at the file's flags (0xD0 vs 0xE0 frame, scheduling and the branch-likely forms); register passthrough checked: func_003C4B50 receives p+0xD0 / p+0xD4 (the value still in a0), the +0xB0 > 0 path calls the handler returned by func_L01_0043B548(0x19E1, 0x6C) through its first word, the lui/gp reads of D_001D673C are the same variable, and the stores in jal delay slots (m+0x10 quad copy before func_003C5180) are in retail order. */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
extern s32 D_001D673C_sda;
extern u8 D_L01_001EAA20[];
extern void **func_L01_0043B548(s32, s32);
extern s32 func_003C4B50(s32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern void func_L01_0033B7C0(u8 *);
extern u8 *func_L01_00301798(u8 *, s32, s32, s32, s32);
extern s32 func_L01_003D4BB0(u8 *);

void func_L01_0033B530(u8 *m) {
    Q16 buf[8];
    u8 *sp = (u8 *)buf;
    u8 *p = *(u8 **)(m + 0x68);
    void **h;
    s32 t;
    V4 *mp;
    V4 *a;
    V4 *b;

    if (*(s32 *)(p + 0xB0) > 0) {
        h = func_L01_0043B548(0x19E1, 0x6C);
        p[0xBE] = 7;
        *(s32 *)(p + 0xB0) = -1;
        ((void (*)(u8 *))h[0])(m);
        return;
    }
    if (*(s32 *)(p + 0xD0) != 0) {
        if (func_003C4B50(*(s32 *)(p + 0xD0)) == 0) {
            *(s32 *)(p + 0xD0) = 0;
        }
    }
    if (*(s32 *)(p + 0xD4) != 0) {
        if (func_003C4B50(*(s32 *)(p + 0xD4)) == 0) {
            *(s32 *)(p + 0xD4) = 0;
        }
    }
    *(unsigned long *)(p + 0xC0) = 0;
    *(unsigned long *)(p + 0xC8) = 0;
    m[0x20] = 1;
    *(s32 *)(p + 0xD8) = 0;
    if (*(s16 *)(m + 0xAA) == 0x1FF) {
        *(s32 *)(p + 0xE4) = *(s32 *)(p + 0xE4) + 1;
    }
    if (D_001D673C_sda != 0) {
        *(u16 *)(m + 0x34) |= 0x100;
        func_003C5180(m + 0x10, sp, 0);
        func_L01_004515D8(m + 0xC0, sp, sp + 0x10);
        func_0038CF68(sp + 0x40, m + 0xE0, 0.5f);
        func_0038CF68(sp + 0x50, m + 0xE0, -4.0f);
        mp = (V4 *)(m + 0x10);
        a = (V4 *)(sp + 0x40);
        b = (V4 *)(sp + 0x50);
        a->x = a->x + mp->x;
        a->y = a->y + mp->y;
        a->z = a->z + mp->z;
        b->x = b->x + mp->x;
        b->y = b->y + mp->y;
        b->z = b->z + mp->z;
        if (func_003D3CB0(sp + 0x40, sp + 0x50, 2, m, 0) != 0) {
            *(Q16 *)(m + 0x10) = *(Q16 *)D_L01_001EAA20;
            func_003C5180(m + 0x10, sp + 0x60, 0);
            func_L01_004515D8(m + 0xC0, sp + 0x60, sp + 0x70);
        }
        *(s32 *)(p + 0xFC) = 1;
    }
    if (*(s32 *)(p + 0xFC) == 0) {
        *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) | 0x14;
        if (((p[0xDC] ^ 1) & 1) != 0) {
            func_L01_0033B7C0(m);
        }
    }
    *(s32 *)(p + 0x12C) = 0;
    t = *(s16 *)(m + 0xAA);
    if (t == 0x1FF) {
        *(s16 *)(p + 0xF6) = 0x64;
    } else if (t == 0x1F5) {
        *(u8 **)(p + 0x12C) = func_L01_00301798(m, 0, *(s32 *)(p + 0x134), *(s32 *)(p + 0x138), *(s32 *)(p + 0x13C));
    } else if (t == 0x200) {
        *(u8 **)(p + 0x12C) = func_L01_00301798(m, 1, *(s32 *)(p + 0x134), *(s32 *)(p + 0x138), *(s32 *)(p + 0x13C));
    } else if (t == 0x1FA) {
        *(s32 *)(p + 0x12C) = func_L01_003D4BB0(m);
    }
}
