/* Wave 13 (r21, 2026-11-28) replaces the earlier draft of this function (NTSC-U draft of `func_L40_00412B88` (Claude wave K)). */
/* PAL near miss (wave 13 r21, 2026-11-28): 230 differences (build/codex/wave10/p10/check.py, level 40, the file's flags; positional count, most of it a one-instruction shift). First PAL draft: the NTSC-U draft of func_L40_00412B88 rewritten with PAL names, data and constants (0x2DE < 0xC, 0x15E, 100), one hinted name each for D_L40_00241640 and D_L40_00241120 (Ps2EeAs gives the lui form and the  form in delay slots, as retail), own loaded before the counter increment (retail's delay slot). The obfuscated-value decode is a static inline with its own 8-byte buffer and the moved position is a block-local, which gives retail's 0x70 frame with both at sp+0 and retail's decode code; the flag test is an inline returning u8 (retail's andi 0xff). Left: (1) self/own allocation swap (self s3, own s4; retail the reverse): global-alloc priority, self 16 weighted refs over 305 insns vs own 14 over 257; wrapping the code after the flag test in do { } while (0) flips it (222 diff) but swaps fp/s7 and moves a block, so it is not kept; (2) the flag inline keeps its value in v0 and is one instruction shorter than retail, whose u8 result lives in t3 across the decode (set to 0 before the first test); (3) the D_L40_00241640/D_L40_0035746C load order in the w1C block (register choice a1/a2/v1). */
#include "common.h"

/* localdecomp:start func_L40_004133A8 */
typedef int Q_004133A8 __attribute__((mode(TI)));

typedef union Buf_004133A8 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[4];
    Q_004133A8 q;
} Buf_004133A8;

typedef struct Rec_004133A8 {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 padC[0x10];
} Rec_004133A8;

typedef struct Sub_004133A8 {
    u8 pad0[0x1C];
    s32 w1C;
    u8 pad20[0x20];
    s32 w40;
} Sub_004133A8;

typedef struct Ent_004133A8 {
    u8 pad0[0x68];
    Sub_004133A8 *p68;
} Ent_004133A8;

typedef struct Own_004133A8 {
    s32 w0;
    u8 pad4[0x18];
    s32 w1C;
    u8 pad20[0x20];
    s16 h40[4];
    s32 w48[2];
    s32 w50[4];
    s32 w60[4];
} Own_004133A8;

extern u8 *D_L40_00241640;
extern s32 *D_L40_00241120;
extern s32 *D_L40_0035746C;
extern Rec_004133A8 D_L40_003AA6E0[];
extern u8 D_L40_003BFE20[];
__asm__(".extern D_L40_00241640, 16");
__asm__(".extern D_L40_00241120, 16");
__asm__(".extern D_L40_0024845C, 16");
__asm__(".extern D_L40_0035746C, 16");

