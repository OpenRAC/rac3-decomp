/* functional: medium. Large diff count; geometry order of the 4 quad vertices not re-derived from asm */
typedef struct { Vec4 v[4]; u32 color[4]; f32 uv[8]; unsigned long state[4]; } Packet_003A94A8;
extern Vec4 D_L01_001E29C0;
extern f32 D_L01_001DE378[];
extern f32 D_L01_001DE37C[];
void func_L01_003A94A8(u8 *obj) {
    extern f32 func_00382538(void);
    extern void func_003D9508(void *,s32,s32,s32,f32,f32,f32);
    extern void func_0038CF68(u8 *,Vec4 *,f32);
    extern void func_0038CE90(u8 *,u8 *,u8 *);
    extern f32 func_L01_00443A18(f32,f32);
    extern unsigned long func_00389598(s32);
    extern void func_003D2DA0(void *,s32,s32);
    Vec4 pos;
    Packet_003A94A8 packet;
    Vec4 a,b,diff,offset,copy,tmp,cam0,cam1,cam2;
    u8 *vars;
    f32 scale;
    s32 i;

    pos=*(Vec4 *)(obj+0x10);
    vars=*(u8 **)(obj+0x68);
    func_003D9508(&pos,65,0x40206080,1,0.75f,0.01f,func_00382538());
    func_0038CF68((u8 *)&offset,(Vec4 *)vars,-3.0f);
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(Vec4 *)&offset) : "m"(*(Vec4 *)&pos), "m"(*(Vec4 *)&offset) : "vf1", "vf2");
    scale=func_L01_00443A18(0.0f,0.2f);
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&diff) : "m"(*(Vec4 *)&pos), "m"(*(Vec4 *)&offset) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tsqc2 $vf2, %0" : "=m"(*(Vec4 *)&cam2) : "m"(*(Vec4 *)&D_L01_001E29C0) : "vf2");
    scale+=0.75f;
    __asm__("lqc2 $vf2, %1\n\tsqc2 $vf2, %0" : "=m"(*(Vec4 *)&cam0) : "m"(*(Vec4 *)&D_L01_001E29C0) : "vf2");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&a) : "m"(*(Vec4 *)&pos), "m"(*(Vec4 *)&cam2) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&b) : "m"(*(Vec4 *)&offset), "m"(*(Vec4 *)&cam0) : "vf1", "vf2");
    func_0038CE90((u8 *)&a,(u8 *)&a,(u8 *)&diff);
    func_0038CF68((u8 *)&a,&a,scale);
    func_0038CE90((u8 *)&b,(u8 *)&b,(u8 *)&diff);
    func_0038CF68((u8 *)&b,&b,scale);
    packet.state[1]=func_00389598(63);
    packet.state[2]=0xFF9000000260UL;
    packet.state[3]=0x8000000048UL;
    packet.state[0]=0;
    packet.color[0]=0x50206080; packet.color[3]=0x50206080; packet.color[2]=0x50206080; packet.color[1]=0x50206080;
    { f32 *src0=D_L01_001DE378, *dst0=&packet.uv[0], *src1=D_L01_001DE37C, *dst1=&packet.uv[1];
    for (i=0;i<4;i++) { f32 u=*src0; f32 v=*src1; *dst0=u; *dst1=v; src0+=2;src1+=2;dst0+=2;dst1+=2; } }
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&tmp) : "m"(*(Vec4 *)&offset), "m"(*(Vec4 *)&a) : "vf1", "vf2"); copy=tmp; packet.v[0]=copy;
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&tmp) : "m"(*(Vec4 *)&offset), "m"(*(Vec4 *)&a) : "vf1", "vf2"); copy=tmp; packet.v[1]=copy;
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&tmp) : "m"(*(Vec4 *)&pos), "m"(*(Vec4 *)&b) : "vf1", "vf2"); copy=tmp; packet.v[2]=copy;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&tmp) : "m"(*(Vec4 *)&pos), "m"(*(Vec4 *)&b) : "vf1", "vf2"); copy=tmp; packet.v[3]=copy;
    func_003D2DA0(&packet,0,0);
    *(f32 *)(vars+0x1C)+=0.15f;
    if (*(f32 *)(vars+0x1C)>=4.0f) *(f32 *)(vars+0x1C)-=4.0f;
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&diff) : "m"(*(Vec4 *)&pos), "m"(*(Vec4 *)&offset) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tsqc2 $vf2, %0" : "=m"(*(Vec4 *)&cam1) : "m"(*(Vec4 *)&D_L01_001E29C0) : "vf2");
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&a) : "m"(*(Vec4 *)&pos), "m"(*(Vec4 *)&D_L01_001E29C0) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&b) : "m"(*(Vec4 *)&offset), "m"(*(Vec4 *)&cam1) : "vf1", "vf2");
    func_0038CE90((u8 *)&a,(u8 *)&a,(u8 *)&diff);
    func_0038CF68((u8 *)&a,&a,0.15f);
    func_0038CE90((u8 *)&b,(u8 *)&b,(u8 *)&diff);
    func_0038CF68((u8 *)&b,&b,0.4f);
    packet.state[1]=func_00389598(61);
    packet.state[2]=0xFF9000000260UL;
    packet.state[3]=0x8000000048UL;
    packet.state[0]=0;
    packet.color[0]=0x80202080; packet.color[3]=0x80202080; packet.color[2]=0x80202080; packet.color[1]=0x80202080;
    { f32 *src0=D_L01_001DE378, *dst0=&packet.uv[0], *src1=D_L01_001DE37C, *dst1=&packet.uv[1];
    for (i=0;i<4;i++) { f32 scroll=*(f32 *)(vars+0x1C); f32 u=*src0; f32 v=*src1; *dst0=u+scroll; *dst1=v; src0+=2;src1+=2;dst0+=2;dst1+=2; } }
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&tmp) : "m"(*(Vec4 *)&offset), "m"(*(Vec4 *)&a) : "vf1", "vf2"); copy=tmp; packet.v[0]=copy;
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&tmp) : "m"(*(Vec4 *)&offset), "m"(*(Vec4 *)&a) : "vf1", "vf2"); copy=tmp; packet.v[1]=copy;
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&tmp) : "m"(*(Vec4 *)&pos), "m"(*(Vec4 *)&b) : "vf1", "vf2"); copy=tmp; packet.v[2]=copy;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec4 *)&tmp) : "m"(*(Vec4 *)&pos), "m"(*(Vec4 *)&b) : "vf1", "vf2"); copy=tmp; packet.v[3]=copy;
    func_003D2DA0(&packet,0,0);
}
