/* functional: high. 19 diff lines at level_01 (near exact); returns 0/1 */
extern u8 *func_00382348(void *);
extern void *func_L01_00448FF0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003ACCD8(void *, void *);
extern void func_L01_00445170(void *, s32);
extern void *func_L01_00449020(void *);
extern void func_L01_00452860(void *, void *, void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 D_L01_001DFB40;

s32 func_L01_003ACD38(u8 *obj, u8 *m) {
    u8 *t;
    u8 *c;
    s32 r;
    s32 cur;
    f32 f;

    if (*(s32 *)(m + 0x64) == 0) {
        return obj[0x20] != 1;
    }
    t = func_00382348(*(void **)(m + 0x64));
    if (t == 0) {
        return 1;
    }
    if (t[0xE] == 2 || t[0x2E] != 0) {
        func_L01_003ACCD8(obj, m);
        return 1;
    }
    r = func_L01_00452FB0(*(void **)(m + 0x64), func_L01_00448FF0(*(void **)(m + 0x64)), 0, 0, 0);
    if (r != 0) {
        if ((u32)(r - 4) < 2) {
            func_L01_003ACCD8(obj, m);
            return 1;
        }
        if ((u32)(r - 2) < 2) {
            func_L01_00445170(obj, 3);
        }
    }
    func_L01_00452860(*(void **)(m + 0x64), t, func_L01_00449020(obj));
    c = *(u8 **)(m + 0x64);
    if ((*(long *)(c + 0x30) & ((long)0x8208 << 29)) != ((long)0x8200 << 23) || *(s32 *)(c + 0x98) != 0) {
        f = *(f32 *)t;
        if (0.0f < f) {
            if (t[0x2F] != 0) {
                func_L01_00456BD0(c, 5);
            } else {
                func_L01_00456BD0(c, 3);
            }
        }
    }
    cur = D_L01_001DFB40;
    if (((*(s16 *)(obj + 0xB2) + 8) % 8) == (cur % 8)) {
        if (t[0x2F] != 0) {
            func_L01_00456C98(obj, *(s32 *)(m + 0xC30), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(m + 0xC34), *(f32 *)(m + 0xC34) * 0.8f, 2.0f);
        } else {
            func_L01_00456C98(obj, *(s32 *)(m + 0xC30), 0, 0, 0, 1, 1, 0, 0, 0, *(f32 *)(m + 0xC34), *(f32 *)(m + 0xC34) * 0.8f, 2.0f);
        }
    }
    if (*(s16 *)(m + 0x44) == 1) {
        *(u128_t *)(m + 0x70) = *(u128_t *)(m + 0x30);
    }
    return 0;
}
