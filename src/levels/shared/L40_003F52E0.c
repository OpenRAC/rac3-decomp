#include "common.h"

/* declared by functions of L40_003F4638.c, which this file was cut from */
extern u8 D_L40_00249FC0[];

/* localdecomp:start func_L40_003F52E0 */
#include "vu0.h"
extern f32 func_0038CEA8(void *v);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_L40_003F5248(f32 *v);
extern vu0_v4 D_L40_0025B9B0;

void func_L40_003F52E0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 tmp;
    f32 len;
    f32 z;

    len = func_0038CEA8(v + 0x2B0) - 0.0024f;
    if (len > 0.160000011f) {
        len = 0.160000011f;
    } else if (len < 0.0f) {
        len = 0.0f;
    }
    func_0038CF68(v + 0x2B0, v + 0x2B0, len);
    vec_add_ba(m + 0x10, m + 0x10, v + 0x2B0);
    *(f32 *)(v + 0x234) = func_0038DAB8(*(f32 *)(v + 0x234), *(f32 *)(v + 0x23C));
    z = *(f32 *)(v + 0x1F8) + *(f32 *)(v + 0x238) * func_0038D0B0(*(f32 *)(v + 0x234));
    if (*(s16 *)(v + 0x246) != 0) {
        z += *(f32 *)(v + 0x230);
    }
    z -= *(f32 *)(m + 0x18);
    if (z > 0.0600000024f) {
        z = 0.0600000024f;
    } else if (z < -0.0600000024f) {
        z = -0.0600000024f;
    }
    *(f32 *)(v + 0x2B8) = z;
    tmp = *(vu0_v4 *)(m + 0x10);
    tmp.z += 0.8f;
    if (func_L01_003FB640(&tmp, 0, m, 0.8f) != 0) {
        vec_sub_ba(&tmp, &D_L40_0025B9B0, m + 0x10);
        if (func_L40_003F5248(&tmp.x) != 0) {
            if (tmp.z > 0.0600000024f) {
                tmp.z = 0.0600000024f;
            } else if (tmp.z < -0.0600000024f) {
                tmp.z = -0.0600000024f;
            }
            vec_add_ab(m + 0x10, m + 0x10, &tmp);
        }
    }
}
/* localdecomp:end func_L40_003F52E0 */

/* localdecomp:start func_L40_003F54B8 */
#include "vu0.h"
extern void func_L01_0044ABD0(void *);
extern void func_L39_0066C470(void *);
extern u8 *func_L01_00447490(void *, int, int);
extern int func_0038CB00(void *);
extern u8 *func_L39_005C1018(void *);
extern void func_003C4A40(void *, void *);
extern float func_L01_004474E8(void *,void *);
extern int func_L40_0053F018(void *);
extern void func_003C3A10(void *,int,int,int);
extern void func_L01_00455E18(void *,void *,void *);
extern u8 *D_L40_0024845C __attribute__((section(".sdata")));
extern int D_L40_0024112C;
int func_L40_003F54B8(u8 *m,u8 *a,void *arg,int unused,int flag) {
 u8 *v=*(u8 **)(m+0x68), *x=*(u8 **)(m+0x90), *p=*(u8 **)v, *q=*(u8 **)(v+0x20), *hit;
 float damage;
 func_L01_0044ABD0(m);
 if (*(float *)(v+0x30)<=0.0f) (*(int *)(v+0x2e4))++;
 if (*(int *)(v+0x2e4)>200) func_L39_0066C470(arg);
 if(flag) hit=func_L01_00447490(m,1,0); else hit=func_L01_00447490(m,65536,0);
 if(!func_0038CB00(p+6)) hit=0;
 if(hit) {
  u8 *o=*(u8 **)(hit+0x20);
  if(o && x) {
   u8 *r=o, *obj;
   while(*(u8 **)(r+0xb8)) r=*(u8 **)(r+0xb8);
   obj=((u8 *(*)(void *))*(void **)(func_L39_005C1018(r)+4))(r);
   if(obj && ((int (*)(void *,int))*(void **)(*(u8 **)(obj+0x14)+0x1c))(obj,*(int *)(x+0x18))) {hit=0; m[0xa8]=255;}
  }
  if(hit) {
   v[0x137]=128; func_003C4A40(m,v+0x130);
   { float f=*(float *)(hit+0x2c);
   if(*(float *)(a+0xa8)!=0.0f) {
    if(*(u8 **)(hit+0x20) && *(short *)(m+0xaa)==*(short *)(*(u8 **)(hit+0x20)+0xaa)) *(float *)(hit+0x2c)=f**(float *)(a+0xa8);
   }
   }
  }
 }
 damage=func_L01_004474E8(m,hit); m[0xa8]=255;
 *(float *)p-=damage;
 if(*(float *)(v+0x30)<=0.0f && func_L40_0053F018(m) && m[0x20]!=a[0x10]) func_L39_0066C470(arg);
 else if(hit && *(float *)(v+0x30)*0.01f<damage && m[0x43]!=4) func_003C3A10(m,4,0,8);
 if(q) func_L01_00455E18(m,q,p);
 if(damage==0.0f) {
  if((m[0x42]==4 || m[0x43]==4) && (m[0x60]&2)) {
   if(m[0x20]==4) {if(m[0x43]!=3) {func_003C3A10(m,3,0,8);}}
   else if(m[0x43]!=2) {func_003C3A10(m,2,0,8);}
  }
  return 0;
 }
 {
  int n;
  *(short *)(a+0x70)=-1;
  if(hit && *(u8 **)(hit+0x20)) *(short *)(a+0x70)=(*(u8 **)(hit+0x20)-D_L40_0024845C)>>8;
  n=300;
  if(*(short *)(p+4)**(float *)(a+0x58)<=0.0f) n=90;
  if(a[0x77] || abs_asm(D_L40_0024112C-*(int *)(a+0x44))>(n*5+2)/6) return 0;
 }
 return 0;
}
/* localdecomp:end func_L40_003F54B8 */

