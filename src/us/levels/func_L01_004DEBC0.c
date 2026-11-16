#include "common.h"

/* NTSC-U counterpart of func_L01_004E2988 (src/levels/shared/L01_004DF428.c) */
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
extern G_4DD4B0 D_001A4BE0;
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
extern void func_L01_00437350(Moby_4E0618 *moby, s32 joint, Lid_4E0618 *lid);
extern G_4DD4B0 D_001A4BE0;
extern u8 D_001D5470;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;

/* localdecomp:start func_L01_004DEBC0 */
#include "vu0.h"
typedef struct { u8 pad[0x20E]; s16 mode; u8 pad210[0x1A28-0x210]; f32 phase; } Hero_004E2988;
extern G_4DD4B0 D_001A4BE0;
extern Lid_4E0618 D_L01_001E14A0_004DEBC0[] __attribute__((section(".sdata")));
extern Lid_4E0618 D_L01_001E14E0_004DEBC0[] __attribute__((section(".sdata")));
extern u8 D_001D5470;
extern f32 D_L01_001DBD7C __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DBD7C, 4");
extern s32 D_L01_001DBFE8_004DEBC0;
__asm__(".extern D_L01_001DBFE8_004DEBC0, 4");
extern s32 D_L01_001DBFEC;
__asm__(".extern D_L01_001DBFEC, 4");
extern s32 D_L01_001DBFF0;
__asm__(".extern D_L01_001DBFF0, 4");
extern s32 D_L01_001DBFF4;
__asm__(".extern D_L01_001DBFF4, 4");
extern s32 D_L01_001DBFF8;
__asm__(".extern D_L01_001DBFF8, 4");
extern s32 D_L01_001DBFFC;
__asm__(".extern D_L01_001DBFFC, 4");
extern s32 D_L01_001DC000;
__asm__(".extern D_L01_001DC000, 4");
extern s32 D_L01_001DC004;
__asm__(".extern D_L01_001DC004, 4");
void func_L01_004DEBC0(u8 *obj) {
    extern void func_L01_004DEA08(u8 *,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_003BDA38(u8 *,s32,u128_t *);
    extern f32 func_00389380(f32,f32);
    extern f32 func_00388978(f32);
    extern void func_L01_004DF808(u128_t *,s32,f32,f32);
    extern void func_L01_00437350(Moby_4E0618 *,s32,Lid_4E0618 *);
    union { u128_t q; f32 f[4]; } point;
    Lid_4E0618 *lid;
    s32 cls;
    *(u16 *)(obj+0x34) |= 0x10;
    if ((*(Hero_004E2988 *)&D_001A4BE0).mode) {
        func_L01_004DEA08(obj,D_L01_001DBFEC,D_L01_001DBFF0,D_L01_001DBFF4,D_L01_001DBFF8,D_L01_001DBFFC,D_L01_001DC000,D_L01_001DC004,D_L01_001DBFE8_004DEBC0);
    } else {
        func_L01_004DEA08(obj,0x38,0x88,0x40,0x80,0x18,0x3C,0x18,0x64);
    }
    if (*(s16 *)(obj+0xAA)==0x1159 || *(s16 *)(obj+0xAA)==0x19C9) {
        func_003BDA38(obj,6,&point.q);
        if (fabs_asm(*(f32 *)(obj+0x18)-point.f[2])>2.0f) {
            func_L01_004DF808(&point.q,0x200000C0,0.25f,0.15f);
        }
    } else if (*(s16 *)(obj+0xAA)==0x57) {
        func_003BDA38(obj,7,&point.q);
        (*(Hero_004E2988 *)&D_001A4BE0).phase=func_00389380((*(Hero_004E2988 *)&D_001A4BE0).phase,0.06690429151058197f);
        func_L01_004DF808(&point.q,(((s32)((func_00388978((*(Hero_004E2988 *)&D_001A4BE0).phase)*0.5f+0.5f)*13.0f)+0x17)<<24)|0xC0,0.04f,0.07f);
    } else if (*(s16 *)(obj+0xAA)==10 || *(s16 *)(obj+0xAA)==0x1F6B) {
        func_003BDA38(obj,1,&point.q);
        (*(Hero_004E2988 *)&D_001A4BE0).phase=func_00389380((*(Hero_004E2988 *)&D_001A4BE0).phase,0.06690429151058197f);
        func_L01_004DF808(&point.q,(((s32)((func_00388978((*(Hero_004E2988 *)&D_001A4BE0).phase)*0.5f+0.5f)*13.0f)+0x17)<<24)|0xC0,0.04f,0.07f);
    }
    cls=*(s16 *)(obj+0xAA);
    lid=D_L01_001E14A0_004DEBC0;
    if (cls==0x27D) lid=D_L01_001E14E0_004DEBC0;
    if (D_001D5470 && !lid->active) {
        if (cls==0x27D) {
            func_L01_00437350((Moby_4E0618 *)obj,1,lid);
        } else {
            func_L01_00437350((Moby_4E0618 *)obj,cls==0x57 ? 5:2,lid);
        }
        { f32 angle = D_L01_001DBD7C;
        ((f32 *)&lid->b)[0]=angle;
        ((f32 *)&lid->b)[1]=angle;
        ((f32 *)&lid->b)[2]=angle; }
    }
}
/* localdecomp:end func_L01_004DEBC0 */
