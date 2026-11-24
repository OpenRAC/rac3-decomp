#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003AAD60 */
typedef struct R_003AAD60 {
    f32 x0;
    s32 x4;
    s32 x8;
    f32 xC;
    s32 x10;
    u8 x14;
    u8 x15;
    u8 x16;
    u8 x17;
    u8 x18;
    u8 x19;
    u8 x1A;
    u8 pad1B;
    s32 x1C;
} R_003AAD60;


typedef struct M_003AAD60 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 x20;
    u8 pad21[0x30 - 0x21];
    u8 x30;
    u8 x31;
    u8 pad32[0x34 - 0x32];
    u16 x34;
    u8 pad36[0x68 - 0x36];
    void *x68;
    u8 pad6C[0x78 - 0x6C];
    s32 x78;
    u8 pad7C[0x96 - 0x7C];
    u16 x96;
    u8 pad98[0xAA - 0x98];
    s16 xAA;
    u8 padAC[0xB2 - 0xAC];
    u16 xB2;
    u8 padB4[0xC0 - 0xB4];
    u8 xC0[0x30];
    u8 padF0[0xF8 - 0xF0];
    f32 xF8;
} M_003AAD60;

typedef struct W_003AAD60 {
    s32 x0;
    s32 x4;
    s32 x8;
} W_003AAD60;

typedef struct H_003AAD60 {
    u8 pad0[0x40];
    u8 x40[0x40];
    vu0_v4 pos;
    u8 pad90[0x98 - 0x90];
    u8 x98[0x100 - 0x98];
    vu0_v4 x100;
    u8 pad110[0x222 - 0x110];
    u16 x222;
    u8 pad224[0x238 - 0x224];
    s32 x238;
    u8 pad23C[0xC08 - 0x23C];
    s32 xC08;
    u8 padC0C[0x1228 - 0xC0C];
    s32 x1228;
    u8 pad122C[0x25C0 - 0x122C];
    u8 *x25C0;
    s32 x25C4;
    u8 pad25C8[0x25F8 - 0x25C8];
    s32 x25F8;
} H_003AAD60;

typedef struct G_003AAD60 {
    u8 pad0[0x14];
    u8 x14;
} G_003AAD60;

typedef struct T_003AAD60 {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0xF0 - 0x14];
} T_003AAD60;

typedef struct C_003AAD60 {
    u8 pad0[0x3C];
    s16 x3C;
    u8 pad3E[0x48 - 0x3E];
    s16 x48;
    u8 pad4A[0x76 - 0x4A];
    u16 x76;
    u8 pad78[0x9E - 0x78];
    u16 x9E;
} C_003AAD60;

typedef struct K_003AAD60 {
    u8 pad0[0xE04];
    u16 xE04;
    u8 padE06[0x10608 - 0xE06];
    u16 x10608;
} K_003AAD60;

typedef struct E_003AAD60 {
    s32 x0;
    u8 pad4[0x24 - 0x4];
    s32 x24;
} E_003AAD60;

typedef struct V_003AAD60 {
    M_003AAD60 *x0;
    s32 x4;
    u8 pad8[0x14 - 0x8];
    f32 x14;
    s32 x18;
    M_003AAD60 *x1C;
    u8 pad20[4];
    s32 x24;
    s32 x28;
    s32 x2C;
    M_003AAD60 *x30;
    M_003AAD60 *x34;
    M_003AAD60 *x38;
    M_003AAD60 *x3C;
    M_003AAD60 *x40;
    s32 x44;
    s32 x48;
    s32 x4C;
    s32 x50;
    s32 x54;
    f32 x58;
    f32 x5C;
    u8 x60;
    u8 x61;
    u8 x62;
    u8 pad63;
    s32 x64;
    s32 x68;
    u8 pad6C[0x70 - 0x6C];
    u8 x70[0xD0 - 0x70];
    f32 xD0;
    u8 padD4[0x1F0 - 0xD4];
    R_003AAD60 rec[4];
    u8 pad270[0x830 - 0x270];
    s32 x830;
    s32 x834;
    s32 x838;
    u8 pad83C[4];
    s32 x840;
    s32 x844;
    s32 x848;
} V_003AAD60;

typedef struct { u8 pad[0x464]; u8 spent[1]; } S_003AAD60;
extern S_003AAD60 D_L03_00235A00;
extern u8 D_001BBE90[];
extern s32 D_001D545C;
extern u8 *D_001D52FC;
extern H_003AAD60 D_001A4BE0;
extern G_003AAD60 D_001425C0;
extern u8 D_00142CB4[];
extern u16 D_00143954[];
extern u8 D_001A30B0[];
extern C_003AAD60 D_001CCFD0;
extern K_003AAD60 D_001A7E18;
extern T_003AAD60 D_L03_002C49C0[];
extern E_003AAD60 D_L03_002E52F0;
extern f32 D_L03_001E9220[];
extern f32 D_L03_001E28E4[];
extern u8 D_L03_001E24C0[];
extern u8 D_L03_001DE630[];
extern u8 D_L03_001DE640[];
extern u8 D_L03_001DE650[];
extern u8 D_L03_001DE668[];
extern u8 D_L03_001DE678[];
extern u8 D_L03_001DE688[];
extern u8 D_L03_001DE698[];
extern u8 D_L03_001DE6A8[];
extern u8 D_L03_001DE6B8[];
extern u8 D_L03_001DE6C8[];
extern u8 D_L03_001DE6D8[];
extern u8 D_L03_001DE6E8[];
extern u8 D_L03_001DE6F8[];
extern u8 D_L03_001DE708[];
__asm__(".extern D_L03_001DE5C0, 4");
extern s32 D_L03_001DE5C0;
__asm__(".extern D_L03_001DE5C4, 4");
extern s32 D_L03_001DE5C4;
__asm__(".extern D_L03_001DE5D4, 4");
extern s32 D_L03_001DE5D4;
__asm__(".extern D_L03_001DE5DC, 4");
extern f32 D_L03_001DE5DC;
__asm__(".extern D_L03_001DE600, 4");
extern f32 D_L03_001DE600;
__asm__(".extern D_L03_001DE610, 8");
extern vu0_v4 D_L03_001DE610 __attribute__((section(".sdata")));
__asm__(".extern D_L03_001DE620, 8");
extern vu0_v4 D_L03_001DE620 __attribute__((section(".sdata")));
extern f32 D_L03_001DF2D0[1];
extern f32 D_L03_001DF370;
extern f32 D_L03_001DF374;
extern u8 D_L03_001DF364;
extern u8 D_L03_001DF365;
extern u8 D_L03_001DF366;
extern s32 D_L03_001DF4C0;

