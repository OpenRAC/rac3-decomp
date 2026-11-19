#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 388618.c's earlier functions */
extern void func_003877A0();
void func_0038D108(void *, void *, s32);
extern void (*D_001D9A40[2])(s32);
extern f32 func_0038D248(void *, void *);
extern void func_0038D348(s32 a, s32 b, f32 x);
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_001D5B94;
extern s32 func_0038CEB0(void *);
extern u128_t D_00222400[];
extern void func_0038D108();
extern s32 D_001D5B98;
extern s32 D_001D52F0;
extern u8 D_001D5884, D_001D58C0, D_001D58D0;
extern void func_003A97F8(s32, unsigned long);
extern void func_00388618(void);

typedef int Q_383BB0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_383BB0;
typedef struct { V_383BB0 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_383BB0;
typedef struct { u8 p0[0x24]; f32 f24, f28; u8 p2C[8]; f32 f34, f38; s32 f3C; } O_383BB0;
extern f32 D_001D59B0_00388610, D_001D59B4_00388610, D_001D59BC_00388610;
extern s32 D_001D59B8_00388610;
extern f32 D_001D5948_00388610, D_001D594C_00388610, D_001D5950_00388610, D_001D5954_00388610;
extern f32 D_001D5958_00388610, D_001D595C_00388610, D_001D5960_00388610, D_001D5964_00388610;
extern V_383BB0 D_00222480_00388610;
extern s32 func_0038CEB0(void *);
extern void func_003C4450_00388610(V_383BB0 *, V_383BB0, V_383BB0, f32);
extern void func_0038D270_00388610(V_383BB0 *, V_383BB0, V_383BB0);
extern f32 func_0038D248(void *, void *);
extern void func_0038D348(s32 a, s32 b, f32 x);
extern f32 func_003C4440(f32, f32, f32);
extern void func_003D3158();
extern s32 func_00382878(s32, s32);
/* localdecomp:start func_00388A90 */
typedef struct { u8 p0[0x34]; u16 flags; u8 p36[0x100 - 0x36]; } M_00388A90;
typedef struct {
    u128_t pos;
    f32 rot[4];
    u128_t *verts;
    f32 sx, sy;
    s32 count;
    s32 overlay;
    u8 p34[0xC];
    M_00388A90 *mobys[4];
} O_00388A90;
typedef struct { u8 p0[0x50]; O_00388A90 *obj; } C_00388A90;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00388A90;
typedef struct { u8 p0[0xB0]; f32 fB0; } G_00388A90;
typedef struct { u128_t pos[4]; s32 color[4]; f32 uv[4][2]; long a, tex, c, d; } P_00388A90;
extern C_00388A90 D_00225700;
extern G_00388A90 D_00225900_00388A90;
extern u128_t D_00222400[];
extern u128_t D_002FF580[];
extern u128_t D_001D5970 __attribute__((section(".sdata")));
extern u128_t D_001D5980 __attribute__((section(".sdata")));
extern u128_t D_001D5990 __attribute__((section(".sdata")));
extern u128_t D_001D59A0 __attribute__((section(".sdata")));
extern f32 D_001D5948[4] __attribute__((section(".sdata")));
extern f32 D_001D5958[4] __attribute__((section(".sdata")));
__asm__(".extern D_001D5970, 4");
__asm__(".extern D_001D5980, 4");
__asm__(".extern D_001D5990, 4");
__asm__(".extern D_001D59A0, 4");
__asm__(".extern D_001D5948, 4");
__asm__(".extern D_001D5958, 4");
extern s32 D_001D59C0;
__asm__(".extern D_001D59C0, 4");
extern s32 D_001DA49C;
extern long D_001D4C30;
extern void func_00381BA8(void);
extern void func_00381BB0(void);
extern void func_003C3A78();
extern void func_003C39F0();
extern void func_003C3A18(void);
extern void func_003C3A48(void);
extern void func_003C3BB8();
extern void func_003C3C18(void);
extern unsigned long func_003C7348(u8 *, unsigned long, unsigned long, unsigned long, unsigned long);
extern void func_003C3B38(s32, s32);
extern void func_00388590(s32, s32, f32);
extern void func_0012FF40(f32 *);
extern void func_00130088(f32 *, f32 *, f32);
extern void func_00130130(f32 *, f32 *, f32);
extern void func_0012FFE0(f32 *, f32 *, f32);
extern void func_00388638(O_00388A90 *, u128_t *, long);
extern void func_003865D0(void);
extern void func_003A99D0();

static __inline__ void qcopy_00388A90(u128_t *d, u128_t *s) {
    *d = *s;
}

void func_00388A90(void) {
    M_00388A90 copies[4];
    f32 saved[16];
    V_00388A90 pos;
    f32 mat[16];
    P_00388A90 packet;
    O_00388A90 *o;
    M_00388A90 *m;
    M_00388A90 *dst;
    s32 i, n, j, k, v;
    f32 old;

    func_00381BA8();
    o = D_00225700.obj;
    if (o != 0) {
        func_003C3A78();
        n = 0;
        func_003C39F0();
        func_003C3A18();
        for (i = 0; i < 4; i++) {
            m = o->mobys[i];
            if (m != 0) {
                ((void (*)(void *, s32, s32, s32, s32))func_003C7348)(m, 0x404040, 0xE, 0, 0);
                n++;
                m->flags |= 1;
            } else {
                break;
            }
        }
        func_003C3B38(D_001DA49C, -1);
        for (i = 0; i < 4; i++) {
            m = o->mobys[i];
            if (m != 0) {
                m->flags &= ~1;
            } else {
                break;
            }
        }
        func_0038D108(saved, &D_00222400[2], 0x40);
        pos = *(V_00388A90 *)&D_00222400[0];
        old = D_00225900_00388A90.fB0;
        func_00388590(8, 8, 1.0f);
        func_0012FF40(mat);
        func_00130088(mat, mat, o->rot[0]);
        func_00130130(mat, mat, o->rot[1]);
        func_0012FFE0(mat, mat, o->rot[2]);
        func_0038D108(&D_00222400[2], mat, 0x40);
        D_00222400[0] = o->pos;
        func_003865D0();
        D_002FF580[0] = D_001D5970;
        D_002FF580[2] = D_001D5980;
        D_002FF580[1] = D_001D5990;
        D_002FF580[3] = D_001D59A0;
        if (n == 1) {
            func_003C3B38((s32)o->mobys[0], 1);
        } else {
            dst = copies;
            for (i = 0; i < 4; i++) {
                m = o->mobys[i];
                if (m != 0) {
                    func_0038D108(dst, m, 0x100);
                    dst++;
                }
            }
            func_003C3B38((s32)copies, n);
        }
        func_00388618();
        D_00225900_00388A90.fB0 = old;
        func_003877A0();
        func_0038D108(&D_00222400[2], saved, 0x40);
        *(V_00388A90 *)&D_00222400[0] = pos;
        func_003865D0();
        func_003A97F8(0x42, 0x8000000044);
        func_003A97F8(8, 5);
        func_003A99D0();
        func_003C3A48();
        func_003C3BB8();
        j = 0;
        for (k = 0; k < D_00225700.obj->count; k++) {
            packet.tex = D_001D4C30;
            packet.c = 0xFF9000000260;
            packet.a = 5;
            packet.d = 0x8000000044;
            packet.color[3] = D_001D59C0;
            packet.color[2] = D_001D59C0;
            packet.color[1] = D_001D59C0;
            packet.color[0] = D_001D59C0;
            for (v = 0; v < 4; v++) {
                packet.uv[v][0] = o->sx * D_001D5948[v] + 0.5f;
                packet.uv[v][1] = o->sy * D_001D5958[v] + 0.5f;
                qcopy_00388A90(&packet.pos[v], &o->verts[j + v]);
            }
            func_003D3158(&packet, 0, 0);
            if (o->overlay != 0) {
                func_00388638(o, &o->verts[j], D_001D4C30);
            }
            j += 4;
        }
    } else {
        func_003C3C18();
    }
    func_00381BB0();
}
/* localdecomp:end func_00388A90 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00388ED0);

typedef int u128_00384420 __attribute__((mode(TI)));
typedef struct { u8 pad[0x450]; s32 x450; u8 pad454[0xC]; } P_00384420;
typedef struct { u8 pad0[4]; s16 x4; } C_00384420;
typedef struct { u128_00384420 q[4]; } Q_00384420;
extern C_00384420 *D_001DA5F0;
extern s32 D_001D9BC4;
extern s32 D_001D9D1C;
extern s32 D_001D9348;
extern s32 D_001D934C;
extern s32 D_001D9C10_00388ED8;
extern s32 D_001D9C14_00388ED8;
extern u8 D_001D58D0;
extern s32 D_001D5B94;
extern s32 D_001D9C08_00388ED8;
extern s32 D_001D9C0C_00388ED8;
extern s32 D_001D9364;
extern s32 D_001D9368;
extern s32 D_001D9C38_00388ED8;
extern volatile s32 D_001D9EC0;
extern s32 D_001D52F0;
extern P_00384420 D_00222480_00388ED8[];
extern u8 D_001D5780;
extern u8 D_001D5781;
extern u8 D_001D5782;
extern u8 D_001D5783;
extern f32 D_001D9BD0;
extern f32 D_001D9BD8[2];
extern s32 D_001D5B98;
extern u8 D_001D5884;
extern s32 D_001D58B8;
extern u8 D_100AE0[];
extern s32 D_00143950[];
extern f32 D_001D9D10;
extern s32 D_001D9D50_00388ED8;
extern u8 D_002FDC00[];
extern u8 D_003064C0[];
extern Q_00384420 D_00225AA0;
extern Q_00384420 D_00334EC0;
extern void func_00392730(s32);
extern void func_003865D0(void);
extern void func_003C3178(void);
extern void func_003875F8(void);
extern void func_00388348(void);
extern void func_0038CD90(void);
extern void func_003CF4A8(void);
extern void func_003AA028_00388ED8(s32);
extern void func_003DA0A8(void);
extern void func_003A9A90(void);
extern void func_00389620(s32);
extern void func_0038A208(void);
extern void func_00389750(void);
extern void func_003A9A30(void);
extern void func_003DF2E0(void);
extern void func_0038B120_00388ED8(u8 *);
extern void func_0038A280(void);
extern void func_00388A90(void);
extern void func_003C3C18(void);
extern void func_0038A190(void);
extern void func_003A97F8(s32, unsigned long);
extern void func_00385400(void);
extern void func_0038A438(void);
extern void func_11F0A0(s32);
extern void func_003CD790(void);
extern void func_0038A348(void);
extern void func_003D8978_00388ED8(s32);
extern void func_003D89F8(void);
extern void func_003D9618_00388ED8(s32);
extern void func_0038A3C0(void);
extern void func_00386108(s32);
extern void func_00392AC8(void);
extern s32 func_003A12A8(s32);
extern void func_0038AD28(void);
extern void func_003AA060_00388ED8(s32);
extern void func_003AFA18(void);
extern void func_00396C18(void);
extern void func_003B34A0(void);
extern void func_003B3510(s32);
extern void func_003B34D8(void);
extern void func_00381C70(void);
extern void func_0038B200(s32, s32, s32, s32);
extern void func_0038AFA0(void);
extern void func_003A9348_00388ED8(void *);
extern void func_003A96A8(s32);
extern void func_003D0538(void *);
extern void func_003CF408(void);
extern void func_003DDB20(void);
extern void func_003D9FE8(void);
extern void func_003E0EC8(void *);
extern void func_003DF1D8(void);
extern void func_003C3568(void);
extern void func_003868A0(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00388ED8);

LINKER_REMNANT("asm/boot_elf/remnants", func_00389600);
