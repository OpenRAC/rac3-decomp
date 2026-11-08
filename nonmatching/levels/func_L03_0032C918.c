/* near miss (level 3, Starship Phoenix): 132 differences, register allocation in the 3-iteration list-walk loop (the 0x60 frame, callees, epilogue, the four short loops and the first ~45 instructions match): retail spills q (p+0xB4) to 0($sp) before the sw to the $gp slot, keeps the A8 base in $s7 with a per-iteration move $a3,$fp and daddu reloads, the C spills the A8 base and keeps q in $fp; an extra copy variable gets CSE'd (147) */
#include "common.h"

/* localdecomp:start func_L03_0032C918 */
typedef struct S_0032C918 {
    char pad0[0x20];
    u8 f20;
    char pad1[0x68 - 0x21];
    struct S_0032C918b *p;
} S_0032C918;
typedef struct S_0032C918b {
    s32 pad0[0xC];
    s32 a30[8];        /* 0x30: pairs a30[2*i], a30[2*i+1] */
    s32 a50[4];
    char pad1[0xA8 - 0x60];
    s32 aA8[3];
    s32 pB4[1];
    char pad2[0xC4 - 0xB8];
    s32 fC4;
    char pad3[0xDC - 0xC8];
    s32 fDC;
    s32 aE0[2];
    s32 fE8;
    s32 fEC;
    char pad4[0xF5 - 0xF0];
    u8 fF5;
    char pad5[0xFE - 0xF6];
    u8 fFE;
    char pad6[0x104 - 0xFF];
    s32 f104;
} S_0032C918b;
extern u8 D_001BBB30;
__asm__(".extern D_001BBB30, 16");
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;
__asm__(".extern D_L03_001DF9D8, 16");
extern s32 D_001DF9D8_sda;
__asm__(".extern D_001DF9D8_sda, 4");
extern void *D_001DD104_sda;
__asm__(".extern D_001DD104_sda, 4");
extern s32 D_001DCF18_sda[1];
__asm__(".extern D_001DCF18_sda, 4");
extern int D_L03_0021C620[];
extern u8 D_001426E0[];
extern s32 D_00142848;
__asm__(".extern D_00142848, 16");
extern char D_001A4C60[];
void func_L03_0032F520();
void *func_L03_0032F6A8();
void func_L03_0032EC38();
void func_L03_0032CED0();
s32 func_L01_0044C078();
void func_L01_004450F0();

void func_L03_0032C918(S_0032C918 *a) {
    S_0032C918b *p;
    s32 *q;
    s32 *r;
    s32 i;
    if (a->f20 == 0) {
        p = a->p;
        if (D_001BBB30 == 0) {
            *(u16 *)(D_L03_001DF99C + (p->fDC << 8) + 0x34) |= 3;
        }
        D_001DD104_sda = a;
        q = p->pB4;
        r = p->aA8;
        func_L03_0032F520();
        for (i = 3; i >= 0; i--) p->a50[i] = -1;
        {
            s32 *x = &p->a30[0];
            s32 *y = &p->a30[1];
            for (i = 0; i < 4; i++) {
                *x = -1;
                *y = -1;
                x += 2;
                y += 2;
            }
        }
        p->f104 = -1;
        for (i = 1; i >= 0; i--) p->aE0[i] = 0;
        for (i = 0; i < 3; i++) {
            short *cur;
            q[i] = D_001DCF18_sda[i];
            cur = (short *)D_L03_0021C620[p->aA8[i]];
            if ((p->aA8[i] & 0xFF) != 0xFF && D_L03_001DF9D8 >= p->aA8[i] && cur != 0 &&
                (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[p->aA8[i]])) {
                do {
                    u8 *buf = D_L03_001DF99C + ((*(u16 *)cur & 0x7FFF) << 8);
                    if (buf == 0) break;
                    cur++;
                    *(void **)func_L03_0032F6A8(buf) = a;
                } while ((r[i] & 0xFF) != 0xFF && D_001DF9D8_sda >= r[i] && cur != 0 &&
                         (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[r[i]]));
            }
        }
        if (D_001426E0[0xE3] != 0) {
            s32 t = D_001426E0[0xE3];
            D_001426E0[0xE3] = 0;
            D_00142848 = t - 1;
        }
        p->fE8 = 0;
        p->fF5 = 0;
        p->fFE = 0;
        p->fEC = -1;
        func_L03_0032EC38(a);
        if (func_L01_0044C078(D_001A4C60, p->fC4) != 0) {
            func_L03_0032CED0(a);
        } else {
            func_L01_004450F0(a, 1, -1);
        }
    }
}
/* localdecomp:end func_L03_0032C918 */
