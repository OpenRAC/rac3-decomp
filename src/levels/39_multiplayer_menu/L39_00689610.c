#include "common.h"

/* localdecomp:start func_L39_00689610 */
extern s32 D_L39_003D2880[];
extern void func_L01_00516AA0();
void func_L39_00689610(void) {
    s32 i;
    s32 *p;
    if (D_L39_003D2880[0x260 / 4] > 0) {
        p = &D_L39_003D2880[0x260 / 4];
        for (i = 5; i >= 0; i--) {
            func_L01_00516AA0(*p, 1, 0);
            p++;
        }
    }
}
/* localdecomp:end func_L39_00689610 */

/* localdecomp:start func_L39_00689670 */
typedef struct S_00689670 S_00689670;
typedef struct {
    u8 pad0[0x1C];
    s32 (*unk1C)(S_00689670 *, s32, s32);
} VT_00689670;
struct S_00689670 {
    u8 pad0[0x10];
    void *unk10;
    u8 pad14[0x50 - 0x14];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    VT_00689670 *unk60;
    u8 pad64[0x10C - 0x64];
    s32 unk10C;
    S_00689670 *unk110[0x60];
    s32 unk290;
    s32 unk294;
    s32 unk298;
    u8 pad29C[8];
    s32 unk2A4;
};
typedef struct {
    s32 unk0;
} Item_00689670;
typedef struct {
    u8 pad0[0x38];
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    u8 pad48[4];
    s32 unk4C;
    Item_00689670 *unk50[0x60];
} Src_00689670;
extern s32 func_L01_00521C90(s32, s32);
extern void *func_L39_0067EE40(void *, void *);
extern void *func_L39_0067FAE8(void *, void *);
extern void *func_L39_0067FE78(void *, void *);
extern void *func_L39_006805A0(void *, void *);
extern void *func_L39_00680F08(void *, void *);
extern void *func_L39_00685BC8(void *, void *);
extern void *func_L39_00681758(void *, void *);
extern void *func_L39_00682840(void *, void *);
extern void *func_L39_00683550(void *, void *);
extern void *func_L39_00682FC0(void *, void *);
extern void *func_L39_00683A30(void *, void *);
extern void *func_L39_00684860(void *, void *);
extern void *func_L39_006844E0(void *, void *);
extern s32 func_L39_0068B178(void *);
extern s32 func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_0067F030(void *);
extern void func_L39_0067F060(s32, s32);
extern void func_L39_0067F050(s32);
extern void func_L39_006888B8(void);
extern u8 D_001DC30A_sda;
void func_L39_00689670(S_00689670 *p, Src_00689670 *q) {
    s32 buf;
    s32 i;
    s32 n;
    buf = p->unk2A4;
    p->unk50 = q->unk38;
    p->unk54 = q->unk3C;
    p->unk58 = q->unk40;
    p->unk5C = q->unk44;
    p->unk10C = q->unk4C;
    for (i = 0; i < p->unk10C; i++) {
        if (q->unk50[i]->unk0 == 0) {
            p->unk110[i] = func_L39_0067EE40((void *)func_L01_00521C90(0x64, buf), q->unk50[i]);
            buf += 0x64;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
        } else if (q->unk50[i]->unk0 == 1) {
            p->unk110[i] = func_L39_0067FAE8((void *)func_L01_00521C90(0x6C, buf), q->unk50[i]);
            buf += 0x6C;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
        } else if (q->unk50[i]->unk0 == 2) {
            p->unk110[i] = func_L39_0067FE78((void *)func_L01_00521C90(0x74, buf), q->unk50[i]);
            buf += 0x74;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
        } else if (q->unk50[i]->unk0 == 3) {
            p->unk110[i] = func_L39_006805A0((void *)func_L01_00521C90(0x1494, buf), q->unk50[i]);
            buf += 0x1494;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
        } else if (q->unk50[i]->unk0 == 4) {
            p->unk110[i] = func_L39_00680F08((void *)func_L01_00521C90(0x84, buf), q->unk50[i]);
            buf += 0x84;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 1, 0);
        } else if (q->unk50[i]->unk0 == 12) {
            p->unk110[i] = func_L39_00685BC8((void *)func_L01_00521C90(0x84, buf), q->unk50[i]);
            buf += 0x84;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 1, 0);
        } else if (q->unk50[i]->unk0 == 5) {
            p->unk110[i] = func_L39_00681758((void *)func_L01_00521C90(0x105A4, buf), q->unk50[i]);
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
            buf += 0x105A4;
        } else if (q->unk50[i]->unk0 == 6) {
            p->unk110[i] = func_L39_00682840((void *)func_L01_00521C90(0xB8, buf), q->unk50[i]);
            buf += 0xB8;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
        } else if (q->unk50[i]->unk0 == 11) {
            p->unk110[i] = func_L39_00683550((void *)func_L01_00521C90(0x78, buf), q->unk50[i]);
            buf += 0x78;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 1, 0);
        } else if (q->unk50[i]->unk0 == 10) {
            p->unk110[i] = func_L39_00682FC0((void *)func_L01_00521C90(0x88, buf), q->unk50[i]);
            buf += 0x88;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
        } else if (q->unk50[i]->unk0 == 7) {
            p->unk110[i] = func_L39_00683A30((void *)func_L01_00521C90(0xD0, buf), q->unk50[i]);
            buf += 0xD0;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
        } else if (q->unk50[i]->unk0 == 8) {
            p->unk110[i] = func_L39_00684860((void *)func_L01_00521C90(0x4A8, buf), q->unk50[i]);
            buf += 0x4A8;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
        } else if (q->unk50[i]->unk0 == 9) {
            p->unk110[i] = func_L39_006844E0((void *)func_L01_00521C90(0x470, buf), q->unk50[i]);
            buf += 0x470;
            p->unk110[i]->unk60->unk1C(p->unk110[i], 3, 0);
        }
        p->unk110[i]->unk10 = p;
    }
    p->unk294 = buf;
    p->unk298 = buf - p->unk2A4;
    n = func_L39_0068B178(p);
    func_L39_0068B2F8(p, n, 0);
    if (!D_001DC30A_sda) {
        func_L39_0067F030(0);
        func_L39_0067F060(2, 0x200000);
        func_L39_0067F050(3);
        func_L39_006888B8();
        D_001DC30A_sda = 1;
    }
}
/* localdecomp:end func_L39_00689670 */

