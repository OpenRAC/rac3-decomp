#include "common.h"

typedef struct S_006A5FE0 {
    u8 pad0[0x2B1];
    u8 f2B1;
    u8 pad1[6];
    s32 f2B8;
    s32 f2BC[576];
    s32 fBBC[1];
} S_006A5FE0;

typedef struct S_006A6108 {
    u8 pad0[0xCBC];
    u8 f_CBC;
    u8 pad1[7];
    s32 f_CC4;
    s32 f_CC8[1];
    u8 pad2[0x8FC];
    s32 f_15C8[1];
} S_006A6108;

typedef struct S_L39_006A6078 {
    u8 pad0[0x16CC];
    s32 f16CC;
    s32 f16D0[11];
    s32 f16FC[1];
} S_L39_006A6078;

/* declared by functions of L39_006A5F30.c, which this file was cut from */
extern s32 func_00381FF0(s32);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_006A6290(void *, s32, s32);

/* localdecomp:start func_L39_006A61A0 */
typedef struct S_006A61A0 {
    u8 pad0[0x48];
    s32 f48;
} S_006A61A0;

extern S_006A61A0 *D_001E2050_sda;
extern u8 D_L39_00248838[];
extern s32 D_L39_00247914_61A0;
extern s32 func_L39_00687450(s32, u8 *, u8 *, s32, s32, s32, s32);
extern S_006A61A0 *func_L39_006D9A40(s32, u8 *);
extern s32 func_00120048(u8 *, s32, ...);
extern void func_L39_006872E8(s32, u8 *, u8 *, s32, s32, f32);

void func_L39_006A61A0(void *arg0) {
    u8 name[0x30];
    u8 buf[0x50];
    S_006A61A0 *r;

    name[0] = 0;
    func_L39_00688340(4, 0, 0);
    func_L39_00687450(D_L39_00247914_61A0, D_L39_00248838, name, 0, 0x21, 0, 0);
    if (name[0] != 0) {
        r = func_L39_006D9A40(D_001E2050_sda->f48, name);
        if (r != 0 && r->f48 >= 0) {
            ((void (*)(void *, s32, u8 *))func_L39_006A6290)(arg0, r->f48, name);
        } else {
            func_00120048(buf, func_00381FF0(0x1175), name);
            func_L39_006872E8(D_L39_00247914_61A0, buf, D_L39_00248838, 4, 0, 0.6f);
        }
    }
}
/* localdecomp:end func_L39_006A61A0 */

INCLUDE_ASM("asm/levels", func_L39_006A6290);

INCLUDE_ASM("asm/levels", func_L39_006A6470);

INCLUDE_ASM("asm/levels", func_L39_006A65B8);

INCLUDE_ASM("asm/levels", func_L39_006A6778);

/* localdecomp:start func_L39_006A6938 */
typedef struct { u8 pad0[0xE0]; s16 f_E0[8]; u8 pad1[0x150 - 0xF0]; s32 f_150[8]; } S_006A6938;
typedef struct { u8 pad0[0x34]; s32 f34; } G_006A6938;
extern S_006A6938 *D_L39_00241640_006A6938;
extern G_006A6938 D_001A5CD0;

s32 func_L39_006A6938(s32 a0, s32 a1)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_L39_00241640_006A6938->f_E0[i] >= 0 && (D_L39_00241640_006A6938->f_150[i] == a1 || D_001A5CD0.f34 == a1)) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006A6938 */

LINKER_REMNANT("asm/levels", func_L39_006A69A0);

INCLUDE_ASM("asm/levels", func_L39_006A69C0);

LINKER_REMNANT("asm/levels", func_L39_006A6F98);

/* localdecomp:start func_L39_006A6FA0 */
/* Retail stores D_L39_0047DA80 at object+0x60 and tail-calls-like func_L39_00688400; see the report. */
extern u8 D_L39_0047DA80[];
extern void func_L39_00688400(u8 *, s32);

void func_L39_006A6FA0(void *object, s32 flags)
{
    u8 *p = (u8 *)object;
    *(void **)(p + 0x60) = D_L39_0047DA80;
    func_L39_00688400(p, flags);
}
/* localdecomp:end func_L39_006A6FA0 */

