#include "common.h"

/* NTSC-U counterpart of func_L01_003138C8 (src/levels/01_veldin/L01_003138C8.c) */
/* localdecomp:start func_L01_003135C0 */
#include "vu0.h"

typedef struct {
    u8 p00[4];
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
    s16 h38;
    s16 h3A;
    f32 f3C;
    s32 w40;
    s32 w44;
    s32 w48;
} S17;

typedef struct {
    u8 p0[0x60];
    u16 h60;
    u8 p62[0x1C0 - 0x62];
    s32 w1C0;
} S7C10;

extern u8 D_001BBC40[];
extern s32 D_L01_001D6694_003135C0;
extern u8 D_001A4C60[];
extern u8 D_001A7C10[];
extern u8 D_001A7E18[];
extern u32 D_001A7FA0[];
extern u32 D_001A7F88[];
extern u32 D_001A7FB8[];
extern u32 D_001A7F48[];
extern u32 D_001A8528[];
extern u32 D_001A8D14[];
extern u32 D_001A8120[];
extern u16 D_001A8520[];
extern u8 D_001426E0_003135C0[];
extern u32 D_00142C04[];
extern u8 D_00142C04_b[];
extern u8 D_00142BA0[];
extern u16 *D_L01_0021DEA0_003135C0[];
extern u8 *D_L01_001E009C_003135C0;
extern u8 *D_001E009C_sda_003135C0;
extern s32 D_001D545C;
extern s32 D_001D4C38_sda_003135C0;
extern s32 D_001E00D8_sda;
extern u8 D_001DC780_sda;
extern f32 D_001DC760_sda;
extern f32 D_001DC770_sda;
extern u8 D_L01_001DC750_003135C0[8];
extern f32 D_L01_001DC764;
extern f32 D_L01_001DC768_003135C0;
extern f32 D_L01_001DC774;
extern f32 D_L01_001DC778_003135C0;
__asm__(".extern D_L01_001E009C_003135C0, 16");
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_L01_001D6694_003135C0, 16");
__asm__(".extern D_001E009C_sda_003135C0, 4");
__asm__(".extern D_001E00D8_sda, 4");
__asm__(".extern D_001DC780_sda, 1");
__asm__(".extern D_001DC760_sda, 4");
__asm__(".extern D_001DC770_sda, 4");
__asm__(".extern D_L01_001DC750_003135C0, 8");
__asm__(".extern D_L01_001DC764, 16");
__asm__(".extern D_L01_001DC768_003135C0, 16");
__asm__(".extern D_L01_001DC774, 16");
__asm__(".extern D_L01_001DC778_003135C0, 16");
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_L01_004B6C68(void);
extern s32 func_L01_003EAB60(s32);
extern void func_00399C90(s32, s32);
extern void func_L01_00438430(s32);
extern void func_L01_00417F60(s32, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_L01_0050FF18(void);
extern void func_00399F90(void);
extern s32 func_L01_00417EA0(void);
extern void func_L01_00416B38(s32);
extern void func_L01_00449AE8(s32);
extern void func_L01_00419718(s32, s32);
extern s32 *func_L01_00438488(s32, s32, s32);
extern void func_003BD360(u8 *);
extern s32 func_003883C8(void *);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void *func_L01_003CCE70(u8 *, void *, void *, f32, s32, s32);
extern s32 func_L01_003C7540(u8 *);
extern void func_L01_00452F40(u8 *, s32);

void func_L01_003135C0(u8 *a0) {
    S17 *s;
    f32 v[4] __attribute__((aligned(16)));
    f32 t;
    u8 *e;
    u8 *ent;
    u32 tt;
    unsigned long bits;
    unsigned long bits2; /* own variable: sharing `bits` moves the second lui to $v0 */
    u32 n;
    u8 *q1;
    u8 *q2;
    u16 *p;
    u32 m;
    s32 x;

    s = *(S17 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        a0[0x30] = 0xFF;
        s->h3A = 120;
        s->h38 = 10;
        s->f3C = 0.008333334f;
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (!(D_001BBC40[s->w2C + D_001D545C * 16] & 0x80)) {
            if (D_L01_001D6694_003135C0 == 0 && func_L01_004B6C68() == 0 && func_L01_003EAB60(s->w34) != 0) {
                if (*(u16 *)(a0 + 0x96) >= 0x33) {
                    func_00399C90(0, -1);
                    func_L01_00438430(s->w2C);
                }
                *(u16 *)(a0 + 0x96) += 1;
            }
        } else {
            *(u16 *)(a0 + 0x96) += 1;
        }
        if (*(u16 *)(a0 + 0x96) >= 0x79 && !(D_001A8528[0] & (1 << D_001D545C))) {
            func_L01_00417F60(0xCEF, 0x96);
        }
        if (((S7C10 *)D_001A7C10)->h60 == 0) {
            if (s->w4 != -1 && func_0037E0F0(D_001A4C60, s->w4, 0) && !(D_001A7FA0[0] & (1 << D_001D545C))) {
                func_L01_00417F60(0xB7D, 0x20);
            }
        }
        if (s->w8 != -1 && func_0037E0F0(D_001A4C60, s->w8, 0) && !(D_001A7F88[0] & (1 << D_001D545C))) {
            func_L01_00417F60(0xB7B, 0x1E);
        }
        if (s->wC != -1 && func_0037E0F0(D_001A4C60, s->wC, 0)) {
            if (func_L01_0050FF18() == 0) {
                if (!(D_001A7FB8[0] & (1 << D_001D545C))) {
                    func_L01_00417F60(0xB7F, 0x22);
                }
            } else {
                x = *(s32 *)(D_001A4C60 + 0x1630);
                if (x == 1 && !(D_001A8D14[0] & (x << D_001D545C))) {
                    func_L01_00417F60(0x1708, 0x13F);
                }
            }
        }
        if (s->w14 != -1 && func_0037E0F0(D_001A4C60, s->w14, 0)) {
            D_001426E0_003135C0[3] = 1;
            func_00399F90();
        }
        if (D_001426E0_003135C0[0] == 0) {
            if (func_L01_004B6C68()) {
                D_001A8520[0] = 0xFFFF;
            }
            bits = D_00142C04[0];
            bits = (bits >> 6) & 1;
            if (bits && func_L01_004B6C68() == 0) {
                if (func_L01_00417EA0() == 0) {
                    func_L01_00416B38(0x27);
                    func_L01_00449AE8(0x27);
                }
                D_001426E0_003135C0[0] = 1;
                func_00399F90();
            }
        } else {
            n = 0x8000;
            e = D_001A7E18 + n;
            if (*(u16 *)(e + 0x9D0) == 0 && *(u16 *)(e + 0x19E4) == 0) {
                if (func_L01_0050FF18() == 0) {
                    func_L01_00419718(0xB7C, 0x1F);
                    if (*(u16 *)(e + 0x9D0) == 0) {
                        *(u16 *)(e + 0x9D0) = 1;
                    }
                } else {
                    func_L01_00419718(0xCD3, 0x7D);
                    if (*(u16 *)(e + 0x19E4) == 0) {
                        *(u16 *)(e + 0x19E4) = 1;
                    }
                }
            }
        }
        if (D_001426E0_003135C0[1] == 0) {
            bits2 = D_00142C04_b[0];
            bits2 = (bits2 >> 7) & 1;
            if (bits2 && func_L01_004B6C68() == 0) {
                if (func_L01_00417EA0() == 0) {
                    func_L01_00416B38(0x77);
                    func_L01_00449AE8(0x77);
                }
                D_001426E0_003135C0[1] = 1;
                func_00399F90();
            }
        } else if (!(D_001A8120[0] & (1 << D_001D545C))) {
            func_L01_00417F60(0xB9D, 0x40);
        }
        if (D_001DC780_sda == 0) {
            if (s->w20 != -1) {
                s32 *r = func_L01_00438488(0xF6E, 0, 4);
                if (r != 0) {
                    u32 id = ((u32 (*)(u8 *))*r)(D_001E009C_sda_003135C0 + (s->w20 << 8));
                    if (*(u32 *)(D_00142BA0 + ((id >> 2) << 2)) & (1 << (id & 0x1F))) {
                        for (p = D_L01_0021DEA0_003135C0[s->w24];
                             (s->w24 & 0xFF) != 0xFF && D_001E00D8_sda >= s->w24 && p != 0 &&
                             (*(s16 *)(p - 1) >= 0 || p == D_L01_0021DEA0_003135C0[s->w24]);
                             p++) {
                            ent = D_L01_001E009C_003135C0 + ((p[0] & 0x7FFF) << 8);
                            if (ent == 0) {
                                break;
                            }
                            tt = ent[0x20];
                            if (tt != 0xFE) {
                                if (tt != 0xFD) {
                                    func_003BD360(ent);
                                }
                            }
                        }
                        D_001DC780_sda = 1;
                    }
                }
            }
        }
        if (s->w28 != -1 && func_L01_0050FF18() == 0) {
            if ((u32)(D_001D4C38_sda_003135C0 - ((S7C10 *)D_001A7C10)->w1C0) >= 0x709) {
                if (func_0037E0F0(D_001A4C60, s->w28, 0)) {
                    if ((u32)(D_001D4C38_sda_003135C0 - D_001A7F48[0]) >= 0xE11 || D_001A7F48[0] == 0) {
                        func_L01_00417F60(0xB76, 0x19);
                    }
                }
            }
        }
        if (func_L01_00417EA0()) {
            m = 1 << D_001D545C;
            q1 = D_001A7E18;
            if (!(*(u32 *)(q1 + 0x61DC) & m)) {
                if (s->w30 != -1) {
                    u8 *o = D_001E009C_sda_003135C0 + (s->w30 << 8);
                    if (o == 0 || o[0x20] == 0xFE || o[0x20] == 0xFD) {
                        q2 = D_001A7E18;
                        if (!(*(u32 *)(q2 + 0x20) & (1 << D_001D545C))) {
                            func_L01_00417F60(0x827, 2);
                        }
                    }
                }
            }
        }
        if (s->w48 == 0 && func_0037E0F0(D_001A4C60, s->w40, 0)) {
            s->w48 = 1;
        } else if (s->w48 == 1 && func_0037E0F0(D_001A4C60, s->w44, 0)) {
            s->w48 = 2;
        }
        if ((s->h3A >= 0x3C && s->w48 == 1 && !func_003883C8(&s->h3A)) || (s->w48 == 2 && !func_003883C8(&s->h3A))) {
            if (func_003883C8(&s->h38)) {
                t = (f32)s->h3A * s->f3C;
                v[0] = func_003BE6A8(D_001DC760_sda, D_001DC770_sda, t);
                v[1] = func_003BE6A8(D_L01_001DC764, D_L01_001DC774, t);
                v[2] = func_003BE6A8(D_L01_001DC768_003135C0, D_L01_001DC778_003135C0, t);
                v[3] = 0.0f;
                vec_sub_ba(v, v, D_L01_001DC750_003135C0);
                func_00388830(v, v, 0.53333336f);
                func_L01_003CCE70(a0, D_L01_001DC750_003135C0, v, 1.0f, 0xF01038FF, 0xF0002080);
                s->h38 = 10;
            }
        }
        if (func_L01_003C7540(D_L01_001E009C_003135C0 + (s->w1C << 8))) {
            func_L01_00452F40(a0, 1);
        }
        break;
    }
}
/* localdecomp:end func_L01_003135C0 */
