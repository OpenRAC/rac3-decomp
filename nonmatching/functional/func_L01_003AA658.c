/* functional: medium. Owner extern of func_003A52A0 should change to s32; frame size differs, one local missing */
void func_L01_003AA658(u8 *m) {
    extern void func_L01_003AAE80(u8 *,u8 *);
    extern s32 func_L01_003ACD38(u8 *,u8 *);
    extern s32 func_L01_004561E0(u8 *);
    extern void func_003C3A10(void *,s32,s32,s32);
    extern void func_L01_003AD418(u8 *,u8 *);
    extern void func_003A52A0(s32,s32,void *);
    extern void func_L01_00445170(u8 *,s32);
    extern s32 func_L01_003AB470(s32,u8 *);
    extern void func_L01_003AADB8(u8 *,G_003AADB8 *);
    extern void func_L01_004450F0(S_3A9AC0m *,int,int);
    extern void func_L01_003AB790(u8 *,u8 *);
    extern s32 func_0038CAD0(s32 *);
    extern s32 func_L01_004AA710(u8 *,s32);
    extern s32 func_L01_003AC000(u8 *,u8 *);
    extern void func_L01_003AD800(u8 *,u8 *);
    extern s32 func_L01_003ADA68(u8 *,u8 *);
    extern void func_L01_003ADBE0(u8 *,u8 *,s32);
    extern void func_L01_003ACAD0(u8 *,s32);
    extern void func_L01_003AB5D0(u8 *,u8 *,f32 *,f32 *,f32 *);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_0038D308(void *,void *);
    extern void func_L01_003AC8C0(u8 *,u8 *,void *);
    extern void func_L01_003AD898(u8 *,u8 *);
    extern void func_L01_003AD010(u8 *,u8 *);
    extern void func_L01_003AB208(u8 *,Moby_003A9A80 *);
    extern u8 *func_L01_0045B958(u8 *);
    u128_t position, rotation;
    f32 dz, rx, ry;
    u8 *v=*(u8 **)(m+0x68);
    u8 *cfg;
    u8 *child;
    u8 *out;
    s32 r;
    s32 *timers;
    if(m[0x20]==0) { func_L01_003AAE80(m,v);return; }
    if(func_L01_003ACD38(m,v)) return;
    position=*(u128_t *)(m+0x10); rotation=*(u128_t *)(m+0xf0);
    *(u128_t *)(m+0x10)=*(u128_t *)(v+0x80);
    *(u128_t *)(m+0xf0)=*(u128_t *)(v+0x90);
    switch(m[0x95]) {
    case 0: case 4: break;
    case 1:
        if(func_L01_004561E0(m)) {
            cfg=*(u8 **)(v+0x68);
            func_003C3A10(*(u8 **)(v+0x64),*(s32 *)(cfg+0x68),0,8);
            *(f32 *)(*(u8 **)(v+0x64)+0x48)=1.0f;
        }
        break;
    case 2:
        if(func_L01_004561E0(m)) {
            cfg=*(u8 **)(v+0x68);
            func_003C3A10(*(u8 **)(v+0x64),*(s32 *)(cfg+0x6c),*(s32 *)(cfg+0x78),4);
            *(f32 *)(*(u8 **)(v+0x64)+0x48)=*(f32 *)(*(u8 **)(v+0x68)+0x7c);
        }
        func_L01_003AD418(m,v); break;
    case 3:
        if(func_L01_004561E0(m)) {
            cfg=*(u8 **)(v+0x68);
            func_003C3A10(*(u8 **)(v+0x64),*(s32 *)(cfg+0x70),0,8);
            *(f32 *)(*(u8 **)(v+0x64)+0x48)=1.0f;
            cfg=*(u8 **)(v+0x68);
            if(*(s32 *)(cfg+0x74)>=0) func_003A52A0(*(s32 *)(cfg+0x74),0,*(u8 **)(v+0x64));
        }
        if((*(u8 **)(v+0x64))[0x60]&2) {
            func_L01_00445170(m,1);
            cfg=*(u8 **)(v+0x68);
            func_003C3A10(*(u8 **)(v+0x64),*(s32 *)(cfg+0x68),0,0);
        }
        break;
    }
    switch(m[0x20]) {
    case 1:
        if(!func_L01_003AB470((s32)m,v)) return;
        func_L01_003AADB8(m,(G_003AADB8 *)v);
        func_L01_004450F0((S_3A9AC0m *)m,1,1);
        *(s32 *)(v+0xd0c)=-1;
        goto reset;
    case 2:
        if(func_L01_003AB470((s32)m,v) && func_0038CAD0((s32 *)(v+0xcf4))) {
            *(s32 *)(v+0xd0c)=-1;
            func_L01_003AB790(m,v);
            *(s32 *)(v+0xd18)=0;
        }
        break;
    case 3:
        cfg=*(u8 **)(v+0x68);
        if(*(s32 *)(cfg+0x64)>=0 && !func_L01_004AA710(*(u8 **)(v+0x64),*(s32 *)(v+0xd1c))) {
            cfg=*(u8 **)(v+0x68);
            /* Retail stores the sound helper's return; the owner's current prototype is void. */
            *(s32 *)(v+0xd1c)=((s32 (*)(s32,s32,void *))func_003A52A0)(*(s32 *)(cfg+0x64),4,*(u8 **)(v+0x64));
        }
        r=func_L01_003AC000(m,v);
        if(r && *(s32 *)(v+0xc90+*(s32 *)(v+0xd0c)*4)==-1) {
            timers=(s32 *)(v+0xcb0);
            if(timers[*(s32 *)(v+0xd0c)]<=0) goto reset;
            func_L01_004450F0((S_3A9AC0m *)m,4,-1);
            *(s32 *)(v+0xcf4)=timers[*(s32 *)(v+0xd0c)];
        } else if(r==2) {
            cfg=*(u8 **)(v+0x68);
            func_L01_003AD800(m,v);
            func_L01_004450F0((S_3A9AC0m *)m,4,-1);
            *(s32 *)(v+0xcf4)=*(s32 *)(v+0xcb0+*(s32 *)(v+0xd0c)*4);
            *(s32 *)(v+0xcf8)=*(s32 *)(v+0x6c)%*(s32 *)(cfg+0x34);
        }
        break;
    case 4:
        cfg=*(u8 **)(v+0x68);
        if(*(s32 *)(cfg+0x64)>=0 && !func_L01_004AA710(*(u8 **)(v+0x64),*(s32 *)(v+0xd1c))) {
            cfg=*(u8 **)(v+0x68);
            *(s32 *)(v+0xd1c)=((s32 (*)(s32,s32,void *))func_003A52A0)(*(s32 *)(cfg+0x64),4,*(u8 **)(v+0x64));
        }
        if(func_0038CAD0((s32 *)(v+0xcf4))) {
            if(*(s32 *)(v+0xc90+*(s32 *)(v+0xd0c)*4)!=-1 && (r=func_L01_003ADA68(m,v))) {
                func_L01_003ADBE0(m,v,r);
                if(func_L01_003ADA68(m,v)) *(s32 *)(v+0xcf4)=*(s32 *)(v+0xcc0+*(s32 *)(v+0xd0c)*4);
                else *(s32 *)(v+0xcf4)=*(s32 *)(v+0xcd0+*(s32 *)(v+0xd0c)*4);
            } else goto reset;
        }
        break;
    case 5:
        cfg=*(u8 **)(v+0x68);
        if(*(s32 *)(cfg+0x64)>=0 && !func_L01_004AA710(*(u8 **)(v+0x64),*(s32 *)(v+0xd1c))) {
            cfg=*(u8 **)(v+0x68);
            *(s32 *)(v+0xd1c)=((s32 (*)(s32,s32,void *))func_003A52A0)(*(s32 *)(cfg+0x64),4,*(u8 **)(v+0x64));
        }
        if(func_L01_003AC000(m,v) && *(s32 *)(v+0xc5c)) { func_L01_003ACAD0(m,1);return; }
        break;
    case 6: break;
    }
    goto finish;
reset:
    func_L01_003AB790(m,v);
finish:
    *(u128_t *)(v+0x80)=*(u128_t *)(m+0x10);
    *(u128_t *)(v+0x90)=*(u128_t *)(m+0xf0);
    func_L01_003AB5D0(m,v,&dz,&rx,&ry);
    *(f32 *)(m+0x18)+=dz;
    *(f32 *)(m+0xf0)=func_0038DAB8(*(f32 *)(m+0xf0),rx);
    *(f32 *)(m+0xf4)=func_0038DAB8(*(f32 *)(m+0xf4),ry);
    func_0038D308(m+0xc0,m+0xf0);
    func_L01_003AC8C0(m,v,&position);
    func_L01_003AD898(m,v);
    func_L01_003AD010(m,v);
    if(*(u8 **)(v+0x64)) {
        if(m[0x20]!=1) func_L01_003AB208(m,(Moby_003A9A80 *)v);
        out=func_L01_0045B958(*(u8 **)(v+0x64));
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
          : "=m"(*(Vec4 *)(out+0xa0))
          : "m"(*(Vec4 *)(m+0x10)), "m"(*(Vec4 *)&position) : "vf1","vf2");
    }
}
