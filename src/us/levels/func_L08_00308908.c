#include "common.h"

/* NTSC-U counterpart of func_L08_00308C30 (src/levels/shared/L08_00308978.c) */
#include "vu0.h"

/* localdecomp:start func_L08_00308908 */
#include "vu0.h"
typedef vu0_v4 V_00308C30;
typedef struct { f32 scale; u8 *obj; } P_00308C30;
__asm__(".extern D_L08_001DC4F4_00308908, 4");
__asm__(".extern D_L08_001DC4F8_00308908, 4");
__asm__(".extern D_L08_001DC4FC_00308908, 4");
__asm__(".extern D_L08_001DC500, 4");
__asm__(".extern D_L08_001DC504, 4");
__asm__(".extern D_L08_001DC508, 4");
extern f32 D_L08_001DC4F4_00308908, D_L08_001DC4F8_00308908, D_L08_001DC4FC_00308908, D_L08_001DC500, D_L08_001DC504, D_L08_001DC508;
typedef struct { u8 p0[0x25C4]; s32 f25C4; u8 p1[4]; s32 f25CC; } H_00308C30;
typedef struct { u8 p0[0x42]; u16 f42; } G_00308C30;
extern u8 D_L08_001DF080_00308908[] __attribute__((section(".sdata")));
typedef struct { u8 p0[0x464]; u8 a[1]; } T_00308C30;
extern T_00308C30 D_L08_00234610_00308908, D_L08_00235280_00308908;
extern H_00308C30 D_001A4BE0;
extern G_00308C30 D_00142660;
__asm__(".extern D_001A4BE0, 16");
__asm__(".extern D_00142660, 16");
extern u8 D_001A4C60[], D_001A4CB0[], D_001BBC40[], D_001BBE90[];
extern s32 D_001D545C_sda_00308908, D_001D545C;
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_001D545C_sda_00308908, 4");
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_003887A0(void *);
extern void func_L01_0040C188(void *, void *, f32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_003BD360(void *);
void func_L08_00308908(u8 *m) {
    P_00308C30 *p = *(P_00308C30 **)(m+0x68);
    ++*(u16 *)(m+0x96);
    switch (m[0x20]) {
    case 0:
        func_L01_00441FB8(m,1,-1);
        if (m[0x43]) func_003BE4F0(m,0,0,0);
        break;
    case 1:
        if (func_00388800(m+0x10,D_001A4C60) < D_L08_001DC4F4_00308908) {
            p->scale = D_L08_001DC504;
            *(f32 *)(m+0x48) = D_L08_001DC504 + D_L08_001DC504;
            func_L01_00441FB8(m,2,-1);
        }
        if (m[0x31]) func_L08_00308670(m);
        break;
    case 2: {
        V_00308C30 d;
        f32 len, speed, threshold=0.12f;
        p->scale += (1.0f-p->scale)*D_L08_001DC500;
        *(f32 *)(m+0x48)=p->scale*2.0f;
        vec_sub_ba(&d, D_001A4CB0, m+0x10);
        d.z+=0.6f;
        len=func_003887A0(&d);
        if (*(u16 *)(m+0x96)<180) {
            if (*(s32 *)(D_001A4CB0+0x24F4)!=49) speed=D_L08_001DC4F8_00308908*0.016666668f*p->scale;
            else { speed=D_L08_001DC4FC_00308908*0.016666668f*p->scale; threshold=0.8f; }
        } else speed=p->scale+p->scale;
        func_L01_0040C188(&d,&d,speed);
        vec_add_ab(m+0x10, m+0x10, &d);
        if (*(f32 *)(m+0x2C)>0.1f || len<threshold || len<speed) {
            *(f32 *)(m+0x2C)-=D_L08_001DC508**(f32 *)(*(u8 **)(m+0x24)+0x24);
        }
        if ((len<speed && *(f32 *)(m+0x2C)<*(f32 *)(*(u8 **)(m+0x24)+0x24)*0.01f) || D_001A4BE0.f25CC==20 || D_001A4BE0.f25CC==25 || D_001A4BE0.f25C4==57 || D_001A4BE0.f25C4==116) {
            u8 *obj, *obj2;
            func_0039FE80(1,0,m);
            ++D_00142660.f42;
            func_L01_0044ECE0(0xD99,-1,0);
            obj=p->obj;
            if (obj) {
                u16 idx;
                u8 *q;
                D_L08_00234610_00308908.a[*(s16 *)(obj+0xB2)]=obj[0xB0]+2;
                obj2=p->obj;
                if (obj2[0xB0]==255 || (!(D_L08_001DF080_00308908[obj2[0xB0]]&0x80) && (D_001BBC40[obj2[0xB0]+D_001D545C*16]&0x80))) {
                    D_L08_00235280_00308908.a[*(s16 *)(obj2+0xB2)]=obj2[0xB0]+2;
                }
                idx=*(u16 *)(p->obj+0xB2);
                if (idx&1) {
                    q=&D_001BBE90[((s16)idx>>1)+D_001D545C_sda_00308908*1024];
                    if (((*q>>4)&7)!=7) *q+=16;
                } else {
                    q=&D_001BBE90[((s16)idx>>1)+D_001D545C_sda_00308908*1024];
                    if ((*q&7)!=7) ++*q;
                }
            }
            func_003BD360(m);
        } else func_L08_00308670(m);
        break;
    }
    }
}
/* localdecomp:end func_L08_00308908 */
