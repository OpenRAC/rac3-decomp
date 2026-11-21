/* functional: high. Near miss (VU0 load order at loop start differs by instruction scheduling only); semantics checked against retail: a=pos+origin, b=second+attached, jittered 24-point curve, then 25 points passed to func_L01_002FDC18. */
void func_L01_002FDA10(void *owner,Effect_002FD530 *input) {
    extern void func_L01_00445208(void *,void *,void *,void *,void *,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern s32 func_00382498(s32,s32);
    extern void func_L01_002FDC18(void *,s32,void *,s32);
    vu0_q points[25];
    vu0_v4 a,b,random,end;
    vu0_q *out=points;
    s32 i;
    for(i=0;i<24;i++,out++) {
        *(vu0_q *)&a=*(vu0_q *)input->pos;
        vec_copy(&end,input->attached);
        *(vu0_q *)&b=*(vu0_q *)input->second;
        vec_add_ba(&a,&a,input->origin);
        vec_add_ba(&b,&b,&end);
        func_L01_00445208(out,input->origin,input->attached,&a,&b,(f32)i/23.0f);
        random.w=0.0f;
        random.x=func_003824E0(-1.0f,1.0f);
        random.y=func_003824E0(-1.0f,1.0f);
        random.z=func_003824E0(-1.0f,1.0f);
        func_0038CF68(&random,&random,0.075f);
        vec_add_ab(out,out,&random);
    }
    if(input->timer>=6)func_L01_002FDC18(owner,func_00382498(64,128),points,25);
    else func_L01_002FDC18(owner,func_00382498(0,64),points,25);
}
