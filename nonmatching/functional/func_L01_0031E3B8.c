/* functional: medium. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 114 words differ in scalar scheduling/register allocation; not byte-identical, behaviour as retail. */
typedef int Q_0031E3B8 __attribute__((mode(TI)));
typedef union { Q_0031E3B8 q; f32 f[4]; } Vec_0031E3B8;
typedef struct { u8 pad[0x16C]; u8 *colors; } Config_0031E3B8;
extern Config_0031E3B8 D_L01_00221098[];
extern Vec_0031E3B8 D_001A4EC0[];
extern Vec_0031E3B8 D_L01_001E29C0[];
extern u8 D_001425C0[];
void func_L01_0031E3B8(u8 *position, s32 unused, s32 flag, u8 *owner) {
    extern f32 func_003824E0(f32,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern void func_0038CE20(f32 *,void *,f32);
    extern u8 *func_L01_004669B0(f32,f32,f32,f32,u8 *,s32,f32 *,u32,s32);
    extern f32 func_00382538(void);
    extern void func_00382760(f32 *,f32,f32,f32);
    extern void func_0038CF68(f32 *,s32,f32);
    extern s32 func_00382498(s32,s32);
    extern u8 *func_L01_004708C8(f32 *,f32 *,u32,u32,s32,s32,s32,s32,s32,f32,f32);
    f32 velocity[4], at[4], smoke[4];
    s32 i;
    s32 life;
    s32 color;
    f32 size, heading, angle;
    u8 *particle;
    for(i=0;i<5;i++) {
        func_0038CE20(velocity,D_001A4EC0,-(func_003824E0(0.1f,1.5f)*0.020000001f));
        life=func_L01_00443A18(1.0f,2.0f);
        size=func_003824E0(0.15f,0.35f)*210000.0f;
        at[0]=*(f32 *)(position+0)+func_L01_00443A18(0.0f,0.1f);
        at[1]=*(f32 *)(position+4)+func_L01_00443A18(0.0f,0.1f);
        at[2]=*(f32 *)(position+8)+func_L01_00443A18(0.0f,0.1f);
 particle=func_L01_004669B0(0.0f,1.0f,1.01f,size,(u8 *)&at,life,velocity,0x7F101010,0);
        if(particle) {
            u8 *v=particle+0x20;
            *(s16 *)(particle+0xA)=75;
            particle[3]=0x44;
            particle[9]=0x44;
            *(f32 *)(v+0x1C)=4.0f;
            *(s32 *)(v+4)=3;
            v[0xA]=0x30;
            v[0xB]=particle[0xA];
        }
    }
    color=1;
    if(((E240_321CB8 *)D_L01_002C5600)[D_001425C0[0x7F]].x1>=4) color=3;
    for(i=0;i<2;i++) {
        angle=func_003824E0(-0.9599310755729675f,-1.3962634f);
        heading=func_00382538();
        func_00382760(velocity,func_003824E0(0.0f,0.5f)*0.020000001f,heading,angle);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(Vec_0031E3B8 *)at) : "m"(*(Vec_0031E3B8 *)position),"m"(D_L01_001E29C0[0]) : "vf1","vf2");
        func_0038CF68(at,(s32)at,0.3f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_0031E3B8 *)position) : "m"(*(Vec_0031E3B8 *)at),"m"(*(Vec_0031E3B8 *)position) : "vf1","vf2");
        size=func_003824E0(50000.0f,75000.0f);
        smoke[0]=*(f32 *)(position+0)+func_L01_00443A18(0.0f,0.02f);
        smoke[1]=*(f32 *)(position+4)+func_L01_00443A18(0.0f,0.02f);
        smoke[2]=*(f32 *)(position+8)+func_L01_00443A18(0.0f,0.02f);
        if(flag) life=func_00382498(8,17);
        else life=func_00382498(21,50);
        particle=func_L01_004708C8(smoke,velocity,0x78FFFFFF,0x101E1E1E,life,1,1,-1,1,size,0.1f);
        if(particle) particle[2]=D_L01_00221098[0].colors[color];
    }
}
