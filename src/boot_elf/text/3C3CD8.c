#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_003C3FA0(f32, f32, f32);
extern void (*D_001D9A40[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C4BA0();
extern void func_003C4BA0(void *, void *);
extern f32 func_003C44F0(f32 *, f32, f32);
extern f32 func_003C4440(f32, f32, f32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3C3280.c's earlier functions (tools/port_from_us.py) */
typedef struct { f32 x, y, z, w; } V4_3BDAC8;
typedef struct { f32 m[12]; V4_3BDAC8 v; } M_3BDAC8;
typedef int Q_3BDAC8 __attribute__((mode(TI)));
extern void func_003CA858();
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D950();
extern void func_0038DA20();
extern int D_001DA050_003C3478;
extern int D_001DA490_003C3478;
extern s32 D_001D4BB0_003C3478;
extern void func_003CB408();
extern void func_003A99D0();
typedef struct { s16 a; s16 b; } T_BDC90;
typedef struct { u8 c[0xC]; s32 fC; } E_BDC90;
typedef struct { u8 p0[0x20]; E_BDC90 *f20; } O_BDC90;
extern s32 D_002DDFF0[];
extern O_BDC90 *D_002DA740[];
extern T_BDC90 D_002DD830[];
extern int D_001DA4E4_003C3640;
extern s32 D_001DA4E0;
extern s32 D_001D9D34_003C3640;
extern s32 D_001D5BA8_003C3640;
extern void func_003D1AC0();
extern void func_003D1768();
typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8;
typedef struct { u8 p0[0x24]; T_3BDEA8 *f24; } O_3BDEA8;
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
extern u8 D_00380120[];
extern u8 D_001D7830[];
extern void func_0038D108();
extern u8 D_00380250[];
extern s32 D_001D9D30;
extern s32 D_001D9D38;
extern void func_11F0A0(s32);
extern void func_0038D108(u32 *, s32, s32);
extern void func_003CB6B8();
extern void func_0038CF58();
extern void func_0038D108();
extern u8 D_002DA380[];
extern void func_0038D108();
extern u8 D_002DA380[];
extern void func_003A9348(void *);
extern u8 D_002FC1A0[];
extern void func_003A96F0();
extern void func_003A97F8(s32, unsigned long);
extern u8 D_00110790[];
extern u8 D_00100080[];
extern u16 D_00110780[];
extern s32 D_001D9D1C_003C3A78;
extern s32 D_001DA050_003C3A78;
extern s32 D_001D9D38_003C3A78;
extern s32 D_001D9D30_003C3A78;
extern s32 D_001DA490_003C3A78;
extern u8 *D_001DA530_003C3A78;
extern s32 D_001DA054_003C3A78;
extern s32 D_001DA498_003C3A78;
extern s32 D_001DA4E4_003C3A78;
extern void *D_001DA498_003C3B38;
extern void func_003A97F8(s32, unsigned long);
extern void func_11F0A0(s32);
extern void func_003C3A48(void);
extern void *func_003CB798(s32, void *, s32, s32);
extern void func_003C3A18(void);
extern void func_003C3478(void);
extern void func_003C39A8(void);
extern void func_003C3640(void);
extern void func_003C3780(void);
extern s32 D_001DA4E4[];
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
extern void func_003C39F0();
extern void func_003C3A78();
extern void func_003C3BB8();
s32 func_003CB798_003C3C18(s32, s32, s32, s32);
extern s32 D_001DA498;
extern s32 D_001DA49C;
extern s32 D_001DA4D4;
extern int D_001DA49C;
extern int D_001DA4A4;

LINKER_REMNANT("asm/boot_elf/remnants", func_003C3CD8);

/* localdecomp:start func_003C3CF0 */
typedef struct { u8 p10[0x10]; u8 n; u8 f11; } T_3BE418;
typedef struct { u8 p0[0x48]; T_3BE418 *e[1]; } Q_3BE418;
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; f32 f48; f32 f4C; u8 p50[8]; f32 *f58; u8 p5c[4]; u8 f60; u8 p61[0xB]; u8 f6C;
} S_3BE418;
extern void func_003C2D68();
void func_003C3CF0(S_3BE418 *p, s32 idx, s32 lim) {
    s32 v;
    s32 n;
    v = lim;
    if (!(lim < p->f24->e[idx]->n)) v = p->f24->e[idx]->n - 1;
    p->f42 = idx;
    p->f40 = v;
    p->f41 = v + 1;
    n = p->f24->e[idx]->n - 1;
    if (n < p->f41) p->f41 = n;
    p->f43 = idx;
    p->f44 = 0;
    if (!(p->f41 < p->f24->e[idx]->n)) p->f41 = 0;
    func_003C2D68(p);
    p->f4C = *p->f58;
    p->f60 &= 0xFD;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_003C3CF0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C3DC8);
TEXT_PADDING(4);

typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; f32 f44; f32 f48; f32 f4C; void *f50; void *f54; u8 p58[8]; u8 f60; u8 p61[0xB]; u8 f6C;
    u8 p6D[0x13]; u128_t f80; u8 p90[0x19]; u8 fA9;
} S_3BE4F0;
extern u128_t D_002DA100[];
extern void func_003C7258_003C3CB0();
extern s32 func_003C30E8();
extern void func_003C8ED0();

LINKER_REMNANT("asm/boot_elf/remnants", func_003C3F80);

extern f32 func_0038D478(f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C3FA0);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4038);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
extern V_3BE7F0 D_00227660;
s32 func_003D4068(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C40E8);

