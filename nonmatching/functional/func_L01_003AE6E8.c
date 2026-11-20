/* functional: medium. Frame padded to retail's 0x150 with q0 at sp+0xA0: the first query's bytes 0x18/0x19 are left as stack garbage by retail (func_L01_00446760 does not set them) and func_003D3CB0 reads them, so the same garbage must be under the same place; D_L01_001EAA18 unsized (lui/lw as retail, was an out-of-reach $gp load). compiles; hit/no-hit control flow read block by block. The state>=2 path reaches the tail with s21=&p90 (set in the beq delay slot), as here. The two vadd.xyz are plain C (w lane from the register retail loads second / first, per the asm); the first one had its operands in the wrong load order. func_L01_003303B8 gets 8 reg ints, 4 floats and 18 stack slots as in the asm; func_003D3CB0 args 4,5 passed as pointer casts */
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00404A10(void *, u8 *);
extern void func_L01_003AEB68(void);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *D_L01_001EAA18[];

void func_L01_003AE6E8(u8 *obj) {
    u8 *pv = *(u8 **)(obj + 0x68);
    f32 p90[4] __attribute__((aligned(16)));
    u8 q0[0x30] __attribute__((aligned(16)));
    f32 d0[4] __attribute__((aligned(16)));
    u8 e0[0x30] __attribute__((aligned(16)));
    u8 pad[0x20] __attribute__((aligned(16))); /* retail's frame is 0x150: q0's bytes 0x18/0x19 are never written, so func_003D3CB0 reads what the stack held there */
    u8 *p;
    s32 hit;
    s32 st;

    *(s32 *)(pv + 0x18) = *(s32 *)(pv + 0x18) + 1;
    if (*(s32 *)(pv + 0x18) >= 0xF1) {
        func_L01_00446780(obj, obj + 0x10, 1, 0, 1, 0, 0.6f, *(f32 *)(pv + 0x14), 0.0f);
        func_L01_004450F0(obj, 1, -1);
    }
    st = obj[0x20];
    if (st == 0) {
        /* vadd.xyz into the register loaded from obj+0x10: w stays obj+0x10's w */
        p90[0] = *(f32 *)(obj + 0x10) + *(f32 *)(pv + 0x0);
        p90[1] = *(f32 *)(obj + 0x14) + *(f32 *)(pv + 0x4);
        p90[2] = *(f32 *)(obj + 0x18) + *(f32 *)(pv + 0x8);
        p90[3] = *(f32 *)(obj + 0x1C);
        func_L01_00446760(q0, obj, (s32)*(f32 *)(pv + 0xC), pv, *(f32 *)(pv + 0x14));
        *(u16 *)(q0 + 0x1A) = *(u16 *)(obj + 0xAA);
        func_L01_004CB320();
        hit = func_003D3CB0(obj + 0x10, p90, 0x10, (s32)obj, (s32)q0);
        if (hit != 0 && D_L01_001EAA18[0] != 0) {
            p = D_L01_001EAA18[0];
            if (*(s16 *)(p + 0xAA) == 0x186D && p[0x20] != 2 && p[0x20] != 5) {
                p[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            p = D_L01_001EAA18[0];
            if (p == 0) {
                vec_copy(d0, pv);
                func_0038CE20(d0, d0, 3.0f);
            } else if (p != *(u8 **)(pv + 0x10)) {
                vec_copy(d0, pv);
                func_0038CE20(d0, d0, 1.5f);
            } else {
                goto no_hit;
            }
            d0[2] = 1.0f;
            d0[3] = 5627.9248046875f;
            func_L01_00446760(e0, obj, (s32)*(f32 *)(pv + 0xC), d0, *(f32 *)(pv + 0x14));
            e0[0x19] = 1;
            *(u16 *)(e0 + 0x1A) = *(u16 *)(obj + 0xAA);
            e0[0x18] = 0;
            func_L01_004450F0(obj, 1, -1);
            return;
        }
no_hit:
        vec_copy(obj + 0x10, p90);
        func_0038CE20(d0, pv, -0.5f);
    } else if (st == 1) {
        func_L01_003303B8(obj + 0x10, 0, 10, 10, 10, 10, 10, 0, 0.25f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 0, 0, 0, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000,
                          0xFF8F00, 0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
        func_003C2880(obj);
        return;
    }
    func_0038CF68(p90, pv, -2.5f);
    p90[0] = p90[0] + *(f32 *)(obj + 0x10);
    p90[1] = p90[1] + *(f32 *)(obj + 0x14);
    p90[2] = p90[2] + *(f32 *)(obj + 0x18);
    p90[3] = 3.0f;
    if (func_0038DC20(p90, (f32)*(s16 *)(obj + 0x32) + 10.0f) >= 0) {
        func_L01_00404A10(func_L01_003AEB68, obj);
    }
}
