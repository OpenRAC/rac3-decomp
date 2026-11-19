#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 383AA8.c's earlier functions */
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern f32 func_003C3FA0(f32, f32, f32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222480[];
extern void (*D_001D9A40[2])(s32);
extern void func_0038DE98(f32, f32);
extern f32 func_0038DEE0(f32, f32);
extern f32 func_0038D248(void *, void *);
extern f32 func_0038D288(void *);
extern f32 func_0038D4A8(f32);
extern void func_0038DC70(void *, void *, void *, f32);
extern void func_0038D348(s32 a, s32 b, f32 x);
extern void func_003838B0();
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_00222720[];

/* localdecomp:start func_00383E48 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00383E48;
typedef union { u128_t q; struct { f32 x, y, z, w; } v; } U_00383E48;
typedef struct {
    f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8];
    V_00383E48 v20; V_00383E48 v30; U_00383E48 u40; u8 m50[0x40];
} B_00383E48;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_00383E48;
typedef struct { u128_t q0; u8 p10[0x1C0 - 0x10]; V_00383E48 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_00383E48;
extern E_00383E48 D_00222480_00383E48[];
extern void func_003C4BA0(void *, void *);
extern void func_0038D970(void *, void *);
extern void func_0038DAA8_00383E48(void *, void *, void *, f32);
extern void func_0038DC10_00383E48(void *, void *);

/* the engine's quadword copy (rac2-decomp's qcopy) */
static __inline__ void qcopy_00383E48(void *d, void *s) {
    *(u128_t *)d = *(u128_t *)s;
}

s32 func_00383E48(void *arg, void *state) {
    O_00383E48 *o = arg;
    B_00383E48 *s = state;
    V_00383E48 v;
    u128_t matrix[4];
    f32 t;

    if (s->f10 == 1.0f && s->f0 == 1.0f) {
        return 1;
    }
    t = func_003C3FA0(0.0f, 1.0f, s->f10);
    vec_add_ba(&s->v30, &D_00222480_00383E48[o->f94].v1C0, &s->v30);
    s->u40.v.x = s->v30.x + (o->f30 - s->v30.x) * t;
    s->u40.v.y = s->v30.y + (o->f34 - s->v30.y) * t;
    s->u40.v.z = s->v30.z + (o->f38 - s->v30.z) * t;
    qcopy_00383E48(&D_00222480_00383E48[o->f94].q0, &s->u40);
    func_003C4BA0(&v, o);
    t = func_003C3FA0(0.0f, 1.0f, s->f0);
    func_0038DAA8_00383E48(s->m50, &s->v20, &v, t);
    func_0038DC10_00383E48(s->m50, matrix);
    func_0038D970(D_00222480_00383E48[o->f94].m380, matrix);
    s->f10 += s->f14 * 1.2f;
    if (s->f10 > 1.0f) {
        s->f10 = 1.0f;
    }
    s->f0 += s->f4 * 1.2f;
    if (s->f0 > 1.0f) {
        s->f0 = 1.0f;
    }
    return 0;
}
/* localdecomp:end func_00383E48 */

typedef struct { f32 f0, f4, f8, fC, f10, f14, f18, f1C; } A_37F588;
typedef struct { s32 p0[3]; s32 fC; f32 f10; s32 f14; } R_37F588;
typedef struct {
    s16 f0; u8 b2; u8 b3; u8 p4[0xC]; A_37F588 a; u128_t q30; u128_t q40; u128_t q50; u128_t q60; R_37F588 r;
} E_37F588;
extern u8 D_00222480_00383C18[];
extern void func_003C4BA0();
typedef int Q_37F7A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F7A8;
typedef struct { f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8]; V_37F7A8 v20; V_37F7A8 v30; u128_t q40; u8 m50[0x40]; } B_37F7A8;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_37F7A8;
typedef struct { u128_t q0; u8 p10[0x1C0 - 0x10]; V_37F7A8 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_37F7A8;
extern E_37F7A8 D_00222480_00383E38[];
extern void func_003C4BA0(void *, void *);
extern void func_0038D970(void *, void *);
extern void func_0038DAA8_00383E38(void *, void *, void *, f32);
extern void func_0038DC10_00383E38(void *, void *);
extern f32 func_003C3FA0(f32, f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00384028);

extern u8 D_00222720[];
extern u8 D_00222480_00384598[];
extern s32 func_00384028();
/* localdecomp:start func_00384598 */
typedef int Q_00384598 __attribute__((mode(TI)));
extern u8 D_00222720[];
extern u8 D_00222480_00384598[];
void func_00384598(u8 *arg) {
    extern s32 func_00383E48(void *,void *);
    extern s32 func_00384028();
    u8 *p = D_00222480_00384598 + 0x2A0 + *(s32 *)(arg+0x94)*0x460;
    s32 ok;
    if(p[2]==0) ok=func_00383E48(arg,p+0x10);
    else ok=func_00384028(arg,p+0x70);
    if(ok) {
        u8 *q = D_00222480_00384598 + *(s32 *)(arg+0x94)*0x460;
        *(Q_00384598 *)(q+0x380)=*(Q_00384598 *)(arg+0);
        *(Q_00384598 *)(q+0x390)=*(Q_00384598 *)(arg+0x10);
        *(Q_00384598 *)(q+0x3A0)=*(Q_00384598 *)(arg+0x20);
        *(Q_00384598 *)(q)=*(Q_00384598 *)(arg+0x30);
        *(s16 *)p=0;
        p[2]=0;
    }
}
/* localdecomp:end func_00384598 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00384640);
