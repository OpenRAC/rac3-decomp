#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad_00[0xAA];
    s16 f_AA;
} S_L14_00354B90;

typedef int Q_3537D8 __attribute__((mode(TI)));
typedef struct { int first,count; char pad[8]; vu0_v4 v[200]; } Table_3537D8;

/* localdecomp:start func_L14_003542F0 */
typedef int u128_t_3542F0 __attribute__((mode(TI)));
extern u8 D_L14_001D66B0;
extern s32 D_L14_001D67B8;
__asm__(".extern D_L14_001DD610, 4");
__asm__(".extern D_L14_001DD614, 4");
__asm__(".extern D_L14_001DD618, 4");
extern f32 D_L14_001DD610;
extern f32 D_L14_001DD614;
extern f32 D_L14_001DD618;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);
void func_L14_003542F0(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0x7F, &D_L14_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        t = *(f32 *)(a0 + 0x2C) / D_L14_001DD618;
        *(u128_t_3542F0 *)&a = 0;
        a.z = D_L14_001DD610 * t;
        b = a;
        *(u128_t_3542F0 *)&a = 0;
        a.z = 0.14000002f;
        func_L02_003E2E38(a0, &b, 0.1f, &a, 0x14, 3, 0.18f, 2.5f, 20.0f, 1.0f, 0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_003303B8(&b, 0, 0, 0, 0, 2, 5, 0, D_L14_001DD614 * t, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
        D_L14_001D67B8 = D_L14_001D67B8 + 1;
        if (D_L14_001D67B8 >= 100) {
            func_L01_00459C50(0x11);
        }
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_003542F0 */

/* localdecomp:start func_L14_00354538 */
typedef int u128_t_354538 __attribute__((mode(TI)));
extern u8 D_L14_001D66B0;
extern s32 D_L14_001D67B8;
__asm__(".extern D_L14_001DD61C, 4");
__asm__(".extern D_L14_001DD620, 4");
__asm__(".extern D_L14_001DD624, 4");
__asm__(".extern D_L14_001DD628, 4");
__asm__(".extern D_L14_001DD62C, 4");
extern s32 D_L14_001DF240;
extern f32 D_L14_001DD61C;
extern f32 D_L14_001DD620;
extern f32 D_L14_001DD624;
extern f32 D_L14_001DD628;
extern f32 D_L14_001DD62C;
extern void func_L01_00404A10(void *, void *);
extern void func_L14_00354B90(S_L14_00354B90 *);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
void func_L14_00354538(u8 *a0) {
    vu0_v4 b;
    vu0_v4 a;
    f32 t;
    if (a0[0x31] != 0 && D_L14_001DF240 != 0) {
        func_L01_00404A10(func_L14_00354B90, a0);
    }
    if (a0[0x20] == 0) {
        D_L14_001D67B8 = 0;
        a0[0x20] = 1;
    }
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0x7F, &D_L14_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        t = 1.0f / D_L14_001DD62C;
        *(u128_t_354538 *)&a = 0;
        a.x = D_L14_001DD61C;
        a.y = D_L14_001DD620;
        a.z = D_L14_001DD624;
        b = a;
        func_0038CE20(&b, &b, t);
        *(u128_t_354538 *)&a = 0;
        a.z = -0.14000002f;
        func_L02_003E2E38(a0, &b, 0.1f, &a, 0x14, 0, 0.18f, 1.5f, 20.0f, 1.0f, 0);
        func_0038CE20(&b, &b, *(f32 *)(a0 + 0x2C));
        func_0038D000(&b, &b, a0 + 0xC0);
        vec_add_ab(&b, &b, a0 + 0x10);
        func_L01_003303B8(&b, 0, 0, 0, 0, 2, 5, 0, D_L14_001DD628 * t * D_L14_001DD62C, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        D_L14_001D67B8 = D_L14_001D67B8 + 1;
        if (D_L14_001D67B8 >= 100) {
            func_L01_00459C50(0x11);
        }
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00354538 */

/* localdecomp:start func_L14_003547F8 */
/* PAL port of the NTSC-U match src/us/levels/func_L14_003537D8.c */
#include "vu0.h"

extern int D_L14_001DF240_003537D8;
extern int D_L14_001D67B8_003537D8;
extern unsigned char D_L14_001D66B0_003537D8;

extern Table_3537D8 D_L14_00284820;
extern char D_L14_002856A0_003537D8[];
extern void func_L01_00404A10(void*,void*);
extern void func_L14_003F7C70(void*,int,int,int,float,float,float);
extern void func_L01_00450DE8(void *, f32, f32, f32, void *);
extern void func_0038CE20(void*,void*,float);
extern void func_0038D000(void*,void*,void*);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);


void func_L14_003547F8(unsigned char *a0) {
 vu0_v4 b,a,offset,temp;
 int i;
 if(!D_L14_001DF240_003537D8) {
  func_L14_003F7C70(D_L14_002856A0_003537D8,0x90000000,20,1,0.4f,0.9f,1.5f);
 }
 if(a0[0x31]) {
  for(i=1;i<D_L14_00284820.count;i++) {
   func_L01_00450DE8(a0, 0.0f, -4.0f, 5.7f, &offset);
   vec_add_ba(&b,&D_L14_00284820.v[i-1],&offset);
   vec_add_ba(&a,&D_L14_00284820.v[i],&offset);
   if(i>=3) {
    __asm__("lqc2 vf1,%3\n\tlqc2 vf2,%4\n\tvadd.xyz vf2,vf2,vf1\n\t"
            "lqc2 vf1,%5\n\tsqc2 vf1,%2\n\tsqc2 vf2,%0\n\t"
            "lqc2 vf1,%0\n\tlqc2 vf2,%2\n\tvadd.xyz vf1,vf1,vf2\n\tsqc2 vf1,%1"
            : "=m"(b),"=m"(a),"=m"(temp)
            : "m"(offset),"m"(D_L14_00284820.v[i+120]),"m"(D_L14_00284820.v[i+60])
            : "vf1","vf2");
   }
  }
  func_L01_00404A10(func_L14_00354B90,a0);
 }
 if(func_L01_00447490(a0,-1,0)) {
  func_003A52A0(0,0,a0);
  func_L01_00451FE0(a0,0x7f,&D_L14_001D66B0_003537D8,3.0f,6.0f,3.0f,6.0f,0xff,-1.0f,-1.0f,0xb4,0,0,0x23,1.0f,1.0f,0,3);
  *(Q_3537D8 *)&b=0;
  b.y=-4.0f;
  b.z=5.4f;
  func_0038CE20(&b,&b,4.099873f);
  *(Q_3537D8 *)&a=0;
  a.z=-0.14000002f;
  func_L02_003E2E38(a0,&b,0.1f,&a,20,0,0.18f,1.5f,20.0f,1.0f,0);
  func_0038CE20(&b,&b,*(float *)(a0+0x2c));
  func_0038D000(&b,&b,a0+0xc0);
  vec_add_ab(&b,&b,a0+0x10);
  func_L01_0032FE90(&b,0,0,0,0,2,5,0,0.70000005f,0.0f,0.0f,0.0f,
    0,1,0,0,0,0,0x1000000,0,0x27B2F3,0xBDFFF,0,0,0,0,0x7F27B2F3,0x280BDFFF,0,0);
  D_L14_001D67B8_003537D8=D_L14_001D67B8_003537D8+1;
  if(D_L14_001D67B8_003537D8>=100)func_L01_00459C50(17);
  func_L01_00451E78(a0,1,0.0f);
  func_003C2880(a0);
 }
}
/* localdecomp:end func_L14_003547F8 */

/* localdecomp:start func_L14_00354B90 */
extern s32 D_L14_001DBC20;
extern u8 D_L14_002856A0[];
extern void func_L01_00450DE8(void *, f32, f32, f32, void *);
extern void func_L14_003F81B8(void *, void *);

void func_L14_00354B90(S_L14_00354B90 *p) {
    u8 buf[16];

    D_L14_001DBC20 |= 1;
    if (p->f_AA != 0x1690) {
        func_L01_00450DE8(p, 0.0f, -4.0f, 5.7f, buf);
    } else {
        func_L01_00450DE8(p, 0.0f, 3.6f, 5.5f, buf);
    }
    func_L14_003F81B8(D_L14_002856A0, buf);
}
/* localdecomp:end func_L14_00354B90 */

/* localdecomp:start func_L14_00354C28 */
extern u8 D_L14_001D66B0;
extern s32 D_L14_001D67B8;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
void func_L14_00354C28(void *a0) {
    vu0_v4 v10;
    vu0_v4 v20;
    s32 i;
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0xFFF, &D_L14_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        qzero(&v10);
        qzero(&v20);
        for (i = 0; i < 7; i++) {
            func_003C2F58(a0, i, &v20);
            func_L02_003E2E38(a0, &v20, 2.0f, &v10, 10, 0, 0.040000003f, 1.5f, 3.0f, 2.0f, 0);
        }
        D_L14_001D67B8 = D_L14_001D67B8 + 1;
        if (D_L14_001D67B8 >= 100) {
            func_L01_00459C50(0x11);
        }
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00354C28 */
