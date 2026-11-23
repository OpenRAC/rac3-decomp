/* functional: high. near-miss (8 words VU scheduling) */
/* localdecomp:start func_L07_003B8FC0 */
typedef union { u128_t q; f32 f[4]; } V_003B8FC0;
__asm__(".extern D_L07_001DE4B0,4");
extern V_003B8FC0 D_L07_001DE4B0 __attribute__((section(".sdata")));
void func_L07_003B8FC0(void *o,s32 n) {
    extern void func_003C2EC0(void *,s32,void *);
    extern void func_0038D890(void *,void *,void *,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_003C4C18(void *,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_L01_0046E078(s32,void *,void *,void *,s32);
    V_003B8FC0 matrix[4],dir,pos,vel;
    V_003B8FC0 *color=&D_L07_001DE4B0;
    s32 i;
    f32 speed;
    func_003C2EC0(o,n,matrix);
    __asm__("lqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf0,$vf1\n\tsqc2 $vf1,%0" : "=m"(dir) : "m"(matrix[2]) : "vf1");
    func_0038D890(&dir,&dir,&matrix[1],0.7853981852531433f);
    func_0038CF68(&dir,&dir,1.0f);
    for(i=0;i<3;i++) {
        pos.q=matrix[3].q;
        func_003C4C18(&pos,0.1f);
        speed=func_003824E0(0.20000001788139343f,0.24000000953674316f);
        func_0038CE20(&vel,&dir,speed);
        func_L01_0046E078(0,&pos,&vel,color,i<2);
        color++;
    }
}
/* localdecomp:end func_L07_003B8FC0 */
