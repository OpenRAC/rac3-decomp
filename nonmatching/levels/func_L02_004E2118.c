/* func_L02_004E2118: near miss (w3 p2w3). Written from asm (twin func_L00_002D40A0 unrelated). Base D_001A4BE0+0x1B40 as p, hero as g; tmp[1] spill matches.
   Remaining 4 rows: sq 0x20 / addiu -0x66 / sq 0 / sw 0x1B50 schedule order (stores).
    */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern void func_L02_004D36C0(s32, s32);

void func_L02_004E2118(u128_t *a0, u128_t *a1, s32 a2) {
    u128_t tmp[1];
    u8 *p = &D_001A4BE0[0x1B40];
    s32 st;
    u8 *g = D_001A4BE0;
    tmp[0] = *a1;
    st = *(s32 *)(g + 0x25C4) - 0x66;
    *(u128_t *)p = *a0;
    *(u128_t *)(p + 0x20) = tmp[0];
    *(s32 *)(g + 0x1B50) = a2;
    if ((u32)st >= 4) {
        func_L02_004D36C0(0x66, 2);
    }
}
