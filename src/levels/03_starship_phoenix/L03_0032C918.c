#include "common.h"

typedef struct S_Foo_0032D228 {
    u8 pad0[0xF2];
    u16 f2;
    u8 f4;
    u8 pad1[0x108 - 0xF5];
    s32 f108;
} S_Foo_0032D228;

typedef struct S_0032D598 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D598;

typedef struct { u8 pad0[0x30]; u8 b30[0x40]; u8 b70[0x10]; } Ent_32CF78;
typedef struct { u8 pad0[0x68]; struct { u8 pad[0xD0]; s32 idx; } *p68; } Obj_32CF78;

/* declared by functions of L03_0032C3A8.c, which this file was cut from */
extern void *D_001DD104_sda;

/* localdecomp:start func_L03_0032C918 */
typedef struct S_0032C918 {
    char pad0[0x20];
    u8 f20;
    char pad1[0x68 - 0x21];
    struct S_0032C918b *p;
} S_0032C918;
typedef struct S_0032C918b {
    s32 pad0[0xC];
    struct { s32 a; s32 b; } a30[4];
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
extern u8 D_001BBB30[];
extern u8 *D_L03_001DF99C;
extern s32 D_L03_001DF9D8;
extern void *D_001DD104_sda;
__asm__(".extern D_001DD104_sda, 4");
extern s32 D_001DCF18_sda[1];
__asm__(".extern D_001DCF18_sda, 4");
extern int D_L03_0021C620[];
extern u8 D_001426E0[];
extern s32 D_00142848[];
extern char D_001A4C60[];
void func_L03_0032F520(void);
void *func_L03_0032F6A8(void *);
void func_L03_0032EC38(int);
void func_L03_0032CED0(void *);
s32 func_L01_0044C078(void *, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L03_0032C918(void *arg0) {
    S_0032C918 *a = arg0;
    S_0032C918b *p;
    s32 i, j, k, m;
    if (a->f20 == 0) {
        p = a->p;
        if (D_001BBB30[0] == 0) {
            *(u16 *)(D_L03_001DF99C + (p->fDC << 8) + 0x34) |= 3;
        }
        D_001DD104_sda = a;
        func_L03_0032F520();
        for (j = 0; j < 4; j++) p->a50[j] = -1;
        for (k = 0; k < 4; k++) {
            p->a30[k].a = -1;
            p->a30[k].b = -1;
        }
        p->f104 = -1;
        for (m = 0; m < 2; m++) p->aE0[m] = 0;
        for (i = 0; i < 3; i++) {
            short *cur;
            p->pB4[i] = D_001DCF18_sda[i];
            cur = (short *)D_L03_0021C620[p->aA8[i]];
            while ((p->aA8[i] & 0xFF) != 0xFF && D_L03_001DF9D8 >= p->aA8[i] && cur != 0 &&
                   (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[p->aA8[i]])) {
                u8 *buf = D_L03_001DF99C + ((*(u16 *)cur & 0x7FFF) << 8);
                if (buf == 0) break;
                cur++;
                *(void **)func_L03_0032F6A8(buf) = a;
            }
        }
        if (D_001426E0[0xE3] != 0) {
            s32 t = D_001426E0[0xE3];
            D_001426E0[0xE3] = 0;
            D_00142848[0] = t - 1;
        }
        p->fE8 = 0;
        p->fF5 = 0;
        p->fFE = 0;
        p->fEC = -1;
        func_L03_0032EC38((int)a);
        if (func_L01_0044C078(D_001A4C60, p->fC4) != 0) {
            func_L03_0032CED0(a);
        } else {
            func_L01_004450F0(a, 1, -1);
        }
    }
}
/* localdecomp:end func_L03_0032C918 */

/* localdecomp:start func_L03_0032CBD8 */
typedef struct S_0032CBD8 { u8 p0[0x1200]; s32 f1200; u8 p1[0x24]; s32 f1228; u8 p2[0x25CC-0x122C]; s32 f25CC; u8 p3[0x2824-0x25D0]; f32 f2824; u8 p4[0x28C9-0x2828]; u8 f28C9; } S_0032CBD8;
extern S_0032CBD8 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 D_L03_002AE4D0[];
extern s32 D_001D4C38_sda;
__asm__(".extern D_001D4C38_sda, 4");
extern s32 D_L03_001D7C20;
__asm__(".extern D_L03_001D7C20, 16");
extern s32 D_L03_001DFA98;
__asm__(".extern D_L03_001DFA98, 16");
void func_L03_0032CE38(void *a);
s32 func_L01_004AAC98(s32 a, s32 b, void *c, s32 d);
void func_L03_00330380(u8 *a);
s32 func_0038CAD0(void *a);
void func_L03_0032D228(u8 *a);
void func_L01_00452560(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_L01_0044CD60(s32 a);
s32 func_L03_0032E0D8(void *a, s32 b);
void func_L01_00404808(void *a, void *b);
void func_L03_003307D0(void *a);
s32 func_L03_0032F660(void *a);
void func_L01_003F1760(void);

void func_L03_0032CBD8(u8 *arg0) {
    u8 *s3 = *(u8 **)(arg0 + 0x68);
    s32 v, q, r;
    func_L03_0032CE38(arg0);
    if ((u8)(arg0[0x20] - 5) < 4) {
        v = *(s32 *)(s3 + 0xEC);
        if (v != -1) {
            q = v / 50;
            r = v % 50;
            if (r == 0) {
                if (q == 5) func_L01_004AAC98(2, 0, arg0, 0x1936);
                else if (q == 4) func_L01_004AAC98(3, 0, arg0, 0x1936);
                else if (q == 3) func_L01_004AAC98(4, 0, arg0, 0x1936);
                else if (q == 2) func_L01_004AAC98(5, 0, arg0, 0x1936);
                else if (q == 1) func_L01_004AAC98(6, 0, arg0, 0x1936);
                func_L03_00330380(arg0);
            }
            if (func_0038CAD0(s3 + 0xEC)) {
                *(s32 *)(s3 + 0x104) = func_L01_004AAC98(6, 0, arg0, 0x1936);
                *(s32 *)(s3 + 0xEC) = 0x11;
                func_L03_0032D228(arg0);
            }
        }
    }
    if ((u8)(arg0[0x20] - 4) < 5) {
        
        u8 *t = D_L03_002AE4D0 + s3[0xF1] * 0x28;
        if (*(s32 *)(t + 0x18) != -1) {
            func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
            if (D_001A4BE0.f1200 == 0 || D_001A4BE0.f1228 != *(s32 *)(t + 0x18)) {
                func_L01_0044CD60(*(s32 *)(t + 0x18));
                D_001A4BE0.f28C9 = 0;
            } else {
                D_001A4BE0.f28C9 = 1;
            }
            if (func_L03_0032E0D8(arg0, *(s32 *)(t + 0x18))) func_L03_0032D228(arg0);
        }
        D_001A4BE0.f2824 = 25.0f;
    }
    if (arg0[0x20] >= 2) func_L01_00404808(func_L03_003307D0, arg0);
    if (func_L03_0032F660(arg0)) {
        s32 w = D_001D4C38_sda;
        if (s3[0xF1] < 9) D_L03_001D7C20 = s3[0xF1]; else D_L03_001D7C20 = 9;
        D_L03_001DFA98 = w;
    }
    if (D_001A4BE0.f25CC == 0x14 && s3[0xF5] == 0) {
        s3[0xF5] = 1;
        func_L01_003F1760();
    }
}
/* localdecomp:end func_L03_0032CBD8 */
