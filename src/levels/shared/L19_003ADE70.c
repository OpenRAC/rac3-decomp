#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef int Q __attribute__((mode(TI)));
typedef struct {u8 pad[0x30]; Q pos; u8 tail[0x40];} Rec;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0xC];
    s32 ids[8];
    u8 quads[0x80];
} P_003AD358;

/* localdecomp:start func_L19_003ADE70 */
/* PAL port of the NTSC-U match src/us/levels/func_L19_003AC268.c */
#include "vu0.h"

extern Rec *D_L19_001DF800_003AC268;
extern u8 D_1A30B0[];
extern void func_L01_004450F0(void *, int, int);
extern void func_L19_003AE108(void *);
extern void func_L19_003AE5A8(void *);
extern int func_L01_004561B8(void *);
extern void func_003A4F28(int);
void func_L19_003ADE70(u8 *o) {
 u8 *p=*(u8 **)(o+0x68); int i;
 switch(o[0x20]) {
 case 0:
 *(Q *)(o+0x10)=D_L19_001DF800_003AC268[*(int *)(p+0x20)].pos;
 *(Q *)(p+0x40)=D_L19_001DF800_003AC268[*(int *)(p+0x28)].pos;
 if (*(int *)(p+4)<10) *(int *)(p+4)=(int)((float)*(int *)(p+4)*50.0f);
 else *(int *)(p+4)=(*(int *)(p+4)*5+2)/6;
 if(abs_asm(*(int *)(p+0x1c))<10) *(int *)(p+0x1c)=(int)((float)*(int *)(p+0x1c)*50.0f);
 else *(int *)(p+0x1c)=(*(int *)(p+0x1c)*5+2)/6;
 *(int *)(p+0x14)=0; *(int *)(p+8)=-1; *(float *)(p+0xc)=0; *(int *)(o+0x98)=0;
 func_L01_004450F0(o,1,-1); break;
 case 1: func_L19_003AE108(o);func_L19_003AE5A8(o); break;
 case 2:
 if(func_L01_004561B8(o)) {
 i=*(int *)(p+8);
 if(i!=-1) {u8 *slot=D_1A30B0+(i<<7); if(*(u8 **)(slot+0xdc)==o && slot[0xd0])func_003A4F28(i);}
 *(int *)(p+8)=-1;
 } break;
 case 3: {
 float t=(float)*(u16 *)(o+0x96)/25.0f;
 float sum = *(float *)(p+0xc) + (t>1.0f ? 1.0f : t);
 *(float *)(p+0xc)=sum;
 if(sum>=1.0f) {--*(int *)(p+0x1c); *(float *)(p+0xc)=sum-1.0f;}
 func_L19_003AE108(o);func_L19_003AE5A8(o);
 if(*(u16 *)(o+0x96)>=25)func_L01_004450F0(o,2,-1);
 break;
 }
 }
 ++*(u16 *)(o+0x96);
}
/* localdecomp:end func_L19_003ADE70 */

INCLUDE_ASM("asm/levels", func_L19_003AE108);

INCLUDE_ASM("asm/levels", func_L19_003AE5A8);

/* localdecomp:start func_L19_003AEBD8 */
extern void func_L01_004450F0(void *, int, int);
void func_L19_003AEBD8(unsigned char *a) {
    if (a[32] == 1) {
        func_L01_004450F0(a, 3, -1);
    }
}
/* localdecomp:end func_L19_003AEBD8 */

/* localdecomp:start func_L19_003AEC08 */

extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3,
                          f32 f0, f32 f1, f32 f2);
extern void func_003D9508(void *p, s32 a, u32 color, s32 b, f32 f0, f32 f1, f32 f2);

void func_L19_003AEC08(u8 *moby) {
    u128_t v[2];
    u8 *pvars = *(u8 **)(moby + 104);
    v[0] = *(u128_t *)(moby + 16);
    v[1] = *(u128_t *)(pvars + 96);
    func_L01_0040A8C0(&v[0], &v[1], 14, 1, 0x401010FF, 0x401010FF, 0x401010FF, 0x401010FF, 0.05f, 1.0f, 0.5f);
    func_003D9508(pvars + 96, 6, 0x401010FF, 1, 0.175f, 0.08f, 0.0f);
}
/* localdecomp:end func_L19_003AEC08 */

INCLUDE_ASM("asm/levels", func_L19_003AECC0);

/* localdecomp:start func_L19_003AEFA8 */
/* PAL port of the NTSC-U match src/us/levels/func_L19_003AD358.c */


extern void func_L01_004450F0(void *, int, int);
extern u8 *D_L19_001DF71C_003AD358;

void func_L19_003AEFA8(u8 *obj)
{
    P_003AD358 *p = *(P_003AD358 **)(obj + 0x68);
    s32 i;
    s32 *src;
    u8 *dst;

    p->f8 = (s32)((f32)p->f8 * 5e+01f);
    p->f10 = -1;
    i = 0;
    if (p->ids[0] >= 0) {
        src = p->ids;
        dst = p->quads;
        do {
            i++;
            *(u128_t *)dst = *(u128_t *)((*src << 8) + (s32)D_L19_001DF71C_003AD358 + 0x10);
            src++;
            dst += 16;
        } while (i < 8 && *src >= 0);
    }
    p->fC = i;
    if (p->f0 != 0) {
        func_L01_004450F0(obj, 3, -1);
        p->f4 = p->f8;
    } else {
        func_L01_004450F0(obj, 1, -1);
        p->f4 = 0;
    }
}
/* localdecomp:end func_L19_003AEFA8 */

INCLUDE_ASM("asm/levels", func_L19_003AF080);
