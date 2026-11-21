/* functional: high. Needs the file's vu0.h, qzero, V_3A7C18, S_3A9AC0m context */
typedef struct { u8 pad[0x18]; u8 b18,b19; u16 h1A; u8 tail[0x14]; } Hit_003A8E50;
extern u8 *D_L01_001EAA18[];
void func_L01_003A8E50(u8 *m) {
    extern void func_L01_00446780(void *,void *,s32,s32,s32,s32,f32,f32,f32);
    extern void func_L01_004450F0(S_3A9AC0m *,int,int);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_0046C470(void *,void *,s32,s32,s32,s32,s32,s32,f32);
    extern void func_L01_00446760(void *,void *,s32,void *,f32);
    extern void func_L01_004CB320(void);
    extern void func_L01_004CB358(void);
    extern s32 func_003D3CB0(void *,void *,s32,void *,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_003D4D00(void *,s32,void *,void *,f32);
    extern void func_L01_003303B8(void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,
        s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_L01_003A94A8(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *),u8 *);
    Vec4 pos, direction, up, side, end;
    u8 *position;
    Vec4 *effect;
    Hit_003A8E50 hit;
    Vec4 impulse;
    Hit_003A8E50 hit2;
    Vec4 tmp1,tmp2;
    V_3A7C18 *p=*(V_3A7C18 **)(m+0x68);
    f32 sn,cs;
    s32 did_hit;
    u8 *other;
    if (++p->f18>240) {
        func_L01_00446780(m,m+0x10,0x10001,0,1,0,0.6f,p->f14,0.0f);
        func_L01_004450F0((S_3A9AC0m *)m,1,-1);
    }
    direction.q=p->q0;
    qzero(&up);
    up.f[2]=1.0f;
    func_0038CE90((u8 *)&side,(u8 *)&up,(u8 *)&direction);
    func_0038CF68((u8 *)&side,&side,1.0f);
    position=m+0x10;
    effect=&pos;
    qzero(&pos);
    sn=func_0038D098(p->f20)*0.25f;
    cs=func_0038D0B0(p->f20)*0.25f;
    func_0038CF68((u8 *)&side,&side,sn);
    func_0038CF68((u8 *)&up,&up,cs);
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(pos) : "m"(pos),"m"(up) : "vf1","vf2");
    __asm__("lqc2 $vf2,%1\n\tsqc2 $vf2,%0" : "=m"(tmp1) : "m"(*(Vec4 *)(m+0x10)) : "vf2");
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(pos) : "m"(pos),"m"(side) : "vf1","vf2");
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(pos) : "m"(pos),"m"(tmp1) : "vf1","vf2");
    func_L01_0046C470(effect,D_L01_001D66B0,0x60202080,16,0,0,64,0,0.75f);
    qzero(&up);qzero(&pos);
    up.f[2]=1.0f;
    func_0038CE90((u8 *)&side,(u8 *)&up,(u8 *)&direction);
    func_0038CF68((u8 *)&side,&side,1.0f);
    func_0038CF68((u8 *)&side,&side,-sn);
    func_0038CF68((u8 *)&up,&up,-cs);
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(pos) : "m"(pos),"m"(up) : "vf1","vf2");
    __asm__("lqc2 $vf2,%1\n\tsqc2 $vf2,%0" : "=m"(tmp2) : "m"(*(Vec4 *)(m+0x10)) : "vf2");
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(pos) : "m"(pos),"m"(side) : "vf1","vf2");
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(pos) : "m"(pos),"m"(tmp2) : "vf1","vf2");
    func_L01_0046C470(effect,D_L01_001D66B0,0x60202080,16,0,0,64,0,0.75f);
    p->f20-=0.25f;
    if(p->f20 < -3.1415927410125732f) p->f20=3.1415927410125732f;
    switch(m[0x20]) {
    case 0:
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(end) : "m"(*(Vec4 *)(m+0x10)),"m"(*(Vec4 *)p) : "vf1","vf2");
        func_L01_00446760(&hit,m,(s32)((Vec4 *)p)->f[3],p,p->f14);
        hit.h1A=*(u16 *)(m+0xAA);
        func_L01_004CB320();
        did_hit=func_003D3CB0(position,&end,0,m,&hit);
        if(did_hit) {
            other=D_L01_001EAA18[0];
            if(other && *(s16 *)(other+0xAA)==0x186D && other[0x20]!=2 && other[0x20]!=5) other[0x20]=4;
        }
        func_L01_004CB358();
        if(did_hit) {
            f32 scale;
            if(D_L01_001EAA18[0]) {
                if(D_L01_001EAA18[0]==p->parent) goto keep_moving;
                scale=1.5f;
            } else scale=3.0f;
            impulse.q=p->q0;
            func_0038CE20(&impulse,&impulse,scale);
            impulse.f[2]=1.0f;
            impulse.f[3]=5627.9248046875f;
            func_L01_00446760(&hit2,m,(s32)((Vec4 *)p)->f[3],&impulse,p->f14);
            hit2.b19=1;hit2.h1A=*(u16 *)(m+0xAA);hit2.b18=0;
            func_003D4D00(m+0x10,0,m,&hit2,0.6f);
            func_L01_004450F0((S_3A9AC0m *)m,1,-1);
            return;
        }
keep_moving:
        *(u128_t *)(m+0x10)=end.q;
        func_0038CE20(&impulse,p,-0.5f);
        break;
    case 1:
        func_L01_003303B8(position,0,10,10,10,10,10,0,0.25f,0.0f,0.0f,2.0f,
            0,1,0,0,0,0,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0);
        func_003C2880((Obj_003A5118 *)m);
        return;
    }
    func_L01_00404A10(func_L01_003A94A8,m);
}
