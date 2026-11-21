/* functional: high. Near-miss draft re-read block by block against the retail asm (all conditions, constants, callee argument orders and the three VU0 sequences); the 341 diff lines are base-pointer lifetime and scheduling. */
/* localdecomp:start func_L01_00512E68 */
extern u8 D_00143950_00512E68[];
extern u8 *D_001D52FC;
extern u8 D_L01_001E2A40[];
extern u128_t D_L01_001E2AC0[];
void func_L01_00512E68(void) {
    extern s32 func_003A3BB8(s32,s32);
    extern void func_L01_00514508(s32);
    extern f32 func_0038CE68(void *,void *);
    extern void func_0038CC88(void *,void *,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038D2A0(void *);
    extern void func_L01_004130D0(void *);
    extern void func_L01_004130C0(void *);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_003C4138(void *,f32,f32);
    extern void func_L01_00413138(void *,void *,void *,void *,void *,s32,f32);
    extern void func_L01_00513FD8(void);
    extern void func_003C3FC0(void *,void *);
    extern void func_L01_005133E8(void);
    M_0050D430 matrix;
    Vec4 target;
    u8 *g=(u8 *)&D_001A4BE0;
    u8 *m;
    u8 *actor;
    s32 input;
    s32 option;
    *(u16 *)(g+0x1620) &= 0xFFF7;
    if (*(s32 *)(g+0x16B0)) {
        input=func_003A3BB8(4,0) & *(s32 *)(D_001D52FC+0x1A0);
        if (input) {
            if(D_00143950_00512E68[0xA4]==1 && (*(s32 *)(g+0x25C4)==1 || *(s32 *)(g+0x25C4)==29)) {
                *(u16 *)(g+0x1620) |= 8;
                func_L01_00514508(2);
            }
        } else if (D_00143950_00512E68[0xA4]==1 &&
                   (*(s32 *)(g+0x16B0)==2 ||
                    (*(s32 *)(g+0x16B0)==1 && func_0038CE68(g+0x1600,g+0x1600)==0.0f))) {
            *(s32 *)(g+0x1668)=0;
            func_L01_00514508(1);
            if(*(f32 *)(g+0x1664)<2.0f) *(f32 *)(g+0x1664)=2.0f;
        }
        m=g+0x1480;
        func_0038CC88(m,g,0x30);
        *(u128_t *)(m+0x20)=D_L01_001E2AC0[0];
        func_0038CF68(m+0x20,m+0x20,1.0f);
        func_0038CE90(m+0x10,m,m+0x20);
        func_0038CF68(m+0x10,m+0x10,1.0f);
        func_0038CE90(m,m+0x20,m+0x10);
        func_0038CF68(m,m,1.0f);
        func_0038D2A0(&matrix);
        func_0038D5B0(&matrix,(M_0050D430 *)m);
        func_0038CC88(m+0x30,&matrix,0x30);
        if ((*(f32 *)(g+0x28)>0.99999f && *(s16 *)(g+0x368)==0 && !D_L01_001D673C) ||
            *(s32 *)(g+0x25C4)==43 || *(s32 *)(g+0x25C4)==44)
            func_L01_004130D0(g+0x1540);
        else func_L01_004130C0(g+0x1540);
        if(*(s32 *)(g+0x25CC)==17) {
            target.q=*(u128_t *)(g+0x80);
            target.f[2]+=0.1f;
        } else {
            func_0038CE20(&target,g+0x14A0,0.7f);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "+m"(target) : "m"(*(Vec4 *)(g+0x80)) : "vf1","vf2");
        }
        option=D_00143950_00512E68[0xA4];
        if(!option && (*(s32 *)(g+0x25C4)==1 || *(s32 *)(g+0x25C4)==29)) *(u16 *)(g+0x1620) |= 8;
        if(*(s32 *)(g+0x25CC)==3 || *(s32 *)(g+0x25CC)==20) {
            if(*(f32 *)(g+0x15F8)!=-0.7853982f) func_003C4138(g+0x15F8,-0.7853982f,0.041887906f);
        } else {
            if(*(f32 *)(g+0x15F8)!=-1.0471976f) func_003C4138(g+0x15F8,-1.0471976f,0.041887906f);
        }
        m=g+0x1540;
        func_L01_00413138(m,D_001D52FC,m-0x20,m-0x30,&target,option,1.0f);
        func_L01_00513FD8();
        if(*(s32 *)(g+0x16B0) && *(s32 *)(g+0x1228)!=9) {
            *(u16 *)(g+0x1434)=2;
            *(u128_t *)(g+0x190)=*(u128_t *)(g+0x1630);
            *(f32 *)(g+0x1A0)=*(f32 *)(g+0x1580);
        }
    } else if(!D_00143950_00512E68[0xA4]) {
        *(f32 *)(g+0x15A0)=*(f32 *)(D_L01_001E2A40+0x14);
        *(f32 *)(g+0x1580)=*(f32 *)(D_L01_001E2A40+0x18);
        *(u128_t *)(g+0x1630)=*(u128_t *)(D_L01_001E2A40+0x380);
        func_0038CC88(g+0x1540,D_L01_001E2A40+0x380,0x30);
        func_0038CF68(g+0x1570,g+0x20,*(f32 *)(g+0x16CC));
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "+m"(*(Vec4 *)(g+0x1570)) : "m"(*(Vec4 *)(g+0x80)) : "vf1","vf2");
        *(u128_t *)(g+0x1520)=*(u128_t *)(g+0x1570);
    }
    if(func_L01_00513EF0() || ((*(s32 *)(g+0x25C4)==1 || *(s32 *)(g+0x25C4)==29) && g[0x25E5])) {
        if(!*(s32 *)(g+0x16B0)) {
            actor=*(u8 **)(g+0x1200);
            if(actor && *(s16 *)(actor+0xAA)!=71) {
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(*(Vec4 *)(g+0x14E0)) : "m"(*(Vec4 *)(actor+0x10)), "m"(*(Vec4 *)(g+0x80)) : "vf1","vf2");
                func_0038D000((Vec4_50D4D8 *)(g+0x14E0),(f32 *)(g+0x14E0),(Vec4_50D4D8 *)(g+0x40));
                func_003C3FC0(g+0x14F0,actor+0xF0);
            }
            *(s32 *)(g+0x16B0)=D_00143950_00512E68[0xA4] ? D_00143950_00512E68[0xA4] : 2;
            *(f32 *)(g+0x16A8)=1.0f;
            *(s32 *)(g+0x16BC)=0;
            *(s32 *)(g+0x16AC)=0;
        }
    } else if(*(s32 *)(g+0x25C4)!=1 && *(s32 *)(g+0x25C4)!=29) *(s32 *)(g+0x16B0)=0;
    if(!g[0x25E4] && *(s32 *)(g+0x16B0)==2) func_L01_005133E8();
}
/* localdecomp:end func_L01_00512E68 */
