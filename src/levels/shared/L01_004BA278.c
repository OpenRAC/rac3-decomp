#include "common.h"

typedef struct {
    s32 id;
    u8 pad4[12];
    u8 b16;
    u8 b17;
    u8 pad18[2];
} Slot_004B6C98;
typedef struct {
    u8 pad0[128];
    s32 cur;
    u8 pad84[188];
    Slot_004B6C98 slots[79];
    u8 pad76C[16];
    s32 unk77C;
} S_00244740;
typedef struct {
    u8 pad0[124];
    s32 value;
    u8 pad80[112];
} S_002C5640;
typedef struct {
    u8 pad0[124];
    s32 value;
    u8 pad80[112];
} Info_004B6C98;
typedef struct {
    u8 active;
    u8 pad[0xEF];
} Ent4B6DF8;
typedef struct {
    s32 id;
    s32 val;
    s32 idx;
    s32 pad;
} Item_004B7420;
typedef struct {
    u8 pad0[320];
    Item_004B7420 items[96];
    s32 count;
} List_004B7420;
typedef struct {
    s32 v[5];
} Tbl_004B7420;
typedef struct { u8 p0[72]; s32 f72; } A_4BBAF0;
typedef struct {
    s32 type;
    u8 b4;
    u8 p5[11];
    u8 b16;
    u8 p17[2];
    u8 b19;
} E_4BBAF0;
typedef struct {
    u8 p0[320];
    E_4BBAF0 e[76];
    u8 p1[1856 - 320 - 76 * 20];
    s32 count;
    u8 p2[44];
    s32 f1904;
    u8 p3[4];
    s32 f1912;
} B_4BBAF0;
typedef struct {
    char pad[1916];
    s32 v;
} Unk244740;
typedef struct {
    s32 id;
    s32 f4;
    s32 kind;
    s32 color;
    u8 pad[32];
} Ent4BD808;

/* localdecomp:start func_L01_004BA278 */
#include "vu0.h"

typedef struct { u8 p0[0xC]; f32 fC; u8 p10[0x24]; u16 h34; u8 p36[0xA]; u8 b40; u8 b41; u8 p42[2]; f32 f44; u8 p48[0x19]; u8 b61; u8 p62; u8 b63; u8 p64[4]; u8 *w68; u8 p6C[3]; u8 b6F; u8 p70[0x3A]; s16 hAA; u8 pAC[8]; s16 hB4; } O_004BA278;
typedef struct { u8 p0[0x34]; s32 w34; s32 w38; s32 w3C; s16 h40; u8 p42[2]; s16 h44; u8 p46[2]; s16 h48; u8 p4A[0x16]; s8 b60; u8 p61[0x13F]; O_004BA278 *arr[1]; } G_004BA278;
typedef struct { u8 p0[0x1A4]; s32 w1A4; } P_004BA278;

extern G_004BA278 D_L01_001E6D80;
extern u8 D_L01_001EA7C0[];
extern f32 D_L01_001DF950;
extern s32 D_L01_001D4D40;
extern P_004BA278 *D_L01_001D52FC;
extern s32 D_L01_00143950[];
extern s16 D_L01_001CCFD4[];

extern void func_00392C48(void *);
extern s32 func_003A0F98(s32, s32);
extern void func_L01_00423A10(void);
extern void func_003E5520(void);
extern void func_003CD058(void);
extern void func_L01_004AB0E0(void);
extern void func_L01_00512A30(void *, s32);
extern void func_L01_004E20E8(void);
extern void func_003CD350(void);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003A1798(void);
extern s32 func_00392C78(void *);
extern void func_003A2750(s32);
extern void func_0039A438(void);
extern s32 func_L01_0042C458(s32);
extern s32 func_003E56E0(void);
extern void func_003C29B0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L01_004472C0(void *);
extern void func_L01_004E2988(void *);
extern void func_L01_004241F0(void);
extern void func_003A4288(void);
extern void func_003D0B20(void);
extern void func_L01_0043AB98(void);
extern void func_003E55B8(void);

