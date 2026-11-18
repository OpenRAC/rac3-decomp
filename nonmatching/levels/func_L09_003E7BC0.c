/* func_L09_003E7BC0: near miss with the file's flags (the check counts 58 differences, but they are one cause plus a one-word shift).
   Found 2026-11-18: the three 0.0f stores go through one float variable assigned after the calls (`z = 0.0f;` then three stores of z) which gives
   retail's mtc1 $zero,$f0 + swc1, and the store order EC, DC, CC in the source gives retail's cc, ec, (jal slot) dc order. Left: (1) the first branch of
   the tail copy: retail has `bnez $v0 ; addiu $v0,$zero,2` (the constant for the second compare in a plain slot, from the fall-through) where gcc's reorg takes the
   target thread, `bnel $v0,$zero ; lq $v0,0x10($a0)`, one word more, which shifts everything after it (the shared-store form with a temp u128 has 10 differences
   but is not retail's structure: retail stores in each arm and the D arm's sq sits in the `b` slot); (2) retail's `move $a1,$s1` comes before the sq of m+0xC0 (the sq
   is in the jal's delay slot), ours has the sq first. Reorg's thread choice follows the jump's static prediction (a NE-against-zero jump predicts taken, so the target thread
   is tried first); `p[0x2F] != 2 && c == 0` in that order gives a beql form with the same target-thread fill. */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_003C7C38(void *);
extern u8 D_001D9B60[];
extern u128_t D_001A4CB0[];

u8 *func_L09_003E7BC0(s32 a0, void *a1, void *a2, s32 a3, s16 a4, s32 a5, s32 a6, s32 a7) {
    u8 *m;
    u8 *p;
    f32 v[4];
    f32 z;
    m = func_003C24B0(0x1C0C, 0x80);
    if (m != 0) {
        m[0x30] = 0xFF;
        *(s32 *)(m + 0xB8) = a0;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 0.4f;
        p = *(u8 **)(m + 0x68);
        *(u128_t *)(m + 0x10) = *(u128_t *)a1;
        *(u128_t *)p = *(u128_t *)a2;
        *(s32 *)(p + 0x20) = a3;
        *(f32 *)(p + 0x24) = func_0038CEA8(a2);
        *(s16 *)(p + 0x2C) = a4;
        p[0x2E] = a5;
        if (a7 != 0) {
            p[0x2F] = 2;
        } else if (a6 != 0) {
            p[0x2F] = 1;
        } else {
            p[0x2F] = 0;
        }
        {
            u8 *q = *(u8 **)(p + 0x20);
            if (q != 0) {
                if (*(s16 *)(q + 0xAA) == 0 && p[0x2F] != 2) {
                    *(u128_t *)(p + 0x10) = D_001A4CB0[0];
                } else {
                    *(u128_t *)(p + 0x10) = *(u128_t *)(q + 0x10);
                }
            }
        }
        func_0038CF68(v, a2, 1.0f);
        *(u128_t *)(m + 0xC0) = *(u128_t *)v;
        func_0038CE90(m + 0xD0, m + 0xC0, D_001D9B60);
        func_0038CF68(m + 0xD0, m + 0xD0, 1.0f);
        func_0038CE90(m + 0xE0, m + 0xD0, m + 0xC0);
        z = 0.0f;
        *(f32 *)(m + 0xEC) = z;
        *(f32 *)(m + 0xDC) = z;
        *(f32 *)(m + 0xCC) = z;
        func_003C48A8(m + 0xC0, m + 0xF0);
        func_003C7C38(m);
    }
    return m;
}
