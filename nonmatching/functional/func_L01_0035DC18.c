/* functional: high. VU0 vadd.xyz written as plain float adds; D_L01_001DD6E8 is the gp-relative agent count (limit 8); all four spawn blocks checked individually. */
extern s32 D_L01_001DD6E8;
extern u8 D_001A4BE0[];
void func_L01_0035DC18(u8 *m) {
    extern s32 func_L01_004CB2D8(u8 *);
    extern void func_L01_004CAB30(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_0035E010(u8 *);
    extern void func_L01_0035E488(u8 *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern u8 *func_L01_003C27E0(u8 *, void *);
    extern void func_L01_004450F0(void *, s32, s32);
    S_38C110v position;
    u8 *agent;
    u8 *hero;
    if (func_L01_004CB2D8(m)) func_L01_004CAB30(m+0x10,m+0x10);
    switch (m[0x20]) {
    case 0:
        *(f32 *)(m+0xF0) = func_0038DAB8(*(f32 *)(m+0xF0),0.08377581089735031f);
        *(f32 *)(m+0xF4) = func_0038DAB8(*(f32 *)(m+0xF4),0.22689281404018402f);
        func_L01_0035E010(m);
        break;
    case 2:
        if (D_L01_001DD6E8 >= 8) goto finished;
        hero = D_001A4BE0;
        *(s128 *)&position = *(s128 *)(*(u8 **)(hero+0x25C0)+0xC0);
        func_0038CF68(&position,&position,func_003824E0(0.25f,0.75f));
        position.x += *(f32 *)(m+0x10); position.y += *(f32 *)(m+0x14); position.z += *(f32 *)(m+0x18); position.w = *(f32 *)(m+0x1C);
        agent = func_L01_003C27E0(m,&position);
        if (agent) *(s32 *)(agent+0xB8) = *(s32 *)(m+0xB8);
        D_L01_001DD6E8++;
        if (D_L01_001DD6E8 >= 8) goto finished;
        *(s128 *)&position = *(s128 *)(*(u8 **)(hero+0x25C0)+0xC0);
        func_0038CF68(&position,&position,-func_003824E0(0.25f,0.75f));
        position.x += *(f32 *)(m+0x10); position.y += *(f32 *)(m+0x14); position.z += *(f32 *)(m+0x18); position.w = *(f32 *)(m+0x1C);
        agent = func_L01_003C27E0(m,&position);
        if (agent) *(s32 *)(agent+0xB8) = *(s32 *)(m+0xB8);
        D_L01_001DD6E8++;
        if (D_L01_001DD6E8 >= 8) goto finished;
        *(s128 *)&position = *(s128 *)(*(u8 **)(hero+0x25C0)+0xD0);
        func_0038CF68(&position,&position,func_003824E0(0.25f,0.75f));
        position.x += *(f32 *)(m+0x10); position.y += *(f32 *)(m+0x14); position.z += *(f32 *)(m+0x18); position.w = *(f32 *)(m+0x1C);
        agent = func_L01_003C27E0(m,&position);
        if (agent) *(s32 *)(agent+0xB8) = *(s32 *)(m+0xB8);
        D_L01_001DD6E8++;
        if (D_L01_001DD6E8 >= 8) goto finished;
        *(s128 *)&position = *(s128 *)(*(u8 **)(hero+0x25C0)+0xD0);
        func_0038CF68(&position,&position,-func_003824E0(0.25f,0.75f));
        position.x += *(f32 *)(m+0x10); position.y += *(f32 *)(m+0x14); position.z += *(f32 *)(m+0x18); position.w = *(f32 *)(m+0x1C);
        agent = func_L01_003C27E0(m,&position);
        if (agent) *(s32 *)(agent+0xB8) = *(s32 *)(m+0xB8);
        D_L01_001DD6E8++;
finished:
        func_L01_004450F0(m,1,-1);
        break;
    case 1:
        func_L01_0035E488(m);
        break;
    }
}
