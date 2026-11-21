/* functional: high. 53 words differ (VU0 scheduling, const hoisting); all 6 random-pair constants, 6 layer parameter sets, gp globals and call order verified against asm */
/* localdecomp:start func_L01_00361690 */
extern u8 D_00142637;
typedef struct { u8 pad0; u8 active; u8 pad2[238]; } Row_00361690;
extern Row_00361690 D_L01_002C5600[];
extern u8 *D_001A71A0[];
__asm__(".extern D_L01_001DD718, 4");
extern f32 D_L01_001DD718;
__asm__(".extern D_L01_001DD724, 4");
extern f32 D_L01_001DD724;
__asm__(".extern D_L01_001DD71C, 4");
extern f32 D_L01_001DD71C;
__asm__(".extern D_L01_001DD728, 4");
extern f32 D_L01_001DD728;
__asm__(".extern D_L01_001DD720, 4");
extern f32 D_L01_001DD720;
__asm__(".extern D_L01_001DD72C, 4");
extern f32 D_L01_001DD72C;
__asm__(".extern D_L01_001DD70C, 4");
extern f32 D_L01_001DD70C;
extern f32 D_L01_001E1AA0;
extern f32 D_L01_001E1AA4;
__asm__(".extern D_L01_001E1AA8, 4");
extern f32 D_L01_001E1AA8;
__asm__(".extern D_L01_001E1AAC, 4");
extern f32 D_L01_001E1AAC;
__asm__(".extern D_L01_001E1AB0, 4");
extern f32 D_L01_001E1AB0;
extern f32 D_L01_001E1AB4;
void func_L01_00361690(u8 *obj) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038CED8(f32 *);
    extern f32 func_0038D160(f32, f32);
    extern void func_L01_00361568(S_38C110v *, void *, s32, s32, f32, f32, f32, f32, f32, f32);
    s128 matrix[4];
    S_38C110v rotation, delta;
    u8 *vars=*(u8 **)(obj+0x68);
    s32 color;
    D_L01_001DD718=func_0038DAB8(D_L01_001DD718,func_003824E0(-1.0f,-2.0f)*0.017453292f);
    D_L01_001DD724=func_0038DAB8(D_L01_001DD724,func_003824E0(-2.0f,-4.0f)*0.017453292f);
    D_L01_001DD71C=func_0038DAB8(D_L01_001DD71C,func_003824E0(-1.0f,-3.0f)*0.017453292f);
    D_L01_001DD728=func_0038DAB8(D_L01_001DD728,func_003824E0(-3.0f,-5.0f)*0.017453292f);
    D_L01_001DD720=func_0038DAB8(D_L01_001DD720,func_003824E0(-1.0f,-3.0f)*0.017453292f);
    D_L01_001DD72C=func_0038DAB8(D_L01_001DD72C,func_003824E0(-1.0f,-4.0f)*0.017453292f);
    if (((Row_00361690 *)((u32)D_00142637 * 240 + (u32)D_L01_002C5600))->active) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(delta) : "m"(*(S_38C110v *)(obj+0x10)), "m"(*(S_38C110v *)(D_001A71A0[0]+0x10)) : "vf1","vf2");
        obj+=0x10;
        rotation.x=0.0f;
        rotation.y=func_0038D160(func_0038CED8((f32 *)&delta),delta.z)+-0.34906584f;
        rotation.z=func_0038D160(delta.x,delta.y);
        rotation.w=1.0f;
        func_0038D328(matrix,&rotation);
        color=(*(s32 *)(vars+0x1C)*14 << 24)|0x608070;
        D_L01_001E1AA0=func_0038DAB8(D_L01_001E1AA0,0.1221730486f);
        func_L01_00361568((S_38C110v *)obj,matrix,29,color,D_L01_001E1AA0,D_L01_001DD70C*1.5f*0.2f,25.0f,35.0f,0.0f,180.0f);
        D_L01_001E1AA4=func_0038DAB8(D_L01_001E1AA4,0.2094395161f);
        func_L01_00361568((S_38C110v *)obj,matrix,29,color,D_L01_001E1AA4,D_L01_001DD70C*1.7f*0.2f,10.0f,20.0f,0.0f,180.0f);
        D_L01_001E1AA8=func_0038DAB8(D_L01_001E1AA8,0.2967059612f);
        func_L01_00361568((S_38C110v *)obj,matrix,29,color,D_L01_001E1AA8,D_L01_001DD70C*2.0f*0.2f,-2.0f,7.0f,0.0f,180.0f);
        D_L01_001E1AAC=func_0038DAB8(D_L01_001E1AAC,0.3316125572f);
        func_L01_00361568((S_38C110v *)obj,matrix,29,color,D_L01_001E1AAC,D_L01_001DD70C*1.8f*0.2f,-5.0f,-10.0f,0.0f,180.0f);
        D_L01_001E1AB0=func_0038DAB8(D_L01_001E1AB0,0.2792526782f);
        func_L01_00361568((S_38C110v *)obj,matrix,29,color,D_L01_001E1AB0,D_L01_001DD70C*1.7f*0.2f,-12.0f,-18.0f,0.0f,180.0f);
        D_L01_001E1AB4=func_0038DAB8(D_L01_001E1AB4,0.2094395161f);
        func_L01_00361568((S_38C110v *)obj,matrix,29,color,D_L01_001E1AB4,D_L01_001DD70C*1.5f*0.2f,5.0f,15.0f,0.0f,180.0f);
    }
}
/* localdecomp:end func_L01_00361690 */
