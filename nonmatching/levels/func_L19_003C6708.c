/* NTSC-U draft (Codex wave 3): C of func_L19_003C4758, the NTSC-U twin of func_L19_003C6708, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 133 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L19_003C4758", whose code is not the PAL one).
 * Worker's note: 133 diff; ten checks; best log func_L19_003C4758.check09.log; native states 0..4 decoded in .switch.txt; remaining 64-bit mask/add operand registers, marker branch, global-store and VU scheduling; allowed flags only
 */
#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

/* localdecomp:start func_L19_003C4758 */
typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    u8 *marker;
    s16 f44, f46;
    s32 f48, f4C;
} PV_3C4758;
extern s32 D_001D66D4_sda;
extern s32 D_L19_001D66D0, D_L19_001E6470[];
extern u8 *D_L19_001DF71C, *D_L19_001DF800;
extern u8 *D_001DF71C_sda;
extern u8 D_001A4C60[], D_001A4BE0[], D_0014270B[], D_0014270C[], D_001A71C4[];
extern u32 D_00142C54[];
extern s32 D_001A8000[], D_001D545C;
extern u8 D_001BBC40[], D_L19_001E2080[];
extern f32 D_001DEA74_sda, D_001DEA78_sda, D_001DEA7C_sda, D_001DEA80_sda;
extern s32 D_001DEA84_sda, D_001DF758_sda;
extern u16 D_L19_001DF42C;
extern s16 *D_L19_0021C260[];
extern f32 D_L19_001DF050[];
extern s32 func_L01_00448E90(void *);
extern void func_003BD360(void *);
extern void func_L19_003C4F68(void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_00399F90(void);
extern void func_L19_003C4F80(void *);
extern void func_L19_003BD048(void *, void *, void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_00417F60(s32, s32);
extern u8 *func_L01_003F08D8(s32, s32);
extern void func_L16_00400938(s32, void *);
extern void func_L01_003F0980(s32, void *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003E94A0(s32, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_003E9510(s32, void *);
extern void func_L01_003E9730(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_0050DA68(void *, s32, f32);
extern void func_003BEBF8(f32, f32, void *);
extern void func_L01_00438430(s32);
extern void func_L19_003C50A8(void *);

__asm__(".extern D_001D66D4_sda, 4");
__asm__(".extern D_001DF71C_sda, 4");
__asm__(".extern D_001DEA74_sda, 4");
__asm__(".extern D_001DEA78_sda, 4");
__asm__(".extern D_001DEA7C_sda, 4");
__asm__(".extern D_001DEA80_sda, 4");
__asm__(".extern D_001DEA84_sda, 4");
__asm__(".extern D_001DF758_sda, 4");
void func_L19_003C4758(u8 *o) {
    vu0_v4 sum, rotation;
    PV_3C4758 *v;
    u8 *m, *p;
    s16 *list;
    f32 count;
    s32 all;
    v=*(PV_3C4758 **)(o+0x68);
    if (!func_L01_00448E90(o+0x10)) return;
    if ((u32)(D_001D66D4_sda-1)<2 || D_L19_001D66D0==1 || D_L19_001D66D0==2) {
        if (D_L19_001E6470[0]==1) {
            u8 *m;
            m=D_L19_001DF71C+(v->f4C<<8);
            if (m) func_003BD360(m);
        }
        return;
    }
    switch(o[0x20]) {
    case 0:
        func_L19_003C4F68(o);
        func_L01_00441FB8(o,1,-1);
        break;
    case 1:
        if (func_0037E0F0(D_001A4C60,v->f14,0) || D_001A4C60[0x2564]==1) {
            D_0014270B[0]=1;
            func_00399F90();
            func_L01_00441FB8(o,2,-1);
        }
        break;
    case 2: {
        u8 *p;
        if (D_001A71C4[0]!=1) func_L19_003C4F80(o);
        p=D_L19_001DF800+(v->f0C<<7);
        func_L19_003BD048(D_L19_001DF71C+(v->f04<<8),p+0x30,p+0x70);
        func_L01_00441FB8(o,3,-1);
        break;
    }
    case 3: {
        u8 *m;
        struct Moby *mobys=(struct Moby *)D_001DF71C_sda;
        if (D_00142C54[0]&0x800000) {
            
            if (((unsigned long)0x8200 << 23)==(*(unsigned long *)(((u8 *)&mobys[v->f04])+0x30)&((unsigned long)0x8208 << 29)) && *(s32 *)(((u8 *)&mobys[v->f04])+0x98)==0) {
                *(u16 *)(((u8 *)&mobys[v->f04])+0x34)&=0xFFBE;
                *(u16 *)(((u8 *)&mobys[v->f04])+0x34)|=*(u16 *)(*(u8 **)(((u8 *)&mobys[v->f04])+0x24)+0x44)&0x1000;
                *(s32 *)(((u8 *)&mobys[v->f04])+0x98)=*(s32 *)(*(u8 **)(((u8 *)&mobys[v->f04])+0x24)+0x10);
                *(u16 *)(((u8 *)&mobys[v->f04])+0x34)&=0xFFFD;
            }
            if ((D_L19_001DF71C+(v->f4C<<8)) && (D_L19_001DF71C+(v->f4C<<8))[0x20]!=0xFE && (D_L19_001DF71C+(v->f4C<<8))[0x20]!=0xFD) func_003BD360((D_L19_001DF71C+(v->f4C<<8)));
        } else {
            if (((unsigned long)0x8200 << 23)!=(*(unsigned long *)(((u8 *)&mobys[v->f04])+0x30)&((unsigned long)0x8208 << 29)) || *(s32 *)(((u8 *)&mobys[v->f04])+0x98)!=0) {
                *(u16 *)(((u8 *)&mobys[v->f04])+0x34)|=0x41;
                *(u16 *)(((u8 *)&mobys[v->f04])+0x34)&=0xEFFF;
                *(s32 *)(((u8 *)&mobys[v->f04])+0x98)=0;
                func_L01_004A6DF8(&mobys[v->f04],1);
                *(u16 *)(((v->f04<<8)+D_L19_001DF71C)+0x34)|=2;
            }
        }
        if (func_0037E0F0(D_001A4C60,v->f38,0)) {
            if (++v->f46>1200) {
                if (D_001A8000[0]>=0) func_L01_00417F60(0xB85,0x28);
                v->f46=0;
            }
            if (v->marker==0) {
                v->marker=func_L01_003F08D8(0,5);
                if (!v->marker) goto marker_done;
            }
            {
                f32 b=D_001DEA78_sda, a=D_001DEA74_sda, c=D_001DEA7C_sda;
                *(f32 *)(v->marker+8)=a;
                *(f32 *)(v->marker+4)=b;
                *(f32 *)(v->marker)=c;
                func_L16_00400938(0,v->marker);
            }
        } else if (v->marker) {
            func_L01_003F0980(0,v->marker);
            v->marker=0;
        }
marker_done:
        if (func_0037E0F0(D_001A4C60,v->f3C,0)) *(f32 *)(D_001A4C60+0x19DC)=D_001DEA80_sda;
        else *(f32 *)(D_001A4C60+0x19DC)=0.0f;
        *(s32 *)(*(u8 **)(D_L19_001DF71C+(v->f28<<8)+0x68)+0xC)=func_L01_00452F60(D_L19_001DF71C+(v->f2C<<8));
        D_L19_001DF42C++;
        if (v->f24>=0 && func_0037E0F0(D_001A4C60,v->f24,0)) {
            if (!D_001DEA84_sda) {
                if (++v->f44>30) {
                    func_L01_003E9588(0,D_L19_001E2080,D_L19_001E2080+0x10,0,0,0);
                    func_L01_003E94A0(0,D_L19_001DF800+(v->f34<<7)+0x30);
                    D_001DEA84_sda=1;
                    v->f24=-1;
                }
            } else {
                v->f24=-1;
                v->f30=-1;
            }
        }
        if (D_001DEA84_sda && v->f30>=0) {
            u8 *m;
            qzero(&sum);
            count=0.0f;
            all=1;
            list=D_L19_0021C260[v->f30];
            while ((v->f30&0xFF)!=0xFF && v->f30<=D_001DF758_sda && list && (list[-1]>=0 || list==D_L19_0021C260[v->f30])) {
                m=D_L19_001DF71C+((*((u16 *)list)&0x7FFF)<<8);
                if (!m) break;
                __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "+m"(sum) : "m"(*(vu0_v4 *)(m+0x10)) : "vf1","vf2");
                count+=1.0f;
                if (m[0x20]!=2) all=0;
                list++;
            }
            func_003886E8(&sum,&sum,1.0f/count);
            rotation.x=0.0f;
            rotation.y=-func_00388A28(func_00388800(D_L19_001DF800+(v->f34<<7)+0x30,&sum),sum.z-*(f32 *)(D_L19_001DF800+(v->f34<<7)+0x38));
            p=D_L19_001DF800+(v->f34<<7);
            rotation.z=func_00388A28(sum.x-*(f32 *)(p+0x30),sum.y-*(f32 *)(p+0x34));
            func_L01_003E9510(0,&rotation);
            if (all) {
                u8 *hero=D_001A4BE0;
                *(f32 *)(hero+0x98)=func_00388A28(sum.x-*(f32 *)(hero+0x80),sum.y-*(f32 *)(hero+0x84));
                func_L01_003E9730(0,2);
                v->f30=-1;
            }
        }
        if (func_L01_00452F60(D_L19_001DF71C+(v->f20<<8))) func_L01_00441FB8(o,4,-1);
        if ((D_001BBC40[v->f10+(D_001D545C<<4)]&0x80) && func_0037E0F0(D_001A4C60,v->f18,0)) func_L01_00441FB8(o,4,-1);
        break;
    }
    case 4: {
        u8 *p;
        if (*(u16 *)(o+0x96)==60) {
            p=D_L19_001DF800+(v->f48<<7);
            func_L01_0050DA68(p+0x30,0,*(f32 *)(p+0x78));
        }
        if (*(u16 *)(o+0x96)>=121) func_003BEBF8(1.0f,0.020000001415610313f,D_L19_001DF050);
        if (*(u16 *)(o+0x96)>=181) {
            func_L01_00438430(v->f10);
            D_0014270C[0]=1;
            func_00399F90();
            func_L19_003C50A8(o);
            func_L01_00441FB8(o,1,-1);
        }
        break;
    }
    }
    if (*(u16 *)(o+0x96)<0xFFFF) ++*(u16 *)(o+0x96);
}
/* localdecomp:end func_L19_003C4758 */
