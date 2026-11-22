#include "common.h"

typedef struct {
    u8 pad0[6];
    s16 h6;
} S_4DBFE8_Ent;
typedef struct {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[2];
    u8 b13;
    u8 pad14[8];
    S_4DBFE8_Ent *entries[1];
} S_4DBFE8_Hdr;
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x3F];
    S_4DBFE8_Hdr *hdrs[1];
} S_4DBFE8_Tbl;
typedef struct {
    u8 pad0[0x24];
    S_4DBFE8_Tbl *tbl;
} S_4DBFE8_Obj;
typedef struct { u8 pad[0xB0]; } S_4DC790;
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[8944];
    u128_t q[8];
    s32 i[8];
    f32 a[8];
    f32 b[8];
    s16 count;
} S_4DF808;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[128];
    s128 v128;
    s128 v144;
    u8 pad160[336];
    s16 h496;
    u8 pad498[126];
    f32 f624;
    f32 f628;
    u8 pad632[12];
    f32 f644;
    u8 pad648[9016];
    u8 *obj;
    u8 pad9668[8];
    s32 w9676;
} S_001A4BE0;
typedef struct {
    u8 p0[0x10];
    u128_t q10;
    u8 p20[0x98 - 0x20];
    s32 f98;
    u8 p9C[0xA8 - 0x9C];
    u8 bA8;
    u8 pA9[0xC0 - 0xA9];
    u8 fC0[0x30];
    u128_t qF0;
} Obj_4E09A8;
typedef struct {
    u8 p0[0x80];
    u128_t q80;
    u128_t q90;
    u8 pA0[0x1F0 - 0xA0];
    s16 h1F0;
    u8 p1F2[0x270 - 0x1F2];
    f32 f270;
    f32 f274;
    u8 p278[0x284 - 0x278];
    f32 f284;
    u8 p288[0x25C0 - 0x288];
    Obj_4E09A8 *f25C0;
    s32 f25C4;
    u8 p25C8[0x25E5 - 0x25C8];
    u8 b25E5;
} S_4E09A8;
typedef struct {
    u8 pad0[8800];
    f32 x2260;
    f32 x2264;
} S_004E1168;
typedef unsigned long u64l;
typedef struct {
    u64l a;
    u64l b;
    u64l c;
    u64l d;
} E_4E1758;
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    u64l x10;
    u64l data[1];
} H_4E1758;
typedef struct { u8 pad[164]; f32 a; f32 b; } S_004E25C8;
typedef struct { u8 pad[340]; f32 a; f32 b; } S_004E25E0;
typedef struct { u8 pad[516]; f32 a; f32 b; } S_004E25F8;
typedef struct { u8 pad[692]; f32 a; f32 b; } S_004E2610;

typedef struct {
    u8 p0[0x1B8];
    s32 f1B8;
    u8 p1BC[0xC0C - 0x1BC];
    s32 fC0C;
    u8 pC10[0x147F - 0xC10];
    u8 b147F;
    u8 p1480[0x25C0 - 0x1480];
    u8 *f25C0;
    s32 f25C4;
} S_004E1218;

typedef struct {
    u8 p0[0x600];
    s32 f600;
    u8 p604[0x650 - 0x604];
    f32 f650;
    u8 p654[0x65C - 0x654];
    s16 h65C;
    u8 p65E[0x25C0 - 0x65E];
    u8 *f25C0;
    s32 f25C4;
} S_4E2E30;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x10];
    f32 angle;
    u8 pad9C[0x350 - 0x9C];
    f32 z;
    u8 pad354[0x9C8 - 0x354];
    u16 counter;
} G_004E5840;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x110 - 0x88];
    f32 vx;
    f32 vy;
    u8 pad118[0x350 - 0x118];
    f32 z;
    u8 pad354[0x9C6 - 0x354];
    s16 counter;
    u8 pad9C8[0x2848 - 0x9C8];
    f32 amount;
} Emit_004E5A20;

/* declared by functions of L01_004DF428.c, which this file was cut from */
extern void func_0038CD28(s32, S_4DBFE8_Ent *, s32);
typedef struct {
    u8 pad0[0x24];
    s32 fire_sequence;
    u8 pad28[0xF0 - 0x28];
} GunRow_4DFDB0;
extern G_4DD4B0 D_001A4BE0;
extern u8 D_001425C0[];
extern GunRow_4DFDB0 D_L01_002C5600[];
extern s32 func_L01_004E9238(s32 slot);
extern s32 D_001A71A0[];
extern S_4DC790 D_L01_002F4540[];
typedef int u128_4E0618 __attribute__((mode(TI)));
typedef struct {
    u8 joint;
    u8 active;
    u8 pad2;
    u8 set;
    u8 pad4[0xC - 4];
    f32 amount;
    u128_4E0618 a;
    u128_4E0618 b;
    u128_4E0618 c;
} Lid_4E0618;
typedef struct {
    u8 pad0[0x43];
    u8 seq;
} Moby_4E0618;
extern void func_L01_0043A430(Moby_4E0618 *moby, s32 joint, Lid_4E0618 *lid);
extern u8 D_001D5470;
extern s32 D_L01_001DFB40;
extern f32 D_L01_001DBD3C __attribute__((section(".sdata")));
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004E3268(void);
extern void func_0038CC88(void *dst, void *src, s32 n);

