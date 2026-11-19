/* functional: high. Projects a skinned/packed sprite model to a screen-space size: builds a scale matrix from the view dims (D_001D4BC0/BC4, D_00225900 +0xB0/+0xB4), optionally poses the skeleton into the scratchpad (func_003AA168), transforms every vertex (plain 16-byte records, or packed words with a 4-bit bone) by bone then matrix, and writes (max-min)/16 for x and y to outx/outy. US draft verified against PAL asm: arg order (a,outx,outy,x,y,time), constants 1.18/1.126, D_001D8064 flag, 0.0625 scale. Scratchpad via named declarations. */
typedef struct { s16 count; u8 pad2[6]; s16 animated; u8 padA[2]; f32 scale; void *vertices; u8 pad14[0x10]; s32 packed; } A_003AA380;
typedef struct { long point; u8 pad8[8]; } E_003AA380;
typedef struct { f32 x,y,z,w; } V_003AA380;
extern f32 D_001D8060;
extern u8 D_001D8064;
extern f32 D_70002000[][16];
extern f32 D_70001FC0[16];
extern s32 D_001D4BC0[], D_001D4BC4[];
typedef struct { u8 pad[0xB0]; f32 x,y; } C_003AA380;
extern C_003AA380 D_00225900;
void func_003AA380(A_003AA380 *a,f32 *outx,f32 *outy,f32 x,f32 y,f32 time) {
    extern void func_0038CF80(void *,s32);
    extern void func_0038D680();
    extern void func_003AA168(A_003AA380 *,void *,f32);
    extern void func_0038D460(void *,long);
    extern void func_0038D408(void *,void *,void *);
    extern void func_0038D1B0(void *,void *,void *);
    extern void func_0038D198(void *,void *,void *);
    f32 matrix[16];
    V_003AA380 minimum,maximum;
    union { long q; s32 xy[2]; V_003AA380 v; } temp;
    V_003AA380 point;
    E_003AA380 *v;
    s32 *packed;
    s32 i,j,bone;
    /* The EE scratchpad holds the animation matrices and identity matrix. */
    f32 (*scratch)[16]=D_70002000;
    if(D_001D8064) {
        x *= a->scale*1.18f;
        y *= (a->scale*1.1260000467300415f)*D_001D8060;
    } else {
        y *= a->scale;
        x *= a->scale;
    }
    func_0038CF80(matrix,0x40);
    matrix[0]=((f32)(D_001D4BC0[0]>>1)/D_00225900.x)*x;
    matrix[9]=-((f32)(D_001D4BC4[0]>>1)/D_00225900.y)*y;
    func_0038D680(D_70001FC0);
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
