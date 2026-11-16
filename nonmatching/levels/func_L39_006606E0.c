/* NTSC-U draft (Claude wave K): C of func_L39_0065DE08, the NTSC-U twin of func_L39_006606E0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 405 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_0065DE08", whose code is not the PAL one).
 * Worker's note: 405 raw diff lines of 738 (shift-sensitive); opcode-only diff (w01/opdiff.py, register/imm blind) = 14 small regions, mine 736 words vs retail 738: the whole control flow is right (draft near/func_L39_0065DE08.low.c). Built from the protected-value read as a ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_006606E0 (src/levels/shared/L39_0065D0A0.c) */
/* localdecomp:start func_L39_0065DE08 */
typedef struct {
    u8 p0[0xB];
    s8 b0B;
    u8 pC[0x21 - 0xC];
    s8 b21;
    u8 p22[0x28 - 0x22];
    f32 f28;
    u8 p2C[0x80 - 0x2C];
} E_0065DE08;
typedef union Buf_0065DE08 {
    u8 b[8];
    u32 w[2];
} Buf_0065DE08;
extern u8 D_L39_004998A0[];
extern E_0065DE08 D_L39_0049C950[];
extern u8 D_L39_0049AB80[];
extern u32 D_L39_0024BAC8;
__asm__(".extern D_L39_0024BAC8, 16");
extern u32 D_L39_002412AC;
__asm__(".extern D_L39_002412AC, 16");
extern s32 func_L39_005C0F08(s32);
extern s32 func_L39_0061E558(u8 *, s32);
extern s32 func_L39_0061E688(u8 *, s32, s32);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L39_00670488(void *, s32, s32, s32, s32, s32);

static __inline__ E_0065DE08 *ent_0065DE08(u8 *g, s32 val) {
    return &D_L39_0049C950[func_L39_00646268(g, val) ? D_L39_0049C950[val].b21 : val];
}

void func_L39_0065DE08(u8 *g, s32 idx) {
    Buf_0065DE08 buf;
    s32 val;
    s32 f1;
    s32 f2;
    u8 *slot;
    u32 key;
    s32 n;
    s32 k;
    s32 i;
    u8 *d;

    val = *(s32 *)(g + idx * 0x50 + 0x478);
    if (idx != 0) {
        return;
    }
    if (val == 10) {
        return;
    }
    if (*(s16 *)(g + 0x320) != 0) {
        return;
    }
    if (*(s32 *)(g + idx * 0x50 + 0x470) < 5) {
        return;
    }
    f2 = 0;
    f1 = 0;
    if ((*(unsigned long *)(g + 0x1A08) & 0x00FFFFFF00000000UL) != 0 || ((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 0x14) == 0 ||
        ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 0x66) == 0 || ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 0x64) == 0 || *(s16 *)(g + 0x2488) != 0) {
        f1 = 1;
    }
    if (f1 == 0 && (func_L39_005C0F08(*(s32 *)(g + 0x2534)) & *(s32 *)(g + idx * 0x50 + 0x460)) != 0) {
        f2 = 1;
        if (func_L39_0061E558(g, val) != 0) {
            if (*(u8 *)(g + idx * 0x50 + 0x458) == 0) {
                *(u8 *)(g + idx * 0x50 + 0x458) = f2;
                func_L39_00670488(g + 0x1A40, 1, -1, -1, 0, 0);
            }
        } else {
            if (*(u8 *)(g + idx * 0x50 + 0x458) == f2) {
                *(u8 *)(g + idx * 0x50 + 0x458) = 0;
                func_L39_00670488(g + 0x1A40, 2, -1, -1, 0, 0);
            }
        }
    } else if (*(u8 *)(g + idx * 0x50 + 0x458) == 1) {
        *(u8 *)(g + idx * 0x50 + 0x458) = 0;
        func_L39_00670488(g + 0x1A40, 2, -1, -1, 0, 0);
    }
    if (f1 != 0) {
        return;
    }
    if (((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 0x1D) == 0 && *(s32 *)(g + 0x2F0) < 0x14) {
        return;
    }
    if (*(s32 *)(g + idx * 0x50 + 0x470) < 0x17) {
        return;
    }
    if (*(f32 *)(g + 0x328) != 0.0f) {
        return;
    }
    if (((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 0xE) == 0 && *(f32 *)(g + 0x628) > 25.0f && *(f32 *)(g + 0x628) < 35.0f) {
        return;
    }
    if (((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 0xB) == 0 && *(s32 *)(g + 0x14E4) == 3 && *(f32 *)(g + 0x628) > 10.0f &&
        *(f32 *)(g + 0x628) < 20.0f) {
        return;
    }
    if (f2 == 0) {
        return;
    }
    if (ent_0065DE08(g, val)->b0B != 0 ||
        (((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) == 0 || ((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 1) == 0 || ((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 0xC) == 0 || ((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 5) == 0 ||
          ((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 0xF) == 0 || (((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 4) == 0 && g[0x153C] != 0)) && g[0x1A07] == 0) ||
        (((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    })) ^ 0x22) == 0 && *(f32 *)(g + 0x628) > 20.0f)) {
        if ((ent_0065DE08(g, val)->b0B == 0 &&
             func_L39_0061E558(g, -1) != 0) ||
            func_L39_0061E688(g, -1, 1) != 0) {
            func_L39_00670488(g + 0x1A40, 8, -1, -1, 0, 0);
            if (ent_0065DE08(g, val)->b0B == 0) {
                g[0x469] = 0x14;
            }
        } else {
            func_L39_00670488(g + 0x1A40, 4, -1, -1, 0, 0);
        }
        *(f32 *)(g + 0x328) =
            1.0f / ent_0065DE08(g, val)->f28;
        slot = g + val + 0x1A42;
        if (*slot == 0) {
            *slot = ++D_L39_0049AB80[0];
        } else {
            n = *slot;
            *slot = D_L39_0049AB80[1];
            D_L39_0049AB80[1] = n;
        }
        key = *(u32 *)(D_L39_0049AB80 + (((u32)slot * D_L39_0024BAC8) % 0x182) * 4);
        buf.w[1] = D_L39_002412AC ^ key;
        buf.w[0] = (u32)slot ^ key;
        n = *slot;
        k = ((u32)slot - n) & 7;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            D_L39_0049AB80[(n + 1) + ((k + i) & 7) * 193] = *d++;
        }
    }
}
/* localdecomp:end func_L39_0065DE08 */
