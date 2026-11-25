/* func_L19_003C1F18: 2 diff in L19_003C0938.c (-mvu0-use-vf0-vf2 @ps2as): the per-frame update of the moby func_L19_003C2388 initialises.
 * Left: the two loads of obj[0x20] at the state-check block after the hero-target test are `lb` here, retail `lbu` (every delay
 * slot is now retail's). With `s32 s` (the previous draft) every opcode is right but 3 slots differ; `s8 s` trades them for these 2.
 * Fixed earlier: s16 s2 assigned inside the first switch's (u8) index (retail's lbu, andi and copy), case 1: goto past the second
 * switch (retail's threaded jump), the 0x10/0x11/0xF compares as nested ifs with return on 0xF (fold-const merges an && chain into a range).
 * The definition takes `void *arg` because the file declares `extern void func_L19_003C1F18(void *);` (in-context compile).
 *
 * Round 29 W29 (Opus; gcc 2.95.3 reorg.c read): with `s32 s` the pre-reorg RTL equals retail's; pass 1 gives the `b L_end` its
 * target's lbu (b -> L_end+4) and the beq 0xFD the annulled lbu of its target L_A (beql), both as retail. Then relax_delay_slots
 * calls try_merge_delay_insns (the slot is from-target and no CODE_LABEL lies between the beq and the b, own_thread_p), the two
 * lbu patterns are rtx_equal_p, so the b's copy is deleted and the beq unannulled; pass 2 refills the b with `addiu 0xf`. Retail
 * did not merge: its two loads must differ as RTL (or a label sat between the beq and the b at reorg time). `s8 s` makes the L_A
 * load a sign_extend (lb): no merge, all slots as retail, proof of the mechanism. Needed: an lbu at L_A whose pattern is not
 * (zero_extend:SI (mem:QI)) like L_end's. Tested: u8 140, s16/u16 3 (same pattern), unsigned long (zero_extend:DI, lbu, no merge)
 * 145 (dsll32/dsra32 truncations for the range test), an (unsigned long) cast on the L_end test 3 (folded), goto/if-else forms of
 * the k arms 3 / 14.
 *
 * Round 25 W7 (b39, ~35 compiles): whole-body duplication in both k arms 166, compare order variants 8 / 13, a switch for the
 * compares 144, declaration orders and block-local s all 3; flags -fno-sched-interblock / -fno-regmove / -fno-strength-reduce 3,
 * -fno-gcse 19.
 */
