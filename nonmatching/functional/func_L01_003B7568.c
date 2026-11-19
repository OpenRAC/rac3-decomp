/* functional: medium. Not byte-matched. Same family as func_L01_003B7290 (type 0x1AB4 with optional second 0x16E4 object, then a 4-count 0x16BD group); passes q (not p) to the second spawn, as retail's $6 holds the second lookup result. gp-relative object base is D_L01_001E001C (gp+0x376C). */
extern s16 *D_L01_0021DE20[];
extern int D_L01_001E0058;
extern Fn_003B52B0 *func_L01_00326D78(s32);
extern u8 *func_L01_003B64F0(u8 *, s32 *, f32, f32);
extern s32 func_L01_003B6B68(u8 *, u8 *, s32, s32, s32, f32);
extern u8 *func_L01_003B6AB0(u8 *, u8 *, u8 *, s32, Fn_003B52B0 *);
extern s32 func_L01_003B69E0(u8 *, u8 *, u8 *, s32, s32);
extern void func_L01_003B69A0(u8 *, u8 *, u8 *);
extern void func_L01_003B6A80(u8 *, u8 *, u8 *, s32, s32);

void func_L01_003B7568(u8 *owner, u8 *s, s32 count, f32 t0) {
    Fn_003B52B0 *tbl1;
    Fn_003B52B0 *tbl2;
    f32 f20, f21;
    s32 stk0, stk4;
    s32 j, best, lt2, slot, r, b8;
    u8 *p, *q, *obj, *w20, *p2;
    s16 *list;
    s32 *A = (s32 *)(s + 0xF0);

    tbl1 = func_L01_00326D78(0x1AB4);
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
    best = 0xFF;
    lt2 = count < 2;
    j = 0;
    while (j < count) {
        p = func_L01_003B64F0(s, &stk4, t0, f20);
        if (p == 0) {
            *(s32 *)(s + 0x24) = 1;
            return;
        }
        if (stk4 >= 0) {
            slot = A[stk4];
        } else {
            slot = *(s32 *)(s + 0x124);
        }
        obj = func_L01_003B6AB0(owner, s, p, 0x1AB4, tbl1);
        if (obj == 0) {
            return;
        }
        *(s32 *)(s + 0x118) = (obj - D_L01_001E001C) >> 8;
        if ((*(s32 *)(s + 0x28) != 0 && !lt2) || slot >= 0) {
            best = func_L01_003B69E0(owner, s, obj, best, slot);
        }
        w20 = 0;
        q = func_L01_003B64F0(s, &stk0, 0.0f, f21);
        if (q != 0) {
            if (stk0 >= 0) {
                slot = A[stk0];
            } else {
                slot = *(s32 *)(s + 0x124);
            }
            w20 = func_L01_003B6AB0(owner, s, q, 0x16E4, tbl2);
            if (w20 != 0) {
                if ((*(s32 *)(s + 0x28) != 0 && !lt2) || slot >= 0) {
                    best = func_L01_003B69E0(owner, s, w20, best, slot);
                }
                func_L01_003B69A0(owner, s, w20);
            }
        }
        r = func_L01_003B6B68(owner, s, 0x16BD, 4, 0, 0.0f);
        j++;
        func_L01_003B69A0(owner, s, obj);
        ((void (*)(u8 *, u8 *, s32))((s32 *)tbl1)[6])(obj, w20, r);
        if (*(s32 *)(s + 0x120) == 0) {
            continue;
        }
        if (w20 != 0) {
            func_L01_003B6A80(owner, s, w20, 0, 0);
        }
        if (r == -1) {
            continue;
        }
        b8 = r & 0xFF;
        list = D_L01_0021DE20[r];
        if (b8 == 0xFF) {
            continue;
        }
        if (D_L01_001E0058 < r) {
            continue;
        }
        if (list == 0) {
            continue;
        }
        do {
            p2 = D_L01_001E001C + ((*(u16 *)list & 0x7FFF) << 8);
            if (p2 == 0) {
                break;
            }
            list++;
            func_L01_003B6A80(owner, s, p2, 0, 0);
            if (b8 == 0xFF) {
                break;
            }
            if (D_L01_001E0058 < r) {
                break;
            }
            if (list == 0) {
                break;
            }
        } while (list[-1] >= 0 || list == D_L01_0021DE20[r]);
    }
}
