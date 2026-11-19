/* functional: high. PAL near miss, 6 words differ (pointer copy and register order in the case 1/2 loop); same calls, order, float maths. */
/* localdecomp:start func_L01_003FF240 */
extern s32 D_L01_001E64C0[];
extern S_003FF4E8 D_L01_001E6850[];
extern s32 D_001A1ED4[];
extern s32 D_001D60C0_sda;
extern f32 D_L01_001DF950;
__asm__(".extern D_001D60C0_sda, 4");
void func_L01_003FF240(void)
{
    extern void func_00389240(s32);
    extern void func_003A9830(void *,s32,s32,s32);
    extern void func_L01_003FFED0(void);
    extern void func_L01_003FFC88(s32,f32);
    extern void func_L01_003FF570(s32,f32);
    extern void func_00389370(void);
    extern void func_0038AE20(s32,s32,s32,s32);
    S_004001E8 *g=(S_004001E8 *)D_L01_001E64C0;
    s32 i,fade,mode;
    f32 t;
    if (*(s16 *)((u8 *)g+0x26)) {
        func_00389240(0);
        func_003A9830((u8 *)D_L01_001E64C0[(s16)(*(u16 *)((u8 *)g+0x1C)^1)]+16,D_001A1ED4[0],512,416);
        func_L01_003FFED0();
        mode=D_L01_001E6850[g->f22].v[6];
        switch(mode) {
        case 0: {
            for(i=0;i<D_L01_001E6850[g->f22].v[7];i++) {
                fade=(D_001D60C0_sda*5+2)/6;
                if (g->f2C<fade)
                    t=(f32)g->f2C/(f32)fade;
                else if (D_L01_001E6850[g->f22].v[9]-fade<g->f2C)
                    t=(f32)(D_L01_001E6850[g->f22].v[9]-g->f2C)/(f32)fade;
                else t=1.0f;
                func_L01_003FFC88(i,t);
            }
        break; }
        case 1: case 2: {
            s32 j,n;
            u8 *g=(u8 *)D_L01_001E64C0;
            j=0;
            if(D_L01_001E6850[*(s16 *)(g+0x22)].v[7]>0) {
                S_004001E8 *state=(S_004001E8 *)g;
                do {
                n=j+1;
                func_L01_003FF570(j,1.0f-((f32)state->f2C-(f32)(D_L01_001E6850[state->f22].v[7]-n)*(f32)state->f370)/(f32)state->f374);
                j=n;
            } while(j<D_L01_001E6850[state->f22].v[7]);
            }
        break; }
        }
        func_00389370();
    }
    func_0038AE20(0,0,0,(s32)(D_L01_001DF950*128.0f));
}
/* localdecomp:end func_L01_003FF240 */
