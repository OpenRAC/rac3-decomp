/* functional: high. Draft (92 diff: loop-invariant constant hoisting and saved-register choice) verified line by line against PAL asm: slot cleanup (>=0xFD), the three-band frame-skip tests (DEE70/74/78, D_L32_001DF9C0), first-free-slot spawn via func_L32_0039FE78, 32-entry x/z offset rebase. */

extern s32 D_L32_001DF9C0;
extern s32 D_L32_001DEE70;
extern s32 D_L32_001DEE78[];
extern s32 D_L32_001DEE74[];
extern u8 *D_L32_001DFE1C[];
extern void func_003C2F58(void *, s32, void *);
extern s32 func_00382498(s32, s32);
extern s32 func_L32_0039FE78(void *, s32, s32, s32, s32);

void func_L32_003B6A58(u8 *a0) {
    u8 *st;
    u8 **tbl;
    u8 **q, **slot;
    s32 i, flag, found, n, j;
    f32 vec[4];
    f32 y;
    u8 *e;
    f32 *p;
    flag = 0;
    st = *(u8 **)(a0 + 0x68);
    tbl = (u8 **)(st + 0x150);
    q = tbl;
    for (i = 0x2F; i >= 0; i--, q++) {
        if (*q != 0) {
            if (!((*q)[0x20] < 0xFD)) {
                *q = 0;
            }
        }
    }
    y = *(f32 *)(a0 + 0x10);
    if (!(*(f32 *)(st + 0x22C) < y)) {
        if (*(f32 *)(st + 0x228) < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE78[0]) == 0;
        } else if (*(f32 *)(st + 0x224) < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE74[0]) == 0;
        } else if (*(f32 *)(st + 0x238) < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE70) == 0;
        }
    }
    if (flag) {
        found = 0;
        for (i = 0; i < 0x30 && !found; i++) {
            slot = &tbl[i];
            if (*slot == 0) {
                found = 1;
                func_003C2F58(a0, 1, vec);
                if (*(f32 *)(st + 0x228) < *(f32 *)(a0 + 0x10)) {
                    n = func_00382498(2, 3);
                } else {
                    n = func_00382498(0, 1);
                }
                *slot = (u8 *)func_L32_0039FE78(vec, *(s32 *)(D_L32_001DFE1C[0] + (*(s32 *)(st + 0x230) << 8) + 0x68) + (n * 0x210 + 0x80), 1, 0, 0);
                if (tbl[i] != 0) {
                    p = (f32 *)(*(u8 **)(tbl[i] + 0x68) + 0x100);
                    for (j = 0x1F; j >= 0; j--, p++) {
                        p[-0x20] += *(f32 *)(a0 + 0x10) - *(f32 *)(st + 0x130);
                        p[0] += *(f32 *)(a0 + 0x18) - *(f32 *)(st + 0x250);
                    }
                }
            }
        }
    }
}

