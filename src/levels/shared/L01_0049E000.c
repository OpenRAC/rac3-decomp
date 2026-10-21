#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6D28 - 0x4958];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

INCLUDE_ASM("asm/levels", func_L01_0049E000);

/* localdecomp:start func_L01_0049E190 */
extern S_func_0049A930 D_00160C40[];
extern void *D_L01_001D94DC;
extern void *D_L01_001D94E0;
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
void func_L01_0049E190(void) {
    D_L01_001D94DC = func_003BB3A8(1);
    D_L01_001D94E0 = func_003BB3A8(1);
    func_003B4528(func_003B42F8(0), (s32)D_L01_001D94DC, (s32)D_L01_001D94E0, D_00160C40->f4954, (s32)D_00160C40->fX);
}
/* localdecomp:end func_L01_0049E190 */

/* localdecomp:start func_L01_0049E1E8 */
extern void *func_003B42F8(s32);
extern void *D_L01_001D94DC;
extern void *D_L01_001D94E0;
extern void func_003BB468(s32);
void func_L01_0049E1E8(void) {
    O_49A988 *o = ((O_49A988 * (*)(s32))func_003B42F8)(0);
    o->vt->fn(o);
    func_003BB468((*(s32 *)&D_L01_001D94DC));
    func_003BB468((*(s32 *)&D_L01_001D94E0));
}
/* localdecomp:end func_L01_0049E1E8 */

INCLUDE_ASM("asm/levels", func_L01_0049E228);

/* localdecomp:start func_L01_0049E380 */

extern s32 D_L01_001D94C8;
extern s32 D_L01_001D94CC;
extern Ent_0049AB20 D_L01_002EC758[];
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);

void func_L01_0049E380(void)
{
    if (D_L01_001D94C8 >= 0) {
        func_L01_00516FD8(0x500008, func_00381FF0(D_L01_002EC758[D_L01_001D94C8].f4));
        func_L01_00517190(0x500003, D_L01_002EC758[D_L01_001D94C8].f8 + 1);
        func_L01_00516D60(D_L01_001D94CC, 1);
    }
}
/* localdecomp:end func_L01_0049E380 */

INCLUDE_ASM("asm/levels", func_L01_0049E408);

INCLUDE_ASM("asm/levels", func_L01_0049E4B0);

INCLUDE_ASM("asm/levels", func_L01_0049E558);

/* localdecomp:start func_L01_0049E5C0 */
extern Ent_0049AB20 D_L01_002EC758[];

extern s32 D_L01_001D94C8;
extern s32 D_L01_001D94C4;
extern s32 D_L01_001D94D4;
extern void func_L01_00517190(s32, s32);

void func_L01_0049E5C0(void) {
    S_2EC7A8 *p;
    s32 cont;

    p = &((S_2EC7A8 *)&D_L01_002EC758)[D_L01_001D94C8];
    cont = 1;
    do {
        p++;
        if (p->f0 == 0) {
            cont = 0;
        } else if (p->f14 != 0 || D_L01_001D94C4 != 0) {
            cont = 0;
            func_L01_00517190(D_L01_001D94D4, p->f8 + 1);
        }
    } while (cont);
}
/* localdecomp:end func_L01_0049E5C0 */

INCLUDE_ASM("asm/levels", func_L01_0049E648);

LINKER_REMNANT("asm/levels", func_L01_0049E6F0);

INCLUDE_ASM("asm/levels", func_L01_0049E710);

/* localdecomp:start func_L01_0049E9F0 */
extern s32 func_L01_0041A4F0(void);