extern void func_L03_003AE8E0(void);
extern void func_L03_003AEB30(void);
extern void func_L03_003AEC58(void);

extern void func_0013C1A0(s32);
extern void func_0013C1D0(s32);
extern void func_0013D3D0(s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_0039AA38(s32);
extern s32 func_0039AC08(s32);
extern s32 func_003A0EC0(s32, s32, void *, s32, s32);
extern void func_003A0F98(s32, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C4BB0(void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_003F1740_003AAD60(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_004048D0_003AAD60(void *, void *);
extern s32 func_L01_0041A5B0(s32, s32);
extern void func_L01_0041A6E0(void);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00448690(void *, void *, f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_00456230(void *, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_L01_004606A8(void *);
extern s32 func_L01_00479200(void);
extern void func_L01_00479280(void);
extern s32 func_L01_0047B3D8(void);
extern s32 func_L01_0047B420(void);
extern s32 func_L01_0047B948(void);
extern void func_L01_0047B990(void);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_00504E38(s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L01_00511A40(void *, s32, f32);
extern s32 func_L01_00511A98(void);
extern u8 *func_L03_00348B88(void *);
extern void func_L03_00348C18(void *, void *, void *, s32, s32, s32);
extern u8 *func_L03_003AC868(u8 *, f32);
extern u8 *func_L03_003AC998(u8 *, void *, s32);
extern u8 *func_L03_003ACAD0(u8 *, u8 *);
extern void func_L03_003ACB68(u8 *);
extern s32 func_L03_003AD098_003AAD60(u8 *);
extern void func_L03_003AD580(void);
extern void func_L03_003AD740(s32);
extern void func_L03_003AD8C8(void *, s32);
extern s32 func_L03_003AD910_003AAD60(u8 *, s32, s32, s32, s32);
extern void func_L03_003ADA98(u8 *);
extern void func_L03_003ADB80(u8 *);
extern void func_L03_003ADBC8(u8 *);
extern void func_L03_003ADC00(void *);
extern void func_L03_003ADC48(void);
extern void func_L03_003ADCD8(u8 *);
extern void func_L03_003ADDA0(u8 *);
extern void func_L03_003ADE98(u8 *, s32, s32);
extern void func_L03_003ADF58(u8 *);
extern void func_L03_003AE480(s32);
extern void func_L03_003AE4C0(s32);
extern void func_L03_003AE5F0(s32);
extern void func_L03_003AE810(u8 *);
extern void func_L03_003AE880(void *);
extern void func_L03_003AE9A0(u8 *);
extern void func_L03_003AEA48(u8 *);
extern void func_L03_003AEB98(u8 *);
extern s32 func_L03_0043F5D0(s32, s32, f32);

void func_L03_003AAD60(M_003AAD60 *a0) {
    V_003AAD60 *v = a0->x68;
    vu0_v4 b;
    vu0_v4 a;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    R_003AAD60 *rec;
    s32 i;
    s32 k;

    switch (a0->x20) {
    case 0: {
        s32 id; s32 bits;
        v->x48 = 0;
        func_L03_003ADC00(a0);
        id = a0->xB2;
        if (D_L03_00235A00.spent[(s16)id] != 0
            || (bits = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)],
                (id & 1) ? (bits >> 4) & 7 : bits & 7)) {
            func_L03_003ADA98((u8 *)a0);
        }
        func_L03_003AEB98((u8 *)a0);
        *(vu0_q *)&a = *(vu0_q *)&b = *(vu0_q *)&a0->pos;
        a.z += 1.0f;
        b.z -= 1.0f;
        if (func_003D3CB0(&a, &b, 2, a0, 0) != 0) {
            a0->pos.z = D_L03_001E9220[2];
        }
        v->x2C = 0;
        v->x18 = -1;
        if (v->x24 == -1) {
            v->x24 = func_00382468(1000);
        }
        v->x834 = 0;
        func_L01_004450F0((u8 *)a0, 1, -1);
        break;
    }
    case 1: {
        s32 bits; T_003AAD60 *tab;
        if (func_0038CF38(&D_001A4BE0.pos, &a0->pos) <= 2.5f
            && func_0038DBA0(a0->xF8, func_0038D160(D_001A4BE0.pos.x - a0->pos.x, D_001A4BE0.pos.y - a0->pos.y)) < 1.5707964f
            && D_00142CB4[0] != 0) {
            if (!(D_L03_00235A00.spent[(s16)a0->xB2] != 0
                  || (bits = D_001BBE90[((s16)a0->xB2 >> 1) + (D_001D545C << 10)],
                      (a0->xB2 & 1) ? (bits >> 4) & 7 : bits & 7))
                || ((D_L03_00235A00.spent[(s16)a0->xB2] != 0
                     || (bits = D_001BBE90[((s16)a0->xB2 >> 1) + (D_001D545C << 10)],
                         (a0->xB2 & 1) ? (bits >> 4) & 7 : bits & 7))
                    && (*(s32 *)(D_001D52FC + 0x1A0) & 8))
                || (D_001D545C == 0x18 && v->x68 == 1)) {
                func_L01_00452560(0, 0xD, 0x87A, 1, 0, 0, 0);
                if (D_001D545C == 0x18 && v->x64 == 1) {
                    func_L01_004048D0_003AAD60(func_L03_003AE8E0, a0);
                }
                tab = D_L03_002C49C0;
                if (func_0039AC08(tab[D_001425C0.x14].x10) == 0) {
                    func_0039AA38(tab[D_001425C0.x14].x10);
                    func_L01_0047B948();
                    break;
                }
                if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                    if (D_001D545C == 0x18 || (*(s32 *)(D_001D52FC + 0x1A0) & 8)) {
                        v->x838 = 0;
                    } else {
                        v->x838 = 1;
                    }
                    v->x4C = D_001A4BE0.x1228;
                    D_001A4BE0.x25F8 = 0x14;
                    func_L01_0047B948();
                    D_001A4BE0.x238 = 0x25;
                    func_L01_004450F0((u8 *)a0, 0xD, -1);
                    break;
                }
                if (D_001D545C == 0x18) {
                    if (*(s32 *)(D_001D52FC + 0x1A0) & 1) {
                        if (*(s32 *)(D_001D52FC + 0x1A0) & 2) {
                            if (v->x64 == 1) {
                                func_L01_004450F0((u8 *)a0, 0xA, -1);
                            }
                        }
                    }
                }
            }
        }
        break;
    }
    case 4: {
        s32 n;
        rec = &v->rec[v->x2C];
        if (func_L01_004561B8(a0)) {
            rec->x8 = rec->x10;
            rec->xC = rec->x0;
        }
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x800) {
            func_L03_003ADCD8((u8 *)a0);
            break;
        }
        n = v->x24 + v->x2C + v->x54 * v->x24;
        if (rec->x4 != -1) {
            n += rec->x4;
        }
        func_0013D3D0(n);
        v->x0->x34 &= 0xFF7F;
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
            func_L01_004450F0((u8 *)a0, 9, -1);
            break;
        }
        switch (rec->x17) {
        case 1:
            if (v->x54 % rec->x10 == 1) {
                s32 cnt = v->x54 / rec->x1C;
                if (rec->x18 < cnt) {
                    cnt = rec->x18;
                } else if (cnt < rec->x19) {
                    cnt = rec->x19;
                }
                func_L03_003AD910_003AAD60((u8 *)a0, func_00382498(cnt - 1, cnt), rec->x14, rec->x15, rec->x16);
            }
            break;
        case 0:
        default:
            if (v->x54 % rec->x8 == 1) {
                func_L03_003AD910_003AAD60((u8 *)a0, func_00382498(rec->x19, rec->x18), rec->x14, rec->x15, rec->x16);
            }
            if (v->x54 % rec->x1C == 1) {
                rec->x8 -= 20;
                if (rec->x8 < 60) {
                    rec->x8 = 60;
                }
            }
            break;
        }
        if (((W_003AAD60 *)v->x0->x68)->x8 == 4 || func_L03_003AD098_003AAD60((u8 *)a0)) {
            func_L03_003ACB68((u8 *)a0);
        }
        func_L03_003AD8C8(v->x1C, v->x2C);
        func_L03_003AD580();
        func_L03_003ADE98((u8 *)a0, 0x604040, 0x403030);
        v->x54++;
        func_L03_003AE9A0((u8 *)a0);
        if (v->x50 >= rec->x1A) {
            func_L01_004450F0((u8 *)a0, 5, -1);
        }
        break;
    }
    case 16: {
        if (func_L01_004561B8(a0)) {
            func_L03_003AE480(0);
            v->x38 = (M_003AAD60 *)func_L03_003AC868((u8 *)a0, D_L03_001DE5D4 * 2);
            v->x40 = (M_003AAD60 *)func_L03_003ACAD0((u8 *)a0, (u8 *)v->x38);
            v->x3C = (M_003AAD60 *)func_L03_003AC998((u8 *)a0, v->x38, v->x4);
            v->x44 = 0x55200000;
            v->x4 = 0x20;
            func_L03_003AD740(0);
        }
        func_003C2F58(v->x38, 0x42, &a);
        *(vu0_q *)&b = *(vu0_q *)D_L03_001E24C0;
        func_0038CF68(&c, v->x38->xC0, D_L03_001DE5D4);
        vec_add_ab(&b, &c, &b);
        if (func_0038CF00(&a, &b) <= 0.5f) {
            func_003C2880(v->x0);
            func_003C2880(v->x30);
            func_003C2880(v->x1C);
            v->x0 = v->x38;
            v->x30 = v->x40;
            v->x1C = v->x3C;
            v->x38 = 0;
            v->x40 = 0;
            v->x3C = 0;
            v->x54 = 0;
            v->x50 = 0;
            func_L03_003AE810((u8 *)a0);
            func_L03_003AE480(1);
            func_L01_004450F0((u8 *)a0, 4, -1);
            break;
        }
        vec_sub_ab(&d, &b, &a);
        func_0038CF68(&d, &d, D_L03_001DE5DC * (1.0f / 60.0f * 1.2f));
        func_0038CF68(&e, &d, (D_L03_001DE5DC + 2.0f) * (1.0f / 60.0f * 1.2f));
        vec_add_ab(&v->x0->pos, &v->x0->pos, &e);
        vec_add_ab(&v->x38->pos, &v->x38->pos, &d);
        vec_add_ab(&v->x30->pos, &v->x30->pos, &e);
        vec_add_ab(&v->x40->pos, &v->x40->pos, &d);
        vec_add_ab(&v->x1C->pos, &v->x1C->pos, &e);
        vec_add_ab(&v->x3C->pos, &v->x3C->pos, &d);
        func_L03_003AD8C8(v->x1C, v->x2C - 1);
        func_L03_003AD8C8(v->x3C, v->x2C);
        func_L03_003AD580();
        break;
    }
    case 5: {
        s32 id;
        if (func_L01_004561B8(a0)) {
            func_003A52A0(8, 0, a0);
            func_L01_00456230(v->x30, 1);
            func_L03_003ADC48();
            v->x2C++;
            func_L03_003AE880(a0);
            if (v->x2C >= v->x28) {
                id = a0->xB2;
                if (id & 1) {
                    if (((D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)] >> 4) & 7) != 7)
                        D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)] += 0x10;
                } else {
                    if ((D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)] & 7) != 7)
                        D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)] += 1;
                }
                func_L03_003ADA98((u8 *)a0);
                func_L01_004450F0((u8 *)a0, 6, -1);
            } else {
                if (v->x838 == 1) {
                    v->x834 = 0;
                }
                func_L01_004450F0((u8 *)a0, 0x10, -1);
            }
            return;
        }
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
            func_L01_004450F0((u8 *)a0, 9, -1);
            break;
        }
        func_L03_003AD8C8(v->x1C, v->x2C);
        func_L03_003AD580();
        func_L03_003ADE98((u8 *)a0, 0x406040, 0x304030);
        break;
    }
    case 6: {
        if (func_L01_004561B8(a0)) {
            func_L03_003AE480(0);
            func_L03_003AD740(0);
        }
        func_003C2F58(v->x0, 0x40, &a);
        *(vu0_q *)&b = *(vu0_q *)D_L03_001E24C0;
        if (func_0038CF00(&a, &b) <= 0.5f) {
            func_L01_004450F0((u8 *)a0, 9, -1);
        } else {
            vec_sub_ab(&c, &b, &a);
            func_0038CF68(&c, &c, (D_L03_001DE5DC + D_L03_001DE5DC) * (1.0f / 60.0f * 1.2f));
            vec_add_ab(&v->x0->pos, &v->x0->pos, &c);
            vec_add_ab(&v->x30->pos, &v->x30->pos, &c);
            vec_add_ab(&v->x1C->pos, &v->x1C->pos, &c);
            func_L03_003AD580();
        }
        func_L03_003ADE98((u8 *)a0, 0x406040, 0x304030);
        break;
    }
    case 19: {
        if (func_L01_004561B8(a0)) {
            func_L03_003AEA48((u8 *)a0);
        }
        func_003C2F58(v->x0, 0x41, &b);
        func_L01_00404808(func_L03_003AEB30, a0);
        break;
    }
    case 7: {
        if (func_L01_004561B8(a0)) {
            func_003A52A0(9, 0, a0);
            func_L03_003AE4C0(1);
            if (v->x838 == 1) {
                v->x834 += 10;
                if (v->x834 > 50) {
                    v->x834 = 50;
                } else if (v->x834 < 0) {
                    v->x834 = 0;
                }
            }
            if (D_001D545C == 3) {
                if (D_L03_001DE5C4 >= 3) {
                    func_L01_0041A5B0(0x10A9, 0xE6);
                    D_L03_001DF2D0[0] = 0.5f;
                    func_L03_003AE5F0(1);
                    D_L03_001DE5C4 = 0;
                } else if (D_L03_001DE5C0 >= 3) {
                    func_L01_0041A5B0(0x10A8, 0xE5);
                    D_L03_001DF2D0[0] = 0.5f;
                    func_L03_003AE5F0(1);
                    D_L03_001DE5C0 = 0;
                }
            }
        }
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
            func_L01_0041A6E0();
            func_L01_004450F0((u8 *)a0, 9, -1);
            break;
        }
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x40) {
            W_003AAD60 *w;
            func_L01_0041A6E0();
            func_L03_003AE5F0(0);
            D_L03_001DF2D0[0] = 0.0f;
            func_L03_003AD740(0);
            func_L03_003ADB80((u8 *)a0);
            w = v->x0->x68;
            w->x8 = func_00382468(2);
            func_L01_004606A8(D_001D52FC);
            func_L03_003AE4C0(0);
            func_L01_004450F0((u8 *)a0, 8, -1);
            break;
        }
        func_L03_003AD8C8(v->x1C, v->x2C);
        func_L03_003AD580();
        func_L01_00404808(func_L03_003AEC58, a0);
        func_L03_003ADE98((u8 *)a0, 0x202060, 0x202040);
        break;
    }
    case 8: {
        if (func_L03_003AD098_003AAD60((u8 *)a0)) {
            func_003C4138(&v->x14, 1.0f, D_L03_001DE600 * (1.0f / 60.0f * 1.2f));
            D_L03_001DF2D0[0] = v->x14;
            if (1.0f <= v->x14) {
                func_L03_003ADBC8((u8 *)a0);
                func_L01_004450F0((u8 *)a0, 3, -1);
            }
        }
        func_L03_003AD8C8(v->x1C, v->x2C);
        func_L03_003AD580();
        func_L03_003ADE98((u8 *)a0, 0x604040, 0x403030);
        break;
    }
    case 9: {
        s32 t;
        func_L03_003ADC00(a0);
        a0->x30 = 0x40;
        D_L03_001DF370 = v->x58;
        D_L03_001DF374 = v->x5C;
        D_L03_001DF364 = v->x60;
        D_L03_001DF365 = v->x61;
        D_L03_001DF366 = v->x62;
        v->x2C = 0;
        func_L03_003AE880(a0);
        func_L03_003AD740(1);
        func_L01_00504E38(0);
        func_003C2F58(a0, 0, &D_001A4BE0.pos);
        if (v->x18 >= 0x34) {
            v->x18 = -1;
        }
        t = v->x18;
        if (t != -1) {
            u8 *s = D_001A30B0 + t * 0x80;
            if (*(M_003AAD60 **)(s + 0xDC) == a0 && s[0xD0] != 0) {
                func_003A4F28(t);
            }
        }
        v->x18 = -1;
        func_003C2880(v->x0);
        func_003C2880(v->x1C);
        func_003C2880(v->x30);
        D_L03_001DE5C4 = 0;
        D_001A4BE0.x25F8 = v->x4C;
        D_L03_001DE5C0 = 0;
        func_L01_003F1740_003AAD60(a0);
        func_L01_0045F1E8(v->x848, v->x844);
        func_0013C1D0(0x4D);
        func_L01_004450F0((u8 *)a0, 0xB, -1);
        break;
    }
    case 11: {
        func_003A0F98(0, 0);
        func_L01_0047B420();
        func_L01_0047B990();
        func_L01_00479280();
        func_L01_004450F0((u8 *)a0, 1, -1);
        break;
    }
    case 13: {
        s32 r;
        D_001A4BE0.x238 = 0x25;
        if (func_L01_004561B8(a0)) {
            func_0038D000(&b, &D_L03_001DE610, a0->xC0);
            vec_add_ab(&b, &b, &a0->pos);
            func_L01_00511A40(&b, 0, func_0038DAB8(a0->xF8, 3.1415927f));
        }
        r = func_L01_00511A98();
        if (r == 2 && D_001A4BE0.x25C0[0x42] == D_001A4BE0.x25C0[0x43]) {
            T_003AAD60 *tab = D_L03_002C49C0;

            if (func_0039AC08(tab[D_001425C0.x14].x10) == 0) {
                func_0039AA38(tab[D_001425C0.x14].x10);
            }
            D_001A4BE0.x25F8 = 0x14;
            func_L01_0047B948();
            func_L01_004450F0((u8 *)a0, 0xE, -1);
            break;
        }
        if (a0->x96++ >= 0xFB) {
            func_L01_00504E38(0);
            D_001A4BE0.x25F8 = v->x4C;
            func_L01_004450F0((u8 *)a0, 1, -1);
            break;
        }
        if (r == 0) {
            D_001A4BE0.x25F8 = v->x4C;
            func_L01_004450F0((u8 *)a0, 1, -1);
        }
        break;
    }
    case 14: {
        D_001A4BE0.x238 = 0x25;
        if (func_L01_004561B8(a0)) {
            func_L01_00479200();
            func_L01_0047B948();
            func_L01_0047B3D8();
            func_L01_005003D0(0x74, 1);
            func_L01_0050FB40(0x4B, 0, 0.0f);
            vec_sub_ab(&b, D_L03_001E24C0, &D_001A4BE0.pos);
            func_0038D000(&b, &b, D_001A4BE0.x40);
            func_L01_003EB438(0, D_L03_001E24C0, D_L03_001E24C0, 3, 100, 0);
            func_003A52A0(0xC, 0, a0);
            v->x14 = 0.0f;
        }
        func_0038D000(&b, &D_L03_001DE610, a0->xC0);
        vec_add_ab(&b, &b, &a0->pos);
        vec_sub_ab(&D_001A4BE0.x100, &b, &D_001A4BE0.pos);
        D_001A4BE0.x100.z = 0.0f;
        func_003C4BB0(&D_001A4BE0.x100, 0.0125f * 1.2f);
        func_L01_00448690(D_001A4BE0.x98, 0, func_0038DAB8(a0->xF8, 3.1415927f), 0.020943953f);
        D_001A4BE0.x222 = 3;
        if (D_001A4BE0.xC08 & 2) {
            func_L01_0050FB40(0x4C, 0, 6.0f);
        }
        if (D_001A4BE0.x25C4 != 0x74) {
            func_L01_003EB5E0(0, 3);
            D_001A4BE0.x25F8 = v->x4C;
            func_L01_004450F0((u8 *)a0, 1, -1);
        }
        func_0038D000(&a, &D_L03_001DE620, &D_001A4BE0);
        vec_add_ab(&a, &a, &D_001A4BE0.pos);
        qzero(&c);
        func_003C2F58(a0, 1, &d);
        c.z = func_0038D160(d.x - a.x, d.y - a.y);
        c.y = -func_0038D160(func_0038CF38(&a, &d), d.z - a.z);
        func_L01_003EB350(0, &a);
        func_L01_003EB3C0(0, &c);
        if (a0->x96++ >= 0x33) {
            func_L01_004450F0((u8 *)a0, 0xF, -1);
        }
        break;
    }
    case 15: {
        D_001A4BE0.x238 = 0x25;
        func_003C2F58(a0, 0, &b);
        if (D_001A4BE0.xC08 & 2) {
            func_L01_0050FB40(0x4C, 0, 0.0f);
        }
        if (func_L01_004561B8(a0)) {
            D_L03_001E28E4[0] = 0.017453292f;
            func_00382810(0, 0x21, 1, 0.017453292f, 0.005f, 0.2f, 0.0f);
        }
        D_001A4BE0.x222 = 3;
        if (a0->x96++ < 0x12) break;
        func_003C4138(&v->x14, 1.0f, 0.14000001f);
        D_L03_001DF2D0[0] = v->x14;
        if (a0->x96 < 0x22) break;
        D_L03_001E28E4[0] = 1.1100293f;
        func_00382810(0, 1, 0, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_L01_003EB5E0(0, 3);
        func_L01_004450F0((u8 *)a0, 2, -1);
        break;
    }
    case 3: {
        if (func_L01_004561B8(a0)) {
            v->x830 = 0;
            if (D_001CCFD0.x76 != 6 && D_001CCFD0.x76 != 7) {
                D_001CCFD0.x76 = 5;
            }
            if (D_001CCFD0.x9E != 6 && D_001CCFD0.x9E != 7) {
                D_001CCFD0.x9E = 5;
            }
            func_L01_0041A6E0();
        }
        v->x0->x34 &= 0xFF7F;
        v->x1C->x34 &= 0xFF7F;
        func_L03_003ADE98((u8 *)a0, 0x604040, 0x403030);
        func_L03_003AD8C8(v->x1C, v->x2C);
        func_L03_003AD580();
        func_003C4138(&v->x14, 0.0f, D_L03_001DE600 * (1.0f / 60.0f * 1.2f));
        D_L03_001DF2D0[0] = v->x14;
        if (v->x14 == 0.0f) {
            if (D_001D545C == 3 && D_001A7E18.xE04 == 0 && D_00143954[0] != 0) {
                if (func_L01_0041A5B0(0x15D6, 0x12B)) {
                    if (D_001A7E18.x10608 == 0) {
                        D_001A7E18.x10608 = 1;
                    }
                    func_L03_003AE5F0(1);
                    func_L01_004450F0((u8 *)a0, 0x11, -1);
                } else if (++v->x830 >= 0x1A) {
                    func_L01_004450F0((u8 *)a0, 4, -1);
                }
            } else {
                func_L01_004450F0((u8 *)a0, 4, -1);
            }
        }
        break;
    }
    case 17: {
        if ((D_L03_002E52F0.x0 == 0 && D_L03_002E52F0.x24 == -1)
            || (*(unsigned long *)(D_001D52FC + 0x1A0) & 0xF000000000)) {
            func_L01_0041A6E0();
            func_L01_004606A8(D_001D52FC);
            func_L03_003AE5F0(0);
            D_L03_001DF2D0[0] = 0.0f;
            func_L01_004450F0((u8 *)a0, 4, -1);
        }
        break;
    }
    case 2: {
        if (func_003A0EC0(7, 1, a0, 4, 0) == 0) {
            a0->x30 = 0xFF;
            a0->x34 &= 0xFF7F;
            v->x0 = (M_003AAD60 *)func_L03_003AC868((u8 *)a0, D_L03_001DE5D4);
            v->x30 = (M_003AAD60 *)func_L03_003ACAD0((u8 *)a0, (u8 *)v->x0);
            v->x4 = 0x20;
            v->x1C = (M_003AAD60 *)func_L03_003AC998((u8 *)a0, v->x0, 0x20);
            v->x58 = D_L03_001DF370;
            v->x5C = D_L03_001DF374;
            D_L03_001DF370 = 100.0f;
            D_L03_001DF374 = 255.0f;
            v->x60 = D_L03_001DF364;
            v->x61 = D_L03_001DF365;
            v->x62 = D_L03_001DF366;
            D_L03_001DF364 = 0x3C;
            D_L03_001DF365 = 0x3F;
            D_L03_001DF366 = 0x41;
            func_L03_003ADF58((u8 *)a0);
            v->x848 = D_001CCFD0.x3C == -1 ? D_001CCFD0.x48 : D_001CCFD0.x3C;
            func_L01_0045F1E8(v->x840, v->x844);
            func_0013C1A0(0x4D);
            func_L01_004450F0((u8 *)a0, 3, -1);
        } else {
            D_L03_001DF2D0[0] = 0.0f;
            func_L01_004450F0((u8 *)a0, 1, -1);
        }
        break;
    }
    case 18: {
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x800) {
            func_L03_003ADDA0((u8 *)a0);
        }
        break;
    }
    case 10: {
        M_003AAD60 *m;
        if (func_L01_004561B8(a0)) {
            v->x34 = (M_003AAD60 *)func_L03_00348B88(a0);
            func_L03_00348C18(v->x34, &v->x24, D_L03_001DE630, 0, 1, 1000000);
            func_L03_00348C18(v->x34, &v->x28, D_L03_001DE640, 0, 1, 4);
            for (i = 0; i < 4; i++) {
                s32 *p = &v->rec[i].x10;
                func_L03_00348C18(v->x34, p, D_L03_001DE650, 4, *p, *p);
                func_L03_00348C18(v->x34, &v->rec[i].x0, D_L03_001DE668, 1, 1, 4);
                func_L03_00348C18(v->x34, &v->rec[i].x4, D_L03_001DE678, 0, -1, 1000000);
                func_L03_00348C18(v->x34, &v->rec[i].x10, D_L03_001DE688, 0, 1, 1000);
                func_L03_00348C18(v->x34, &v->rec[i].x14, D_L03_001DE698, 2, 0, 100);
                func_L03_00348C18(v->x34, &v->rec[i].x15, D_L03_001DE6A8, 2, 10, 100);
                func_L03_00348C18(v->x34, &v->rec[i].x16, D_L03_001DE6B8, 2, 0, 100);
                func_L03_00348C18(v->x34, &v->rec[i].x17, D_L03_001DE6C8, 2, 0, 1);
                func_L03_00348C18(v->x34, &v->rec[i].x18, D_L03_001DE6D8, 2, 1, 8);
                func_L03_00348C18(v->x34, &v->rec[i].x19, D_L03_001DE6E8, 2, 0, 7);
                func_L03_00348C18(v->x34, &v->rec[i].x1A, D_L03_001DE6F8, 2, 0, 100);
                func_L03_00348C18(v->x34, &v->rec[i].x1C, D_L03_001DE708, 0, 0, 1000);
            }
        }
        func_L01_00452560(0, 1, 0, 1, 0, 0, 0);
        m = v->x34;
        if (m == 0 || m->xAA != 0x118A || m->x20 == 0xFE || m->x20 == 0xFD) {
            func_L01_004450F0((u8 *)a0, 1, -1);
        }
        break;
    }
    }
    v->xD0 = (D_L03_001DF4C0 % 359) * 0.017453292f;
    func_L01_0044E850(a0, v->x70, 3, 0.036f * 1.2f, 0.36f * 1.2f);
    if (a0->x31 != 0) {
        s32 period = 100;
        k = D_L03_001DF4C0 % period;
        a0->x78 = func_L03_0043F5D0(0x404040, 0x202020, k * 6.2831855f / period - 3.1415927f);
    }
    a0->x96++;
}
/* localdecomp:end func_L03_003AAD60 */

