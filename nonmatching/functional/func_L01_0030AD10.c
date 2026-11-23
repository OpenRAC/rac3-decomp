/* functional: high. Draft verified against PAL assembly (16 samples t=i/15 along the arc curve, noise 0.075, strand count by the delay counter >= 8); 80 words differ in codegen only. points[16] is left unwritten as in retail. */
void func_L01_0030AD10(u8 *obj, u8 *state)
{
    extern void func_L01_0030ABF8(f32 *, f32 *, f32 *, f32 *, f32 *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0030AF18(u8 *, s32, vu0_v4 *, s32);
    vu0_v4 points[17];
    vu0_v4 a, b, noise, copy;
    s32 i;
    for (i=0; i<16; i++) {
        *(vu0_q *)&a = *(vu0_q *)state;
        *(vu0_q *)&b = *(vu0_q *)(state+0x10);
        vec_copy(&copy,state+0x30);
        vec_add_ba(&a,&a,state+0x20);
        vec_add_ba(&b,&b,&copy);
        func_L01_0030ABF8((f32 *)&points[i],(f32 *)(state+0x20),(f32 *)(state+0x30),(f32 *)&a,(f32 *)&b,(f32)i/15.0f);
        noise.w=0;
        noise.x=func_003824E0(-0.5f,0.5f);
        noise.y=func_003824E0(-0.5f,0.5f);
        noise.z=func_003824E0(-0.5f,0.5f);
        func_0038CF68(&noise,&noise,0.075f);
        vec_add_ab(&points[i],&noise,&points[i]);
    }
    if (*(s32 *)(state+0x88)>=8)
        func_L01_0030AF18(obj,func_00382498(64,128),points,17);
    else
        func_L01_0030AF18(obj,func_00382498(0,64),points,17);
}
