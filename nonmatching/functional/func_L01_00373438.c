/* functional: high. Verified vs PAL asm: width falloff after t>32, VU sub/add operands for both quads, rand ranges (0.1-0.3, 0.05-0.15) and offsets, GS tag words, UV copy loop, packet layout (vertices at +0x10 passed to the draw helper), tex ids 0x3E/0x3F, colours; bytes differ in VU scheduling only. */
typedef int Q_00373438 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00373438;
typedef struct {
    Q_00373438 input;
    V_00373438 vertices[4];
    u32 colors[4];
    f32 uv[8];
    unsigned long tag[4];
} Packet_00373438;
extern V_00373438 D_L01_001E29C0;
extern s32 D_L01_001DD9D8;
__asm__(".extern D_L01_001DD9D8, 4");
extern u32 D_L01_001DD9E0;
__asm__(".extern D_L01_001DD9E0, 4");
extern f32 D_L01_001DD9E8[];
extern f32 D_L01_001DD9EC[];
void func_L01_00373438(u8 *obj, Q_00373438 *input) {
    extern void func_0038CE90(void *,void *,void *);
    extern f32 func_L01_00443A18(f32,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern unsigned long func_00389598(s32);
    extern void func_003D2DA0(void *,s32,s32);
    Packet_00373438 packet;
    V_00373438 a,b,dir,copy,tmp,saved;
    u8 *state;
    V_00373438 *global = &D_L01_001E29C0;
    f32 width = 0.65f;
    f32 t;
    s32 i;

    packet.input = *input;
    state = *(u8 **)(obj + 0x68);
    if (32.0f < *(f32 *)(state + 0x38)) {
        width = (1.0f - (*(f32 *)(state + 0x38) - 32.0f) / 6.0f) * width;
        if (width < 0.001f) width = 0.001f;
    }
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(dir) : "m"(*(V_00373438 *)state), "m"(*(V_00373438 *)(state+0x10)) : "vf1","vf2");
    __asm__("lqc2 $vf2,0(%5)\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0\n\tlqc2 $vf1,%3\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%1" : "=m"(a),"=m"(b) : "m"(*(V_00373438 *)state),"m"(*(V_00373438 *)(state+0x10)),"m"(D_L01_001E29C0),"r"(global) : "vf1","vf2");
    func_0038CE90(&a,&a,&dir);
    t=func_L01_00443A18(0.1f,0.3f);
    func_0038CF68(&a,&a,(t+0.65f)*width);
    func_0038CE90(&b,&b,&dir);
    t=func_L01_00443A18(0.1f,0.3f);
    func_0038CF68(&b,&b,(t+0.65f)*width);
    packet.tag[1]=func_00389598(0x3E);
    packet.tag[2]=0xFF9000000260UL;
    packet.tag[3]=((unsigned long)D_L01_001DD9D8 << 32) | 0x48;
    packet.tag[0]=0;
    packet.colors[0]=D_L01_001DD9E0;
    packet.colors[3]=D_L01_001DD9E0;
    packet.colors[2]=D_L01_001DD9E0;
    packet.colors[1]=D_L01_001DD9E0;
    { f32 *src0,*src1,*dst0,*dst1;
    src0=D_L01_001DD9E8; src1=D_L01_001DD9E8+1; dst0=packet.uv;dst1=packet.uv+1;
    for(i=3;i>=0;i--) { f32 x=*src0; f32 y=*src1; *dst0=x;*dst1=y;src0+=2;src1+=2;dst0+=2;dst1+=2; } }
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_00373438 *)(state+0)),"m"(a) : "vf1","vf2");
    copy=tmp;packet.vertices[0]=tmp;
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_00373438 *)(state+0)),"m"(a) : "vf1","vf2");
    copy=tmp;packet.vertices[1]=tmp;
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_00373438 *)(state+16)),"m"(b) : "vf1","vf2");
    copy=tmp;packet.vertices[2]=tmp;
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_00373438 *)(state+16)),"m"(b) : "vf1","vf2");
    copy=tmp;packet.vertices[3]=tmp;
    func_003D2DA0(packet.vertices,0,0);
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(dir) : "m"(*(V_00373438 *)state), "m"(*(V_00373438 *)(state+0x10)) : "vf1","vf2");
    __asm__("lqc2 $vf2,0(%6)\n\tlqc2 $vf1,0(%6)\n\tsqc2 $vf1,%2\n\tlqc2 $vf1,%3\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0\n\tlqc2 $vf2,%2\n\tlqc2 $vf1,%4\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%1" : "=m"(a),"=m"(b),"=m"(saved) : "m"(*(V_00373438 *)state),"m"(*(V_00373438 *)(state+0x10)),"m"(D_L01_001E29C0),"r"(global) : "vf1","vf2");
    func_0038CE90(&a,&a,&dir);
    t=func_L01_00443A18(0.05f,0.15f);
    func_0038CF68(&a,&a,(t+0.325f)*width);
    func_0038CE90(&b,&b,&dir);
    t=func_L01_00443A18(0.05f,0.15f);
    func_0038CF68(&b,&b,(t+0.325f)*width);
    packet.tag[1]=func_00389598(0x3F);
    packet.tag[2]=0xFF9000000260UL;
    packet.tag[3]=((unsigned long)D_L01_001DD9D8 << 32) | 0x48;
    packet.tag[0]=0;
    packet.colors[0]=0x60DDDDDD;
    packet.colors[3]=0x60DDDDDD;
    packet.colors[2]=0x60DDDDDD;
    packet.colors[1]=0x60DDDDDD;
    { f32 *src0,*src1,*dst0,*dst1;
    src0=D_L01_001DD9E8;src1=D_L01_001DD9E8+1;dst0=packet.uv;dst1=packet.uv+1;
    for(i=3;i>=0;i--) { f32 x=*src0; f32 y=*src1; *dst0=x;*dst1=y;src0+=2;src1+=2;dst0+=2;dst1+=2; } }
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_00373438 *)(state+0)),"m"(a) : "vf1","vf2");
    copy=tmp;packet.vertices[0]=tmp;
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_00373438 *)(state+0)),"m"(a) : "vf1","vf2");
    copy=tmp;packet.vertices[1]=tmp;
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_00373438 *)(state+16)),"m"(b) : "vf1","vf2");
    copy=tmp;packet.vertices[2]=tmp;
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_00373438 *)(state+16)),"m"(b) : "vf1","vf2");
    copy=tmp;packet.vertices[3]=tmp;
    func_003D2DA0(packet.vertices,0,0);
}
