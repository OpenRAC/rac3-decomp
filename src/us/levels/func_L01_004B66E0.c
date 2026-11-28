#include "common.h"
/* localdecomp:start func_L01_004B66E0 */
#include "vu0.h"

typedef struct { u8 p0[0xC]; f32 fC; u8 p10[0x24]; u16 h34; u8 p36[0xA]; u8 b40; u8 b41; u8 p42[2]; f32 f44; u8 p48[0x19]; u8 b61; u8 p62; u8 b63; u8 p64[4]; u8 *w68; u8 p6C[3]; u8 b6F; u8 p70[0x3A]; s16 hAA; u8 pAC[8]; s16 hB4; } O_004BA278;
typedef struct { u8 p0[0x34]; s32 w34; s32 w38; s32 w3C; s16 h40; u8 p42[2]; s16 h44; u8 p46[2]; s16 h48; u8 p4A[0x16]; s8 b60; u8 p61[0x13F]; O_004BA278 *arr[1]; } G_004BA278;
typedef struct { u8 p0[0x1A4]; s32 w1A4; } P_004BA278;

extern G_004BA278 D_L01_001E6E00;
extern u8 D_L01_001EA840[];
extern f32 D_L01_001DF9D0;
extern s32 D_001D4D40;
extern P_004BA278 *D_001D52FC;
extern s32 D_00143950[];
extern s16 D_001CCFD4[];

extern void func_0038E410(void *);
extern s32 func_0039BF98(s32, s32);
extern void func_L01_00420CD8(void);
extern void func_003DFFD0(void);
extern void func_003C7AE8(void);
extern void func_L01_004A76F0(void);
extern void func_L01_0050EA58(void *, s32);
extern void func_L01_004DE348(void);
extern void func_003C7DE0(void);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_0039C710(void);
extern s32 func_0038E440(void *);
extern void func_0039D6C8(s32);
extern void func_00395648(void);
extern s32 func_L01_004296B0(s32);
extern s32 func_003E0190(void);
extern void func_003BD490(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003C26C8(void *);
extern f32 func_003887C8(void *, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_L01_00444188(void *);
extern void func_L01_004DEBC0(void *);
extern void func_L01_004214C0(void);
extern void func_0039EE68(void);
extern void func_003CB5B0(void);
extern void func_L01_00437AB8(void);
extern void func_003E0068(void);

void func_L01_004B66E0(void) {
    s32 k;
    s32 lim;
    s32 done;
    s32 end;
    s32 r;
    s32 i;
    vu0_v4 a, b;

    if (D_L01_001E6E00.b60 != 0) {
        return;
    }
    if (D_L01_001E6E00.h40 == 0) {
        func_0038E410(D_L01_001EA840);
        D_L01_001E6E00.b60 = 1;
        func_0039BF98(0, 0);
        return;
    }
    if (D_L01_001E6E00.h40 < D_L01_001E6E00.w34 + 15) {
        k = D_L01_001E6E00.h40 - 15;
        D_L01_001DF9D0 = (f32)(D_L01_001E6E00.w34 - k) * 0.06666667f;
    }
    func_003DFFD0();
    func_L01_00420CD8();
    func_003C7AE8();
    func_L01_004A76F0();
    func_L01_004DE348();
    func_003C7DE0();
    D_L01_001E6E00.w38++;
    D_L01_001E6E00.w34++;
    if (D_L01_001E6E00.w34 < 30) {
        func_003BEBF8(&D_L01_001DF9D0, 0.0f, 0.0400000028f);
        if (D_L01_001DF9D0 > 1.0f) {
            D_L01_001DF9D0 = 1.0f;
        }
    }
    if (D_L01_001E6E00.w34 >= D_L01_001E6E00.h48) {
        func_0039C710();
    }
    done = 0;
    end = D_L01_001E6E00.w34 >= D_L01_001E6E00.h40;
    if (D_L01_001E6E00.w34 >= 18 && D_L01_001DF9D0 == 0.0f) {
        if (!(D_001D4D40 & 0x80)) {
            s32 f = D_001D4D40 & ~0xC0;
            if (f != 2) {
                if (f == 0 && (D_001D52FC->w1A4 & 0x9FF)) {
                    done = 1;
                } else {
                    s32 m = D_001D52FC->w1A4 & 0x800;
                    done = m != 0;
                }
            }
        }
    }
    if (done) {
        D_001D4D40 &= ~0x80;
        D_L01_001EA840[0x64] = 1;
        func_0038E410(D_L01_001EA840);
        D_L01_001E6E00.b60 = 1;
        func_0039BF98(0, 0);
    } else if (end) {
        D_001D4D40 &= ~0x80;
        D_L01_001E6E00.b60 = 1;
        if (func_0038E440(D_L01_001EA840) == 0) {
            func_0039BF98(0, 0);
        }
    } else {
        lim = 0x60;
        if (D_00143950[0]) {
            lim = 0x50;
        }
        if (D_L01_001E6E00.w38 >= lim) {
            D_L01_001E6E00.w3C++;
            if (D_001CCFD4[0] != 0) {
                func_0039D6C8(1);
            }
            func_00395648();
            func_L01_004296B0(D_L01_001E6E00.w3C + 1);
        }
        r = func_003E0190();
        for (i = 0; i < D_L01_001E6E00.h44; i++) {
            O_004BA278 *o = D_L01_001E6E00.arr[i];
            u8 *base;
            s32 h = D_L01_001E6E00.w38 >> 1;
            o->b41 = h + 1;
            o->b40 = h;
            func_003BD490(o);
            o->f44 = (f32)(D_L01_001E6E00.w38 & 1) * 0.5f;
            if (r != 0 && (D_L01_001E6E00.w38 & 1) && o->hB4 == 0) {
                o->f44 = 1.0f;
            }
            base = o->w68;
            func_003886E8(&a, base + o->b40 * 16, 1.0f - o->f44);
            func_003886E8(&b, base + o->b41 * 16, o->f44);
            vec_add_ab((u8 *)o + 0x10, &a, &b);
            o->b61 = 0xFF;
            func_003C26C8(o);
            if (o->b63) {
                if (D_L01_001E6E00.w3C != 0 && D_L01_001E6E00.w38 < 16) {
                    f32 d = func_003887C8(o, (u8 *)o + 0xF0);
                    if (d < 20.0f) {
                        f32 s = (f32)D_L01_001E6E00.w38 * 0.0625f;
                        func_003886C0(o, (u8 *)o + 0xF0, o, s);
                        o->fC += d * (1.0f - s);
                    }
                } else {
                    *(vu0_q *)((u8 *)o + 0xF0) = *(vu0_q *)o;
                    o->h34 |= 0x100;
                }
            }
            if (o->b6F) {
                func_L01_00444188(o);
            }
            if (o->hAA == 0 || o->hAA == 0xF6B) {
                func_L01_0050EA58(o, 0);
            }
            if (o->hAA == 0xA || o->hAA == 0x19C9 || o->hAA == 0x1159 || o->hAA == 0x1F6B || o->hAA == 0x57 || o->hAA == 0x259 || o->hAA == 0x1F6B) {
                func_L01_004DEBC0(o);
            }
        }
    }
    func_L01_004214C0();
    func_0039EE68();
    func_003CB5B0();
    func_L01_00437AB8();
    func_003E0068();
}
/* localdecomp:end func_L01_004B66E0 */