/* localdecomp:start func_003C4158 */
typedef int Q_3BE860 __attribute__((mode(TI)));
extern V_3BE7F0 D_001A4C90;
extern void func_003C5538_003C4158();
s32 func_003C4158(V_3BE7F0 *out, void *obj, s32 flags, s32 c, f32 scale) {
    V_3BE7F0 a, b, d;
    Q_3BE860 x, y;
    func_003C5538_003C4158(obj, &d, 1);
    a = D_001A4C90;
    func_0038D200((f32 *)&b, &d, scale);

    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_3BE7F0 *)obj));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
    if (func_003D4068(&b, &a, flags | 2, c, 0)) {
        *out = D_00227660;
        return 1;
    }
    *out = a;
    return 0;
}
/* localdecomp:end func_003C4158 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4240);

extern s32 D_001D99C0;
extern s32 D_001D99A8;
extern f32 D_001D99B8;
extern f32 D_001D99BC;
extern f32 D_001D99B0[];
extern s32 func_00381C60();
extern f32 func_0038D318();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C4280);

/* localdecomp:start func_003C4378 */
extern s32 func_0038DA68();
extern void func_0038DB30(void *, s32, f32);
void func_003C4378(s32 *arg0, void *arg1) {
    s32 spv[12];

    func_0038DB30(&spv[8], 0, (*(f32 *)((u8 *)arg1 + 0)));
    func_0038DB30(&spv[4], 1, (*(f32 *)((u8 *)arg1 + 4)));
    func_0038DB30(spv, 2, (*(f32 *)((u8 *)arg1 + 8)));
    ((s32 (*)())func_0038DA68)(arg0, &spv[8], &spv[4]);
    ((s32 (*)())func_0038DA68)(arg0, arg0, spv);
}
/* localdecomp:end func_003C4378 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4410);

/* localdecomp:start func_003C4440 */
f32 func_003C4440(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}
/* localdecomp:end func_003C4440 */

/* localdecomp:start func_003C4450 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) Vector_003BEB58;
extern f32 func_003C4440(f32, f32, f32);
void func_003C4450(Vector_003BEB58 *output, Vector_003BEB58 first, Vector_003BEB58 second, f32 fraction) {
    output->x = func_003C4440(first.x, second.x, fraction);
    output->y = func_003C4440(first.y, second.y, fraction);
    output->z = func_003C4440(first.z, second.z, fraction);
    output->w = func_003C4440(first.w, second.w, fraction);
}
/* localdecomp:end func_003C4450 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C44E8);

/* localdecomp:start func_003C44F0 */
f32 func_003C44F0(f32 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f13;

    var_f13 = fparg1;
    var_f0 = fparg0 - *arg0;
    if ((var_f13 < var_f0) || (var_f13 = -var_f13, (var_f0 < var_f13))) {
        var_f0 = var_f13;
    }
    temp_f1 = *arg0 + var_f0;
    *arg0 = temp_f1;
    { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(fparg0 - temp_f1)); return r; }
}
/* localdecomp:end func_003C44F0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4540);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C4558);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4700);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C4718);
TEXT_PADDING(2);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C48F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C4950);

typedef struct { s32 v[3]; } N3_3BF058;
extern N3_3BF058 D_001D9118;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C4958);

/* localdecomp:start func_003C4BA0 */
extern void func_0038D950(void *, void *);
extern void func_003C4958(void *, void *);
extern void func_0038D970(void *, void *);
void func_003C4BA0(void *a, void *b) {
    u8 m[0x40];
    func_0038D950(m, b);
    func_003C4958(a, m);
    func_0038D970(b, m);
}
/* localdecomp:end func_003C4BA0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4BF0);

/* localdecomp:start func_003C4BF8 */
extern f32 func_0038D490(f32);
extern f32 func_0038D478(f32);
extern void func_0038D200(f32 *, void *, f32);
void func_003C4BF8(f32 *q, void *axis, f32 angle) {
    f32 h = angle * 0.5f;
    func_0038D200(q, axis, func_0038D490(h));
    q[3] = func_0038D478(h);
}
/* localdecomp:end func_003C4BF8 */
