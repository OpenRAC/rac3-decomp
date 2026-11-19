/* functional: medium. Written from the PAL asm (no draft). Per-condition checks 0..11 of an enable-flag table (cfg+0x30) setting or clearing bit k of the output set via func_L01_0032A0C8/A118. Blocks 1 and 2 are identical in retail (cfg+0x50/0x54 and 0x58/0x5C) and are written as a loop over k. In the list mode of block 0 (cfg+0x4C != -1) every exit leaves the result at 0 in retail (no path sets it), reproduced as is, with the queries still called. D_001A71A0 is read as a pointer in entry 0. Parameter 4 is the work object the caller passes in $a3 (unused here). 559 words differ. */
/* localdecomp:start func_L01_00334868 */
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0100;
extern u8 *D_L01_001DFC48;
extern u8 *D_L01_001EFFE8[];
extern s32 D_L01_001F01E8[];
extern s32 D_L01_001D6774;
extern u16 *D_L01_0021DE20[];
extern u8 *D_001A71A0[];
extern u8 D_001BBC40[];
extern u8 D_00142BA0[];
extern s32 D_001D545C;
extern f32 func_0038CF38(void *, void *);
__asm__(".extern D_001E0058_sda, 4");
extern s32 D_001E0058_sda;
s32 func_L01_00334868(u8 *m, u8 *st, u8 *tgt, u8 *work, void *bits, u8 *cfg, u8 *vt)
{
    extern void func_L01_0032A0C8(void *, u8 *, s32);
    extern void func_L01_0032A118(void *, u8 *, s32);
    extern s32 func_L01_00456500(void *, s32);
    extern void func_L01_00456270(s32);
    extern int func_L01_00456B40(u8 *, u8 *, f32, f32);
    extern s32 func_L01_00445AD0(s32, s32, s32);
    extern s32 func_L01_00456250(void *);
    extern s32 func_L01_004561B8(void *);
    extern s32 func_L01_0043B568(s32, s32, s32);
    extern void func_L01_00333F18(u8 *);
    s8 *flags;
    s32 a, i, n, k, k2, idx, off, v;
    u8 *t, *p, *obj, *rec;
    u16 *lst;
    f32 d, f1;
    s32 (*fn)(u8 *);
    s32 (**vtbl)(u8 *);

    if ((s8)st[0x5C] != -1) return 1;
    flags = (s8 *)(cfg + 0x30);

    if (flags[0] != 0) {
        a = 0;
        idx = *(s32 *)(cfg + 0x4C);
        if (idx == -1) {
            if (*(s32 *)(cfg + 0x48) == idx) t = D_001A71A0[0];
            else t = D_L01_001E001C + (*(s32 *)(cfg + 0x48) << 8);
            if (*(s32 *)(cfg + 0x40) == -1) {
                f1 = *(f32 *)(cfg + 0x44);
                if (0.0f < f1) {
                    d = func_0038CF38(tgt + 0x10, t + 0x10);
                    if (d < *(f32 *)(cfg + 0x44)) a = 1;
                }
            } else {
                a = func_L01_00456500(t + 0x10, *(s32 *)(cfg + 0x40)) != 0;
            }
        } else {
            lst = D_L01_0021DE20[idx];
            for (;;) {
                if ((idx & 0xFF) == 0xFF) break;
                if (D_001E0058_sda < idx) break;
                if (lst == 0) break;
                if ((s16)lst[-1] < 0 && lst != D_L01_0021DE20[idx]) break;
                t = D_L01_001E001C + ((*lst & 0x7FFF) << 8);
                if (t == 0) break;
                if (*(s32 *)(cfg + 0x40) != -1) {
                    if (func_L01_00456500(t + 0x10, *(s32 *)(cfg + 0x40)) != 0) break;
                }
                if (0.0f < *(f32 *)(cfg + 0x44)) {
                    d = func_0038CF38(tgt + 0x10, t + 0x10);
                    if (d < *(f32 *)(cfg + 0x44)) break;
                }
                idx = *(s32 *)(cfg + 0x4C);
                lst++;
            }
        }
        if (a != 0) func_L01_0032A0C8(bits, m, 0);
        else func_L01_0032A118(bits, m, 0);
    }

    for (k = 1; k < 3; k++) {
        if (flags[k] != 0) {
            off = (k - 1) * 8;
            t = 0;
            if (*(s32 *)(cfg + 0x50 + off) != -1) {
                func_L01_00456270(*(s32 *)(cfg + 0x50 + off));
                rec = D_L01_001DFC48 + *(s32 *)(cfg + 0x50 + off) * 0xE0;
                n = rec[4];
                if (n != 0) {
                    i = 0;
                    p = rec;
                    for (;;) {
                        i++;
                        if (p[5] == 3) {
                            obj = *(u8 **)p;
                            if (obj != 0 && obj[0x20] != 0xFE && obj[0x20] != 0xFD) {
                                t = obj;
                                break;
                            }
                        }
                        if (!(i < n)) break;
                        p += 8;
                    }
                }
            } else if (0.0f < *(f32 *)(cfg + 0x54 + off) && D_L01_001D6774 > 0) {
                for (k2 = 0; k2 < D_L01_001D6774; k2++) {
                    t = D_L01_001EFFE8[k2];
                    if (D_L01_001F01E8[k2] == 3) {
                        if (func_L01_00456B40(t, tgt + 0x10, *(f32 *)(cfg + 0x54 + off), 10.0f) != 0 &&
                            t != 0 && t[0x20] != 0xFE && t[0x20] != 0xFD) {
                            break;
                        }
                    }
                    t = 0;
                }
            }
            if (t != 0) func_L01_0032A0C8(bits, m, k);
            else func_L01_0032A118(bits, m, k);
        }
    }

    if (flags[3] != 0) {
        fn = *(s32 (**)(u8 *))(vt + 0x6C);
        if (fn != 0 && fn(tgt) != 0) func_L01_0032A0C8(bits, m, 3);
        else func_L01_0032A118(bits, m, 3);
    }

    if (flags[4] != 0) {
        a = 0;
        if (*(s32 *)(cfg + 0x64) != -1 && cfg[0x10] != 2 && cfg[0x11] != 2) {
            d = func_0038CF38(tgt + 0x10, D_L01_001E0100 + (*(s32 *)(cfg + 0x64) << 7) + 0x30);
            if (d < 2.0f) a = 1;
        } else if (*(s32 *)(cfg + 0x60) != -1 && cfg[0x10] != 2 && cfg[0x11] != 2) {
            d = func_0038CF38(tgt + 0x10, D_L01_001E001C + (*(s32 *)(cfg + 0x60) << 8) + 0x10);
            if (d < 5.0f) a = 1;
        } else if (*(s32 *)(cfg + 0x6C) != -1 && cfg[0x99] == 0) {
            a = st[0x5E] != 0;
        }
        if (a != 0) func_L01_0032A0C8(bits, m, 4);
        else func_L01_0032A118(bits, m, 4);
    }

    if (flags[5] != 0) {
        if (*(s32 *)(cfg + 0x68) != -1 && func_L01_00445AD0(*(s32 *)(cfg + 0x68), -1, 0) == 0) {
            func_L01_0032A0C8(bits, m, 5);
        } else {
            func_L01_0032A118(bits, m, 5);
        }
    }

    if (flags[7] != 0) {
        if (st[0x5D] != 0) func_L01_0032A0C8(bits, m, 7);
        else func_L01_0032A118(bits, m, 7);
    }

    if (flags[8] != 0) {
        a = 0;
        if (*(s32 *)(cfg + 0x60) != -1) {
            a = func_L01_00456250(D_L01_001E001C + (*(s32 *)(cfg + 0x60) << 8)) != 0;
        } else if (*(s32 *)(cfg + 0x48) != *(s32 *)(cfg + 0x60)) {
            a = func_L01_00456250(D_L01_001E001C + (*(s32 *)(cfg + 0x48) << 8)) != 0;
        }
        if (a != 0) func_L01_0032A0C8(bits, m, 8);
        else func_L01_0032A118(bits, m, 8);
    }

    if (flags[9] != 0 && *(s32 *)(cfg + 0x60) != -1) {
        vtbl = (s32 (**)(u8 *))func_L01_0043B568(0xF6E, 0, 4);
        if (vtbl != 0) {
            v = (*vtbl)(D_L01_001E001C + (*(s32 *)(cfg + 0x60) << 8));
            if (((u32 *)D_00142BA0)[(u32)v >> 2] & (1 << (v & 0x1F))) func_L01_0032A0C8(bits, m, 9);
            else func_L01_0032A118(bits, m, 9);
        } else {
            func_L01_0032A118(bits, m, 9);
        }
    }

    if (flags[10] != 0 && *(s32 *)(cfg + 0x74) != -1) {
        if (D_001BBC40[*(s32 *)(cfg + 0x74) + D_001D545C * 16] & 0x80) func_L01_0032A0C8(bits, m, 10);
        else func_L01_0032A118(bits, m, 10);
    }

    if (flags[11] != 0) {
        if (tgt[0x31] != 0) func_L01_0032A0C8(bits, m, 11);
        else func_L01_0032A118(bits, m, 11);
    }

    if (m[0x20] != 0x19) return 0;
    if (func_L01_004561B8(m) == 0) func_L01_0032A0C8(bits, m, 7);
    else func_L01_0032A118(bits, m, 7);
    if ((s8)st[0x5C] != -1) func_L01_00333F18(m);
    return 0;
}
/* localdecomp:end func_L01_00334868 */
