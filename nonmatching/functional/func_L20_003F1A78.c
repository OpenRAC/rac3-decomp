/* functional: high. Draft re-verified line by line against the PAL asm (branches, offsets, constants, args, 30-arg effect call, shift loop, callee names; the shift-callback is the catalogue name func_L13_003C5E20 at this level). Differs only in frame size (0x160 vs 0x150), register allocation and VU0 load scheduling. */
typedef int Q_3F1A78 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_3F1A78;
typedef struct { u8 pad[0x18]; u8 flag0,flag1; u16 kind; u8 rest[0x14]; } Hit_3F1A78;
typedef struct { u8 pad[0xD0]; u8 flag; u8 padD1[0xB]; void *owner; } Slot_3F1A78;
static __inline__ void sub_3F1A78(void *d,void *a,void *b) {
    __asm__(
        "lqc2 $vf1,%1\n"
        "lqc2 $vf2,%2\n"
        "vsub.xyz $vf1,$vf1,$vf2\n"
        "sqc2 $vf1,%0\n"
        : "=m"(*(V_3F1A78 *)d) : "m"(*(V_3F1A78 *)a),"m"(*(V_3F1A78 *)b) : "vf1","vf2");
}
static __inline__ void addba_3F1A78(void *d,void *a,void *b) {
    __asm__(
        "lqc2 $vf2,%2\n"
        "lqc2 $vf1,%1\n"
        "vadd.xyz $vf1,$vf1,$vf2\n"
        "sqc2 $vf1,%0\n"
        : "=m"(*(V_3F1A78 *)d) : "m"(*(V_3F1A78 *)a),"m"(*(V_3F1A78 *)b) : "vf1","vf2");
}
extern u8 D_001A30B0[];
extern u8 D_001A4BE0[];
extern s32 func_003A52A0(s32,s32,void *);
extern void func_003A4F28(s32);
extern s32 func_L01_003303B8(void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,
    s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
extern void func_003C2880(void *);
extern void func_003C2F58(void *,s32,void *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32,f32);
extern s32 func_00382498(s32,s32);
extern u8 *func_L01_0046A610(void *,void *,s32,s32,s32,s32,f32,f32,f32,f32,f32);
extern u8 D_L20_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L20_002202B4[];
extern void func_0038CF68(void *,void *,f32);
extern void func_003C4098(void *,void *,void *,f32);
extern f32 func_0038CEA8(void *);
extern void func_0038D890(void *,void *,void *,f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32,f32);
extern f32 func_0038DAB8(f32,f32);
extern void func_L01_00446760(void *,void *,s32,void *,f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *,void *,s32,void *,void *);
extern u8 *D_L20_001E9BD8[];
extern V_3F1A78 D_L20_001E9BE0;
extern void func_L01_00446780(void *,void *,s32,s32,s32,s32,f32,f32,f32);
extern void func_L01_00404A10(void (*)(void *),void *);
extern void func_L13_003C5E20(void *);
void func_L20_003F1A78(u8 *m) {
    V_3F1A78 a,b,c,d,tmp;
    Hit_3F1A78 hit;
    u8 *p=*(u8 **)(m+0x68);
    u8 *other;
    u8 *source;
    s32 id=*(s32 *)(p+0x28);
    s32 collision;
    s32 i;
    f32 angle;
    if(id==-1 || ((Slot_3F1A78 *)(D_001A30B0+(id<<7)))->owner!=m ||
        ((Slot_3F1A78 *)(D_001A30B0+(id<<7)))->flag==0)
        *(s32 *)(p+0x28)=func_003A52A0(1,4,m);
    if(*(u16 *)(m+0x96)>=351) {
        id=*(s32 *)(p+0x28);
        if(id!=-1 && ((Slot_3F1A78 *)(D_001A30B0+(id<<7)))->owner==m &&
            ((Slot_3F1A78 *)(D_001A30B0+(id<<7)))->flag!=0) func_003A4F28(id);
        *(s32 *)(p+0x28)=-1;
        func_003A52A0(0,0,m);
        func_L01_003303B8(m+0x10,0,6,6,6,6,10,0,1.0f,0.0f,0.0f,2.0f,
            0,1,0,0,0,0,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,
            0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0);
        func_003C2880(m);
        return;
    }
    func_003C2F58(m,0,&a);
    {
        s32 rnd=func_00382468(40);
        u8 *e=func_L01_0046A610(&a,D_L20_001D66B0,17,96,0x101010,rnd,
            252000.015625f,func_003824E0(500.0f,1500.0f),1.0f,0.0f,0.0f);
        if(e) { e[2]=D_L20_002202B4[0][0]; e[3]=0x44; }
    }
    source=p+0x10;
    if(*(u16 *)(m+0x96)>=61) {
        other=*(u8 **)(p+0x2C);
        if(other==*(u8 **)(D_001A4BE0+0x25C0))
            sub_3F1A78(&b,D_001A4BE0+0xD0,m+0x10);
        else sub_3F1A78(&b,other+0x10,m+0x10);
        other=*(u8 **)(D_001A4BE0+0x19E0);
        if(other && *(s16 *)(other+0xAA)==0x1A17 &&
            *(void **)(p+0x2C)==*(void **)(D_001A4BE0+0x25C0)) {
            u8 *v=*(u8 **)(other+0x68);
            if(*(f32 *)(*(u8 **)(v+0x6D0)+0x138)>0.200000018f) {
                func_0038CF68(&d,other+0xC0,(f32)func_00382498(15,30));
                __asm__(
                    "lqc2 $vf1,%3\n"
                    "lqc2 $vf2,%4\n"
                    "vadd.xyz $vf2,$vf2,$vf1\n"
                    "lqc2 $vf1,%5\n"
                    "sqc2 $vf1,%2\n"
                    "sqc2 $vf2,%1\n"
                    "lqc2 $vf1,%1\n"
                    "lqc2 $vf2,%2\n"
                    "vsub.xyz $vf1,$vf1,$vf2\n"
                    "sqc2 $vf1,%0\n"
                    : "=m"(b),"=m"(c),"=m"(tmp)
                    : "m"(*(V_3F1A78 *)(D_001A4BE0+0xD0)),"m"(d),"m"(*(V_3F1A78 *)(m+0x10))
                    : "vf1","vf2");
            }
        }
        *(Q_3F1A78 *)&c=*(Q_3F1A78 *)(p+0x10);
        func_003C4098(p+0x10,&c,&b,0.01f);
        source=p+0x10;
        if(*(u16 *)(m+0x96)>=61 && *(s32 *)(p+0x20)!=0) {
            *(Q_3F1A78 *)&b=*(Q_3F1A78 *)p;
            *(Q_3F1A78 *)&c=*(Q_3F1A78 *)(p+0x10);
            func_003C4098(p,&b,&c,0.005f);
            if(func_0038CEA8(p)>2.0000002384f) func_0038CF68(p,p,2.0000002384f);
            if(*(s32 *)(p+0x20)==1) func_0038CF68(p,p,1.2f);
        }
    }
    *(Q_3F1A78 *)&b=*(Q_3F1A78 *)(m+0x10);
    func_0038D890(p,p,source,0.139626354f);
    *(f32 *)(m+0xF4)=-func_0038D160(func_0038CED8(p),*(f32 *)(p+8));
    *(f32 *)(m+0xF8)=func_0038D160(*(f32 *)p,*(f32 *)(p+4));
    angle=func_0038DAB8(*(f32 *)(m+0xF0),0.139626354f);
    *(f32 *)(m+0xF0)=angle;
    addba_3F1A78(m+0x10,m+0x10,p);
    func_0038CF68(&c,p,1.0f);
    func_L01_00446760(&hit,m,1,&c,45.0f);
    hit.flag1=1;
    hit.kind=*(u16 *)(m+0xAA);
    hit.flag0=1;
    {
        void *col=*(void **)(m+0xB8);
        func_L01_004CB320();
        collision=func_003D3CB0(&b,m+0x10,0,col,&hit);
    }
    if(collision) {
        other=D_L20_001E9BD8[0];
        if(other && *(s16 *)(other+0xAA)==0x186D &&
            other[0x20]!=2 && other[0x20]!=5) other[0x20]=4;
    }
    func_L01_004CB358();
    if(collision && (D_L20_001E9BD8[0]==0 ||
        (u32)(*(u16 *)(D_L20_001E9BD8[0]+0xAA)-0x199A)>=3)) {
        id=*(s32 *)(p+0x28);
        if(id!=-1 && ((Slot_3F1A78 *)(D_001A30B0+(id<<7)))->owner==m &&
            ((Slot_3F1A78 *)(D_001A30B0+(id<<7)))->flag!=0) func_003A4F28(id);
        *(s32 *)(p+0x28)=-1;
        func_003A52A0(0,0,m);
        func_L01_003303B8(&D_L20_001E9BE0,0,6,6,6,6,10,0,1.0f,0.0f,0.0f,2.0f,
            0,1,0,0,0,0,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,
            0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0);
        func_L01_00446780(m,&D_L20_001E9BE0,1,0,1,0,2.0f,45.0f,1.0f);
        func_003C2880(m);
        return;
    }
    *(Q_3F1A78 *)&d=*(Q_3F1A78 *)&a;
    for(i=3;i>0;i--) *(Q_3F1A78 *)(p+0x30+i*16)=*(Q_3F1A78 *)(p+0x20+i*16);
    *(Q_3F1A78 *)(p+0x30)=*(Q_3F1A78 *)&d;
    if(++*(s32 *)(p+0x24)>=4) func_L01_00404A10(func_L13_003C5E20,m);
    ++*(u16 *)(m+0x96);
}
