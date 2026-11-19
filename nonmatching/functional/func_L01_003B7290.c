/* functional: medium. Not byte-matched. In retail the second func_003B6AB0 call reuses the first object p (not the result of the second func_003B64F0), kept as retail. Declares func_L01_003B6B68 with a trailing f32 (retail passes f12=0.0). */
extern Fn_003B52B0 *func_L01_00326D78(s32);
extern u8 *func_L01_003B64F0(u8 *, s32 *, f32, f32);
extern s32 func_L01_003B6B68(u8 *, u8 *, s32, s32, s32, f32);
extern u8 *func_L01_003B6AB0(u8 *, u8 *, u8 *, s32, Fn_003B52B0 *);
extern s32 func_L01_003B69E0(u8 *, u8 *, u8 *, s32, s32);
extern void func_L01_003B69A0(u8 *, u8 *, u8 *);
extern void func_L01_003B6A80(u8 *, u8 *, u8 *, s32, s32);

void func_L01_003B7290(u8 *owner, u8 *s, s32 count, f32 t0) {
    Fn_003B52B0 *tbl1;
    Fn_003B52B0 *tbl2;
    f32 f20, f21;
    s32 stk0, stk4;
    s32 j, best, lt2, slot, slot2, r6, v7;
    u8 *p, *obj, *w22, *vars;
    s32 *A = (s32 *)(s + 0xF0);

    tbl1 = func_L01_00326D78(0x18AD);
    if (((s32 *)tbl1)[1] != 0) {
        f20 = ((f32 (*)(void))((s32 *)tbl1)[1])();
    } else {
        f20 = 0.0f;
    }
    f21 = 0.0f;
    tbl2 = func_L01_00326D78(0x16E4);
    if (tbl2 != 0 && ((s32 *)tbl2)[1] != 0) {
        f21 = ((f32 (*)(void))((s32 *)tbl2)[1])();
    }
    lt2 = count < 2;
    best = 0xFF;
    j = 0;
    while (j < count) {
        p = func_L01_003B64F0(s, &stk4, t0, f20);
        if (p == 0) {
            *(s32 *)(s + 0x24) = 1;
            return;
        }
        vars = *(u8 **)(p + 0x68);
        if (stk4 >= 0) {
            slot = A[stk4];
        } else {
            slot = *(s32 *)(s + 0x124);
        }
        obj = func_L01_003B6AB0(owner, s, p, 0x18AD, tbl1);
        if (obj == 0) {
            return;
        }
        if ((*(s32 *)(s + 0x28) != 0 && !lt2) || slot >= 0) {
            best = func_L01_003B69E0(owner, s, obj, best, slot);
        }
        w22 = 0;
        if (*(s32 *)(vars + 0x3C) != 0) {
            if (func_L01_003B64F0(s, &stk0, 0.0f, f21) != 0) {
                if (stk0 >= 0) {
                    slot2 = A[stk0];
                } else {
                    slot2 = *(s32 *)(s + 0x124);
                }
                w22 = func_L01_003B6AB0(owner, s, p, 0x16E4, tbl2);
                if (w22 != 0) {
                    if ((*(s32 *)(s + 0x28) != 0 && !lt2) || slot2 >= 0) {
                        best = func_L01_003B69E0(owner, s, w22, best, slot2);
                    }
                    func_L01_003B69A0(owner, s, w22);
                }
            }
        }
        *(s32 *)(s + 0x78) = 2;
        v7 = *(s32 *)(vars + 0x4C);
        r6 = 0xFF;
        if (v7 != 0) {
            r6 = func_L01_003B6B68(owner, s, 0x16BD, v7, 0, 0.0f);
        }
        *(s32 *)(s + 0x78) = 0;
        j++;
        ((void (*)(u8 *, u8 *, s32))((s32 *)tbl1)[6])(obj, w22, r6);
        func_L01_003B69A0(owner, s, obj);
        func_L01_003B6A80(owner, s, obj, 0, 0);
    }
}
