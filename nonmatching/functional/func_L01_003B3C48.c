/* functional: medium. Same reads, call order, conditions and return values (inverted sense vs 36A8: 1 = finished/rejected); only register allocation differs (instruction count equal). 5C80 float return, null out pointers. */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DE634;
extern u8 D_001A4C60[];
extern s32 func_L01_003B5B68(u8 *);
extern s32 func_L01_003B5B88(u8 *, s32);
extern s32 func_L01_003B5F10(u8 *);
extern s32 func_L01_003B5F30(u8 *, s32);
extern f32 func_L01_003B5C80(u8 *, s32, s32, f32 *, f32 *);
extern s32 func_L01_003B5EF0(u8 *, s32);
extern f32 func_L01_003B5F60(u8 *, s32);
extern s32 func_L01_003B5FC8(u8 *, s32);
extern s32 func_L01_00456500(u8 *, s32);
extern s32 func_L01_00456250(u8 *);
extern s32 func_L01_00445AD0(s32, s32, s32);

s32 func_L01_003B3C48(u8 *a0, u8 *c) {
    u8 *t68 = *(u8 **)(*(u8 **)(c + 8) + 104);
    u16 *p;
    u8 *n;
    u8 *cur;
    u8 *st;
    f32 sx = 0.0f;
    f32 sy = 0.0f;
    f32 r;
    s32 cntX = 0;
    s32 cntY = 0;
    s32 cntA = 0;
    s32 cntB = 0;
    s32 idx;
    s32 all;

    if (*(s32 *)(c + 124) != 0) {
        if (D_L01_001DFB40 - *(s32 *)(c + 4) > *(s32 *)(c + 124) * 50) {
            return 1;
        }
    }
    if (*(s32 *)(c + 128) != 0) {
        if (D_L01_001DFB40 - *(s32 *)(t68 + 96) > *(s32 *)(c + 128) * 50) {
            return 1;
        }
    }
    if (*(s32 *)(c + 136) != 0) {
        p = D_L01_0021DE20[*(s32 *)(c + 12)];
        while ((*(s32 *)(c + 12) & 0xFF) != 255 && *(s32 *)(c + 12) <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(c + 12)])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            if (func_L01_003B5B68(n) != 0) {
                if (func_L01_003B5B88(n, 1) != 0) {
                    return 1;
                }
            }
            p++;
        }
    }
    if (*(s32 *)(c + 140) != 0) {
        p = D_L01_0021DE20[*(s32 *)(c + 12)];
        while ((*(s32 *)(c + 12) & 0xFF) != 255 && *(s32 *)(c + 12) <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(c + 12)])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            if (func_L01_003B5F10(n) != 0) {
                if (func_L01_003B5F30(n, 1) != 0) {
                    return 1;
                }
            }
            p++;
        }
    }
    cur = (u8 *)D_L01_001DE634;
    if (cur != 0) {
        st = *(u8 **)(cur + 104);
        while (1) {
            if (func_L01_003B5B68(cur) != 0) {
                if (*(f32 *)(c + 160) >= 0.0f) {
                    r = func_L01_003B5C80(cur, 1, 1, 0, 0);
                    if (r >= 0.0f) {
                        sx += r;
                        cntX += 1;
                    }
                } else if (*(s32 *)(c + 164) < 0) {
                    if (func_L01_003B5B88(cur, 1) != 0) {
                        return 1;
                    }
                } else {
                    cntX += 1;
                    cntA += func_L01_003B5EF0(cur, 1);
                }
            } else if (func_L01_003B5F10(cur) != 0) {
                if (*(f32 *)(c + 168) >= 0.0f) {
                    r = func_L01_003B5F60(cur, 1);
                    cntY += 1;
                    sy += r;
                } else if (*(s32 *)(c + 172) >= 0) {
                    cntB += func_L01_003B5FC8(cur, 1);
                    cntY += 1;
                } else if (func_L01_003B5F30(cur, 1) != 0) {
                    return 1;
                }
            }
            cur = *(u8 **)(st + 88);
            if (cur == 0) {
                break;
            }
            st = *(u8 **)(cur + 104);
        }
        if (*(f32 *)(c + 160) >= 0.0f) {
            if (cntX >= 2) {
                sx = sx / (f32)cntX;
            }
            if (*(f32 *)(c + 160) <= sx) {
                return 1;
            }
        } else if (*(s32 *)(c + 164) >= 0) {
            if (cntA >= *(s32 *)(c + 164)) {
                return 1;
            }
        }
        if (*(f32 *)(c + 168) >= 0.0f) {
            if (cntY >= 2) {
                sy = sy / (f32)cntY;
            }
            if (*(f32 *)(c + 168) <= sy) {
                return 1;
            }
        } else if (*(s32 *)(c + 172) >= 0) {
            if (cntB >= *(s32 *)(c + 172)) {
                return 1;
            }
        }
    }
    idx = *(s32 *)(c + 132);
    if (idx != -1) {
        if (func_L01_00456500(D_001A4C60, idx) != 0) {
            return 1;
        }
    }
    idx = *(s32 *)(c + 144);
    if (idx != -1) {
        if (func_L01_00456250(D_L01_001E001C + (idx << 8)) != 0) {
            return 1;
        }
    }
    idx = *(s32 *)(c + 148);
    if (idx != -1) {
        all = 1;
        p = D_L01_0021DE20[idx];
        while ((idx & 0xFF) != 255 && idx <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[idx])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            if (func_L01_00456250(n) == 0) {
                all = 0;
                break;
            }
            p++;
            idx = *(s32 *)(c + 148);
        }
        if (all != 0) {
            return 1;
        }
    }
    idx = *(s32 *)(c + 152);
    if (idx != -1) {
        n = D_L01_001E001C + (idx << 8);
        if (n == 0) {
            return 1;
        }
        if (n[32] == 0xFE || n[32] == 0xFD) {
            return 1;
        }
    }
    idx = *(s32 *)(c + 156);
    if (idx != -1) {
        if (func_L01_00445AD0(idx, -1, 0) == 0) {
            return 1;
        }
    }
    return 0;
}
