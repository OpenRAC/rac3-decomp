#include "common.h"

/* localdecomp:start func_L08_00308978 */
#include "vu0.h"

__asm__(".extern D_L08_001DC4CC, 4");
__asm__(".extern D_L08_001DC4D0, 4");
__asm__(".extern D_L08_001DC4D4, 4");
__asm__(".extern D_L08_001DC4D8, 4");
__asm__(".extern D_L08_001DC4DC, 4");
__asm__(".extern D_L08_001DC4E0, 4");
__asm__(".extern D_L08_001DC4E4, 4");
__asm__(".extern D_L08_001DC4E8, 4");
__asm__(".extern D_L08_001DC4EC, 4");
__asm__(".extern D_L08_001DC4F0, 4");
__asm__(".extern D_L08_001DC4F4, 4");
__asm__(".extern D_L08_001DC4F8, 4");
__asm__(".extern D_L08_001DC4FC, 4");
extern f32 D_L08_001DC4CC;
extern f32 D_L08_001DC4D0;
extern f32 D_L08_001DC4D4;
extern f32 D_L08_001DC4D8;
extern s32 D_L08_001DC4DC;
extern s32 D_L08_001DC4E0;
extern s32 D_L08_001DC4E4;
extern f32 D_L08_001DC4E8;
extern f32 D_L08_001DC4EC;
extern s32 D_L08_001DC4F0;
extern s32 D_L08_001DC4F4;
extern s32 D_L08_001DC4F8;
extern s32 D_L08_001DC4FC;
extern s32 D_L08_001DEDC0;
extern vu0_v4 D_L08_001E1CC0;

