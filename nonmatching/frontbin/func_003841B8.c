/* US draft of func_003841B8 (rac3-uya-decomp func_0037FEE8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_0037F7A8. */


/* localdecomp:start func_003841B8 */
extern u8 D_00222720[];
extern u8 D_00222480_003841B8[];
extern s32 func_0037F7A8();
extern s32 func_00383C48();
void func_003841B8(u8 *o) {
    u8 *e;
    u8 *d;
    s32 r;
    e = D_00222720 + *(s32 *)(o + 0x94) * 0x460;
    if (e[2] == 0) {
        r = func_0037F7A8(o, e + 0x10);
    } else {
        r = func_00383C48(o, e + 0x70);
    }
    if (r) {
        d = D_00222480_003841B8 + *(s32 *)(o + 0x94) * 0x460;
        *(u128_t *)(d + 0x380) = *(u128_t *)(o + 0x00);
        *(u128_t *)(d + 0x390) = *(u128_t *)(o + 0x10);
        *(u128_t *)(d + 0x3A0) = *(u128_t *)(o + 0x20);
        *(volatile u128_t *)(d + 0x000) = *(u128_t *)(o + 0x30);
        *(volatile u8 *)(e + 2) = 0;
        *(volatile u16 *)e = 0;
    }
}
/* localdecomp:end func_003841B8 */