static __inline__ u32 Decode_004133A8(u8 *q) {
    Buf_004133A8 buf;
    s32 n, k, m, i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

static __inline__ u8 Check_004133A8(u8 *p) {
    if (*(u8 **)(p + 0x2530) != 0 && (*(u8 **)(p + 0x2530))[0x27B] != 0 && (Decode_004133A8(p + 0x19E4) ^ 0x31) == 0) {
        return 1;
    }
    return 0;
}

void func_L40_004133A8(u8 *self) {
    extern void func_003C2880(void *);
    extern void func_L39_0066C828(void *, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern u8 *func_L39_0061BF38(s32);
    extern void func_0038CB00(void *);
    extern s32 func_L39_006626C8(void *, s32);
    extern void func_L40_00413200(void *, s32, void *, s32, f32);
    extern s32 func_L01_00436620(s32);
    extern void func_L01_00451F60(s32, s32);
    Own_004133A8 *s3;
    u8 *s0;
    s32 fp;
    s32 s7;
    s32 s5;
    s32 *s2;
    s16 *s1;
    s32 a1;
    u8 *ent;
    s32 j;

    s3 = *(Own_004133A8 **)(self + 0x68);
    if (*(u16 *)(self + 0x96) < 0x7FFD) {
        *(u16 *)(self + 0x96) = *(u16 *)(self + 0x96) + 1;
    }
    switch (self[0x20]) {
    case 0:
        if (*(s8 *)(D_L40_00241640 + 0x195) == 0) {
            func_003C2880(self);
            return;
        }
        func_L39_0066C828(self, -1, 1);
        for (j = 3; j >= 0; j--) {
            s3->h40[j] = 0;
        }
        func_L01_004450F0(self, 1, -1);
        return;
    case 1:
        break;
    default:
        return;
    }
    if (s3->w0 == -1) {
        return;
    }
    fp = -1;
    ent = 0;
    s7 = 1;
    if (s3->w1C >= 0) {
        Sub_004133A8 *sb;

        ent = D_L40_0024845C + s3->w1C * 256;
        sb = ((Ent_004133A8 *)ent)->p68;
        s7 = sb->w40;
        fp = *(s32 *)((u8 *)D_L40_0035746C + sb->w1C * 4 + 0x88);
        if (*(s32 *)(D_L40_00241640 + 0x180) == 2) {
            s7 = 1;
        } else if (*(s32 *)(D_L40_00241640 + 0x180) == 1) {
            s7 = 0;
        }
    }
    s5 = 0;
    if (*D_L40_00241120 > 0) {
        do {
            s0 = func_L39_0061BF38(s5);
            func_0038CB00((u8 *)s3 + 0x40 + s0[0x24C9] * 2);
            if (s0 != 0) {
                s3->w50[s0[0x24C9]] = 0;
                if (*(s32 *)(s0 + 0x2CC) == (s32)self) {
                    if ((Decode_004133A8(s0 + 0x19E6) ^ 0x14) != 0) {
                        if (Check_004133A8(s0)) {
                            goto next;
                        }
                        if (*(s16 *)(s0 + 0x2DE) < 0xC && D_L40_003AA6E0[*(s32 *)(s0 + 0x2544)].w0 != 5) {
                            a1 = *(s32 *)(s0 + 0x251C) != 0;
                            s3->w50[s0[0x24C9]] = (s32)s0;
                            if ((s7 != 0 || fp == *(s32 *)(s0 + 0x2548)) && a1 == 0) {
                                D_L40_003AA6E0[*(s32 *)(s0 + 0x2544)].w0 = 4;
                                D_L40_003AA6E0[*(s32 *)(s0 + 0x2544)].w8 = 10;
                                s2 = s3->w60;
                                if (ent != 0) {
                                    s3->w60[s0[0x24C9]] = 0xA40;
                                } else {
                                    s3->w60[s0[0x24C9]] = 0xA41;
                                }
                                if ((*(s32 *)(*(u8 **)(s0 + 0x2534) + 0x1A4) & 0x10) != 0) {
                                    if (func_L39_006626C8(self, *(s32 *)(s0 + 0x2544)) != 0) {
                                        return;
                                    }
                                    if (Decode_004133A8(s0 + 0x19E4) == 0x66) {
                                        return;
                                    }
                                    {
                                        Buf_004133A8 pos;

                                        pos.q = *(Q_004133A8 *)(self + 0x10);
                                        pos.f[2] = pos.f[2] + 0.2f;
                                        func_L40_00413200(self, *(s32 *)(s0 + 0x2544), &pos, ent != 0, *(f32 *)(*(u8 **)(s0 + 0x2524) + 0xF8));
                                    }
                                    return;
                                }
                            } else {
                                s2 = s3->w60;
                                s3->w60[s0[0x24C9]] = -1;
                                if (a1 != 0) {
                                    if (*(s32 *)(s0 + 0x2548) == fp) {
                                        s2[s0[0x24C9]] = 0x1701;
                                    } else if (*(s32 *)(D_L40_00241640 + 0x180) == 0) {
                                        s2[s0[0x24C9]] = 0xA3F;
                                    }
                                } else if (*(s32 *)(D_L40_00241640 + 0x180) == 0) {
                                    s2[s0[0x24C9]] = 0xA3F;
                                }
                            }
                            s1 = s3->h40;
                            a1 = func_L01_00436620(s0[0x24C9]);
                            if (a1 == 0) {
                                if (s1[s0[0x24C9]] == 0 && s2[s0[0x24C9]] != -1) {
                                    func_L01_00451F60(s2[s0[0x24C9]], -1);
                                    s1[s0[0x24C9]] = 0x15E;
                                    goto next;
                                }
                            }
                            if (a1 != 0) {
                                if (s1[s0[0x24C9]] < 100) {
                                    s1[s0[0x24C9]] = 100;
                                }
                            }
                        }
                    }
                }
            }
          next:
            s5 = s5 + 1;
        } while (s5 < *D_L40_00241120);
    }
}
/* localdecomp:end func_L40_004133A8 */