typedef struct { f32 x, y, z, w; } V_3C1F18 __attribute__((aligned(16)));
typedef struct { u8 p0[0xBF4]; u8 *xBF4; u8 p1[0x25C0 - 0xBF8]; u8 *x25C0; u8 p2[0x2850 - 0x25C4]; s32 x2850; } H_3C1F18;
extern H_3C1F18 D_001A4BE0;
extern u8 D_001A71C4[];
extern u8 *D_L19_001DF71C;
__asm__(".extern D_L19_001DF71C, 16");
extern u8 *D_L19_001E8E58[];
extern void func_L19_003C2388(u8 *);
extern void func_L19_003C2A98(u8 *);
extern void func_L19_003C29D0(A *);
extern void func_L01_00451DF8(void *, float *, float, int, int);
extern s32 func_L01_00452F78(u8 *, s32, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_00456BD0(void *, s32);
extern s32 func_L01_00456500(void *, s32);
extern int func_L01_00456B40(u8 *, u8 *, f32, f32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L19_003C1F18(void *arg) {
    u8 *obj = arg;
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *e;
    s32 idx;
    s32 found;
    s32 was;
    s8 s; s32 s4; s16 s2;
    V_3C1F18 a;
    V_3C1F18 b;

    if (obj[0x20] == 0)
        func_L19_003C2388(obj);
    obj[0x62] = 0;
    func_L01_00451DF8(obj, (float *)(p + 0x240), 2.5f, 0, 1);
    if ((*(unsigned long *)(obj + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23) || *(s32 *)(obj + 0x98) != 0) {
        if (obj[0x20] != 2) {
            if (D_001A71C4[0] == 1) {
                *(f32 *)(p + 0x30) = 1.0f;
                *(s16 *)(p + 0x34) = 1;
            }
            if (func_L01_00452F78(obj, 0, 0, 0) != 0)
                func_L19_003C2A98(obj);
        }
    }
    obj[0xA8] = 0xFF;
    func_L01_00452860(obj, p + 0x30, 0);
    if (*(s16 *)(p + 0x19A) == 0xD) {
        func_L01_004450F0(obj, 0x11, 7);
        return;
    }
    switch ((u8)(s2 = obj[0x95])) {
    case 1:
        goto done95;
    case 7:
        break;
    default:
        if (p[0x3E] == 2 || p[0x5E] != 0 || p[0x60] != 0) {
            func_L01_004443E8(obj, 0, 3);
            if (*(s32 *)(p + 0x444) != 0) {
                *(s8 *)(obj + 0x7F) = 0;
                *(u16 *)(obj + 0xB6) = (u16)((u16)(*(u16 *)(obj + 0xB6)) >> 1);
                *(u16 *)(obj + 0xB4) = (u16)((s32)((*(u16 *)(obj + 0xB4)) << 0x10) >> 0x11);
            }
            func_L19_003C29D0((A *)obj);
            return;
        }
    }
    switch ((u8)s2) {
    case 1:
    case 7:
        break;
    default:
        func_L01_00456BD0(obj, p[0x5F] ? 5 : 3);
    }
done95:
    {
    u8 *t = *(u8 **)(p + 0x230);
    if (t != 0) {
        s32 k = 0;
        if (t == D_001A4BE0.x25C0 || t == D_001A4BE0.xBF4 || *(s16 *)(t + 0xAA) == 0x173B)
            k = 1;
        if (!k ? (t != D_001A4BE0.x25C0 && (t == 0 || t[0x20] == 0xFE || t[0x20] == 0xFD)) : D_001A4BE0.x2850 <= 0) {
            s = obj[0x20];
            if ((u32)(s - 1) >= 4) {
                if ((u8)s != 0x10)
                    if ((u8)s != 0x11) {
                        if ((u8)s == 0xF)
                            return;
                        func_L01_004450F0(obj, 0xF, -1);
                    }
            }
        }
    }
    }
    if (obj[0x20] == 0xF)
        return;
    found = 0;
    was = *(s16 *)(p + 0x234) == 1;
    idx = *(s32 *)(p + 0x410);
    if (idx >= 0) {
        e = D_L19_001DF71C + (idx << 8);
        if (e != 0) {
            if ((*(s32 *)(p + 0x428) >= 0 && func_L01_00456500(e + 0x10, *(s32 *)(p + 0x428)) != 0) ||
                (*(s32 *)(p + 0x428) < 0 && func_L01_00456B40(e, obj + 0x10, *(f32 *)(p + 0x42C), 3.0f) != 0)) {
                *(u8 **)(p + 0x230) = e;
                *(s16 *)(p + 0x234) = 1;
                found = 1;
                *(u128_t *)(p + 0x220) = *(u128_t *)(e + 0x10);
            }
        }
    }
    if (!found) {
        s4 = obj[0x95];
        if (s4 == 4 || s4 == 2)
            func_L01_00456C98(obj, *(s32 *)(p + 0x420), 0, 0, 0, 0, p[0x5F] ? 3 : 1, 0, 0, 0, *(f32 *)(p + 0x424), 3.0f, 1.0f);
        else
            func_L01_00456C98(obj, *(s32 *)(p + 0x428), 0, 0, 0, 0, p[0x5F] ? 3 : 1, 0, 0, 0, *(f32 *)(p + 0x42C), 3.0f, 1.0f);
    }
    if (was)
        return;
    if (*(s16 *)(p + 0x234) != 1)
        return;
    a = *(V_3C1F18 *)(obj + 0x10);
    a.z = a.z + 0.5f;
    b = *(V_3C1F18 *)(p + 0x220);
    b.z = b.z + 0.5f;
    if (func_003D3CB0(&a, &b, 0, obj, 0) != 0 && D_L19_001E8E58[0] != *(u8 **)(p + 0x230))
        *(s16 *)(p + 0x234) = 0;
}
