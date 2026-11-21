/* functional: high. Draft verified op by op against PAL asm (loop runs twice, args and constants match); 71 diff under ps2as: an extra saved float and constant hoisting only. */
typedef int Q_003AB4B8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003AB4B8;
void func_L07_003AB4B8(u8 *obj) {
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DB48(f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00474078(void *, void *, s32, u32, u32, s32, s32, f32, f32, f32, f32);
    V_003AB4B8 pos, vel, end;
    u8 *p = *(u8 **)(obj+0x68);
    s32 i=1, life, n;
    f32 speed, angle;
    func_003C2F58(obj,p[0x533],(f32 *)&pos);
    do {
        i--;
        speed=func_003824E0(3.0f,5.0f);
        angle=func_0038DB48(*(f32 *)(obj+0xF8)+*(f32 *)(p+0x2A8)+func_003824E0(-0.7853981852531433f,0.7853981852531433f));
        func_00382760(&vel,speed,angle,func_003824E0(-0.7853981852531433f,0.7853981852531433f));
        n=func_00382498(20,30);
        life=*(s16 *)(p+0x530);
        if(life>=n) life=n;
        *(Q_003AB4B8 *)&end=*(Q_003AB4B8 *)&pos;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(end) : "m"(pos), "m"(vel) : "vf1", "vf2");
        func_0038CE20(&vel,&vel,-1.0f/(f32)life);
        func_L01_00474078(&end,&vel,life,0x80808020,0x30FF8020,4,0,0.04f,3.0f,1.5f,0.5f);
    } while(i>=0);
}