/* localdecomp:start func_L01_004E2988 */
#include "vu0.h"
typedef struct { u8 pad[0x20E]; s16 mode; u8 pad210[0x1A28-0x210]; f32 phase; } Hero_004E2988;
extern G_4DD4B0 D_001A4BE0;
extern Lid_4E0618 D_L01_001E1420[] __attribute__((section(".sdata")));
extern Lid_4E0618 D_L01_001E1460[] __attribute__((section(".sdata")));
extern u8 D_001D5470;
extern f32 D_L01_001DBD3C __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DBD3C, 4");
extern s32 D_L01_001DBFA8;
__asm__(".extern D_L01_001DBFA8, 4");
extern s32 D_L01_001DBFAC;
__asm__(".extern D_L01_001DBFAC, 4");
extern s32 D_L01_001DBFB0;
__asm__(".extern D_L01_001DBFB0, 4");
extern s32 D_L01_001DBFB4;
__asm__(".extern D_L01_001DBFB4, 4");
extern s32 D_L01_001DBFB8;
__asm__(".extern D_L01_001DBFB8, 4");
extern s32 D_L01_001DBFBC;
__asm__(".extern D_L01_001DBFBC, 4");
extern s32 D_L01_001DBFC0;
__asm__(".extern D_L01_001DBFC0, 4");
extern s32 D_L01_001DBFC4;
__asm__(".extern D_L01_001DBFC4, 4");
void func_L01_004E2988(u8 *obj) {
    extern void func_L01_004E27A8(u8 *,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_003C2F58(u8 *,s32,u128_t *);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_004E35D0(u128_t *,s32,f32,f32);
    extern void func_L01_0043A430(Moby_4E0618 *,s32,Lid_4E0618 *);
    union { u128_t q; f32 f[4]; } point;
    Lid_4E0618 *lid;
    s32 cls;
    *(u16 *)(obj+0x34) |= 0x10;
    if ((*(Hero_004E2988 *)&D_001A4BE0).mode) {
        func_L01_004E27A8(obj,D_L01_001DBFAC,D_L01_001DBFB0,D_L01_001DBFB4,D_L01_001DBFB8,D_L01_001DBFBC,D_L01_001DBFC0,D_L01_001DBFC4,D_L01_001DBFA8);
    } else {
        func_L01_004E27A8(obj,0x38,0x88,0x40,0x80,0x18,0x3C,0x18,0x64);
    }
    if (*(s16 *)(obj+0xAA)==0x1159 || *(s16 *)(obj+0xAA)==0x19C9) {
        func_003C2F58(obj,6,&point.q);
        if (fabs_asm(*(f32 *)(obj+0x18)-point.f[2])>2.0f) {
            func_L01_004E35D0(&point.q,0x200000C0,0.25f,0.15f);
        }
    } else if (*(s16 *)(obj+0xAA)==0x57) {
        func_003C2F58(obj,7,&point.q);
        (*(Hero_004E2988 *)&D_001A4BE0).phase=func_0038DAB8((*(Hero_004E2988 *)&D_001A4BE0).phase,0.0802851543f);
        func_L01_004E35D0(&point.q,(((s32)((func_0038D0B0((*(Hero_004E2988 *)&D_001A4BE0).phase)*0.5f+0.5f)*13.0f)+0x17)<<24)|0xC0,0.04f,0.07f);
    } else if (*(s16 *)(obj+0xAA)==10 || *(s16 *)(obj+0xAA)==0x1F6B) {
        func_003C2F58(obj,1,&point.q);
        (*(Hero_004E2988 *)&D_001A4BE0).phase=func_0038DAB8((*(Hero_004E2988 *)&D_001A4BE0).phase,0.0802851543f);
        func_L01_004E35D0(&point.q,(((s32)((func_0038D0B0((*(Hero_004E2988 *)&D_001A4BE0).phase)*0.5f+0.5f)*13.0f)+0x17)<<24)|0xC0,0.04f,0.07f);
    }
    cls=*(s16 *)(obj+0xAA);
    lid=D_L01_001E1420;
    if (cls==0x27D) lid=D_L01_001E1460;
    if (D_001D5470 && !lid->active) {
        if (cls==0x27D) {
            func_L01_0043A430((Moby_4E0618 *)obj,1,lid);
        } else {
            func_L01_0043A430((Moby_4E0618 *)obj,cls==0x57 ? 5:2,lid);
        }
        { f32 angle = D_L01_001DBD3C;
        ((f32 *)&lid->b)[0]=angle;
        ((f32 *)&lid->b)[1]=angle;
        ((f32 *)&lid->b)[2]=angle; }
    }
}
/* localdecomp:end func_L01_004E2988 */

/* localdecomp:start func_L01_004E2C48 */
typedef struct {
    u8 pad0[0x1B8]; s32 timer;
    u8 pad1BC[0x1200 - 0x1BC]; u8 *attachment;
    u8 pad1204[0x1228 - 0x1204]; s32 weapon;
    u8 pad122C[0x25C0 - 0x122C]; u8 *moby; s32 state;
    u8 pad25C8[0x2818 - 0x25C8]; unsigned long saved_color; s32 flashing;
} Hero_004E2C48;
typedef struct {
    u8 b0; u8 active;
    u8 pad2[0xF0 - 2];
} Gun_004E2C48;
extern G_4DD4B0 D_001A4BE0;

void func_L01_004E2C48(void) {
    extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);
    extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
    extern void func_L01_004E2720(void);
    extern void func_L01_004E27A0_004E2C48(u8 *, u8 *);
    s32 r, g, b;
    s32 flash = 0;

    if ((*(Hero_004E2C48 *)&D_001A4BE0).state == 0x82 ||
        (*(Hero_004E2C48 *)&D_001A4BE0).state == 0xB1 ||
        (*(Hero_004E2C48 *)&D_001A4BE0).state == 0x84) {
        flash = (*(Hero_004E2C48 *)&D_001A4BE0).timer < 25;
    }
    if (flash) {
        if (!(*(Hero_004E2C48 *)&D_001A4BE0).flashing) {
            (*(Hero_004E2C48 *)&D_001A4BE0).saved_color =
                *(unsigned long *)((*(Hero_004E2C48 *)&D_001A4BE0).moby + 0x38);
            (*(Hero_004E2C48 *)&D_001A4BE0).flashing = 1;
        }
        func_003C6FB0((*(Hero_004E2C48 *)&D_001A4BE0).moby, &r, &g, &b);
        if ((*(Hero_004E2C48 *)&D_001A4BE0).timer % 4 < 3) {
            r = 0;
            g = 0;
            b = 0;
        } else {
            r = 0x90;
            g = 0x90;
            b = 0xF0;
        }
        func_L01_0043B9E8((*(Hero_004E2C48 *)&D_001A4BE0).moby, r, g, b);
        func_L01_004E2720();
    } else if ((*(Hero_004E2C48 *)&D_001A4BE0).flashing) {
        *(unsigned long *)((*(Hero_004E2C48 *)&D_001A4BE0).moby + 0x38) =
            (*(Hero_004E2C48 *)&D_001A4BE0).saved_color;
        (*(Hero_004E2C48 *)&D_001A4BE0).flashing = 0;
    }
    if ((*(Hero_004E2C48 *)&D_001A4BE0).weapon >= 0 &&
        ((Gun_004E2C48 *)D_L01_002C5600)[D_001425C0[(*(Hero_004E2C48 *)&D_001A4BE0).weapon]].active &&
        (*(Hero_004E2C48 *)&D_001A4BE0).attachment) {
        func_L01_004E27A0_004E2C48((*(Hero_004E2C48 *)&D_001A4BE0).attachment,
                          (*(Hero_004E2C48 *)&D_001A4BE0).moby);
    }
}
/* localdecomp:end func_L01_004E2C48 */

