#include "common.h"

/* NTSC-U counterpart of func_L39_006DB948 (src/levels/39_multiplayer_menu/L39_006D9FD8.c) */
/* localdecomp:start func_L39_006D8DF0 */
typedef struct E_006DB948 {
    u8 pad00[0x1C];
    s32 f1C;
    u16 f20;
    u8 pad22[6];
    s32 f28;
    u8 pad2C[0x10];
    u8 f3C[0xB];
    u8 f47[1];
} E_006DB948;
typedef struct L_006DB948 {
    s32 f0;
    s32 count;
    E_006DB948 **items;
} L_006DB948;

typedef struct G_006DB948 { u8 pad[0x78]; s32 f78; } G_006DB948;
extern G_006DB948 D_001A5E50_006D8DF0;
extern u8 D_L39_0024A048[];
s32 func_00120884(void *);
s32 func_001200E0(void *, void *, s32 *);
s32 func_L39_006D9388();

s32 func_L39_006D8DF0(u8 *obj, s32 arg1, s32 *out, s32 target, s32 mode) {
    s32 result = 0;
    L_006DB948 *list;

    if (obj[0x199] == 0) {
        list = 0;
        if (*(s32 *)(obj + 0x1AC) >= 0) {
            list = (L_006DB948 *)(obj + 0x1B4 + *(s32 *)(obj + 0x1AC) * 12);
        }
        if (list != 0 && list->count > 0) {
            s32 found = 0;
            s32 lo = 99999;
            s32 best0 = -1;
            s32 i = 0;
            s32 best1 = -1, best2 = -1, any = -1;
            s32 hi = 0;
            s32 sel = -1;
            s32 v28 = 0, v2C = 0, v30 = 0;
            s32 none = -1;

            for (; i < list->count; i++) {
                E_006DB948 *e = list->items[i];
                s32 id;
                if (target != none) {
                    s32 num = none;
                    s32 n;
                    if (e->f28 == 1) {
                        if ((u32)func_00120884(e->f3C) < 13) {
                            n = 0;
                            goto have;
                        }
                        func_001200E0(e->f47, D_L39_0024A048, &num);
                    }
                    n = num;
                have:
                    if (mode == 0) {
                        if (n >= hi && n < target && e->f20 < 0xDB) {
                            hi = n;
                            sel = e->f1C;
                        }
                    } else if (mode == 1) {
                        if (n <= lo && target < n && e->f20 < 0xDB) {
                            sel = e->f1C;
                            lo = n;
                        }
                    }
                }
                if (e->f1C == D_001A5E50_006D8DF0.f78 && e->f1C != none && e->f20 <= 0xDA) {
                    found = 1;
                }
                if (e->f20 >= 1 && e->f20 < 32) {
                    if (best0 == none || v28 < e->f20) {
                        best0 = e->f1C;
                        v28 = e->f20;
                    }
                }
                if (e->f20 >= 32 && e->f20 < 64) {
                    if (best1 == none || e->f20 < v2C) {
                        best1 = e->f1C;
                        v2C = e->f20;
                    }
                }
                if ((e->f20 >= 64 && e->f20 < 219 && best2 == none) || e->f20 < v30) {
                    v30 = e->f20;
                    best2 = e->f1C;
                }
                if (e->f20 == 0 && any == none) {
                    any = e->f1C;
                }
            }
            if (target != -1) {
                if (sel != -1) {
                    result = func_L39_006D7B28((void *)obj, sel, 0);
                    if (result) {
                        *out = sel;
                    }
                }
            } else if (found) {
                result = func_L39_006D7B28((void *)obj, D_001A5E50_006D8DF0.f78, 0);
                if (result) {
                    *out = D_001A5E50_006D8DF0.f78;
                }
            } else if (best0 != -1) {
                result = func_L39_006D7B28((void *)obj, best0, 0);
                if (result) {
                    *out = best0;
                }
            } else if (best1 != -1) {
                result = func_L39_006D7B28((void *)obj, best1, 0);
                if (result) {
                    *out = best1;
                }
            } else if (list->count >= 256 && best2 != -1) {
                result = func_L39_006D7B28((void *)obj, best2, 0);
                if (result) {
                    *out = best2;
                }
            } else if (any != -1) {
                result = func_L39_006D7B28((void *)obj, any, 0);
                if (result) {
                    *out = any;
                }
            } else {
                result = func_L39_006D9388(obj, arg1, out);
                if (result != 0 || *(s32 *)(obj + 0xDC) == -0x3CE) {
                    result = func_L39_006D7B28((void *)obj, *out, 0);
                }
            }
        } else {
            result = func_L39_006D9388(obj, arg1, out);
            if (result != 0 || *(s32 *)(obj + 0xDC) == -0x3CE) {
                result = func_L39_006D7B28((void *)obj, *out, 0);
            }
        }
    }
    return result;
}
/* localdecomp:end func_L39_006D8DF0 */
