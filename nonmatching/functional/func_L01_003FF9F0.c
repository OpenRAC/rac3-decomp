/* functional: high. PAL near miss, 28 words differ (register allocation and scheduling only); all args, offsets and switch cases checked against the asm. */
/* localdecomp:start func_L01_003FF9F0 */
extern s32 D_001D4BC0;
extern f32 D_L01_001E6838[];
typedef struct { u8 pad0[0x22]; s16 index; u8 pad24[0x364]; s32 value; } State_003FF9F0;
extern s32 D_L01_001E64C0[];
extern S_003FF4E8 D_L01_001E6850[];
void func_L01_003FF9F0(u8 *text,s32 mode,s32 color,s32 x,s32 style,f32 t) {
    extern s32 func_0011B868(void);
    extern s32 func_L01_00412708(u8 *,s32);
    extern s32 func_L01_00400368(f32,f32,f32);
    extern void func_003910C0(void *,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_0038FA18(void *,s32,void *,s32,unsigned long,f32,f32);
    extern void func_0038AF30(s32,s32,s32,s32,u32);
    u8 rect[32] __attribute__((aligned(16)));
    s32 shift=0;
    s32 width;
    f32 alpha=0.0f;
    width=func_L01_00412708(text,func_0011B868());
    switch(mode) {
    case 1: shift=(s32)t;
    case 0: shift+=D_001D4BC0/2; alpha=1.0f; break;
    case 2: shift=func_L01_00400368(D_L01_001E6838[0],(f32)(D_001D4BC0/2)+(f32)width,t)-width; alpha=t; break;
    case 3: { f32 u=1.0f-t; shift=width+D_001D4BC0-func_L01_00400368(D_L01_001E6838[0],(f32)(D_001D4BC0/2)+(f32)width,u); alpha=u; break; }
    }
    if(style==0) {
        State_003FF9F0 *g=(State_003FF9F0 *)D_L01_001E64C0;
        s32 h=D_L01_001E6850[((State_003FF9F0 *)D_L01_001E64C0)->index].v[8];
        func_003910C0(rect,x,x+h,-D_001D4BC0,D_001D4BC0*2,shift,x+h/2,g->value,3);
        func_0038FA18(rect,color,text,-1,0x80000000UL,1.0f,1.0f);
    } else if(style==1) {
        func_0038AF30(x+2,x+D_L01_001E6850[((State_003FF9F0 *)D_L01_001E64C0)->index].v[8]-2,-D_001D4BC0,D_001D4BC0*2,(s32)(alpha*96.0f)<<24);
    }
}
/* localdecomp:end func_L01_003FF9F0 */
