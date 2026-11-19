/* functional: medium. Same reads, call order, conditions and return values; only register allocation differs (instruction count equal). func_003B5C80/5F60 return floats; a0 unused as in retail. */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DE634;
extern u8 D_001A4C60[];
extern s32 func_L01_003B5B40(u8 *);
extern s32 func_L01_003B5B88(u8 *, s32);
extern s32 func_L01_003B5F00(u8 *);
extern s32 func_L01_003B5F30(u8 *, s32);
extern f32 func_L01_003B5C80(u8 *, s32, s32, f32 *, f32 *);
extern s32 func_L01_003B5EF0(u8 *, s32);
extern f32 func_L01_003B5F60(u8 *, s32);
extern s32 func_L01_003B5FC8(u8 *, s32);
extern s32 func_L01_00327330(void);
extern s32 func_L01_00456500(u8 *, s32);
extern s32 func_L01_00456250(u8 *);
extern s32 func_L01_00445AD0(s32, s32, s32);

s32 func_L01_003B36A8(u8 *a0, u8 *c) {
    u8 *t68 = *(u8 **)(*(u8 **)(c + 8) + 104);
    u16 *p;
    u8 *n;
    u8 *cur;
    u8 *st;
    f32 sx = 0.0f;
    f32 sy = 0.0f;
    f32 sz = 0.0f;
    f32 r;
    f32 sp[2];
    s32 cntA = 0;
    s32 cntB = 0;
    s32 cnt = 0;
    s32 idx;

    if (*(s32 *)(c + 52) != 0) {
        if (D_L01_001DFB40 - *(s32 *)(c + 4) < *(s32 *)(c + 52) * 50) {
            return 0;
        }
    }
    if (*(s32 *)(c + 56) != 0) {
        if (D_L01_001DFB40 - *(s32 *)(t68 + 96) < *(s32 *)(c + 56) * 50) {
            return 0;
        }
    }
    if (*(s32 *)(c + 64) != 0) {
        p = D_L01_0021DE20[*(s32 *)(c + 12)];
        while ((*(s32 *)(c + 12) & 0xFF) != 255 && *(s32 *)(c + 12) <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(c + 12)])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            if (func_L01_003B5B40(n) != 0) {
                if (func_L01_003B5B88(n, 0) == 0) {
                    return 0;
                }
            }
            p++;
        }
    }
    if (*(s32 *)(c + 68) != 0) {
        p = D_L01_0021DE20[*(s32 *)(c + 12)];
        while ((*(s32 *)(c + 12) & 0xFF) != 255 && *(s32 *)(c + 12) <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(c + 12)])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            if (func_L01_003B5F00(n) != 0) {
                if (func_L01_003B5F30(n, 0) == 0) {
                    return 0;
                }
            }
            p++;
        }
    }
    cur = (u8 *)D_L01_001DE634;
    if (cur != 0) {
        st = *(u8 **)(cur + 104);
        while (1) {
            if (func_L01_003B5B40(cur) != 0) {
                if (*(f32 *)(c + 88) >= 0.0f) {
                    r = func_L01_003B5C80(cur, 0, 1, &sp[0], &sp[1]);
                    if (r >= 0.0f) {
                        sx += sp[0];
                        sz += sp[1];
                    }
                } else if (*(s32 *)(c + 92) < 0) {
                    if (func_L01_003B5B88(cur, 0) == 0) {
                        return 0;
                    }
                } else {
                    cntA += func_L01_003B5EF0(cur, 0);
                }
            } else if (func_L01_003B5F00(cur) != 0) {
                if (*(f32 *)(c + 96) >= 0.0f) {
                    r = func_L01_003B5F60(cur, 0);
                    cnt += 1;
                    sy += r;
                } else if (*(s32 *)(c + 100) >= 0) {
                    cntB += func_L01_003B5FC8(cur, 0);
                    cnt += 1;
                } else if (func_L01_003B5F30(cur, 0) == 0) {
                    return 0;
                }
            }
            cur = *(u8 **)(st + 88);
            if (cur == 0) {
                break;
            }
            st = *(u8 **)(cur + 104);
        }
        if (*(f32 *)(c + 88) >= 0.0f) {
            r = 0.0f;
            if (sz > 0.0f) {
                r = sx / sz;
            }
            if (r < *(f32 *)(c + 88)) {
                return 0;
            }
        } else if (*(s32 *)(c + 92) >= 0) {
            if (cntA < *(s32 *)(c + 92)) {
                return 0;
            }
        }
        if (*(f32 *)(c + 96) >= 0.0f) {
            if (cnt >= 2) {
                sy = sy / (f32)cnt;
            }
            if (sy < *(f32 *)(c + 96)) {
                return 0;
            }
        } else if (*(s32 *)(c + 100) >= 0) {
            if (cntB < *(s32 *)(c + 100)) {
                return 0;
            }
        }
    }
    if (*(s32 *)(c + 104) != 0) {
        if (func_L01_00327330() != 0) {
            return 0;
        }
    }
    idx = *(s32 *)(c + 60);
    if (idx != -1) {
        if (func_L01_00456500(D_001A4C60, idx) == 0) {
            return 0;
        }
    }
    idx = *(s32 *)(c + 72);
    if (idx != -1) {
        if (func_L01_00456250(D_L01_001E001C + (idx << 8)) == 0) {
            return 0;
        }
    }
    idx = *(s32 *)(c + 76);
    if (idx != -1) {
        p = D_L01_0021DE20[idx];
        while ((idx & 0xFF) != 255 && idx <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[idx])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            if (func_L01_00456250(n) == 0) {
                return 0;
            }
            p++;
            idx = *(s32 *)(c + 76);
        }
    }
    idx = *(s32 *)(c + 80);
    if (idx != -1) {
        n = D_L01_001E001C + (idx << 8);
        if (n != 0) {
            s32 b = n[32];
            if (b != 0xFE && b != 0xFD) {
                return 0;
            }
        }
    }
    idx = *(s32 *)(c + 84);
    if (idx != -1) {
        if (func_L01_00445AD0(idx, -1, 0) != 0) {
            return 0;
        }
    }
    return 1;
}