s32 func_L01_0049E9F0(s32 a0) {
    s32 r = 0;
    if (func_L01_0041A4F0() == 0 || a0 != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_0049E9F0 */

INCLUDE_ASM("asm/levels", func_L01_0049EA38);

INCLUDE_ASM("asm/levels", func_L01_0049EE28);

LINKER_REMNANT("asm/levels", func_L01_0049F150);

/* localdecomp:start func_L01_0049F168 */
extern void func_L01_0049F2C8(void);
extern void func_L01_0049F868_0049F168(void);
extern void func_L01_0049F798(void);
extern void func_L01_0049F8A8_0049F168(void);
extern void func_L01_0049F8C8_0049F168(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L01_001E0C58;
extern s32 D_L01_001E0C78;
extern s32 D_L01_001E0C98;
extern s32 D_L01_001E0CB8;
extern s32 D_L01_001E0C40[2];
extern s32 D_L01_001E0C60[2];
extern s32 D_L01_001E0C80[2];
extern s32 D_L01_001E0CA0[2];
extern V16_48DCD8 D_L01_001D9628[];
s32 func_L01_0049F168(s32 idx) {
    V16_48DCD8 v;
    if (D_L01_001E0C58 == 0) {
        func_003E6FA0(D_L01_001E0C40, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0C58 = 1;
    }
    if (D_L01_001E0C78 == 0) {
        func_003E6FA0(D_L01_001E0C60, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0C78 = 1;
    }
    if (D_L01_001E0C98 == 0) {
        func_003E6FA0(D_L01_001E0C80, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0C98 = 1;
    }
    if (D_L01_001E0CB8 == 0) {
        func_003E6FA0(D_L01_001E0CA0, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0CB8 = 1;
    }
    v = D_L01_001D9628[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_0049F168 */

INCLUDE_ASM("asm/levels", func_L01_0049F2C8);

INCLUDE_ASM("asm/levels", func_L01_0049F798);

/* localdecomp:start func_L01_0049F868 */
extern void func_L01_00517918(s32);
extern void func_L01_004A03A8_0049F868(void);
extern void func_003A2750(s32);

void func_L01_0049F868(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_L01_004A03A8_0049F868();
    func_003A2750(1);
}
/* localdecomp:end func_L01_0049F868 */

/* localdecomp:start func_L01_0049F8A8 */
extern void func_L01_0047E4B8_0049F8A8();
 
void func_L01_0049F8A8(void) {
    func_L01_0047E4B8_0049F8A8();
}
/* localdecomp:end func_L01_0049F8A8 */

/* localdecomp:start func_L01_0049F8C8 */
extern void func_L01_0047E520_0049F8C8();
 
void func_L01_0049F8C8(void) {
    func_L01_0047E520_0049F8C8();
}
/* localdecomp:end func_L01_0049F8C8 */

INCLUDE_ASM("asm/levels", func_L01_0049F8E8);

INCLUDE_ASM("asm/levels", func_L01_0049FBC8);

INCLUDE_ASM("asm/levels", func_L01_0049FDF0);

INCLUDE_ASM("asm/levels", func_L01_004A02B8);

INCLUDE_ASM("asm/levels", func_L01_004A0300);

INCLUDE_ASM("asm/levels", func_L01_004A03A8);

INCLUDE_ASM("asm/levels", func_L01_004A0430);

INCLUDE_ASM("asm/levels", func_L01_004A04B8);

/* localdecomp:start func_L01_004A0608 */

extern s32 D_L01_002ED730[];
extern S_236B80 D_L01_00236B00;

extern s32 func_L01_00516FD8(s32 id, s32 v);

void func_L01_004A0608(void) {
    func_L01_00516FD8(0x54000A, D_L01_00236B00.v[0][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54000E, D_L01_00236B00.v[1][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540012, D_L01_00236B00.v[2][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540016, D_L01_00236B00.v[3][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54001A, D_L01_00236B00.v[4][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54001E, D_L01_00236B00.v[5][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540022, D_L01_00236B00.v[10][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540026, D_L01_00236B00.v[11][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54002A, D_L01_00236B00.v[8][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54002E, D_L01_00236B00.v[7][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540032, D_L01_00236B00.v[6][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540036, D_L01_00236B00.v[9][D_L01_002ED730[0]]);
}
/* localdecomp:end func_L01_004A0608 */

INCLUDE_ASM("asm/levels", func_L01_004A0788);

INCLUDE_ASM("asm/levels", func_L01_004A0A78);

/* localdecomp:start func_L01_004A0A80 */
extern void func_L01_004A0AF8(s32);

void func_L01_004A0A80(void) {
    func_L01_004A0AF8(0);
    func_L01_004A0AF8(1);
    func_L01_004A0AF8(2);
    func_L01_004A0AF8(3);
    func_L01_004A0AF8(4);
    func_L01_004A0AF8(5);
    func_L01_004A0AF8(6);
    func_L01_004A0AF8(7);
    func_L01_004A0AF8(8);
    func_L01_004A0AF8(9);
    func_L01_004A0AF8(10);
    func_L01_004A0AF8(11);
}
/* localdecomp:end func_L01_004A0A80 */

INCLUDE_ASM("asm/levels", func_L01_004A0AF8);

INCLUDE_ASM("asm/levels", func_L01_004A0F28);

INCLUDE_ASM("asm/levels", func_L01_004A1050);

LINKER_REMNANT("asm/levels", func_L01_004A1120);

/* localdecomp:start func_L01_004A1128 */
extern s32 func_L01_004A1128(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0CF8;
extern s32 D_L01_001E0CE0[2];
extern void func_L01_004A1180();
extern void func_L01_004A15B0();
extern void func_L01_004A1520();
extern void func_L01_004A15F0_004A1128(void);
extern void func_L01_004A1610_004A1128();
s32 func_L01_004A1128(void) {
    if (D_L01_001E0CF8 == 0) {
        func_003E6FA0(D_L01_001E0CE0, (s32)func_L01_004A1180, (s32)func_L01_004A15B0, (s32)func_L01_004A1520, (s32)func_L01_004A15F0_004A1128, (s32)func_L01_004A1610_004A1128);
        D_L01_001E0CF8 = 1;
    }
    return (s32)D_L01_001E0CE0;
}
/* localdecomp:end func_L01_004A1128 */

INCLUDE_ASM("asm/levels", func_L01_004A1180);

INCLUDE_ASM("asm/levels", func_L01_004A1520);

/* localdecomp:start func_L01_004A15B0 */
extern void func_L01_00517918(s32);
extern void func_L01_004A1D00(void);
extern void func_003A2750(s32);

void func_L01_004A15B0(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_L01_004A1D00();
    func_003A2750(1);
}
/* localdecomp:end func_L01_004A15B0 */

/* localdecomp:start func_L01_004A15F0 */
extern void func_L01_0047E4B8_004A15F0();
 
void func_L01_004A15F0(void) {
    func_L01_0047E4B8_004A15F0();
}
/* localdecomp:end func_L01_004A15F0 */

/* localdecomp:start func_L01_004A1610 */
extern void func_L01_0047E520_004A1610();
 
void func_L01_004A1610(void) {
    func_L01_0047E520_004A1610();
}
/* localdecomp:end func_L01_004A1610 */

INCLUDE_ASM("asm/levels", func_L01_004A1630);

INCLUDE_ASM("asm/levels", func_L01_004A1910);

INCLUDE_ASM("asm/levels", func_L01_004A1AC8);

INCLUDE_ASM("asm/levels", func_L01_004A1CA8);

INCLUDE_ASM("asm/levels", func_L01_004A1D00);

INCLUDE_ASM("asm/levels", func_L01_004A1D40);

/* localdecomp:start func_L01_004A1E18 */
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 D_L01_001D9660;
extern s32 D_L01_001D9658;
extern s32 D_L01_001D96AC;
extern E_49E5B8 D_L01_002ED850[];
extern char D_L01_001D96B0[];

void func_L01_004A1E18(void) {
    D_L01_001D9660 = func_003B9C58(func_003B9BD0(0));
    if (D_L01_001D9660 < 0) {
        return;
    }
    if (D_L01_001D9658 != D_L01_001D9660) {
        if (D_L01_002ED850[D_L01_001D9660].x14) {
            func_L01_00516FD8(0x570005, func_00381FF0(D_L01_002ED850[D_L01_001D9660].x0));
            func_L01_00516FD8(0x570006, func_00381FF0(D_L01_002ED850[D_L01_001D9660].x4));
        } else {
            func_L01_00516FD8(0x570005, func_00381FF0(456));
            func_L01_00516FD8(0x570006, (s32)D_L01_001D96B0);
        }
        D_L01_001D96AC = 30;
    }
    if (D_L01_001D96AC != 0) {
        if (--D_L01_001D96AC == 0) {
            if (D_L01_002ED850[D_L01_001D9660].x14) {
                ((s32 (*)(s32, s32))func_L01_00517190)(0x570009, D_L01_002ED850[D_L01_001D9660].x8 + 1);
                ((s32 (*)(s32, s32))func_L01_00516D60)(0x570009, 1);
            } else {
                ((s32 (*)(s32, s32))func_L01_00516D60)(0x570009, 0);
            }
        }
    }
    D_L01_001D9658 = D_L01_001D9660;
}
/* localdecomp:end func_L01_004A1E18 */

INCLUDE_ASM("asm/levels", func_L01_004A1F78);

/* localdecomp:start func_L01_004A2240 */
extern s32 func_L01_004A2240(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0D18;
extern s32 D_L01_001E0D00[2];
extern void func_L01_004A2298();
extern void func_L01_004A2360();
extern void func_L01_004A22C8();
extern void func_L01_004A23D8_004A2240(void);
extern void func_L01_004A23F8();
s32 func_L01_004A2240(void) {
    if (D_L01_001E0D18 == 0) {
        func_003E6FA0(D_L01_001E0D00, (s32)func_L01_004A2298, (s32)func_L01_004A2360, (s32)func_L01_004A22C8, (s32)func_L01_004A23D8_004A2240, (s32)func_L01_004A23F8);
        D_L01_001E0D18 = 1;
    }
    return (s32)D_L01_001E0D00;
}
/* localdecomp:end func_L01_004A2240 */

/* localdecomp:start func_L01_004A2298 */
extern void *func_003BB3A8(s32);
extern s32 D_L01_001D96E8;
extern s32 D_L01_001D96EC;
extern s32 D_L01_001D96F0;

void func_L01_004A2298(void) {
    D_L01_001D96E8 = ((s32 (*)(s32))func_003BB3A8)(1);
    D_L01_001D96EC = ((s32 (*)(s32))func_003BB3A8)(1);
    D_L01_001D96F0 = 0;
}
/* localdecomp:end func_L01_004A2298 */

INCLUDE_ASM("asm/levels", func_L01_004A22C8);

INCLUDE_ASM("asm/levels", func_L01_004A2360);

/* localdecomp:start func_L01_004A23D8 */
extern void func_L01_0047E4B8_004A23D8();
 
void func_L01_004A23D8(void) {
    func_L01_0047E4B8_004A23D8();
}
/* localdecomp:end func_L01_004A23D8 */

INCLUDE_ASM("asm/levels", func_L01_004A23F8);

INCLUDE_ASM("asm/levels", func_L01_004A2560);

INCLUDE_ASM("asm/levels", func_L01_004A2840);

/* localdecomp:start func_L01_004A2848 */
extern void *func_003B42F8(s32);
void func_L01_004A2848(void) {
    void *o = func_003B42F8(1);
    ((void (*)(void *))(*(void ***)((u8 *)o + 0x4))[3])(o);
}
/* localdecomp:end func_L01_004A2848 */

INCLUDE_ASM("asm/levels", func_L01_004A2878);

INCLUDE_ASM("asm/levels", func_L01_004A28C8);

INCLUDE_ASM("asm/levels", func_L01_004A2BE0);

INCLUDE_ASM("asm/levels", func_L01_004A2E88);

INCLUDE_ASM("asm/levels", func_L01_004A2FC0);

INCLUDE_ASM("asm/levels", func_L01_004A32E0);

INCLUDE_ASM("asm/levels", func_L01_004A34A8);

INCLUDE_ASM("asm/levels", func_L01_004A3548);

INCLUDE_ASM("asm/levels", func_L01_004A35C0);

INCLUDE_ASM("asm/levels", func_L01_004A3610);

INCLUDE_ASM("asm/levels", func_L01_004A3848);

INCLUDE_ASM("asm/levels", func_L01_004A3A90);

/* localdecomp:start func_L01_004A3AD0 */


extern u8 *func_L01_004A3A90(s32 a, s32 b);
extern void func_0038CC88(void *dst, void *src, s32 size);

void func_L01_004A3AD0(Table_4A0270 *table) {
    s32 i;
    for (i = 0; i < table->count; i++) {
        Entry_4A0270 *e = &table->entries[i];
        u8 *obj = func_L01_004A3A90(e->arg0, e->arg1);
        if (obj != 0) {
            u8 *dst;
            if (e->kind == 1) {
                dst = (u8 *)e->offset + (s32)obj;
            } else {
                dst = (u8 *)e->offset + *(s32 *)(obj + 104);
            }
            func_0038CC88(dst, &e->data, e->size);
        }
    }
}
/* localdecomp:end func_L01_004A3AD0 */

INCLUDE_ASM("asm/levels", func_L01_004A3B88);