/* localdecomp:start func_L39_006A6FC8 */
typedef struct P_006A6FC8 {
    s16 f0;
    s16 f2;
} P_006A6FC8;

typedef struct G_006A6FC8 {
    u8 pad0[0x120];
    s32 f120[8];
    P_006A6FC8 f140[8];
    u8 pad160[0x48];
    s32 f1A8;
    u8 pad1AC[0xC];
    s16 f1B8[8];
    u8 pad1C8[0x644];
    s32 f80C;
} G_006A6FC8;

typedef struct M_006A6FC8 {
    u8 pad0[0x19D];
    s8 f19D;
} M_006A6FC8;

typedef struct S_006A6FC8 {
    u8 pad0[0x2A8];
    u8 names[8][0x10];
} S_006A6FC8;

extern G_006A6FC8 D_001FD7E8;
extern M_006A6FC8 *D_L39_00241640;
extern s32 func_00120884(u8 *);

s32 func_L39_006A6FC8(void *arg, s32 a, s32 b) {
    S_006A6FC8 *arg0 = arg;
    s32 da;
    s32 db;
    s32 sa;
    s32 sb;

    if (func_00120884(arg0->names[a]) == 0 && func_00120884(arg0->names[b]) == 0) {
        return 0;
    }
    if (func_00120884(arg0->names[a]) == 0) {
        return 1;
    }
    if (func_00120884(arg0->names[b]) == 0) {
        return 0;
    }
    da = D_001FD7E8.f140[a].f0 - D_001FD7E8.f1B8[a];
    db = D_001FD7E8.f140[b].f0 - D_001FD7E8.f1B8[b];
    sa = D_001FD7E8.f140[a].f2;
    sb = D_001FD7E8.f140[b].f2;
    if (D_001FD7E8.f1A8 == -1 || (D_001FD7E8.f80C == 2 && D_L39_00241640->f19D == 0)) {
        if (da < db) {
            return 1;
        }
        if (da == db) {
            return sb < sa;
        }
        return 0;
    }
    if (D_001FD7E8.f120[a] != D_001FD7E8.f1A8 && D_001FD7E8.f120[b] == D_001FD7E8.f1A8) {
        return 1;
    }
    if (D_001FD7E8.f120[a] != D_001FD7E8.f120[b]) {
        return 0;
    }
    if (da < db) {
        return 1;
    }
    if (da == db) {
        return sb < sa;
    }
    return 0;
}
/* localdecomp:end func_L39_006A6FC8 */

/* localdecomp:start func_L39_006A7178 */
typedef struct E_006A7178 {
    u8 name[0x20];
} E_006A7178;

typedef struct G_006A7178 {
    E_006A7178 e[8];
    u8 pad100[0xA8];
    s32 f1A8;
} G_006A7178;

typedef struct S_006A7178 {
    u8 pad0[0x2A8];
    u8 names[8][0x10];
    u8 pad328[0x128];
    s32 order[8];
} S_006A7178;

extern G_006A6FC8 D_001FD7E8;
extern void func_001206F4(u8 *, u8 *);
extern s32 func_L39_006A6FC8(void *, s32, s32);

void func_L39_006A7178(S_006A7178 *arg0) {
    s32 i;
    s32 j;
    s32 t;

    for (i = 0; i < 8; i++) {
        if (((G_006A7178 *)&D_001FD7E8)->e[i].name[0] != 0) {
            func_001206F4(arg0->names[i], ((G_006A7178 *)&D_001FD7E8)->e[i].name);
        } else {
            arg0->names[i][0] = 0;
        }
        arg0->order[i] = i;
    }
    if (D_001FD7E8.f1A8 != -1) {
        for (i = 0; i < 8; i++) {
            for (j = i + 1; j < 8; j++) {
                if (func_L39_006A6FC8(arg0, arg0->order[i], arg0->order[j]) != 0) {
                    t = arg0->order[i];
                    arg0->order[i] = arg0->order[j];
                    arg0->order[j] = t;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006A7178 */

INCLUDE_ASM("asm/levels", func_L39_006A72B0);