/* localdecomp:start func_L01_004E2DC8 */
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);

void func_L01_004E2DC8(void) {
    u8 *b = (u8 *)&D_001A4BE0;
    s32 x = ((S_4E09A8 *)b)->f25C4;

    if (x != 0x81 && x != 0x50) {
        return;
    }
    func_L01_0044EAE0(((S_4E09A8 *)b)->f25C0, b + 0x738, b + 0x73C, 0.3f, 0.139626354f, -1.0f);
}
/* localdecomp:end func_L01_004E2DC8 */

/* localdecomp:start func_L01_004E2E30 */
extern void func_L01_0044EBA0(u8 *, f32 *, f32 *, f32, f32, f32);

void func_L01_004E2E30(void) {
    if ((*(S_4E2E30 *)&D_001A4BE0).f25C4 == 0x81 || (*(S_4E2E30 *)&D_001A4BE0).f25C4 == 0x50) {
        func_L01_0044EBA0((*(S_4E2E30 *)&D_001A4BE0).f25C0, (f32 *)((u8 *)&D_001A4BE0 + 0x740),
                          (f32 *)((u8 *)&D_001A4BE0 + 0x744), 0.1745329252f, 0.031415927f, 0.0418879053f);
    }
    if ((*(S_4E2E30 *)&D_001A4BE0).h65C == 0) {
        return;
    }
    if ((*(S_4E2E30 *)&D_001A4BE0).f600 != 0) {
        return;
    }
    *(f32 *)((*(S_4E2E30 *)&D_001A4BE0).f25C0 + 0xF4) = (*(S_4E2E30 *)&D_001A4BE0).f650;
}
/* localdecomp:end func_L01_004E2E30 */
