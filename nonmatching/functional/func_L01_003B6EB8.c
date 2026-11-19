/* functional: medium. Not byte-matched; the retail index of the final s+0x7C store is the last loop idx (kept in a register), written the same here. */
extern s16 *D_L01_0021DE20[];
extern int D_L01_001E0058;
extern Fn_003B52B0 *func_L01_00326D78(s32);
extern u8 *func_L01_003B6AB0(u8 *, u8 *, u8 *, s32, Fn_003B52B0 *);
extern s32 func_L01_003B69E0(u8 *, u8 *, u8 *, s32, s32);
extern void func_L01_003B69A0(u8 *, u8 *, u8 *);

void func_L01_003B6EB8(u8 *owner, u8 *s, s32 count) {
    Fn_003B52B0 *tbl;
    s32 *out = (s32 *)(s + 0xA0);
    s32 *src = (s32 *)(s + 0xD0);
    s32 k, idx, i, cnt, v, best, b21, c;
    u8 *obj;
    u8 *p;
    s16 *list;

    tbl = func_L01_00326D78(*(s32 *)s);
    out[3] = -1;
    out[2] = -1;
    out[1] = -1;
    out[0] = -1;
    idx = 0;
    for (k = 0; k < 4; k++) {
        idx = (*(s32 *)(s + 0x7C) + k) % 4;
        if (src[idx] == -1) {
            continue;
        }
        cnt = *(s32 *)(s + 0x90 + idx * 4);
        if (cnt == 0) {
            continue;
        }
        v = *(s32 *)(s + 0xF0 + idx * 4);
        best = 0xFF;
        *(s32 *)(s + 0x78) = 1;
        c = count;
        if (c > 0) {
            i = 0;
            do {
                p = D_L01_001E001C + ((D_L01_0021DE20[src[idx]][i] & 0x7FFF) << 8);
                i++;
                obj = func_L01_003B6AB0(owner, s, p, *(s32 *)s, tbl);
                if (obj == 0) {
                    break;
                }
                best = func_L01_003B69E0(owner, s, obj, best, v);
                cnt--;
                c--;
                if (cnt == 0) {
                    break;
                }
            } while (c > 0);
        }
        *(s32 *)(s + 0x78) = 0;
        b21 = best & 0xFF;
        list = D_L01_0021DE20[best];
        if (b21 != 0xFF && D_L01_001E0058 <= best && list != 0) {
            do {
                p = D_L01_001E001C + ((*(u16 *)list & 0x7FFF) << 8);
                if (p == 0) {
                    break;
                }
                if (p[0x20] == 0) {
                    func_L01_003B69A0(owner, s, p);
                }
                if (b21 == 0xFF) {
                    break;
                }
                list++;
                if (D_L01_001E0058 < best) {
                    break;
                }
                if (list == 0) {
                    break;
                }
            } while (list[-1] >= 0 || list == D_L01_0021DE20[best]);
        }
        out[idx] = best;
    }
    *(s32 *)(s + 0x7C) = idx + 1;
}
