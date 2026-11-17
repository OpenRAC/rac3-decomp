/* NTSC-U draft (2026-11-14, Codex worker): C of func_L08_00308908, the NTSC-U twin of func_L08_00308C30, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L08_00308978.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
/* localdecomp:start func_L08_00308908 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_308908;
typedef struct { f32 scale; u8 *obj; } P_308908;
extern f32 D_001DC4F4_sda, D_001DC4F8_sda, D_001DC4FC_sda, D_001DC500_sda, D_001DC504_sda, D_001DC508_sda;
extern u8 D_001A4C60[], D_001A4CB0[], D_001A4BE0[], D_00142660[], D_L08_00234610[], D_L08_00235280[], D_L08_001DF080[], D_001BBC40[], D_001BBE90[];
extern s32 D_001D545C_sda, D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L01_00441FB8(void *,s32,s32);
extern void func_003BE4F0(void *,s32,s32,s32);
extern f32 func_00388800(void *,void *);
extern f32 func_003887A0(void *);
extern void func_L01_0040C188(void *,void *,f32);
extern void func_L08_00308670(void *);
extern void func_0039FE80(s32,s32,void *);
extern void func_L01_0044ECE0(s32,s32,s32);
extern void func_003BD360(void *);
void func_L08_00308908(u8 *m) {
    P_308908 *p = *(P_308908 **)(m+0x68);
    ++*(u16 *)(m+0x96);
    switch (m[0x20]) {
    case 0:
        func_L01_00441FB8(m,1,-1);
        if (m[0x43]) func_003BE4F0(m,0,0,0);
        break;
    case 1:
        if (func_00388800(m+0x10,D_001A4C60) < D_001DC4F4_sda) {
            p->scale = D_001DC504_sda;
            *(f32 *)(m+0x48) = D_001DC504_sda * 2.0f;
            func_L01_00441FB8(m,2,-1);
        }
        if (m[0x31]) func_L08_00308670(m);
        break;
    case 2: {
        V_308908 d;
        f32 len, speed, threshold=0.12f;
        p->scale += (1.0f-p->scale)*D_001DC500_sda;
        *(f32 *)(m+0x48)=p->scale*2.0f;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(d) : "m"(*(V_308908 *)(m+0x10)), "m"(*(V_308908 *)D_001A4CB0) : "vf1","vf2");
        d.z+=0.6f;
        len=func_003887A0(&d);
        if (*(u16 *)(m+0x96)<180) {
            if (*(s32 *)(D_001A4CB0+0x24F4)!=49) speed=D_001DC4F8_sda*0.0166666675f*p->scale;
            else { speed=D_001DC4FC_sda*0.0166666675f*p->scale; threshold=0.8f; }
        } else speed=p->scale*2.0f;
        func_L01_0040C188(&d,&d,speed);
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(*(V_308908 *)(m+0x10)) : "m"(d) : "vf1","vf2");
        if (*(f32 *)(m+0x2C)>0.1f || len<threshold || len<speed) {
            *(f32 *)(m+0x2C)-=D_001DC508_sda**(f32 *)(*(u8 **)(m+0x24)+0x24);
            if (len<speed && *(f32 *)(m+0x2C)<*(f32 *)(*(u8 **)(m+0x24)+0x24)*0.01f) goto destroy;
        }
        if (*(s32 *)(D_001A4BE0+0x25CC)==20 || *(s32 *)(D_001A4BE0+0x25CC)==25 || *(s32 *)(D_001A4BE0+0x25C4)==57 || *(s32 *)(D_001A4BE0+0x25C4)==116) {
            u8 *obj;
        destroy:
            func_0039FE80(1,0,m);
            ++*(u16 *)(D_00142660+0x42);
            func_L01_0044ECE0(0xD99,-1,0);
            obj=p->obj;
            if (obj) {
                s32 idx;
                u8 *q;
                D_L08_00234610[0x464+*(s16 *)(obj+0xB2)]=obj[0xB0]+2;
                obj=p->obj;
                if (obj[0xB0]==255 || (!(D_L08_001DF080[obj[0xB0]]&0x80) && (D_001BBC40[D_001D545C*16+obj[0xB0]]&0x80))) {
                    D_L08_00235280[0x464+*(s16 *)(obj+0xB2)]=obj[0xB0]+2;
                }
                idx=*(s16 *)(p->obj+0xB2);
                if (idx&1) {
                    q=D_001BBE90+D_001D545C_sda*1024+(idx>>1);
                    if (((*q>>4)&7)!=7) *q+=16;
                } else {
                    q=D_001BBE90+D_001D545C_sda*1024+(idx>>1);
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