void func_L01_004BA278(void) {
    s32 k;
    s32 lim;
    s32 done;
    s32 end;
    s32 r;
    s32 i;
    vu0_v4 a, b;

    if (D_L01_001E6D80.b60 != 0) {
        return;
    }
    if (D_L01_001E6D80.h40 == 0) {
        func_00392C48(D_L01_001EA7C0);
        D_L01_001E6D80.b60 = 1;
        func_003A0F98(0, 0);
        return;
    }
    if (D_L01_001E6D80.h40 < D_L01_001E6D80.w34 + 15) {
        k = D_L01_001E6D80.h40 - 15;
        D_L01_001DF950 = (f32)(D_L01_001E6D80.w34 - k) * 0.06666667f;
    }
    func_003E5520();
    func_L01_00423A10();
    func_003CD058();
    func_L01_004AB0E0();
    func_L01_004E20E8();
    func_003CD350();
    D_L01_001E6D80.w38++;
    D_L01_001E6D80.w34++;
    if (D_L01_001E6D80.w34 < 25) {
        func_003C4138(&D_L01_001DF950, 0.0f, 0.048000004f);
        if (D_L01_001DF950 > 1.0f) {
            D_L01_001DF950 = 1.0f;
        }
    }
    if (D_L01_001E6D80.w34 >= D_L01_001E6D80.h48) {
        func_003A1798();
    }
    done = 0;
    end = D_L01_001E6D80.w34 >= D_L01_001E6D80.h40;
    if (D_L01_001E6D80.w34 >= 15 && D_L01_001DF950 == 0.0f) {
        if (!(D_L01_001D4D40 & 0x80)) {
            s32 f = D_L01_001D4D40 & ~0xC0;
            if (f != 2) {
                if (f == 0 && (D_L01_001D52FC->w1A4 & 0x9FF)) {
                    done = 1;
                } else {
                    s32 m = D_L01_001D52FC->w1A4 & 0x800;
                    done = m != 0;
                }
            }
        }
    }
    if (done) {
        D_L01_001D4D40 &= ~0x80;
        D_L01_001EA7C0[0x64] = 1;
        func_00392C48(D_L01_001EA7C0);
        D_L01_001E6D80.b60 = 1;
        func_003A0F98(0, 0);
    } else if (end) {
        D_L01_001D4D40 &= ~0x80;
        D_L01_001E6D80.b60 = 1;
        if (func_00392C78(D_L01_001EA7C0) == 0) {
            func_003A0F98(0, 0);
        }
    } else {
        lim = 0x60;
        if (D_L01_00143950[0]) {
            lim = 0x50;
        }
        if (D_L01_001E6D80.w38 >= lim) {
            D_L01_001E6D80.w3C++;
            if (D_L01_001CCFD4[0] != 0) {
                func_003A2750(1);
            }
            func_0039A438();
            func_L01_0042C458(D_L01_001E6D80.w3C + 1);
        }
        r = func_003E56E0();
        for (i = 0; i < D_L01_001E6D80.h44; i++) {
            O_004BA278 *o = D_L01_001E6D80.arr[i];
            u8 *base;
            s32 h = D_L01_001E6D80.w38 >> 1;
            o->b41 = h + 1;
            o->b40 = h;
            func_003C29B0(o);
            o->f44 = (f32)(D_L01_001E6D80.w38 & 1) * 0.5f;
            if (r != 0 && (D_L01_001E6D80.w38 & 1) && o->hB4 == 0) {
                o->f44 = 1.0f;
            }
            base = o->w68;
            func_0038CE20(&a, base + o->b40 * 16, 1.0f - o->f44);
            func_0038CE20(&b, base + o->b41 * 16, o->f44);
            vec_add_ab((u8 *)o + 0x10, &a, &b);
            o->b61 = 0xFF;
            func_003C7C38(o);
            if (o->b63) {
                if (D_L01_001E6D80.w3C != 0 && D_L01_001E6D80.w38 < 16) {
                    f32 d = func_0038CF00(o, (u8 *)o + 0xF0);
                    if (d < 20.0f) {
                        f32 s = (f32)D_L01_001E6D80.w38 * 0.0625f;
                        func_0038CDF8(o, (u8 *)o + 0xF0, o, s);
                        o->fC += d * (1.0f - s);
                    }
                } else {
                    *(vu0_q *)((u8 *)o + 0xF0) = *(vu0_q *)o;
                    o->h34 |= 0x100;
                }
            }
            if (o->b6F) {
                func_L01_004472C0(o);
            }
            if (o->hAA == 0 || o->hAA == 0xF6B) {
                func_L01_00512A30(o, 0);
            }
            if (o->hAA == 0xA || o->hAA == 0x19C9 || o->hAA == 0x1159 || o->hAA == 0x1F6B || o->hAA == 0x57 || o->hAA == 0x259 || o->hAA == 0x1F6B) {
                func_L01_004E2988(o);
            }
        }
    }
    func_L01_004241F0();
    func_003A4288();
    func_003D0B20();
    func_L01_0043AB98();
    func_003E55B8();
}
/* localdecomp:end func_L01_004BA278 */

/* localdecomp:start func_L01_004BA7B8 */
extern f32 D_L01_001DF950;
__asm__(".extern D_L01_001DF950, 16");
extern f32 D_L01_001D6720;
extern void func_0038A238(s32);

void func_L01_004BA7B8(void) {
    D_L01_001D6720 = 1.2f;
    if (D_L01_001DF950 < 1.0f) {
        func_0038A238(5);
    }
}
/* localdecomp:end func_L01_004BA7B8 */
