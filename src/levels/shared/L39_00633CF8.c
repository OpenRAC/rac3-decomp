#include "common.h"

/* localdecomp:start func_L39_00633CF8 */
#include "vu0.h"
typedef union Buf_00633CF8 {
    u8 b[8];
    u32 w[2];
} Buf_00633CF8;

extern u8 D_L39_004997E0[];
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern f32 func_L39_00633C78(void *, void *, s32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L39_00634E18(u8 *, f32, f32);
extern void func_L39_00634E28(u8 *, f32, f32);
extern void func_L39_00634E38(u8 *, f32, f32);
extern void func_L39_00634E48(u8 *, f32, f32);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_00633CF8(u8 *q) {
    Buf_00633CF8 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

/* reads an obfuscated 8-bit flag stored as an index byte at q */
static __inline__ s32 get_flag_00633CF8(u8 *q) {
    Buf_00633CF8 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    u32 a;
    u32 c;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 24; i += 3) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    c = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (c >> 16) / (((c ^ (c >> 16)) << 16) + 1);
    return buf.b[4];
}

void func_L39_00633CF8(u8 *o) {
    f32 v;
    f32 d1;
    f32 g1;
    f32 d3;
    f32 f;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 e1;
    f32 e2;
    f32 e3;
    s32 a;
    s32 c;

    if (*(s16 *)(o + 0x3E4) != 0 ||
        (*(s32 *)(o + 0x1310) == 1 && func_L01_004606E8(0x28, 2, 0, *(s32 *)(o + 0x2534)) != 0 &&
        func_L39_006212E8(o) != 0xA)) {
        if ((get_state_00633CF8(o + 0x19E4) ^ 0x10) != 0 && *(f32 *)(o + 0x2468) > 0.15f) {
            if ((get_state_00633CF8(o + 0x19E4) ^ 0xB) != 0 && o[0x3E6] == 0) {
                f32 g;
                *(f32 *)(o + 0x804) = 0.053280003f;
                *(f32 *)(o + 0x808) = 0.38880002f;
                *(f32 *)(o + 0x8B4) = 0.036000002f;
                *(f32 *)(o + 0x8B8) = 0.38880002f;
                if (o[0x1A06] != 0) {
                    g = func_L39_00633C78(o, o + 0x3D0, 0);
                } else {
                    g = func_0038DB00(*(f32 *)(o + 0x3E8), *(f32 *)(o + 0xB8));
                }
                *(f32 *)(o + 0x7C8) = g;
                *(f32 *)(o + 0x878) = -g;
                return;
            }
        }
    }
    if ((get_state_00633CF8(o + 0x19E4) ^ 2) == 0) {
        func_L39_00634E18(o, 0.04f, 0.2f);
        func_L39_00634E28(o, 0.04f, 0.2f);
        func_L39_00634E38(o, 0.04f, 0.2f);
        func_L39_00634E48(o, 0.02f, 0.2f);
        if ((get_state_00633CF8(o + 0x19E5) ^ 1) == 0) {
            f = *(f32 *)(o + 0xFD4) * 17.0f;
            if (f > 1.4f) {
                f = 1.4f;
            } else if (f < -1.4f) {
                f = -1.4f;
            }
            if (fabs_asm(*(f32 *)(o + 0xFD8)) * 3.0f < f) {
                f = fabs_asm(*(f32 *)(o + 0xFD8)) * 3.0f;
            } else if (f < -fabs_asm(*(f32 *)(o + 0xFD8)) * 3.0f) {
                f = -fabs_asm(*(f32 *)(o + 0xFD8)) * 3.0f;
            }
            if (o[0x142F] != 0) {
                if (f > 1.1f) {
                    f = 1.1f;
                } else if (f < -1.1f) {
                    f = -1.1f;
                }
                func_L39_00634E28(o, 0.0792f, 0.43200004f);
                func_L39_00634E48(o, 0.10080001f, 0.43200004f);
                if (fabs_asm(*(f32 *)(o + 0xFD8)) < f) {
                    f = fabs_asm(*(f32 *)(o + 0xFD8));
                } else if (f < -fabs_asm(*(f32 *)(o + 0xFD8))) {
                    f = -fabs_asm(*(f32 *)(o + 0xFD8));
                }
            }
            d1 = -f * 0.11f;
            *(f32 *)(o + 0x7C0) = d1;
            if (o[0x142F] != 0) {
                *(f32 *)(o + 0x7C0) = d1 * 0.25f;
            }
            e1 = *(f32 *)(o + 0x1A4) / 0.11400001f;
            if (e1 > 1.0f) {
                e1 = 1.0f;
            }
            if (e1 < 0.0f) {
                e1 = 0.0f;
            }
            *(f32 *)(o + 0x7C0) = *(f32 *)(o + 0x7C0) * e1;
            *(f32 *)(o + 0x878) = f * 0.31f;
            if (o[0x142F] != 0) {
                *(f32 *)(o + 0x878) = 0.0f;
            }
            g1 = f * -0.15f;
            *(f32 *)(o + 0x9D4) = fabs_asm(f) * -0.15f;
            *(f32 *)(o + 0x9D8) = f * 0.7f;
            *(f32 *)(o + 0x9D0) = fabs_asm(f) * 0.16f;
            *(f32 *)(o + 0x920) = g1;
        } else {
            v = *(f32 *)(o + 0xFD8);
            if (*(f32 *)(o + 0x2468) < 0.8f && *(s32 *)(o + 0x2F0) < 0x21) {
                func_003C4138(&v, 0.0f, (f32)(0x21 - *(s32 *)(o + 0x2F0)) * 0.08726646f);
            }
            f2 = v * 0.5f;
            if (f2 > 0.8f) {
                f2 = 0.8f;
            } else if (f2 < -0.8f) {
                f2 = -0.8f;
            }
            f2 = f2 * fabs_asm(f2) * 1.25f;
            *(f32 *)(o + 0x878) = f2;
            *(f32 *)(o + 0x9D8) = f2;
            *(f32 *)(o + 0x9D4) = fabs_asm(f2) * 0.25f;
        }
    } else {
        if ((get_state_00633CF8(o + 0x19E4) ^ 8) == 0) {
            func_L39_00634E18(o, 0.008f, 0.08f);
            func_L39_00634E28(o, 0.015f, 0.08f);
            func_L39_00634E38(o, 0.015f, 0.08f);
            func_L39_00634E48(o, 0.008f, 0.1f);
            f3 = *(f32 *)(o + 0xFD8) * 1.6f;
            if (f3 > 1.25f) {
                f3 = 1.25f;
            } else if (f3 < -1.25f) {
                f3 = -1.25f;
            }
            *(f32 *)(o + 0x7C0) = -f3 * 0.52f;
            if (*(f32 *)(o + 0x7C0) > 0.28f) {
                *(f32 *)(o + 0x7C0) = 0.28f;
            } else if (*(f32 *)(o + 0x7C0) < -0.28f) {
                *(f32 *)(o + 0x7C0) = -0.28f;
            }
            *(f32 *)(o + 0x9D8) = f3 * 1.2f;
            *(f32 *)(o + 0x878) = f3 * 0.58f;
            *(f32 *)(o + 0x920) = f3 * -0.28f;
            if (*(f32 *)(o + 0x9D8) > 0.6f) {
                *(f32 *)(o + 0x9D8) = 0.6f;
            } else if (*(f32 *)(o + 0x9D8) < -0.6f) {
                *(f32 *)(o + 0x9D8) = -0.6f;
            }
            *(f32 *)(o + 0x9D4) = fabs_asm(f3) * 0.2f;
            if (*(f32 *)(o + 0x9D4) > 0.2f) {
                *(f32 *)(o + 0x9D4) = 0.2f;
            } else if (*(f32 *)(o + 0x9D4) < -0.2f) {
                *(f32 *)(o + 0x9D4) = -0.2f;
            }
            *(f32 *)(o + 0x9D0) = fabs_asm(f3) * 0.16f;
        } else {
            if ((get_state_00633CF8(o + 0x19E4) ^ 0x84) == 0) {
                func_L39_00634E18(o, 0.017f, 0.33f);
                func_L39_00634E28(o, 0.015f, 0.25f);
                func_L39_00634E38(o, 0.015f, 0.25f);
                func_L39_00634E48(o, 0.008f, 0.25f);
                f4 = *(f32 *)(o + 0xFD8) * 0.7f;
                if (f4 > 1.2f) {
                    f4 = 1.2f;
                } else if (f4 < -1.2f) {
                    f4 = -1.2f;
                }
                *(f32 *)(o + 0x7C0) = -f4 * 0.52f;
                if (*(f32 *)(o + 0x7C0) > 0.28f) {
                    *(f32 *)(o + 0x7C0) = 0.28f;
                } else if (*(f32 *)(o + 0x7C0) < -0.28f) {
                    *(f32 *)(o + 0x7C0) = -0.28f;
                }
                *(f32 *)(o + 0x9D8) = f4 * 1.2f;
                *(f32 *)(o + 0x878) = f4 * 0.58f;
                *(f32 *)(o + 0x920) = f4 * -0.28f;
                if (*(f32 *)(o + 0x9D8) > 0.6f) {
                    *(f32 *)(o + 0x9D8) = 0.6f;
                } else if (*(f32 *)(o + 0x9D8) < -0.6f) {
                    *(f32 *)(o + 0x9D8) = -0.6f;
                }
                *(f32 *)(o + 0x9D0) = fabs_asm(f4) * 0.16f;
                *(f32 *)(o + 0x7C4) = func_0038DAB8(*(f32 *)(o + 0x7C4), -0.12217305f);
                if (*(f32 *)(o + 0x2468) > 0.1f) {
                    e2 = func_0038DB00(*(f32 *)(o + 0xFD0), *(f32 *)(o + 0xB8));
                    d3 = *(f32 *)(o + 0x2468) * 0.61086524f;
                    *(f32 *)(o + 0x7C0) = -func_0038D0B0(e2) * d3;
                    *(f32 *)(o + 0x7C4) = func_0038DAB8(*(f32 *)(o + 0x7C4), func_0038D098(e2) * d3);
                    if (*(f32 *)(o + 0x7C0) > 0.47123888f) {
                        *(f32 *)(o + 0x7C0) = 0.47123888f;
                    } else if (*(f32 *)(o + 0x7C0) < -0.47123888f) {
                        *(f32 *)(o + 0x7C0) = -0.47123888f;
                    }
                    if (*(f32 *)(o + 0x7C4) > 0.47123888f) {
                        *(f32 *)(o + 0x7C4) = 0.47123888f;
                    } else if (*(f32 *)(o + 0x7C4) < -0.47123888f) {
                        *(f32 *)(o + 0x7C4) = -0.47123888f;
                    }
                }
                *(f32 *)(o + 0xD84) = 0.025f;
                *(f32 *)(o + 0xD88) = 0.37f;
                *(f32 *)(o + 0xE34) = 0.025f;
                *(f32 *)(o + 0xE38) = 0.37f;
                a = 1;
                c = 1;
                if ((get_flag_00633CF8(o + 0x1A17) ^ 1) == 0) {
                    c = 0;
                } else if ((get_flag_00633CF8(o + 0x1A17) ^ 2) == 0) {
                    a = 0;
                    c = 0;
                }
                e3 = func_0038DAB8(*(f32 *)(o + 0x148) * 5.0f, 0.29670596f);
                if (a != 0) {
                    *(f32 *)(o + 0xD40) = -e3;
                    *(f32 *)(o + 0xD48) = -0.34906584f;
                    if (*(f32 *)(o + 0xD40) > 0.61086524f) {
                        *(f32 *)(o + 0xD40) = 0.61086524f;
                    } else if (*(f32 *)(o + 0xD40) < -0.61086524f) {
                        *(f32 *)(o + 0xD40) = -0.61086524f;
                    }
                }
                if (c != 0) {
                    *(f32 *)(o + 0xDF0) = e3;
                    *(f32 *)(o + 0xDF8) = 0.34906584f;
                    if (*(f32 *)(o + 0xDF0) > 0.61086524f) {
                        *(f32 *)(o + 0xDF0) = 0.61086524f;
                    } else if (*(f32 *)(o + 0xDF0) < -0.61086524f) {
                        *(f32 *)(o + 0xDF0) = -0.61086524f;
                    }
                }
                *(f32 *)(o + 0x9D4) = -*(f32 *)(o + 0x148) * 7.7f;
                if (*(f32 *)(o + 0x9D4) > 0.6457718f) {
                    *(f32 *)(o + 0x9D4) = 0.6457718f;
                } else if (*(f32 *)(o + 0x9D4) < -0.6457718f) {
                    *(f32 *)(o + 0x9D4) = -0.6457718f;
                }
            } else {
                if ((get_state_00633CF8(o + 0x19E6) ^ 2) == 0 || (get_state_00633CF8(o + 0x19E6) ^ 4) == 0) {
                    func_L39_00634E18(o, 0.04f, 0.2f);
                    func_L39_00634E28(o, 0.04f, 0.2f);
                    func_L39_00634E38(o, 0.04f, 0.2f);
                    func_L39_00634E48(o, 0.02f, 0.2f);
                    f5 = *(f32 *)(o + 0xFD8);
                    if (f5 > 1.4f) {
                        f5 = 1.4f;
                    } else if (f5 < -1.4f) {
                        f5 = -1.4f;
                    }
                    *(f32 *)(o + 0x878) = f5 * 0.29f;
                    *(f32 *)(o + 0x920) = f5 * -0.27f;
                    *(f32 *)(o + 0x9D8) = f5 * 0.87f;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_00633CF8 */