/* localdecomp:start func_L39_00689A70 */
void func_L39_006121B0(s32);
extern u8 D_001DC30A_sda;

void func_L39_00689A70(void) {
    func_L39_006121B0(2);
    D_001DC30A_sda = 0;
}
/* localdecomp:end func_L39_00689A70 */

/* localdecomp:start func_L39_00689A90 */
extern char D_001DC310_sda[8];
extern int D_L39_003D28C0[];
extern int func_0038CAD0(char *);
extern void func_L01_00516AA0();
void func_L39_00689A90(void)
{
    if (func_0038CAD0(D_001DC310_sda)) {
        func_L01_00516AA0(D_L39_003D28C0[0], 1, 0);
    }
}
/* localdecomp:end func_L39_00689A90 */

INCLUDE_ASM("asm/levels", func_L39_00689AC8);

/* localdecomp:start func_L39_00689B58 */
extern int D_L39_003D28C0[];
extern void func_L01_00516470(int);

void func_L39_00689B58(void) {
    if (*(unsigned char *)&D_001DC30A_sda != 0)
        func_L01_00516470(D_L39_003D28C0[0]);
}
/* localdecomp:end func_L39_00689B58 */

/* localdecomp:start func_L39_00689B80 */
extern int D_L39_003D28C0[];
extern void func_L01_00516AA0();
__asm__(".extern D_L39_003D28C0, 16");
void func_L39_00689B80(void)
{
    if (D_001DC30A_sda)
        func_L01_00516AA0(D_L39_003D28C0[0], 1, 0);
}
/* localdecomp:end func_L39_00689B80 */

/* localdecomp:start func_L39_00689BB0 */
extern s32 D_L39_003D28B0[];
void func_L01_00516AA0(s32);

void func_L39_00689BB0(void) {
    func_L01_00516AA0(D_L39_003D28B0[0]);
}
/* localdecomp:end func_L39_00689BB0 */

INCLUDE_ASM("asm/levels", func_L39_00689BD8);
