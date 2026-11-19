/* functional: medium. Not byte-matched. The jalr on tbl[1] is called with no args as retail leaves a0 stale (possible passthrough, unverified). Two linked-list walks over D_L01_0021DE20 mirror retail loops. */
extern s16 *D_L01_0021DE20[];
extern int D_L01_001E0058;
extern Fn_003B52B0 *func_L01_00326D78(s32);
extern u8 *func_L01_003B64F0(u8 *, s32 *, f32, f32);
extern u8 *func_L01_003B6AB0(u8 *, u8 *, u8 *, s32, Fn_003B52B0 *);
extern s32 func_L01_003B69E0(u8 *, u8 *, u8 *, s32, s32);
extern void func_L01_003B69A0(u8 *, u8 *, u8 *);
extern void func_L01_003B6A80(u8 *, u8 *, u8 *, s32, s32);
extern s32 func_003C4B40(s32);

s32 func_L01_003B6B68(u8 *owner, u8 *s, s32 type, s32 count, s32 flag, f32 t0) {
    Fn_003B52B0 *tbl;
    f32 t;
    s32 best;
    s32 stk0;
    s32 i;
    s32 lt2;
    u8 *p;
    u8 *obj;
    s32 slot;
    s32 b21;
    s16 *list;

    tbl = func_L01_00326D78(type);
    if (((s32 *)tbl)[1] != 0) {
        t = ((f32 (*)(void))((s32 *)tbl)[1])();
    } else {
        t = 0.0f;
    }
    best = 0xFF;
    if (*(s32 *)(s + 0x28) != 0 && *(s32 *)(s + 0x2C) != 0) {
        best = *(s32 *)(s + 0x68);
    }
    lt2 = count < 2;
    for (i = 0; i < count; i++) {
        p = func_L01_003B64F0(s, &stk0, t0, t);
        if (p == 0) {
            *(s32 *)(s + 0x24) = 1;
            best = 0xFF;
            goto after;
        }
        if (stk0 >= 0) {
            slot = *(s32 *)(s + 0xF0 + stk0 * 4);
        } else {
            slot = *(s32 *)(s + 0x124);
        }
        obj = func_L01_003B6AB0(owner, s, p, type, tbl);
        if (obj == 0) {
            goto after;
        }
        if ((*(s32 *)(s + 0x28) != 0 && !lt2) || slot >= 0) {
            best = func_L01_003B69E0(owner, s, obj, best, slot);
        }
        if (best == 0xFF) {
            func_L01_003B69A0(owner, s, obj);
        }
        if (flag) {
            func_L01_003B6A80(owner, s, obj, 0, 0);
        }
    }
after:
    if (best == 0xFF) {
        *(s32 *)(s + 0x68) = best;
        return best;
    }
    b21 = best & 0xFF;
    if (func_003C4B40(type) != 0 && b21 != 0xFF) {
        list = D_L01_0021DE20[best];
        if (D_L01_001E0058 <= best && list != 0) {
            do {
                p = D_L01_001E001C + ((*(u16 *)list & 0x7FFF) << 8);
                if (p == 0) {
                    break;
                }
                *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) & 0xFFBE;
                *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) | (*(u16 *)(*(u8 **)(p + 0x24) + 0x44) & 0x1000);
                list++;
                *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
                func_003C7C38((Obj_003B51A0 *)p);
                if (b21 == 0xFF) {
                    break;
                }
                if (D_L01_001E0058 < best) {
                    break;
                }
                if (list == 0) {
                    break;
                }
            } while (list[-1] >= 0 || list == D_L01_0021DE20[best]);
        }
    }
    if (b21 != 0xFF) {
        list = D_L01_0021DE20[best];
        if (D_L01_001E0058 < best) {
            *(s32 *)(s + 0x68) = best;
            return best;
        }
        if (list != 0) {
            do {
                p = D_L01_001E001C + ((*(u16 *)list & 0x7FFF) << 8);
                if (p == 0) {
                    break;
                }
                if (p[0x20] == 0) {
                    func_L01_003B69A0(owner, s, p);
                }
                list++;
                if (b21 == 0xFF) {
                    break;
                }
                if (D_L01_001E0058 < best) {
                    break;
                }
                if (list == 0) {
                    break;
                }
            } while (list[-1] >= 0 || list == D_L01_0021DE20[best]);
        }
    }
    *(s32 *)(s + 0x68) = best;
    return best;
}
