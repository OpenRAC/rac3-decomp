/* US draft of func_00385168 (rac3-uya-decomp func_00385140, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00385168 */
extern u8 D_00222480_00383C18[];
extern u8 *D_001D9B40[2];
extern s32 D_001D9B00[2];
extern s32 D_001D5B98;
extern s32 D_001D90B8;
extern s32 D_001D90B0;
extern void func_00384CB8(s32);
extern void func_00384878(s32, s32);
extern void func_00383760(s32);
extern void func_003C4C60();
extern void func_00384620();
extern void func_003862D0();
extern void func_00382CB8(s32);
void func_00385168(void) {
    s32 saved[16];
    s32 i;
    u8 *o;
    u8 *e;
    u8 *s;
    u8 *t;
    {
        s32 j;
        for (j = 0; j < 16; j++) {
            u8 *c = D_001D9B40[j];
            if (c != 0) {
                if (c[0x20] == 0xFE) {
                    D_001D9B40[j] = 0;
                } else if (c[0x20] == 0xFD) {
                    D_001D9B40[j] = 0;
                } else {
                    saved[j] = *(s32 *)(c + 0x98);
                    *(s32 *)(c + 0x98) = 0;
                }
            }
        }
    }
    for (i = 0; i < 1; i++) {
        e = D_00222480_00383C18 + i * 0x460;
        s = e + 0x150;
        if (*(s32 *)(s + 0x100) == 0x31) {
            u8 *t0 = *(u8 **)(s + 0xF4);
            if (t0 != 0) *(s32 *)(t0 + 0x98) = 0;
        }
        *(s32 *)(e + 0x454) += 1;
        func_00384EA8(i);
        func_00384F98(i);
        func_00384CB8(i);
        func_00384878(i, 0);
        func_00383760(i);
        o = *(u8 **)(e + 0x50);
        if (*(s32 *)(e + 0x458) > 0) *(s16 *)(e + 0x2A0) = 0;
        if ((u16)(*(u16 *)(e + 0x2A0) - 1) < 2) func_00383C18(*(u8 **)(e + 0x54));
        if (*(s16 *)(e + 0x2A0) == 3) {
            func_00384598(o);
        } else {
            *(u128_t *)(e + 0x000) = *(u128_t *)(o + 0x30);
            *(u128_t *)(e + 0x380) = *(u128_t *)(o + 0x00);
            *(u128_t *)(e + 0x390) = *(u128_t *)(o + 0x10);
            *(u128_t *)(e + 0x3A0) = *(u128_t *)(o + 0x20);
        }
        func_003C4C60(e + 0x380, e + 0x10);
        func_00384620(i, e + 0x20, 0);
        func_00384620(i, e + 0x30, 1);
        func_00384620(i, e + 0x40, 2);
        func_00384B58(i);
        func_003862D0(e);
        func_00382CB8(i);
        __asm__ __volatile__("sq $0,%0" : "=m"(*(u128_t *)(e + 0x410)));
        if (*(s32 *)(s + 0x100) == 0x31) {
            t = *(u8 **)(s + 0xF4);
            if (t != 0) *(s32 *)(t + 0x98) = *(s32 *)(*(u8 **)(t + 0x24) + 0x10);
        }
        ((u128_t *)D_001D9B00)[i] = *(u128_t *)e;
        func_0038CEB0(e + 0x458);
    }
    if (D_001D5B98 == 0) {
        D_001D90B0 = *(volatile s32 *)&D_001D90B8;
        func_003850A8(0);
    }
    {
        s32 j;
        for (j = 0; j < 16; j++) {
            u8 *c = D_001D9B40[j];
            if (c != 0) *(s32 *)(c + 0x98) = saved[j];
        }
    }
}
/* localdecomp:end func_00385168 */
TEXT_PADDING(2);
