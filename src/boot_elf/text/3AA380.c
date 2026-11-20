#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AA060.c's earlier functions */
extern u8 D_001D8064;

/* localdecomp:start func_003AA380 */
typedef struct { s16 count; u8 pad2[6]; s16 animated; u8 padA[2]; f32 scale; void *vertices; u8 pad14[0x10]; s32 packed; } A_003AA380;
typedef struct { long point; u8 pad8[8]; } E_003AA380;
typedef struct { f32 x,y,z,w; } V_003AA380;
extern f32 D_001D8060;
__asm__(".extern D_001D8060, 4");
__asm__(".extern D_001D8064, 1");
extern s32 D_001D4BC0, D_001D4BC4;
typedef struct { u8 pad[0xB0]; f32 x,y; } C_003AA380;
extern C_003AA380 D_00225900;
extern void func_0038CF80(void *,s32);
extern void func_0038D680(f32 *);
extern void func_003AA168(A_003AA380 *,void *,f32);
extern void func_0038D460(void *,long);
extern void func_0038D408(void *,void *,void *);
extern void func_0038D1B0(void *,void *,void *);
extern void func_0038D198(void *,void *,void *);
void func_003AA380(A_003AA380 *a,f32 *outx,f32 *outy,f32 x,f32 y,f32 time) {
    f32 matrix[16];
    V_003AA380 minimum,maximum;
    union { long q; s32 xy[2]; V_003AA380 v; } temp;
    V_003AA380 point;
    E_003AA380 *v;
    s32 *packed;
    s32 i,j,bone;
    /* The EE scratchpad holds the animation matrices and identity matrix. */
    f32 (*scratch)[16];
    if(D_001D8064) {
        x *= a->scale*1.18f;
        y *= (a->scale*1.126f)*D_001D8060;
    } else {
        x *= a->scale;
        y *= a->scale;
    }
    func_0038CF80(matrix,0x40);
    scratch=(f32 (*)[16])0x70002000;
    matrix[0]=((f32)(D_001D4BC0>>1)/D_00225900.x)*x;
    matrix[9]=-((f32)(D_001D4BC4>>1)/D_00225900.y)*y;
    func_0038D680((f32 *)0x70001FC0);
    if(a->animated) func_003AA168(a,scratch,time);
    minimum.x=100000.0f;
    minimum.y=1000000.0f;
    maximum.x=-100000.0f;
    maximum.y=-1000000.0f;
    if(!a->packed) {
        v=a->vertices;
        for(i=0;i<a->count;i++) {
            func_0038D460(&temp,v->point);
            temp.v.w=1.0f;
            func_0038D408(&temp,&temp,scratch[*(s16 *)((u8 *)v+6)]);
            v++;
            func_0038D408(&temp,&temp,matrix);
            func_0038D1B0(&minimum,&minimum,&temp);
            func_0038D198(&maximum,&maximum,&temp);
        }
    } else {
        packed=a->vertices;
        for(j=0;j<a->count;j++) {
            temp.xy[0]=(*packed<<18)>>16;
            temp.xy[1]=(*packed<<4)>>16;
            bone=*packed>>28;
            packed++;
            func_0038D460(&point,temp.q);
            point.w=1.0f;
            func_0038D408(&point,&point,scratch[bone]);
            func_0038D408(&point,&point,matrix);
            func_0038D1B0(&minimum,&minimum,&point);
            func_0038D198(&maximum,&maximum,&point);
        }
    }
    *outx=(maximum.x-minimum.x)*0.0625f;
    *outy=(maximum.y-minimum.y)*0.0625f;
}
/* localdecomp:end func_003AA380 */

/* US draft of func_003AA6D8 (rac3-uya-decomp func_003AA588, commit 13cf5c5), names moved to PAL addresses
   where known. The called helper is func_003AA780 in PAL (func_003AA630 in the US build). */


/* localdecomp:start func_003AA6D8 */
typedef struct { u8 p0[0xC]; f32 fC; } O_A4DC8;
extern void func_0038D680();
extern void func_003AA780(O_A4DC8 *, f32, f32, s32, f32, f32 *);
void func_003AA6D8(O_A4DC8 *o, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 m[16];
    if ((flag >> 24) != 0) {
        func_0038D680(m);
        m[0] = c * o->fC;
        m[10] = d * o->fC;
        func_003AA780(o, a, b, flag, e, m);
    }
}
/* localdecomp:end func_003AA6D8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AA780);
