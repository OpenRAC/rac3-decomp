#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003DA0A8(void);
extern void func_003D9FE8(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028;
extern void func_003D98C0(E_3A3028 *, s32, s32, s32, f32, f32, f32);
extern void func_003DA160();
extern void func_003D9808();
extern void func_003D9AF8(void *, s32, s32, s32, s32, f32);
/* --- end of declarations from other files --- */

/* declarations of 3D6C70.c's earlier functions (tools/port_from_us.py) */
extern void func_003D6E98(long **, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_001D5600;
extern s32 D_001D5604;
extern s32 D_001D4BD0_003D6F78;
extern s32 D_001D4BD4_003D6F78;
extern void func_003D6E98(long **, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003D7790(s32, s32, s32, s32, s32);
extern void func_003D7790(s32, s32, s32, s32, s32);
extern void func_003D7790(s32, s32, s32, s32, s32);
extern s32 func_003D6DD8(s32 *, s32);
extern void func_003D81A0(void);
extern void func_003D88B8(void);
extern s32 D_001D5608, D_001D5610, D_001D5614, D_001D561C;
extern s32 D_001D5624, D_001D560C, D_001D5620, D_001D55EC;
extern s32 D_001A1ED4[];
extern s32 D_001D0A50[];
extern s32 D_001D5600, D_001D5604, D_001D5608_003D81A0, D_001D5610_003D81A0, D_001D5614_003D81A0, D_001D561C_003D81A0, D_001D5620, D_001D55F0;
extern u8 D_001D936C;
extern s32 D_001D9350, D_001D9354, D_001D9358, D_001D935C;
extern void func_003D6DF8(long **, s32, s32, s32, s32, s32);
extern void func_003D7668(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D72A0(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003D7C08(s32, s32, s32);
extern void func_003D7C30(s32, s32, s32);
extern void func_003D7C58(s32, s32, s32);
extern void func_003D7C98(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_001D5608_003D88B8, D_001D5620, D_001D561C_003D88B8, D_001D9360, D_001D55F4;
extern u8 D_001D2A50[];
extern void func_003D7668(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7C08();
extern void func_003D6F78(u8 **, s32, s32, s32, s32, s32, s32);
extern s32 D_001D55F0;
extern u32 *D_001DA050;
extern s32 D_001D934C;
extern s32 D_001D0A50[];
extern u32 *D_001DA050;
extern s32 D_001D55F4;
extern u8 D_001D2A50[];
extern s32 D_001D934C;
extern s32 D_001A1ED0[];
extern s32 D_001A1ED0[];
typedef struct { s32 f0; s32 f4; s32 f8; } T_3D3780;
extern T_3D3780 D_001A1ED0_003D90A8;
extern s32 D_001D5600_003D9378;
extern s32 D_001D5604_003D9378;
extern s32 D_001D5628_003D9378;
extern s32 D_001D5630_003D9378;
extern s32 D_001D5634_003D9378;
extern s32 D_001D55F8_003D9378;
extern u8 D_001D3650_003D9378[];
extern void func_003D7668(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7C08();
extern s32 D_001D5600_003D94B8;
extern s32 D_001D5604_003D94B8;
extern s32 D_001D5628_003D94B8;
extern s32 D_001D55FC_003D94B8;
extern u8 D_001D3EF0[];
extern s32 func_003D8A70();
extern s32 func_003D8D50();
extern s32 func_003D90A8();
extern void func_003D6F78(u8 **, s32, s32, s32, s32, s32, s32);
extern s32 func_003D6DD8();
extern void func_003D9378(void);
extern void func_003D94B8(void);
extern s32 D_001D5634;
extern s32 D_001D5630;
extern s32 D_001D5628;
extern s32 D_001A1ED4[];
extern s32 D_001D55EC;
extern u32 *D_001DA050;
extern s32 D_001D55F8;
extern s32 D_001D55FC;
extern u8 D_001D3650[];
extern u8 D_001D3EF0[];
typedef struct { u8 pad[0x150]; s16 h150; s16 h152; } S_1CFEC0;
extern S_1CFEC0 D_1CFEC0;
extern s32 D_001D5604;
extern s32 D_001D5600;
extern void func_003D80E8();
extern void func_003D95A8();

LINKER_REMNANT("asm/boot_elf/remnants", func_003D9730);

/* localdecomp:start func_003D9768 */
extern long func_00389978(s32);
extern u8 D_00380E60[];

void func_003D9768(void *arg0, s32 arg1, s32 arg2, long arg3) {
    void *temp_s0;

    (*(long *)((u8 *)(arg0) + 0x78)) = func_00389978(arg1);
    (*(long *)((u8 *)(arg0) + 0x80)) = (long) (0xFF9000000000 | 0x260);
    (*(long *)((u8 *)(arg0) + 0x70)) = 0;
    temp_s0 = (arg2 * 0x14) + D_00380E60;
    (*(long *)((u8 *)(arg0) + 0x88)) = (long) ((*(s32 *)((u8 *)(temp_s0) + 0)) | ((long) (*(s32 *)((u8 *)(temp_s0) + 4)) * 4) | ((long) (*(s32 *)((u8 *)(temp_s0) + 8)) * 0x10) | ((long) (*(s32 *)((u8 *)(temp_s0) + 0xC)) << 6) | (arg3 << 0x20));
}
/* localdecomp:end func_003D9768 */

/* localdecomp:start func_003D9808 */
typedef int u128_3D3EE0 __attribute__((mode(TI)));
extern void func_003D9768(void *, s32, s32, long);
void func_003D9808(u8 *p, s32 a1, s32 a2, f32 *src, u128_3D3EE0 *q, s32 a5) {
    s32 i;
    f32 *fp;
    s32 *ip;
    func_003D9768(p, a1, a5, 0x80);
    ip = (s32 *)(p + 0x40);
    fp = (f32 *)(p + 0x54);
    for (i = 0; i < 4; i++) {
        fp[i * 2 - 1] = src[i * 2];
        fp[i * 2] = src[i * 2 + 1];
        ip[i] = a2;
        ((u128_3D3EE0 *)p)[i] = q[i];
    }
}
/* localdecomp:end func_003D9808 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D98A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D98C0);

typedef int Q_3D3FA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D3FA0;
typedef struct { V_3D3FA0 v[4]; s32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } B_3D3FA0;
extern V_3D3FA0 D_00222400_003D9760[];
extern V_3D3FA0 D_001D9180[];
typedef struct { u8 pad[0x80]; f32 f80[4]; u8 pad2[0x3D0]; } G_3D3FA0;
extern G_3D3FA0 D_002225D0_003D9760[];
extern u8 D_002225D0[];
extern s32 D_001D52F0;
extern void func_0038D348(void *, void *, f32);
extern void func_0038D270(void *, void *, void *);
extern void func_0038D6E8(void *, void *);
extern void func_0038D9D0(void *, void *, void *);
extern void func_0038D200(void *, void *, f32);
extern void func_0038D408(void *, void *, void *);
extern void func_003D3158(void *, s32, s32);

LINKER_REMNANT("asm/boot_elf/remnants", func_003D9AB0);

typedef struct { f32 x, y, z; } P_3D41E0;
typedef struct { f32 a, b; } T_3D41E0;
extern f32 D_001D9390;
extern f32 D_001D93C0;
extern s32 D_001D9348;
extern P_3D41E0 D_002FF880[];
extern s32 D_002FF988[];
extern T_3D41E0 D_002FF9E0[];
extern void func_003A97F8(s32, unsigned long);
extern long func_00389978(s32);
extern void func_0038CB30(void);
extern void func_0038D408();
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern s32 func_0038DFB8(s32, s32, f32);
extern void func_003D3DDC(s32, void *, void *, void *, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D9AF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D9F98);

extern s32 D_001D4BB0[];
extern void func_003DCFA8(s32);
extern void func_003A99D0(void);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D9FB8);

/* localdecomp:start func_003D9FE8 */
typedef struct { s16 a; s16 b; } T_D46E0;
typedef struct { u8 p0[0x33]; u8 f33; } E_D46E0;
typedef struct { u8 p0[0xF]; u8 cnt; u8 q[0xC]; E_D46E0 *ent; } O_D46E0;
extern s32 D_00304EC0[];
extern O_D46E0 *D_002FFAC0[];
extern T_D46E0 D_003048C0[];
void func_003D9FE8(void) {
    s32 *p;
    s32 i;
    O_D46E0 *o;
    u8 *e;
    for (p = D_00304EC0; *p >= 0; p++) {
        o = D_002FFAC0[*p];
        e = (u8 *)o->ent;
        for (i = 0; i < o->cnt; i++) {
            T_D46E0 *t = &D_003048C0[e[0x33]];
            if (t->a != 0) { *(u32 *)e = (*(u32 *)e & 0xFFFFC000) | t->a; }
            if (t->b != 0) { *(u32 *)(e + 0x20) = (*(u32 *)(e + 0x20) & 0xFFFFC000) | t->b; }
            e += 0x50;
        }
    }
}
/* localdecomp:end func_003D9FE8 */

extern s32 D_001D4BB4;
void func_0038D108(s32, s32 *, s32);
void func_003A9348(s32 *);
extern void func_003A97F8(s32, unsigned long);
void func_003DB148();
void func_003DC518();
void func_003DD258();
void func_11F0A0(s32);
extern s32 D_001D4BB0_003DA0A8;
extern u8 D_001D7960[];
extern s32 D_001DA050_003DA0A8;
extern u8 D_100AE0[];
extern u8 D_1159B0[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003DA0A8);

LINKER_REMNANT("asm/boot_elf/remnants", func_003DA158);

typedef struct {
    u8 pad[0x7614];
    s32 value;
} SourceBlock_003DA018;
extern u8 *D_001DA704;
extern u8 *D_001DA708;
extern s32 D_001DA710;
extern s32 D_001DA728;
extern s32 D_001DA72C;
extern s32 D_001DA730;
extern u8 *D_001DA734;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003DA160);