extern s32 func_00382468(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L08_00308978(u8 *o) {
    vu0_v4 pos, v10, v20, v30, v40;
    s32 i, j;
    s32 c;
    f32 q;

    *(vu0_q *)&pos = *(vu0_q *)(o + 0x10);
    if (func_00382468(4) == 0) {
        func_L01_00443B88(&v10, D_L08_001DC4CC * 0.020000001f, D_L08_001DC4D0 * 0.020000001f);
        i = 2;
        func_L01_0046C470(&pos, &v10, D_L08_001DC4E0, D_L08_001DC4E8, D_L08_001DC4DC, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        do {
            func_L01_00443B88(&v20, D_L08_001DC4D4 * 0.020000001f, D_L08_001DC4D8 * 0.020000001f);
            vec_add_ab(&v10, &v10, &v20);
            func_L01_0046C470(&pos, &v10, D_L08_001DC4E4, D_L08_001DC4EC, D_L08_001DC4DC, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        } while (--i >= 0);
    }
    vec_sub_ba(&v30, &D_L08_001E1CC0, &pos);
    func_0038CF68(&v30, &v30, -0.3f);
    func_0038CF68(&v40, &v30, 0.1f);
    vec_add_ab(&v30, &v30, &pos);
    for (j = 0; j < 4; j++) {
        s32 x = (D_L08_001DEDC0 + j * 20) & 0xFF;
        s32 r = func_0038DBD8(D_L08_001DC4F0, D_L08_001DC4F4, fabs_asm(0.5f - (f32)(212 - (x * 5 + 2) / 6) / 212.0f));
        c = *(u8 *)&D_L08_001DEDC0;
        if (j & 2) c = c << 1;
        if (j & 1) c = 255 - c;
        func_L01_0046C2E8(&v30, r, c & 0xFF, D_L08_001DC4FC, D_L08_001DC4F8, 2, 0,
                          0, ((f32)j + 3.0f) * (*(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24)));
        vec_add_ab(&v30, &v30, &v40);
    }
}
/* localdecomp:end func_L08_00308978 */

/* localdecomp:start func_L08_00308C30 */
#include "vu0.h"
typedef vu0_v4 V_00308C30;
typedef struct { f32 scale; u8 *obj; } P_00308C30;
__asm__(".extern D_L08_001DC4B4, 4");
__asm__(".extern D_L08_001DC4B8, 4");
__asm__(".extern D_L08_001DC4BC, 4");
__asm__(".extern D_L08_001DC4C0, 4");
__asm__(".extern D_L08_001DC4C4, 4");
__asm__(".extern D_L08_001DC4C8, 4");
extern f32 D_L08_001DC4B4, D_L08_001DC4B8, D_L08_001DC4BC, D_L08_001DC4C0, D_L08_001DC4C4, D_L08_001DC4C8;
typedef struct { u8 p0[0x25C4]; s32 f25C4; u8 p1[4]; s32 f25CC; } H_00308C30;
typedef struct { u8 p0[0x42]; u16 f42; } G_00308C30;
extern u8 D_L08_001DF080[] __attribute__((section(".sdata")));
typedef struct { u8 p0[0x464]; u8 a[1]; } T_00308C30;
extern T_00308C30 D_L08_00234610, D_L08_00235280;
extern H_00308C30 D_001A4BE0;
extern G_00308C30 D_00142660;
__asm__(".extern D_001A4BE0, 16");
__asm__(".extern D_00142660, 16");
extern u8 D_001A4C60[], D_001A4CB0[], D_001BBC40[], D_001BBE90[];
extern s32 D_001D545C_sda, D_001D545C;
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_001D545C_sda, 4");
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CED8(void *);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_003C2880(void *);
void func_L08_00308C30(u8 *m) {
    P_00308C30 *p = *(P_00308C30 **)(m+0x68);
    ++*(u16 *)(m+0x96);
    switch (m[0x20]) {
    case 0:
        func_L01_004450F0(m,1,-1);
        if (m[0x43]) func_003C3A10(m,0,0,0);
        break;
    case 1:
        if (func_0038CF38(m+0x10,D_001A4C60) < D_L08_001DC4B4) {
            p->scale = D_L08_001DC4C4;
            *(f32 *)(m+0x48) = D_L08_001DC4C4 * 2.0f;
            func_L01_004450F0(m,2,-1);
        }
        if (m[0x31]) func_L08_00308978(m);
        break;
    case 2: {
        V_00308C30 d;
        f32 len, speed, threshold=0.12f;
        p->scale += (1.0f-p->scale)*D_L08_001DC4C0;
        *(f32 *)(m+0x48)=p->scale*2.0f;
        vec_sub_ba(&d, D_001A4CB0, m+0x10);
        d.z+=0.6f;
        len=func_0038CED8(&d);
        if (*(u16 *)(m+0x96)<150) {
            if (*(s32 *)(D_001A4CB0+0x24F4)!=49) speed=D_L08_001DC4B8*0.020000001f*p->scale;
            else { speed=D_L08_001DC4BC*0.020000001f*p->scale; threshold=0.8f; }
        } else speed=p->scale*2.4f;
        func_L01_0040E6B8(&d,&d,speed);
        vec_add_ab(m+0x10, m+0x10, &d);
        if (*(f32 *)(m+0x2C)>0.1f || len<threshold || len<speed) {
            *(f32 *)(m+0x2C)-=D_L08_001DC4C8*1.2f**(f32 *)(*(u8 **)(m+0x24)+0x24);
        }
        if ((len<speed && *(f32 *)(m+0x2C)<*(f32 *)(*(u8 **)(m+0x24)+0x24)*0.01f) || D_001A4BE0.f25CC==20 || D_001A4BE0.f25CC==25 || D_001A4BE0.f25C4==57 || D_001A4BE0.f25C4==116) {
            u8 *obj, *obj2;
            func_003A52A0(1,0,m);
            ++D_00142660.f42;
            func_L01_00451F60(0xD99,-1,0);
            obj=p->obj;
            if (obj) {
                u16 idx;
                u8 *q;
                D_L08_00234610.a[*(s16 *)(obj+0xB2)]=obj[0xB0]+2;
                obj2=p->obj;
                if (obj2[0xB0]==255 || (!(D_L08_001DF080[obj2[0xB0]]&0x80) && (D_001BBC40[obj2[0xB0]+D_001D545C*16]&0x80))) {
                    D_L08_00235280.a[*(s16 *)(obj2+0xB2)]=obj2[0xB0]+2;
                }
                idx=*(u16 *)(p->obj+0xB2);
                if (idx&1) {
                    q=&D_001BBE90[((s16)idx>>1)+D_001D545C_sda*1024];
                    if (((*q>>4)&7)!=7) *q+=16;
                } else {
                    q=&D_001BBE90[((s16)idx>>1)+D_001D545C_sda*1024];
                    if ((*q&7)!=7) ++*q;
                }
            }
            func_003C2880(m);
        } else func_L08_00308978(m);
        break;
    }
    }
}
/* localdecomp:end func_L08_00308C30 */