/* localdecomp:start func_L03_003AC868 */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_003C7C38(void *);
extern u8 D_L03_001E24C0[];
__asm__(".extern D_L03_001DE5E0, 8");
extern u8 D_L03_001DE5E0[8];
__asm__(".extern D_L03_001DE5F0, 8");
extern u8 D_L03_001DE5F0[8];
extern u8 D_L03_001F02C0[];

u8 *func_L03_003AC868(u8 *a0, f32 t) {
    u8 *m = func_003C24B0(0x1C01, 0x80);
    u8 *v;
    vu0_v4 d;
    u8 *mat;
    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        v = *(u8 **)(m + 0x68);
        mat = m + 0xC0;
        *(long *)(m + 0x38) = *(long *)(a0 + 0x38);
        *(vu0_q *)(m + 0x10) = *(vu0_q *)(D_L03_001E24C0 + 0x00);
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(D_L03_001E24C0 + 0x10);
        *(s32 *)(m + 0xF0) = 0;
        *(f32 *)(v + 4) = *(f32 *)(v + 0) = *(f32 *)(m + 0xF0);
        *(s32 *)(v + 8) = 4;
        func_0038D308(mat, m + 0xF0);
        func_0038CF68(&d, mat, t);
        vec_add_ba(m + 0x10, &d, m + 0x10);
        *(vu0_q *)(D_L03_001F02C0 + 0x10) = *(vu0_q *)D_L03_001DE5E0;
        qzero(D_L03_001F02C0 + 0x30);
        *(vu0_q *)(D_L03_001F02C0 + 0x00) = *(vu0_q *)D_L03_001DE5F0;
        qzero(D_L03_001F02C0 + 0x20);
        func_003C6F90(m, 0x604040, 0xE, 0xE, 0xE);
        *(u16 *)(m + 0x34) &= 0xFF7F;
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L03_003AC868 */

/* localdecomp:start func_L03_003AC998 */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_003C7C38(void *);
extern u8 D_L03_001E24C0[];

u8 *func_L03_003AC998(u8 *a0, void *a1, s32 a2) {
    u8 *m = func_003C24B0(0x1C40, 0x80);
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 d;
    if (m != 0) {
        if (a1 != 0) {
            func_003C2F58(a1, 0x20, m + 0x10);
        }
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(D_L03_001E24C0 + 0x10);
        func_0038D308(m + 0xC0, m + 0xF0);
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a0;
        *(long *)(m + 0x38) = *(long *)(a0 + 0x38);
        *(u16 *)(m + 0x34) &= 0xFF7F;
        func_003C6F90(m, 0x505050, 0xE, 0xE, 0xE);
        func_003C2F58(a1, a2 - 0x20, &p);
        func_003C2F58(a1, a2, &q);
        vec_sub_ba(&d, &q, &p);
        func_0038CF68(&d, &d, 0.75f);
        vec_add_ab(m + 0x10, m + 0x10, &d);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L03_003AC998 */

/* localdecomp:start func_L03_003ACAD0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);

u8 *func_L03_003ACAD0(u8 *a0, u8 *a1) {
    u8 *m = func_003C24B0(0x1C4F, 0x80);
    if (m != 0) {
        *(u8 **)(m + 0xB8) = a0;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        *(long *)(m + 0x38) = *(long *)(a1 + 0x38);
        *(u8 **)(*(u8 **)(m + 0x68) + 0x20) = a1;
        *(u128_t *)(m + 0x10) = *(u128_t *)(a1 + 0x10);
        *(u128_t *)(m + 0xF0) = *(u128_t *)(a1 + 0xF0);
        func_0038D308(m + 0xC0, m + 0xF0);
    }
    return m;
}
/* localdecomp:end func_L03_003ACAD0 */

/* localdecomp:start func_L03_003ACB68 */
extern s32 func_L01_004606E8_003ACB68(s32, s32, s32, s32);
extern void func_L01_004AAC98_003ACB68(s32, s32, s32, s32);
extern void func_L03_003B8DF8_003ACB68(u8 *, s32, f32);
extern void func_L03_003B9688_003ACB68(u8 *, s32, f32);
extern void func_L01_004606A8_003ACB68(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern u8 D_1A30B0[];
extern u8 *D_001D52FC;
__asm__(".extern D_L03_001DE608_003ACB68, 4");
extern f32 D_L03_001DE608_003ACB68;
__asm__(".extern D_L03_001DE60C_003ACB68, 4");
extern f32 D_L03_001DE60C_003ACB68;

static inline void sel_sound(s32 *s, u8 *a0, s32 dir) {
    s32 h = s[6];
    u8 *e;
    if (h == -1 || (e = D_1A30B0 + h * 0x80, *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
        s[6] = func_003A52A0(dir, 4, a0);
    }
}

void func_L03_003ACB68(u8 *a0) {
    s32 *s = *(s32 **)(a0 + 0x68);
    u8 *p;
    s32 *r;
    f32 f;
    s32 flags;
    s32 h;

    if (func_L01_004606E8_003ACB68(0x60, 0x3C, 0, 0)) {
        func_L01_004AAC98_003ACB68(3, 0, s[0], 0x1AE0);
        func_L03_003B8DF8_003ACB68(a0, s[1], D_L03_001DE608_003ACB68);
        func_L01_004606A8_003ACB68((s32)D_001D52FC);
    } else if (func_L01_004606E8_003ACB68(0x80, 0x3C, 0, 0)) {
        func_L01_004AAC98_003ACB68(5, 0, s[0], 0x1AE0);
        func_L03_003B9688_003ACB68(a0, s[1], D_L03_001DE60C_003ACB68);
        func_L01_004606A8_003ACB68((s32)D_001D52FC);
    }
    p = D_001D52FC;
    r = *(s32 **)(s[0] + 0x68);
    f = *(f32 *)(p + 0x148);
    if (*(s32 *)(p + 0x1D8) != 0) {
        if (f < -0.699999988f) {
            sel_sound(s, a0, 0);
            s[1] += 4;
            if (s[1] >= 0x40) s[1] -= 0x20;
            *(f32 *)r = ((s[1] - 0x20) / 4) * 0x2D;
            r[2] = 1;
        } else if (0.699999988f < f) {
            sel_sound(s, a0, 1);
            s[1] -= 4;
            if (s[1] < 0x20) s[1] += 0x20;
            *(f32 *)r = ((s[1] - 0x20) / 4) * 0x2D;
            r[2] = 0;
        }
    } else {
        flags = *(s32 *)(p + 0x1A0);
        if (flags & 0x2000) {
            sel_sound(s, a0, 1);
            s[1] -= 4;
            if (s[1] < 0x20) s[1] += 0x20;
            *(f32 *)r = ((s[1] - 0x20) / 4) * 0x2D;
            r[2] = 0;
        } else if (flags & 0x8000) {
            sel_sound(s, a0, 0);
            s[1] += 4;
            if (s[1] >= 0x40) s[1] -= 0x20;
            *(f32 *)r = ((s[1] - 0x20) / 4) * 0x2D;
            r[2] = 1;
        } else if (flags & 8) {
            sel_sound(s, a0, 1);
            s[1] -= 0x10;
            if (s[1] < 0x20) s[1] += 0x20;
            *(f32 *)r = ((s[1] - 0x20) / 4) * 0x2D;
            r[2] = 2;
        } else if (flags & 4) {
            sel_sound(s, a0, 0);
            s[1] += 0x10;
            if (s[1] >= 0x40) s[1] -= 0x20;
            *(f32 *)r = ((s[1] - 0x20) / 4) * 0x2D;
            r[2] = 3;
        } else {
            if (s[6] >= 0x34) s[6] = -1;
            h = s[6];
            if (h != -1) {
                u8 *e = D_1A30B0 + h * 0x80;
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_003A4F28(h);
                }
            }
            s[6] = -1;
        }
    }
}
/* localdecomp:end func_L03_003ACB68 */

/* localdecomp:start func_L03_003AD030 */
f32 func_L03_003AD030(f32 a, f32 b) {
    a = a + b;
    if (a < 0.0f) {
        a += 360.0f;
    } else if (359.0f < a) {
        a -= 360.0f;
    }
    return a;
}
/* localdecomp:end func_L03_003AD030 */

/* localdecomp:start func_L03_003AD098 */
typedef struct B_003AD098 {
    u8 pad0[0xC0];
    u8 xC0[0x30];
    f32 fF0;
} B_003AD098;

typedef struct A_003AD098 {
    B_003AD098 *x0;
    u8 pad4[0x14];
    s32 x18;
    void *x1C;
    u8 pad20[0x48 - 0x20];
    f32 f48;
    u8 pad4C[0x150 - 0x4C];
    f32 f150;
    u8 pad154[0x1D0 - 0x154];
    f32 f1D0;
} A_003AD098;

typedef struct C_003AD098 {
    f32 f0;
    f32 f4;
    s32 x8;
} C_003AD098;

typedef struct G_003AD098 {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xDC - 0xD1];
    void *xDC;
} G_003AD098;

typedef struct O_003AD098 {
    u8 pad0[0x68];
    A_003AD098 *x68;
} O_003AD098;

extern u8 D_1A30B0[];
extern f32 D_L03_001DE5C8_003AD098;
__asm__(".extern D_L03_001DE5C8_003AD098, 4");
extern f32 func_L03_003AD030_003AD098(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0044E850_003AD098(void *, void *, s32, f32, f32);
extern void func_0038D308(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);

/* Steps a two-joint opening or closing motion by direction (cases 0 to 3): plays a sound if none is
 * playing, advances the joint angle and rotation through func_L03_003AD030_003AD098, and returns 1 and plays
 * a final sound when the target angle is reached. */
s32 func_L03_003AD098(O_003AD098 *o) {
    A_003AD098 *a = o->x68;
    C_003AD098 *c = *(C_003AD098 **)((u8 *)a->x0 + 0x68);

    switch (c->x8) {
    case 0:
        if (a->x18 == -1 || ((G_003AD098 *)(D_1A30B0 + (a->x18 << 7)))->xDC != o || ((G_003AD098 *)(D_1A30B0 + (a->x18 << 7)))->bD0 == 0) {
            a->x18 = func_003A52A0(1, 4, o);
        }
        a->f48 = func_L03_003AD030_003AD098(a->f48, 10.0f) ;
        a->f150 = func_0038DAB8(0.0f, a->f48 * 0.017453292f);
        func_L01_0044E850_003AD098(a->x1C, (u8 *)a + 0xF0, 0, 2.88f, 2.88f);
        a->f1D0 = func_0038DAB8(0.0f, a->f48 * 0.017453292f);
        func_L01_0044E850_003AD098(a->x1C, (u8 *)a + 0x170, 1, 2.88f, 2.88f);
        c->f4 = func_L03_003AD030_003AD098(c->f4, -D_L03_001DE5C8_003AD098);
        break;
    case 1:
        if (a->x18 == -1 || ((G_003AD098 *)(D_1A30B0 + (a->x18 << 7)))->xDC != o || ((G_003AD098 *)(D_1A30B0 + (a->x18 << 7)))->bD0 == 0) {
            a->x18 = func_003A52A0(0, 4, o);
        }
        a->f48 = func_L03_003AD030_003AD098(a->f48, -10.0f) ;
        a->f150 = func_0038DAB8(0.0f, a->f48 * 0.017453292f);
        func_L01_0044E850_003AD098(a->x1C, (u8 *)a + 0xF0, 0, 2.88f, 2.88f);
        a->f1D0 = func_0038DAB8(0.0f, a->f48 * 0.017453292f);
        func_L01_0044E850_003AD098(a->x1C, (u8 *)a + 0x170, 1, 2.88f, 2.88f);
        c->f4 = func_L03_003AD030_003AD098(c->f4, D_L03_001DE5C8_003AD098);
        break;
    case 2:
        if (a->x18 == -1 || ((G_003AD098 *)(D_1A30B0 + (a->x18 << 7)))->xDC != o || ((G_003AD098 *)(D_1A30B0 + (a->x18 << 7)))->bD0 == 0) {
            a->x18 = func_003A52A0(1, 4, o);
        }
        a->f48 = func_L03_003AD030_003AD098(a->f48, 20.0f) ;
        a->f150 = func_0038DAB8(0.0f, a->f48 * 0.017453292f);
        func_L01_0044E850_003AD098(a->x1C, (u8 *)a + 0xF0, 0, 2.88f, 2.88f);
        a->f1D0 = func_0038DAB8(0.0f, a->f48 * 0.017453292f);
        func_L01_0044E850_003AD098(a->x1C, (u8 *)a + 0x170, 1, 2.88f, 2.88f);
        c->f4 = func_L03_003AD030_003AD098(c->f4, -D_L03_001DE5C8_003AD098 * 2.0f);
        break;
    case 3:
        if (a->x18 == -1 || ((G_003AD098 *)(D_1A30B0 + (a->x18 << 7)))->xDC != o || ((G_003AD098 *)(D_1A30B0 + (a->x18 << 7)))->bD0 == 0) {
            a->x18 = func_003A52A0(0, 4, o);
        }
        a->f48 = func_L03_003AD030_003AD098(a->f48, -20.0f) ;
        a->f150 = func_0038DAB8(0.0f, a->f48 * 0.017453292f);
        func_L01_0044E850_003AD098(a->x1C, (u8 *)a + 0xF0, 0, 2.88f, 2.88f);
        a->f1D0 = func_0038DAB8(0.0f, a->f48 * 0.017453292f);
        func_L01_0044E850_003AD098(a->x1C, (u8 *)a + 0x170, 1, 2.88f, 2.88f);
        c->f4 = func_L03_003AD030_003AD098(c->f4, D_L03_001DE5C8_003AD098 * 2.0f);
        break;
    default:
        break;
    }
    a->x0->fF0 = func_0038DAB8(0.0f, c->f4 * 0.017453292f);
    func_0038D308((u8 *)a->x0 + 0xC0, (u8 *)a->x0 + 0xF0);
    if (c->f4 == c->f0) {
        c->x8 = 4;
        func_003A52A0(2, 0, o);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L03_003AD098 */

/* localdecomp:start func_L03_003AD510 */
extern void func_L03_003ADC48(void);
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);

s32 func_L03_003AD510(u8 *a0) {
    u8 *v;
    if (*(s16 *)(a0 + 170) != 6880) {
        return 0;
    }
    v = *(u8 **)(a0 + 104);
    if (*(s32 *)(v + 80) >= v[*(s32 *)(v + 44) * 32 + 522]) {
        return 0;
    }
    func_L03_003ADC48();
    func_L01_004450F0(a0, 7, -1);
    return 1;
}
/* localdecomp:end func_L03_003AD510 */

/* localdecomp:start func_L03_003AD580 */
extern void func_003C7C38(void *);
extern u8 *D_L03_001DF9A0;
extern u8 *D_L03_001DF9A4;
typedef struct { void (*a)(void); void (*b)(void); } Cb_3AD580;
typedef struct { u8 pad[0x24E10]; Cb_3AD580 cb[3]; } G_3AD580;
extern G_3AD580 *D_001D67C8;

void func_L03_003AD580(void) {
    u8 *p;
    s32 i;
    u16 u;
    for (p = D_L03_001DF9A0; p <= D_L03_001DF9A4; p += 0x100) {
        if (p != 0 && p[0x20] != 0xFE && p[0x20] != 0xFF) {
            u = *(u16 *)(p + 0xAA);
            if ((u32)(u - 0x1C04) < 3 || (s16)u == 0x1C16 || (s16)u == 0x1C19 || (s16)u == 0x1C01 || (s16)u == 0x1C40 || (s16)u == 0x1C3F || (s16)u == 0x1C3E || (s16)u == 0x1C4F) {
                (*(void (**)(u8 *))(p + 0x64))(p);
                if (*(s32 *)(p + 0x24) != 0) {
                    func_003C7C38(p);
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (D_001D67C8->cb[i].a != 0) {
            (&D_001D67C8->cb[i])->a();
        }
        if (D_001D67C8->cb[i].b != 0) {
            (&D_001D67C8->cb[i])->b();
        }
    }
}
/* localdecomp:end func_L03_003AD580 */

/* localdecomp:start func_L03_003AD740 */
extern u8 *D_L03_001DF9A0_003AD740;
extern u8 *D_L03_001DF9A4_003AD740;
extern void func_003C2880(void *);

void func_L03_003AD740(s32 a0) {
    u8 *p;
    for (p = D_L03_001DF9A0_003AD740; p <= D_L03_001DF9A4_003AD740; p += 0x100) {
        if (p != 0 && p[0x20] != 0xFE && p[0x20] != 0xFF) {
            if (*(s16 *)(p + 0xAA) == 0x1C04 || *(s16 *)(p + 0xAA) == 0x1C05 || *(s16 *)(p + 0xAA) == 0x1C06 || *(s16 *)(p + 0xAA) == 0x1C16 || *(s16 *)(p + 0xAA) == 0x1C19 || *(s16 *)(p + 0xAA) == 0x1C01 || *(s16 *)(p + 0xAA) == 0x1C40 || *(s16 *)(p + 0xAA) == 0x1C3F || *(s16 *)(p + 0xAA) == 0x1C3E || *(s16 *)(p + 0xAA) == 0x1C4F) {
                if (*(s16 *)(p + 0xAA) == 0x1C19) {
                    p[0x20] = 1;
                } else if (*(s16 *)(p + 0xAA) != 0x1C01 && *(s16 *)(p + 0xAA) != 0x1C40 && *(s16 *)(p + 0xAA) != 0x1C3F && *(s16 *)(p + 0xAA) != 0x1C4F && (*(s16 *)(p + 0xAA) != 0x1C3E || a0 == 1)) {
                    func_003C2880(p);
                }
            }
        }
    }
}
/* localdecomp:end func_L03_003AD740 */