/* localdecomp:start func_L40_003F5880 */
#include "vu0.h"
typedef struct {
    vu0_v4 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_003F5880;
__asm__(".extern D_L40_00241118, 16");
extern s32 D_L40_00241118;
extern u8 D_L40_00249FC0[];
__asm__(".extern D_L40_00246F14, 4");
__asm__(".extern D_L40_00246F18, 4");
__asm__(".extern D_L40_00246F20, 8");
extern f32 D_L40_00246F14;
extern f32 D_L40_00246F18;
extern vu0_v4 D_L40_00246F20[4] __attribute__((section(".sdata")));
extern long func_L39_00589890(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L40_003F5880(u8 *m) {
    S_003F5880 s;
    vu0_v4 up;
    vu0_v4 mat[4];
    vu0_v4 t;
    u8 *v;
    s32 i;
    s32 c;

    *(vu0_q *)&up = 0;
    v = *(u8 **)(m + 0x68);
    up.z = 1.0f;
    up.w = 1.0f;
    s.x78 = func_L39_00589890(0xB);
    s.x88 = 0x8000000048L;
    s.x80 = 0xFF9000000260L;
    s.x70 = 5;
    s.uv[0][0] = 0.0f;
    s.uv[0][1] = 0.0f;
    s.uv[1][0] = 0.0f;
    s.uv[1][1] = 1.0f;
    s.uv[2][0] = 1.0f;
    s.uv[2][1] = 0.0f;
    s.uv[3][0] = 1.0f;
    s.uv[3][1] = 1.0f;
    mat[3] = *(vu0_v4 *)(v + 0x250);
    vec_sub_ba(&mat[0], D_L40_00249FC0 + D_L40_00241118 * 0x460, &mat[3]);
    func_0038CF68(&mat[0], &mat[0], 1.0f);
    func_0038CE90(&mat[1], &mat[0], &up);
    func_0038CF68(&mat[1], &mat[1], 1.0f);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CE20(&t, &mat[0], D_L40_00246F14);
    c = (*(u32 *)(m + 0x78) & 0xFFFFFF) | 0x40000000;
    vec_add_ab(&mat[3], &mat[3], &t);
    s.c4C = c;
    s.c48 = c;
    s.c44 = c;
    s.c40 = c;
    for (i = 0; i < 4; i++) {
        func_0038CE20(&s.m[i], &D_L40_00246F20[i], D_L40_00246F18);
        func_0038D028(&s.m[i], &s.m[i], mat);
    }
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L40_003F5880 */
