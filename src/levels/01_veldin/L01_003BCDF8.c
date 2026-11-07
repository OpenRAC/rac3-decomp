#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003BCDF8);

/* localdecomp:start func_L01_003BD608 */
typedef struct { u8 p0[0x43]; u8 b43; u8 p44[0x54]; s32 f98; u8 p9C[0xE]; s16 hAA; } R_BD608;
typedef struct { u8 p0[0x324]; s32 f324; s32 f328; } P_BD608;
extern u8 *D_L01_001E001C_a;
__asm__(".extern D_L01_001E001C_a, 16");
extern u8 *D_L01_001E001C_b;
__asm__(".extern D_L01_001E001C_b, 16");
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
extern s16 *D_L01_0021DE20[];
extern void func_00444D90(void *, s32, s32, s32);
extern void func_L01_0044FD88(void *, void *, s32, s32);
void func_L01_003BD608(void *a0, P_BD608 *p) {
    R_BD608 *r;
    s16 *q;
    s32 i;
    if (p->f324 != -1) {
        r = (R_BD608 *)(D_L01_001E001C_a + (p->f324 << 8));
        if (r->b43 != 5) func_00444D90(r, 5, 0, 6);
        func_L01_0044FD88(a0, r, 1, 0);
        r->f98 = 0;
    }
    if (p->f328 != -1) {
        i = 0;
        q = D_L01_0021DE20[p->f328];
        while ((p->f328 & 0xFF) != 0xFF && p->f328 <= D_001E0058_sda && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[p->f328])) {
            r = (R_BD608 *)(D_L01_001E001C_b + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) break;
            switch (r->hAA) {
            case 0x16BD:
                if (r->b43 != 0) func_00444D90(r, 0, 0, 6);
                break;
            case 0x16E4:
                if (r->b43 != 5) func_00444D90(r, 5, 0, 6);
                break;
            }
            if (r->hAA == 0x16BD || r->hAA == 0x16E4) {
                func_L01_0044FD88(a0, r, i + 2, 0);
                i++;
                r->f98 = 0;
            }
            q++;
        }
    }
}
/* localdecomp:end func_L01_003BD608 */

/* localdecomp:start func_L01_003BD7D8 */
/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */
typedef struct { char p0[0x18]; float f18; char p1[4]; unsigned char b20; char p2[0x47]; char *p68; char p3[0x29]; unsigned char b95; } A;
typedef struct { char p0[0x18]; float f18; } B;
typedef struct S {
    char p0[0x30]; float f30; char p1[0xa]; unsigned char b3e; char p2[0x20]; unsigned char b5f; char p3[6]; short h66;
    char p4[0xf8]; char r160[0x190]; int w2f0; float f2f4; int w2f8; float f2fc; char p6[0x20]; int w320;
} S;
extern B *D_L01_0021F6C0[];
extern int func_L01_003BD9A8(void);
extern int func_L01_00452FB0(A *, void *, int, int, int);
extern void func_L01_003BD608(void *, P_BD608 *);
extern void func_L01_003BDC88(A *, int);
extern void func_L01_00456BD0(A *, int);
extern void func_L01_00456C98(A *, int, int, int, int, int, int, int, int, int, float, float, float);
int func_L01_003BD7D8(A *a) {
    S *s = (S *)a->p68;
    if (a->b20 == 0 && func_L01_003BD9A8()) return 1;
    if (func_L01_00452FB0(a, s->r160, 0, 0, 0)) {
        if (s->h66 < 3) s->h66++;
    }
    if (0.0f < s->f30) func_L01_003BD608(a, s);
    if (s->b3e == 2) func_L01_003BDC88(a, 1);
    if (s->b5f) func_L01_00456BD0(a, 5); else func_L01_00456BD0(a, 3);
    if (s->w320 != -1) a->f18 = D_L01_0021F6C0[s->w320]->f18;
    if (s->b5f) {
        if (a->b95 == 0) func_L01_00456C98(a, s->w2f0, 0, 0, 0, 0, 3, 0, 0, 0, s->f2f4, 10.0f, 1.0f);
        else func_L01_00456C98(a, s->w2f8, 0, 0, 0, 0, 3, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    } else {
        func_L01_00456C98(a, s->w2f8, 0, 0, 0, 0, 1, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L01_003BD7D8 */

INCLUDE_ASM("asm/levels", func_L01_003BD9A8);

/* localdecomp:start func_L01_003BDC88 */
typedef struct { void (*f0)(void *); void (*f4)(void *); s32 p8, pC; void (*f10)(void *); } V_BDC88;
typedef struct { char p0[0x240]; s32 f240; char p1[0xE0]; s32 f324; s32 f328; } O_BDC88;
extern u8 *D_L01_001E001C;
__asm__(".extern D_L01_001E001C, 16");
extern s16 *D_L01_0021DE20[];
extern u8 *D_001E001C_sda;
__asm__(".extern D_001E001C_sda, 4");
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
extern V_BDC88 *func_L01_0043B548(s32, s32);
extern s32 func_L01_0043B930(s32);
extern s32 func_L01_0043B960(s32);
extern void func_L01_00439300(void *);
void func_L01_003BDC88(A *a, int flag) {
    O_BDC88 *o = (O_BDC88 *)a->p68;
    V_BDC88 *v;
    s16 *p;
    if (o->f240) {
        v = func_L01_0043B548(0x19E1, 0x6C);
        if (o->f324 != -1) {
            v->f10(D_L01_001E001C + (o->f324 << 8));
            o->f324 = -1;
        }
        if (o->f328 != -1) {
            if (func_L01_0043B960(o->f328)) {
                while (!func_L01_0043B930(o->f328)) {
                    v->f10(D_L01_001E001C + ((*D_L01_0021DE20[o->f328] & 0x7FFF) << 8));
                }
                o->f328 = -1;
            } else {
                p = D_L01_0021DE20[o->f328];
                while ((o->f328 & 0xFF) != 0xFF && o->f328 <= D_001E0058_sda && p && (p[-1] >= 0 || p == D_L01_0021DE20[o->f328])) {
                    u8 *r = D_L01_001E001C + ((*(u16 *)p & 0x7FFF) << 8);
                    if (!r) break;
                    v->f10(r);
                    p++;
                }
                o->f328 = -1;
            }
        }
        v->f0(a);
        if (flag) v->f4(a);
    } else {
        if (o->f324 != -1) func_L01_00439300(D_001E001C_sda + (o->f324 << 8));
        if (o->f328 != -1) {
            p = D_L01_0021DE20[o->f328];
            while ((o->f328 & 0xFF) != 0xFF && o->f328 <= D_001E0058_sda && p && (p[-1] >= 0 || p == D_L01_0021DE20[o->f328])) {
                u8 *r = D_L01_001E001C + ((*(u16 *)p & 0x7FFF) << 8);
                if (!r) break;
                func_L01_00439300(r);
                p++;
            }
        }
        func_L01_00439300(a);
    }
}
/* localdecomp:end func_L01_003BDC88 */
