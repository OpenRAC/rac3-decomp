/* functional: high. near-miss (29 words scheduling); loop count verified 120 */
/* localdecomp:start func_L07_003B8D80 */
typedef int Q_003B8D80 __attribute__((mode(TI)));
extern u8 *D_L07_0021EC98[];
void func_L07_003B8D80(u8 *obj) {
    extern void func_003C4C18(void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
    Q_003B8D80 pos, vel;
    f32 speed, angle, pitch, x, y, z;
    s32 time, color;
    s32 i;
    u8 *particle;
    i=120;
    while (i-- > 0) {
        pos=*(Q_003B8D80 *)(obj+0x10);
        func_003C4C18(&pos, 2.0f);
        speed=func_003824E0(0.10000000894069672f,0.20000001788139343f);
        angle=func_00382538();
        pitch=func_003824E0(0.0f,0.785398006439209f);
        func_00382760(&vel,speed,angle,pitch);
        func_003C4C18(&vel,0.06000000238418579f);
        time=func_00382498(40,80);
        color=func_0038DBD8(0x808080,0xFFFFFF,func_003824E0(0.0f,1.0f));
        x=func_003824E0(210000.0f,315000.0f);
        y=func_003824E0(630000.0f,1050000.0f);
        z=func_003824E0(0.0020000000949949026f,0.004000000189989805f);
        particle=func_L01_0046FB40(&pos,&vel,x,y,z,time,color,func_00382468(2)?3:-3,96,0,0);
        if (particle) {
            u8 value=D_L07_0021EC98[0x7C][1];
            particle[3]=68;
            particle[2]=value;
        }
    }
}
/* localdecomp:end func_L07_003B8D80 */
