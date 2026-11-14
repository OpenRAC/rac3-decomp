#include "common.h"

/* NTSC-U counterpart of func_L39_006CA060 (src/levels/39_multiplayer_menu/L39_006CA060.c) */
extern s32 *D_L39_0024D860;
extern u8 *D_L39_00247A74;

/* localdecomp:start func_L39_006C7570 */
extern s32 D_001A5E84[];
extern u8 D_L39_00249A18_006C7570[];
extern s32 func_0037DF98(s32);
s32 func_L39_006847C8(s32 *, s32, s32, s32, s32, f32);
s32 func_L39_006D46C0(void *, s32, s32, void *);
void func_L39_006CD720(void *, s32, void *);

typedef struct E_006CA060 {
    s32 x0;
    s32 n;
    u8 **items;
} E_006CA060;

s32 func_L39_006C7570(u8 *arg0, s32 arg1)
{
    u8 buf[0x190];
    u8 *mgr;
    s32 *cur;
    u8 *t;
    E_006CA060 *e;
    s8 found;
    s32 hit;
    s32 dup;
    s32 i;
    s32 j;
    s32 n;
    s32 *m1;
    s32 *m2;
    s32 *m3;

    if (arg1 == D_001A5E84[0]) {
        return 0;
    }
    mgr = (u8 *)D_L39_0024D860;
    cur = *(s32 **)(mgr + 0x38);
    if (func_L39_006D46C0(*(void **)(mgr + 0x44), arg1, 0, buf)) {
        if (*(s32 *)(buf + 0x30) == *cur) {
            return 0;
        }
        if (*(s32 *)(buf + 0x30) >= 0) {
            m1 = (s32 *)D_L39_00247A74;
            func_L39_006847C8(m1, func_0037DF98(0xFA5), func_0037DF98(0x1874), 4, 0, 0.6f);
            return 0;
        }
        t = *(u8 **)(mgr + 0x40);
        hit = 0;
        e = 0;
        if (t[0] != 0 && *(s32 *)(t + 4) >= 0) {
            e = (E_006CA060 *)(t + 0x28 + *(s32 *)(t + 4) * 12);
        }
        if (e != 0) {
            for (i = 0; i < e->n; i++) {
                if (*(s32 *)(e->items[i] + 0x1C) == arg1) {
                    hit = 1;
                    break;
                }
            }
        }
        found = hit;
        if (found) {
            m2 = (s32 *)D_L39_00247A74;
            func_L39_006847C8(m2, func_0037DF98(0xFA5), func_0037DF98(0x1875), 4, 0, 0.6f);
            return 0;
        }
        n = *(s32 *)(arg0 + 0x2B0);
        dup = 0;
        for (j = 0; j < n; j++) {
            dup |= ((s32 *)(arg0 + 0x2B4))[j] == arg1;
        }
        if (dup) {
            return 1;
        }
        func_L39_006CD720(cur, arg1, cur + 1);
        arg0[0x2A8] = 1;
        return 1;
    }
    m3 = (s32 *)D_L39_00247A74;
    func_L39_006847C8(m3, func_0037DF98(0xFA5), (s32)D_L39_00249A18_006C7570, 4, 0, 0.6f);
    return 0;
}
/* localdecomp:end func_L39_006C7570 */
