#include "common.h"

/* localdecomp:start func_L39_0061C520 */
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern s32 D_L39_00241118;
extern s32 D_L39_00241128;
extern u8 D_L39_004997E0[];
typedef struct { u8 pad[0xA4]; u8 flags[0x100]; } Tab_0061C520;
extern Tab_0061C520 D_001A5810;
typedef struct { u8 pad[0x4500]; } E_0061C520;
extern E_0061C520 D_L39_002FB000[];
extern s32 func_L39_00639D90(void *);
extern void func_L39_00646660(void *, s32);
extern void func_L39_0066ADA0(void);

static __inline__ s16 dec16_0061C520(u8 *q) {
    u32 buf[2];
    u32 y;
    u8 *b;
    s32 m, k, j;
    if (*q == 0) {
        return 0;
    }
    m = *q + 1;
    k = ((s32)q - *q) & 7;
    b = (u8 *)buf;
    for (j = 0; j < 24; j += 3) {
        *b++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
    }
    buf[0] ^= (u32)q;
    y = buf[1] ^ buf[0];
    buf[1] = (y >> 16) / (((y ^ (y >> 16)) << 16) + 1);
    return *(u16 *)&buf[1];
}

static __inline__ u32 dec32_0061C520(u8 *q) {
    u32 buf[2];
    u8 *b;
    s32 m, k, j;
    if (*q == 0) {
        return 0;
    }
    m = *q + 1;
    k = ((s32)q - *q) & 7;
    b = (u8 *)buf;
    for (j = 0; j < 40; j += 5) {
        *b++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
    }
    buf[0] ^= (u32)q;
    buf[1] ^= buf[0];
    return buf[1];
}

static __inline__ s32 eq32_0061C520(u8 *q, u32 v) {
    return dec32_0061C520(q) == v;
}

void func_L39_0061C520(void) {
    s32 i;
    for (i = 0; i < *D_L39_00241120; i++) {
        u8 *p = (u8 *)&D_L39_002FB000[i];
        if (p != 0) {
            s32 jj;
            u8 *e;
            s32 s22, s17, t11;
            s32 s21, c, s18;

            s22 = 0;
            if (dec16_0061C520(p + 0x314) != 0
                || (p[0x1A0A] != 0 && (eq32_0061C520(p + 0x19E4, 1) || eq32_0061C520(p + 0x19E4, 0x1D)))) {
                s22 = 1;
            }

            s21 = 0;
            if (D_001A5810.flags[*(s32 *)(p + 0x2544)] == 1) {
                c = eq32_0061C520(p + 0x19E4, 1) || eq32_0061C520(p + 0x19E4, 0x1D) || p[0x24FE] != 0 || p[0x2500] != 0;
                if (c == 1) {
                    s21 = 1;
                }
            }

            t11 = func_L39_00639D90(p) == 2;
            s18 = 0;
            if (eq32_0061C520(p + 0x19E6, 0x14) || eq32_0061C520(p + 0x19E4, 0x7A)) {
                if (p[0x1A0A] != 0) {
                    s18 = 1;
                }
            }

            s17 = 0;
            if ((t11 || s22 || s21 || s18) && i == D_L39_00241118) {
                s17 = 1;
                *(u16 *)(*(u8 **)(p + 0x424) + 0x34) |= 1;
                e = p;
                for (jj = 0; jj < 6; jj++) {
                    if (jj != 0) {
                        if (*(u8 **)(e + 0x450) != 0) {
                            *(u16 *)(*(u8 **)(e + 0x450) + 0x34) |= 1;
                        }
                        if (*(u8 **)(e + 0x454) != 0) {
                            *(u16 *)(*(u8 **)(e + 0x454) + 0x34) |= 1;
                        }
                    }
                    e += 0x50;
                }
                if (*(s32 *)(p + 0x478) == 10 && *(u8 **)(p + 0x450) != 0 && D_L39_00241128 == 0
                    && *(*(u8 **)(p + 0x450) + 0x20) != 0) {
                    *(u16 *)(*(u8 **)(p + 0x450) + 0x34) &= 0xFFBE;
                }
                func_L39_00646660(p, 1);
            }
            if (s17 == 0) {
                if (!eq32_0061C520(p + 0x19E4, 0x31) && s18 == 0) {
                    *(u16 *)(*(u8 **)(p + 0x424) + 0x34) &= 0xFFFE;
                    for (jj = 0; jj < 6; jj++) {
                        u8 *sl = p + jj * 0x50;
                        if (*(u8 **)(sl + 0x450) != 0) {
                            *(u16 *)(*(u8 **)(sl + 0x450) + 0x34) &= 0xFFFE;
                        }
                        if (*(u8 **)(sl + 0x454) != 0) {
                            *(u16 *)(*(u8 **)(sl + 0x454) + 0x34) &= 0xFFFE;
                        }
                    }
                    func_L39_00646660(p, 0);
                }
                if (*(s32 *)(p + 0x251C) != 0 && *(s32 *)(p + 0x478) == 10) {
                    if (*(u8 **)(p + 0x450) != 0) {
                        *(u16 *)(*(u8 **)(p + 0x450) + 0x34) |= 1;
                    }
                    if (*(u8 **)(p + 0x454) != 0) {
                        *(u16 *)(*(u8 **)(p + 0x454) + 0x34) |= 1;
                    }
                }
                if ((p[0x1A10] != 0 && *(s32 *)(p + 0x478) == 10) || p[0x1A0B] != 0) {
                    if (*(u8 **)(p + 0x450) != 0) {
                        *(u16 *)(*(u8 **)(p + 0x450) + 0x34) |= 0x41;
                    }
                }
            }
        }
    }
    func_L39_0066ADA0();
}
/* localdecomp:end func_L39_0061C520 */
