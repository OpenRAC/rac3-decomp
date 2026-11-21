#include "common.h"

/* NTSC-U counterpart of func_003AA380 (boot_elf). */
extern u8 D_U_001D8060;

/* localdecomp:start func_U_003AA238 */
typedef struct { s16 count; u8 pad2[6]; s16 animated; u8 padA[2]; f32 scale; void *vertices; u8 pad14[0x10]; s32 packed; } A_003AA380;
typedef struct { long point; u8 pad8[8]; } E_003AA380;
typedef struct { f32 x,y,z,w; } V_003AA380;
__asm__(".extern D_U_001D8060, 1");
extern s32 D_001D4BC0, D_001D4BC4;
typedef struct { u8 pad[0xB0]; f32 x,y; } C_003AA380;
extern C_003AA380 D_U_00225980;
extern void func_U_0038CEC8(void *,s32);
extern void func_U_0038D5C8(f32 *);
extern void func_U_003AA020(A_003AA380 *,void *,f32);
extern void func_U_0038D3A8(void *,long);
extern void func_U_0038D350(void *,void *,void *);
extern void func_U_0038D0F8(void *,void *,void *);
extern void func_U_0038D0E0(void *,void *,void *);
void func_U_003AA238(A_003AA380 *a,f32 *outx,f32 *outy,f32 x,f32 y,f32 time) {
    f32 matrix[16];
    V_003AA380 minimum,maximum;
    union { long q; s32 xy[2]; V_003AA380 v; } temp;
    V_003AA380 point;
    E_003AA380 *v;
    s32 *packed;
    s32 i,j,bone;
    /* The EE scratchpad holds the animation matrices and identity matrix. */
    f32 (*scratch)[16];
    if(D_U_001D8060) {
        x *= a->scale*1.18f;
        y *= a->scale*1.126f;
    } else {
        x *= a->scale;
        y *= a->scale;
    }
    func_U_0038CEC8(matrix,0x40);
    scratch=(f32 (*)[16])0x70002000;
    matrix[0]=((f32)(D_001D4BC0>>1)/D_U_00225980.x)*x;
    matrix[9]=-((f32)(D_001D4BC4>>1)/D_U_00225980.y)*y;
    func_U_0038D5C8((f32 *)0x70001FC0);
    if(a->animated) func_U_003AA020(a,scratch,time);
    minimum.x=100000.0f;
    minimum.y=1000000.0f;
    maximum.x=-100000.0f;
    maximum.y=-1000000.0f;
    if(!a->packed) {
        v=a->vertices;
        for(i=0;i<a->count;i++) {
            func_U_0038D3A8(&temp,v->point);
            temp.v.w=1.0f;
            func_U_0038D350(&temp,&temp,scratch[*(s16 *)((u8 *)v+6)]);
            v++;
            func_U_0038D350(&temp,&temp,matrix);
            func_U_0038D0F8(&minimum,&minimum,&temp);
            func_U_0038D0E0(&maximum,&maximum,&temp);
        }
    } else {
        packed=a->vertices;
        for(j=0;j<a->count;j++) {
            temp.xy[0]=(*packed<<18)>>16;
            temp.xy[1]=(*packed<<4)>>16;
            bone=*packed>>28;
            packed++;
            func_U_0038D3A8(&point,temp.q);
            point.w=1.0f;
            func_U_0038D350(&point,&point,scratch[bone]);
            func_U_0038D350(&point,&point,matrix);
            func_U_0038D0F8(&minimum,&minimum,&point);
            func_U_0038D0E0(&maximum,&maximum,&point);
        }
    }
    *outx=(maximum.x-minimum.x)*0.0625f;
    *outy=(maximum.y-minimum.y)*0.0625f;
}
/* localdecomp:end func_U_003AA238 */
